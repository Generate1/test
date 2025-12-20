
define i32 @main() {
entry:
  ; 分配变量 a 和 i
  %a = alloca i32
  %i = alloca i32

  ; 初始化
  store i32 10, i32* %a
  store i32 0, i32* %i
  
  ; 跳转到循环判断条件
  br label %while.cond

while.cond:
  ; 取出 i
  %val_i = load i32, i32* %i
  ; 比较 i < 10 (slt: signed less than)
  %cmp = icmp slt i32 %val_i, 10
  ; 如果真跳转 body，假跳转 end
  br i1 %cmp, label %while.body, label %while.end

while.body:
  ; i = i + 1
  %t1 = load i32, i32* %i
  %inc = add i32 %t1, 1
  store i32 %inc, i32* %i
  
  ; a = a + i (注意：这里用的是更新后的 i)
  %t2 = load i32, i32* %a
  %t3 = load i32, i32* %i
  %add = add i32 %t2, %t3
  store i32 %add, i32* %a
  
  ; 跳转回条件判断
  br label %while.cond

while.end:
  ; return a
  %res = load i32, i32* %a
  ret i32 %res
}