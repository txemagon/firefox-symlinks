




















var std_isFinite=isFinite;
var std_isNaN=isNaN;
var std_Array_indexOf=ArrayIndexOf;
var std_Array_join=Array.prototype.join;
var std_Array_push=Array.prototype.push;
var std_Array_shift=Array.prototype.shift;
var std_Array_slice=Array.prototype.slice;
var std_Array_sort=Array.prototype.sort;
var std_Boolean_toString=Boolean.prototype.toString;
var Std_Date=Date;
var std_Date_now=Date.now;
var std_Function_bind=Function.prototype.bind;
var std_Math_floor=Math.floor;
var std_Math_max=Math.max;
var std_Math_min=Math.min;
var std_Object_create=Object.create;
var std_Object_defineProperty=Object.defineProperty;
var std_Object_getOwnPropertyNames=Object.getOwnPropertyNames;
var std_Object_hasOwnProperty=Object.prototype.hasOwnProperty;
var std_RegExp_test=RegExp.prototype.test;
var Std_String=String;
var std_String_indexOf=String.prototype.indexOf;
var std_String_lastIndexOf=String.prototype.lastIndexOf;
var std_String_match=String.prototype.match;
var std_String_replace=String.prototype.replace;
var std_String_split=String.prototype.split;
var std_String_substring=String.prototype.substring;
var std_String_toLowerCase=String.prototype.toLowerCase;
var std_String_toUpperCase=String.prototype.toUpperCase;






function List(){
if((typeof(List.prototype)==='undefined')){
var a=std_Object_create(null);
a.indexOf=std_Array_indexOf;
a.join=std_Array_join;
a.push=std_Array_push;
a.slice=std_Array_slice;
a.sort=std_Array_sort;
List.prototype=a;
}
}
MakeConstructible(List);






function Record(){
return std_Object_create(null);
}
MakeConstructible(Record);






function HasProperty(a,b){
return b in a;
}



function ToBoolean(a){
return!!a;
}



function ToNumber(a){
return+a;
}



function ToString(a){
assert(arguments.length>0,"__toString");
return Std_String(a);
}





function assert(a,c){
if(!a)
AssertionFailed(c);
}
















