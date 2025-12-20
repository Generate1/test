
define i32 @callee(i32 %0) {
entry:
  ; 分配栈空间存储参数 a
  %a.addr = alloca i32
  store i32 %0, i32* %a.addr

  ; 取出 a 进行计算
  %val = load i32, i32* %a.addr
  %res = mul i32 2, %val
  
  ret i32 %res
}

define i32 @main() {
entry:
  ; 调用 callee(110)
  %call = call i32 @callee(i32 110)
  ret i32 %call
}