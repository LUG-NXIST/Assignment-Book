#include <stdio.h>
#include "star_math.h"

/* 欢迎来到星际导航AI修复工程。
    请按照注释中的 TODO 提示完成代码。
    所有的数学工具和测试代码都在 "star_math.h" 中。
*/

// ============================================================
// TASK A: 计算加权和 (Weighted Sum)
// 公式: 见任务书
// ============================================================
double calculate_weighted_sum(double inputs[], Neuron neuron) {
    double sum = 0.0;
    
    // TODO: 1. 编写 for 循环    
    // TODO: 2. 在循环中，将 inputs[i] 与 neuron.weights[i] 相乘，累加到 sum 中
    
    // (在此处写代码)

    
    // TODO: 3. 加上偏置值 (neuron.bias)
    
    return sum;
}

// ============================================================
// TASK B: Nova 激活函数
// 公式: 见任务书
// ============================================================
double nova_activation(double x) {
    // TODO: 使用 if - else if - else 结构实现公式
    
    // 情况 1: 
    // return ...;
    
    // 情况 2: 
    // return ...;
    
    // 情况 3: 正常区间
    // return x;
    
    return 0.0; // 删除这行，替换为你的代码
}

// ============================================================
// TASK C: 前向传播 (Forward Pass)
// 整合 A 和 B
// ============================================================
double forward_pass(double inputs[], Neuron neuron) {
    // TODO: 1. 调用 calculate_weighted_sum 计算线性结果 z
    // double z = ...
    
    // TODO: 2. 调用 nova_activation 处理 z，得到最终输出 a
    // double a = ...
    
    return 0.0; // 替换为返回 a
}

// ============================================================
// TASK D: 计算误差 (Calculate Loss)
// 公式: 见任务书
// ============================================================
double calculate_loss(double predicted, double target) {
    // TODO: 计算误差
    
    return 0.0; // 替换为你的代码
}


// ============================================================
// 主函数 (无需修改，用于运行测试)
// ============================================================
int main() {
    printf("System Booting...\n");
    printf("Loading Neural Core...\n");

    // 1. 测试加权和
    test_step_1(calculate_weighted_sum);

    // 2. 测试激活函数
    test_step_2(nova_activation);

    // 3. 测试完整流程
    test_step_3(forward_pass);
    
    // 4. 测试误差计算
    test_step_4(calculate_loss);

    printf("\n========================================\n");
    printf("  Diagnostics Complete.  \n");
    printf("========================================\n");
    
    return 0;
}