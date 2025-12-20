; ModuleID = 'cminus'
source_filename = "/home/skapeach/Desktop/2025ustc-jianmu-compiler/tests/2-ir-gen/autogen/testcases/lv1/assign_int_array_local.cminus"

declare i32 @input()

declare void @output(i32)

declare void @outputFloat(float)

declare void @neg_idx_except()

define void @main() {
label_entry:
  %op0 = alloca [10 x i32]
  %op1 = icmp slt i32 3, 0
  br i1 %op1, label %label_failBB, label %label_passBB
label_failBB:                                                ; preds = %label_entry
  call void @neg_idx_except()
  br label %label_passBB
label_passBB:                                                ; preds = %label_entry, %label_failBB
  %op2 = getelementptr [10 x i32], [10 x i32]* %op0, i32 0, i32 3
  store i32 1234, i32* %op2
  %op3 = icmp slt i32 3, 0
  br i1 %op3, label %label_failBB, label %label_passBB
label_failBB:                                                ; preds = %label_passBB
  call void @neg_idx_except()
  br label %label_passBB
label_passBB:                                                ; preds = %label_passBB, %label_failBB
  %op4 = getelementptr [10 x i32], [10 x i32]* %op0, i32 0, i32 3
  %op5 = load i32, i32* %op4
  call void @output(i32 %op5)
  ret void
}
