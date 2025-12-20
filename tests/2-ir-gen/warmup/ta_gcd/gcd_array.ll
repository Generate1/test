@x = global [1 x i32] zeroinitializer
@y = global [1 x i32] zeroinitializer

define i32 @gcd(i32 %0, i32 %1) {
  %3 = alloca i32
  %4 = alloca i32
  %5 = alloca i32
  store i32 %0, i32* %4
  store i32 %1, i32* %5
  %6 = load i32, i32* %5
  %7 = icmp eq i32 %6, 0
  br i1 %7, label %8, label %10

8:
  %9 = load i32, i32* %4
  store i32 %9, i32* %3
  br label %20

10:
  %11 = load i32, i32* %5
  %12 = load i32, i32* %4
  %13 = load i32, i32* %4
  %14 = load i32, i32* %5
  %15 = sdiv i32 %13, %14
  %16 = load i32, i32* %5
  %17 = mul i32 %15, %16
  %18 = sub i32 %12, %17
  %19 = call i32 @gcd(i32 %11, i32 %18)
  store i32 %19, i32* %3
  br label %20

20:
  %21 = load i32, i32* %3
  ret i32 %21
}

define i32 @funArray(i32* %0, i32* %1) {
  %3 = alloca i32*
  %4 = alloca i32*
  %5 = alloca i32
  %6 = alloca i32
  %7 = alloca i32
  store i32* %0, i32** %3
  store i32* %1, i32** %4
  %8 = load i32*, i32** %3
  %9 = getelementptr i32, i32* %8, i64 0
  %10 = load i32, i32* %9
  store i32 %10, i32* %5
  %11 = load i32*, i32** %4
  %12 = getelementptr i32, i32* %11, i64 0
  %13 = load i32, i32* %12
  store i32 %13, i32* %6
  %14 = load i32, i32* %5
  %15 = load i32, i32* %6
  %16 = icmp slt i32 %14, %15
  br i1 %16, label %17, label %21

17:
  %18 = load i32, i32* %5
  store i32 %18, i32* %7
  %19 = load i32, i32* %6
  store i32 %19, i32* %5
  %20 = load i32, i32* %7
  store i32 %20, i32* %6
  br label %21

21:
  %22 = load i32, i32* %5
  %23 = load i32, i32* %6
  %24 = call i32 @gcd(i32 %22, i32 %23)
  ret i32 %24
}

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = getelementptr [1 x i32], [1 x i32]* @x, i64 0, i64 0
  store i32 90, i32* %2		
  %3 = getelementptr [1 x i32], [1 x i32]* @y, i64 0, i64 0
  store i32 18, i32* %3
  %4 = getelementptr [1 x i32], [1 x i32]* @x, i64 0, i64 0
  %5 = getelementptr [1 x i32], [1 x i32]* @y, i64 0, i64 0
  %6 = call i32 @funArray(i32* %4, i32* %5)
  ret i32 %6
}