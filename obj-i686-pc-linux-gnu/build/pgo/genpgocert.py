
from automation import Automation
import os
import re
import shutil
import sys

DIST_BIN = "/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist/bin"
BIN_SUFFIX = ""
PROFILE_DIR = "../../_profile/pgo"
CERTS_SRC_DIR = "/home/txema/work/firefox-20.0+build1/build/pgo/certs"

automation = Automation()

dbFiles = [
  re.compile("^cert[0-9]+\.db$"),
  re.compile("^key[0-9]+\.db$"),
  re.compile("^secmod\.db$")
]

def unlinkDbFiles(path):
  for root, dirs, files in os.walk(path):
    for name in files:
      for dbFile in dbFiles:
        if dbFile.match(name) and os.path.exists(os.path.join(root, name)):
          os.unlink(os.path.join(root, name))

def dbFilesExist(path):
  for root, dirs, files in os.walk(path):
    for name in files:
      for dbFile in dbFiles:
        if dbFile.match(name) and os.path.exists(os.path.join(root, name)):
          return True
  return False


def runUtil(util, args, inputdata = None):
  if inputdata:
    proc = automation.Process([util] + args, env = automation.environment(), stdin = automation.PIPE)
    proc.communicate(inputdata)
    return proc.returncode
  return automation.Process([util] + args, env = automation.environment()).wait()


def createRandomFile(randomFile):
  import random
  file = open(randomFile, "wb");
  for count in xrange(0, 2048):
    file.write(chr(random.randint(0, 255)))
  file.close()


def createCertificateAuthority(profileDir, srcDir):
  certutil = DIST_BIN + "/certutil" + BIN_SUFFIX
  pk12util = DIST_BIN + "/pk12util" + BIN_SUFFIX

  tempDbDir = os.path.join(profileDir, ".temp")
  if not os.path.exists(tempDbDir):
    os.mkdir(tempDbDir)
  
  pwfilePath = os.path.join(tempDbDir, ".crtdbpw")
  rndfilePath = os.path.join(tempDbDir, ".rndfile")
  pgoCAModulePathSrc = os.path.join(srcDir, "pgoca.p12")
  pgoCAPathSrc = os.path.join(srcDir, "pgoca.ca")
  
  pwfile = open(pwfilePath, "w")
  pwfile.write("\n")
  pwfile.close()

  unlinkDbFiles(tempDbDir)

  # Create temporary certification database for CA generation
  status = runUtil(certutil, ["-N", "-d", tempDbDir, "-f", pwfilePath])
  if status != 0:
    return status

  createRandomFile(rndfilePath);
  status = runUtil(certutil, ["-S", "-d", tempDbDir, "-s", "CN=Temporary Certificate Authority, O=Mozilla Testing, OU=Profile Guided Optimization", "-t", "C,,", "-x", "-m", "1", "-v", "120", "-n", "pgo temporary ca", "-2", "-f", pwfilePath, "-z", rndfilePath], "Y\n0\nN\n")
  if status != 0:
    return status
 
  status = runUtil(certutil, ["-L", "-d", tempDbDir, "-n", "pgo temporary ca", "-a", "-o", pgoCAPathSrc, "-f", pwfilePath])
  if status != 0:
    return status
 
  status = runUtil(pk12util, ["-o", pgoCAModulePathSrc, "-n", "pgo temporary ca", "-d", tempDbDir, "-w", pwfilePath, "-k", pwfilePath])
  if status != 0:
    return status
    
  unlinkDbFiles(tempDbDir)
  os.unlink(pwfilePath)
  os.unlink(rndfilePath)
  os.rmdir(tempDbDir)
  return 0


def createSSLServerCertificate(profileDir, srcDir):
  certutil = DIST_BIN + "/certutil" + BIN_SUFFIX
  pk12util = DIST_BIN + "/pk12util" + BIN_SUFFIX

  pwfilePath = os.path.join(profileDir, ".crtdbpw")
  rndfilePath = os.path.join(profileDir, ".rndfile")
  pgoCAPath = os.path.join(srcDir, "pgoca.p12")
  
  pwfile = open(pwfilePath, "w")
  pwfile.write("\n")
  pwfile.close()

  if not dbFilesExist(srcDir):
    # Make sure all DB files from src are really deleted
    unlinkDbFiles(srcDir)
    
    # Create certification database for ssltunnel
    status = runUtil(certutil, ["-N", "-d", srcDir, "-f", pwfilePath])
    if status != 0:
      return status
  
    status = runUtil(pk12util, ["-i", pgoCAPath, "-w", pwfilePath, "-d", srcDir, "-k", pwfilePath])
    if status != 0:
      return status

  # Generate automatic certificate
  locations = automation.readLocations(os.path.join(profileDir, "server-locations.txt"))
  locations.pop(0)
  locationsParam = ""
  firstLocation = ""
  for loc in locations:
    if loc.scheme == "https" and "nocert" not in loc.options:
      customCertOption = False
      customCertRE = re.compile("^cert=(?:\w+)")
      for option in loc.options:
        match = customCertRE.match(option)
        if match:
          customCertOption = True
          break

      if not customCertOption:
        if len(locationsParam) > 0:
          locationsParam += ","
        locationsParam += loc.host
        
        if firstLocation == "":
          firstLocation = loc.host
      
  if firstLocation == "":
    print "Nothing to generate, no automatic secure hosts specified"
  else:
    createRandomFile(rndfilePath);
    
    runUtil(certutil, ["-D", "-n", "pgo server certificate", "-d", srcDir, "-z", rndfilePath, "-f", pwfilePath])
    # Ignore the result, the certificate may not be present when new database is being built
    
    status = runUtil(certutil, ["-S", "-s", "CN=%s" % firstLocation, "-t", "Pu,,", "-c", "pgo temporary ca", "-m", "2", "-8", locationsParam, "-v", "120", "-n", "pgo server certificate", "-d", srcDir, "-z", rndfilePath, "-f", pwfilePath])
    if status != 0:
      return status
    
  os.unlink(pwfilePath)
  os.unlink(rndfilePath)
  return 0


if len(sys.argv) == 1:
  print "Specify --gen-server or --gen-ca"
  sys.exit(1)

if sys.argv[1] == "--gen-server":
  certificateStatus = createSSLServerCertificate(PROFILE_DIR, CERTS_SRC_DIR)
  if certificateStatus != 0:
    print "TEST-UNEXPECTED-FAIL | SSL Server Certificate generation"
  
  sys.exit(certificateStatus)
  
if sys.argv[1] == "--gen-ca":
  certificateStatus = createCertificateAuthority(PROFILE_DIR, CERTS_SRC_DIR)
  if certificateStatus != 0:
    print "TEST-UNEXPECTED-FAIL | Certificate Authority generation"
  else:
    print "\n\n"
    print "==================================================="
    print " IMPORTANT:"
    print " To use this new certificate authority in tests"
    print " run 'make' at testing/mochitest"
    print "==================================================="

  sys.exit(certificateStatus)

print "Invalid option specified"
sys.exit(1)