
define i32 @main() {
entry:
  ; 1. 分配数组空间 int a[10]
  %a = alloca [10 x i32]

  ; 2. a[0] = 10
  ; 获取 a[0] 的地址 (getelementptr: 数组基址, 索引0用于解引用数组指针, 索引0是数组下标)
  %ptr_a0 = getelementptr [10 x i32], [10 x i32]* %a, i64 0, i64 0
  store i32 10, i32* %ptr_a0

  ; 3. 计算 a[0] * 2
  ; 读取 a[0]
  %val_a0 = load i32, i32* %ptr_a0
  ; 乘法
  %mul = mul i32 %val_a0, 2

  ; 4. a[1] = 结果
  ; 获取 a[1] 的地址
  %ptr_a1 = getelementptr [10 x i32], [10 x i32]* %a, i64 0, i64 1
  store i32 %mul, i32* %ptr_a1

  ; 5. return a[1]
  %ret_val = load i32, i32* %ptr_a1
  ret i32 %ret_val
}