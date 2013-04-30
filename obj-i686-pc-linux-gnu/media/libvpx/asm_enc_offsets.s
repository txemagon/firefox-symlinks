	.file	"asm_enc_offsets.c"
	.text
.Ltext0:
	.section	.text.startup.main,"ax",@progbits
	.globl	main
	.hidden	main
	.type	main, @function
main:
.LFB104:
	.file 1 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c"
	.loc 1 20 0
	.cfi_startproc
	.loc 1 23 0
#APP
# 23 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_coeff EQU $4
# 0 "" 2
	.loc 1 24 0
# 24 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_zbin EQU $20
# 0 "" 2
	.loc 1 25 0
# 25 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_round EQU $28
# 0 "" 2
	.loc 1 26 0
# 26 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_quant EQU $8
# 0 "" 2
	.loc 1 27 0
# 27 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_quant_fast EQU $12
# 0 "" 2
	.loc 1 28 0
# 28 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_zbin_extra EQU $32
# 0 "" 2
	.loc 1 29 0
# 29 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_zrun_zbin_boost EQU $24
# 0 "" 2
	.loc 1 30 0
# 30 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_quant_shift EQU $16
# 0 "" 2
	.loc 1 32 0
# 32 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_blockd_qcoeff EQU $0
# 0 "" 2
	.loc 1 33 0
# 33 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_blockd_dequant EQU $12
# 0 "" 2
	.loc 1 34 0
# 34 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_blockd_dqcoeff EQU $4
# 0 "" 2
	.loc 1 35 0
# 35 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_blockd_eob EQU $40
# 0 "" 2
	.loc 1 38 0
# 38 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_base_src EQU $36
# 0 "" 2
	.loc 1 39 0
# 39 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_src EQU $40
# 0 "" 2
	.loc 1 40 0
# 40 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_src_diff EQU $0
# 0 "" 2
	.loc 1 41 0
# 41 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_block_src_stride EQU $44
# 0 "" 2
	.loc 1 43 0
# 43 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_blockd_predictor EQU $8
# 0 "" 2
	.loc 1 46 0
# 46 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_lowvalue EQU $0
# 0 "" 2
	.loc 1 47 0
# 47 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_range EQU $4
# 0 "" 2
	.loc 1 48 0
# 48 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_value EQU $8
# 0 "" 2
	.loc 1 49 0
# 49 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_count EQU $12
# 0 "" 2
	.loc 1 50 0
# 50 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_pos EQU $16
# 0 "" 2
	.loc 1 51 0
# 51 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_buffer EQU $20
# 0 "" 2
	.loc 1 52 0
# 52 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_buffer_end EQU $24
# 0 "" 2
	.loc 1 53 0
# 53 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_error EQU $28
# 0 "" 2
	.loc 1 55 0
# 55 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
tokenextra_token EQU $6
# 0 "" 2
	.loc 1 56 0
# 56 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
tokenextra_extra EQU $4
# 0 "" 2
	.loc 1 57 0
# 57 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
tokenextra_context_tree EQU $0
# 0 "" 2
	.loc 1 58 0
# 58 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
tokenextra_skip_eob_node EQU $7
# 0 "" 2
	.loc 1 59 0
# 59 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
TOKENEXTRA_SZ EQU $8
# 0 "" 2
	.loc 1 61 0
# 61 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_extra_bit_struct_sz EQU $16
# 0 "" 2
	.loc 1 63 0
# 63 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_token_value EQU $0
# 0 "" 2
	.loc 1 64 0
# 64 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_token_len EQU $4
# 0 "" 2
	.loc 1 66 0
# 66 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_extra_bit_struct_tree EQU $0
# 0 "" 2
	.loc 1 67 0
# 67 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_extra_bit_struct_prob EQU $4
# 0 "" 2
	.loc 1 68 0
# 68 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_extra_bit_struct_len EQU $8
# 0 "" 2
	.loc 1 69 0
# 69 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_extra_bit_struct_base_val EQU $12
# 0 "" 2
	.loc 1 71 0
# 71 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_comp_tplist EQU $170496
# 0 "" 2
	.loc 1 72 0
# 72 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_comp_common EQU $104544
# 0 "" 2
	.loc 1 73 0
# 73 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_comp_bc EQU $117040
# 0 "" 2
	.loc 1 74 0
# 74 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_writer_sz EQU $40
# 0 "" 2
	.loc 1 76 0
# 76 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
tokenlist_start EQU $0
# 0 "" 2
	.loc 1 77 0
# 77 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
tokenlist_stop EQU $4
# 0 "" 2
	.loc 1 78 0
# 78 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
TOKENLIST_SZ EQU $8
# 0 "" 2
	.loc 1 80 0
# 80 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c" 1
	
vp8_common_mb_rows EQU $2296
# 0 "" 2
	.loc 1 82 0
#NO_APP
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE104:
	.size	main, .-main
	.text
.Letext0:
	.file 2 "/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/boolhuff.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xd2
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF13
	.byte	0x1
	.long	.LASF14
	.long	0
	.long	0
	.long	.Ldebug_ranges0+0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF2
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF5
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF6
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF7
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF9
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.long	.LASF10
	.uleb128 0x4
	.long	0x48
	.long	0x89
	.uleb128 0x5
	.long	0x2c
	.byte	0xff
	.byte	0
	.uleb128 0x6
	.byte	0x1
	.long	.LASF15
	.byte	0x1
	.byte	0x14
	.byte	0x1
	.long	0x25
	.long	.LFB104
	.long	.LFE104
	.byte	0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x4
	.long	0x2c
	.long	0xb1
	.uleb128 0x5
	.long	0x2c
	.byte	0xff
	.byte	0
	.uleb128 0x7
	.long	.LASF11
	.byte	0x2
	.byte	0x2d
	.long	0xbe
	.byte	0x1
	.byte	0x1
	.uleb128 0x8
	.long	0xa1
	.uleb128 0x7
	.long	.LASF12
	.byte	0x2
	.byte	0x30
	.long	0xd0
	.byte	0x1
	.byte	0x1
	.uleb128 0x8
	.long	0x79
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.LFB104
	.long	.LFE104-.LFB104
	.long	0
	.long	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.LFB104
	.long	.LFE104
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF3:
	.string	"long long int"
.LASF0:
	.string	"unsigned int"
.LASF15:
	.string	"main"
.LASF9:
	.string	"long unsigned int"
.LASF11:
	.string	"vp8_prob_cost"
.LASF14:
	.string	"/home/txema/work/firefox-20.0+build1/media/libvpx/vp8/encoder/asm_enc_offsets.c"
.LASF6:
	.string	"long long unsigned int"
.LASF4:
	.string	"unsigned char"
.LASF12:
	.string	"vp8_norm"
.LASF7:
	.string	"long int"
.LASF10:
	.string	"double"
.LASF13:
	.string	"GNU C 4.6.3"
.LASF5:
	.string	"short unsigned int"
.LASF1:
	.string	"signed char"
.LASF2:
	.string	"short int"
.LASF8:
	.string	"char"
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
