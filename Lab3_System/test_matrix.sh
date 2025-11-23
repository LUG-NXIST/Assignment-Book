#!/bin/bash

echo "Testing matrix multiplication program..."

# 编译程序
make clean
make

if [ ! -f "./matrix_mul" ]; then
    echo "Error: Failed to compile the program"
    exit 1
fi

# 测试用例1: README.md中提供的示例
# echo "Test case 1: Example from README.md"
# echo "Matrix A:"
# echo "1 2 3"
# echo "4 5 6"
# echo "7 8 9"
# echo ""
# echo "Matrix B:"
# echo "9 8 7"
# echo "6 5 4"
# echo "3 2 1"
# echo ""

# echo "Running: ./matrix_mul \"1,2,3,4,5,6,7,8,9\" \"9,8,7,6,5,4,3,2,1\""
result=$(./matrix_mul "1,2,3,4,5,6,7,8,9" 3 3 "9,8,7,6,5,4,3,2,1" 3 3)
# echo "$result"
echo ""

# 检查结果是否正确（去除末尾空格进行比较）
result_lines=$(echo "$result" | sed 's/ *$//' | tr '\n' '|')
expected_lines="Result:|30 24 18|84 69 54|138 114 90|"

if [[ "$result_lines" == "$expected_lines" ]]; then
    echo "Test case 1 PASSED"
else
    echo "Test case 1 FAILED"
    # echo "Expected lines: $expected_lines"
    # echo "Got lines: $result_lines"
fi

echo ""
echo "----------------------------------------"
echo ""

# 测试用例2: 单位矩阵测试
# echo "Test case 2: Identity matrix"
# echo "Matrix A:"
# echo "1 0 0"
# echo "0 1 0"
# echo "0 0 1"
# echo ""
# echo "Matrix B:"
# echo "5 2 3"
# echo "1 4 6"
# echo "7 8 9"
# echo ""

# echo "Running: ./matrix_mul \"1,0,0,0,1,0,0,0,1\" \"5,2,3,1,4,6,7,8,9\""
result2=$(./matrix_mul "1,0,0,0,1,0,0,0,1" 3 3 "5,2,3,1,4,6,7,8,9" 3 3)
# echo "$result2"
# echo ""

result2_lines=$(echo "$result2" | sed 's/ *$//' | tr '\n' '|')
expected2_lines="Result:|5 2 3|1 4 6|7 8 9|"

if [[ "$result2_lines" == "$expected2_lines" ]]; then
    echo "Test case 2 PASSED"
else
    echo "Test case 2 FAILED"
    # echo "Expected lines: $expected2_lines"
    # echo "Got lines: $result2_lines"
fi

echo ""
echo "----------------------------------------"
echo ""

# 测试用例3: 零矩阵测试
# echo "Test case 3: Zero matrix"
# echo "Matrix A:"
# echo "0 0 0"
# echo "0 0 0"
# echo "0 0 0"
# echo ""
# echo "Matrix B:"
# echo "1 2 3"
# echo "4 5 6"
# echo "7 8 9"
# echo ""

# echo "Running: ./matrix_mul \"0,0,0,0,0,0,0,0,0\" \"1,2,3,4,5,6,7,8,9\""
result3=$(./matrix_mul "0,0,0,0,0,0,0,0,0" 3 3 "1,2,3,4,5,6,7,8,9" 3 3)
# echo "$result3"
# echo ""

result3_lines=$(echo "$result3" | sed 's/ *$//' | tr '\n' '|')
expected3_lines="Result:|0 0 0|0 0 0|0 0 0|"

if [[ "$result3_lines" == "$expected3_lines" ]]; then
    echo "Test case 3 PASSED"
else
    echo "Test case 3 FAILED"
    # echo "Expected lines: $expected3_lines"
    # echo "Got lines: $result3_lines"
fi

echo ""
echo "----------------------------------------"
echo ""

# 测试用例4: 不同大小的矩阵 (2x3) * (3x2) = (2x2)
# echo "Test case 4: Different sized matrices (2x3) * (3x2)"
# echo "Matrix A:"
# echo "1 2 3"
# echo "4 5 6"
# echo ""
# echo "Matrix B:"
# echo "7 8"
# echo "9 10"
# echo "11 12"
# echo ""

# echo "Running: ./matrix_mul \"1,2,3,4,5,6\" 2 3 \"7,8,9,10,11,12\" 3 2"
result4=$(./matrix_mul "1,2,3,4,5,6" 2 3 "7,8,9,10,11,12" 3 2)
# echo "$result4"
# echo ""

result4_lines=$(echo "$result4" | sed 's/ *$//' | tr '\n' '|')
expected4_lines="Result:|58 64|139 154|"

if [[ "$result4_lines" == "$expected4_lines" ]]; then
    echo "Test case 4 PASSED"
else
    echo "Test case 4 FAILED"
    # echo "Expected lines: $expected4_lines"
    # echo "Got lines: $result4_lines"
fi

echo ""
echo "----------------------------------------"
echo ""

# 测试用例5: 不同大小的矩阵 (4x2) * (2x3) = (4x3)
# echo "Test case 5: Different sized matrices (4x2) * (2x3)"
# echo "Matrix A:"
# echo "1 2"
# echo "3 4"
# echo "5 6"
# echo "7 8"
# echo ""
# echo "Matrix B:"
# echo "1 2 3"
# echo "4 5 6"
# echo ""

# echo "Running: ./matrix_mul \"1,2,3,4,5,6,7,8\" 4 2 \"1,2,3,4,5,6\" 2 3"
result5=$(./matrix_mul "1,2,3,4,5,6,7,8" 4 2 "1,2,3,4,5,6" 2 3)
# echo "$result5"
# echo ""

result5_lines=$(echo "$result5" | sed 's/ *$//' | tr '\n' '|')
expected5_lines="Result:|9 12 15|19 26 33|29 40 51|39 54 69|"

if [[ "$result5_lines" == "$expected5_lines" ]]; then
    echo "Test case 5 PASSED"
else
    echo "Test case 5 FAILED"
    # echo "Expected lines: $expected5_lines"
    # echo "Got lines: $result5_lines"
fi

echo ""
echo "----------------------------------------"
echo ""

echo ""
echo "All tests completed."
make clean