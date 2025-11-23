#ifndef STAR_MATH_H
#define STAR_MATH_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// --- 1. 基础定义 ---

// 定义输入向量的维度（假设有5个传感器）
#define INPUT_SIZE 5

// 神经元结构体
typedef struct {
    double weights[INPUT_SIZE]; // 权重
    double bias;                // 偏置
} Neuron;

// --- 2. 辅助工具函数 ---

// 用于比较两个浮点数是否足够接近（计算机无法精确比较浮点数相等）
int is_close(double a, double b) {
    double diff = a - b;
    if (diff < 0) diff = -diff;
    return diff < 0.0001;
}

// 打印数组内容的辅助函数
void print_array(double arr[], int size) {
    printf("[ ");
    for(int i=0; i<size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("]\n");
}

// --- 3. 自动阅卷系统 (Auto-Grader) ---

// 颜色代码，让控制台输出好看一点
#define COL_GREEN "\033[0;32m"
#define COL_RED "\033[0;31m"
#define COL_RESET "\033[0m"

void test_step_1(double (*student_func)(double[], Neuron)) {
    printf("\n========================================\n");
    printf("  TEST STEP 1: 突触加权求和 (Synaptic Sum)\n");
    printf("========================================\n");

    // 测试用例 1
    double inputs[INPUT_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
    Neuron n = {{0.1, 0.1, 0.1, 0.1, 0.1}, 0.5}; 
    // 预期: (1+2+3+4+5)*0.1 + 0.5 = 1.5 + 0.5 = 2.0
    
    double result = student_func(inputs, n);
    double expected = 2.0;

    if (is_close(result, expected)) {
        printf("%s[PASS]%s Case 1: Inputs All Positive\n", COL_GREEN, COL_RESET);
    } else {
        printf("%s[FAIL]%s Case 1\n", COL_RED, COL_RESET);
        printf("   期待: %.4f\n", expected);
        printf("   你的输出: %.4f\n", result);
        return;
    }

    // 测试用例 2 (包含负数)
    double inputs2[INPUT_SIZE] = {-1.0, 0.0, 1.0, 0.0, -1.0};
    Neuron n2 = {{1.0, 2.0, 3.0, 4.0, 5.0}, -1.0};
    // (-1*1 + 0 + 1*3 + 0 + -1*5) - 1.0 = (-1 + 3 - 5) - 1 = -3 - 1 = -4.0
    
    result = student_func(inputs2, n2);
    expected = -4.0;

    if (is_close(result, expected)) {
        printf("%s[PASS]%s Case 2: Mixed Negative inputs\n", COL_GREEN, COL_RESET);
    } else {
        printf("%s[FAIL]%s Case 2\n", COL_RED, COL_RESET);
        printf("   Expected: %.4f\n", expected);
        printf("   Your Output: %.4f\n", result);
    }
}

void test_step_2(double (*student_func)(double)) {
    printf("\n========================================\n");
    printf("  TEST STEP 2: Nova 激活函数\n");
    printf("========================================\n");

    // Case 1: 线性区间 (-2 到 2)
    double val = 1.5;
    if (is_close(student_func(val), 1.5)) printf("%s[PASS]%s Linear Range (1.5 -> 1.5)\n", COL_GREEN, COL_RESET);
    else printf("%s[FAIL]%s Linear Range. Input 1.5 should be 1.5\n", COL_RED, COL_RESET);

    // Case 2: 大于 2
    val = 3.0;
    // Expected: 2 + 0.1 * (3.0 - 2) = 2.1
    if (is_close(student_func(val), 2.1)) printf("%s[PASS]%s Upper Saturation (3.0 -> 2.1)\n", COL_GREEN, COL_RESET);
    else printf("%s[FAIL]%s Upper Saturation. Input 3.0 should be 2.1\n", COL_RED, COL_RESET);

    // Case 3: 小于 -2
    val = -10.0;
    // Expected: -2 + 0.1 * (-10 + 2) = -2 + 0.1 * (-8) = -2.8
    if (is_close(student_func(val), -2.8)) printf("%s[PASS]%s Lower Saturation (-10.0 -> -2.8)\n", COL_GREEN, COL_RESET);
    else printf("%s[FAIL]%s Lower Saturation. Input -10.0 should be -2.8\n", COL_RED, COL_RESET);
}

void test_step_3(double (*student_func)(double[], Neuron)) {
    printf("\n========================================\n");
    printf("  TEST STEP 3: 前向传播 (End-to-End)\n");
    printf("========================================\n");
    
    // 构造一个会产生大数值的输入，测试是否正确调用了激活函数
    double inputs[INPUT_SIZE] = {10, 10, 10, 10, 10};
    Neuron n = {{1,1,1,1,1}, 0}; 
    // Sum = 50. 
    // Activation(50) => 2 + 0.1*(50-2) = 2 + 4.8 = 6.8
    
    double result = student_func(inputs, n);
    if (is_close(result, 6.8)) {
        printf("%s[PASS]%s Forward Pass Integration\n", COL_GREEN, COL_RESET);
    } else {
        printf("%s[FAIL]%s Forward Pass.\n", COL_RED, COL_RESET);
        printf("   期待: 6.8 (Logic: Sum is 50, Activation suppresses it)\n");
        printf("   你的输出: %.4f\n", result);
        printf("   提示: 你在步骤 3 中调用步骤 2 的函数了吗?\n");
    }
}

void test_step_4(double (*student_func)(double, double)) {
    printf("\n========================================\n");
    printf("  TEST STEP 4: 能量损失 (Loss)\n");
    printf("========================================\n");
    
    // Target = 1.0, Pred = 3.0. Diff = 2.0. Sq = 4.0. *0.5 = 2.0
    if (is_close(student_func(3.0, 1.0), 2.0)) {
         printf("%s[PASS]%s Loss Calculation\n", COL_GREEN, COL_RESET);
    } else {
         printf("%s[FAIL]%s Loss Calculation\n", COL_RED, COL_RESET);
    }
}

#endif