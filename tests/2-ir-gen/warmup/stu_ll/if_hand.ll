
define i32 @main() {
entry:
  ; 分配并初始化 float a
  %a = alloca float
  store float 0x40B63851E0000000, float* %a ; 5.555 的十六进制浮点表示，或者写成 5.555000e+00

  ; 读取 a
  %val = load float, float* %a
  
  ; 比较: a > 1.0 (注意 C 语言中 1 会隐式转换为 1.0)
  ; fcmp ogt: floating-point compare ordered greater than
  %cond = fcmp ogt float %val, 1.000000e+00
  
  ; 条件跳转
  br i1 %cond, label %if.then, label %if.end

if.then:
  ret i32 233

if.end:
  ret i32 0
}