function myFun(a:u8):void{
  var vt:v128 = v128(42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  var b:u8 = a;
  v128.extract_lane<i32>(vt, 0);
}
myFun(3);