#include <iostream>
#include <iomanip>
#define SAMPLE_LENGTH 10
#define DATA_NUM 4
#define PARAMS_NUM 4
#define MAX_ITERATION 128
using namespace std;

/****************** TODO ******************/

double mean_square_error(int data[SAMPLE_LENGTH][DATA_NUM], const double params[PARAMS_NUM]){
    double MSE = 0.0;

    for (int i = 0; i < SAMPLE_LENGTH; ++i){
        double predicted = params[0] * data[i][0] + params[1] * data[i][1] +
                          params[2] * data[i][2] + params[3];
        double error = data[i][3] - predicted; //线性函数值与真实值的差值
        MSE += error * error;
    }
    MSE /= SAMPLE_LENGTH;
    return MSE;
}

void update_params(int data[SAMPLE_LENGTH][DATA_NUM], double params[PARAMS_NUM]){
    const double learning_rate = 0.01; //学习率 α
    double grad_w1 = 0.0, grad_w2 = 0.0, grad_w3 = 0.0, grad_b = 0.0;

    for (int i = 0; i < SAMPLE_LENGTH; ++i) {
        double predicted = params[0] * data[i][0] + params[1] * data[i][1] +
                          params[2] * data[i][2] + params[3];
        double error = data[i][3] - predicted; //同第一个函数

        grad_w1 += -2.0 * error * data[i][0];// ∂MSE/∂ω1 = -2/n ∑(yi - ŷi)*x1i
        grad_w2 += -2.0 * error * data[i][1];
        grad_w3 += -2.0 * error * data[i][2];
        grad_b += -2.0 * error; //∂MSE/∂b = -2/n ∑(yi - ŷi)
    }

    grad_w1 /= SAMPLE_LENGTH;
    grad_w2 /= SAMPLE_LENGTH;
    grad_w3 /= SAMPLE_LENGTH;
    grad_b /= SAMPLE_LENGTH; //遍历完所有样本之后除以样本个数取平均

    //每个参数都沿着梯度在这个方向上的分量进行更新
    params[0] -= learning_rate * grad_w1; //ω1 := ω1 - α * ∂MSE/∂ω1
    params[1] -= learning_rate * grad_w2;
    params[2] -= learning_rate * grad_w3;
    params[3] -= learning_rate * grad_b; //b := b - α * ∂MSE/∂b
}

/**************** TODO-END ****************/

int main()
{
    int data[SAMPLE_LENGTH][DATA_NUM] = {};

    // 输入训练数据
    for (int i = 0; i < SAMPLE_LENGTH; ++i)
    {
        for (int j = 0; j < DATA_NUM; ++j)
        {
            cin >> data[i][j];
        }
    }

    // 1. 参数初始化
    double params[PARAMS_NUM] = {};
    // 四个参数初始化为零，从前往后分别是w1,w2,w3,b

    // 进行迭代
    double loss = 0;
    cout << "Start Iteration!" << endl;
    cout << fixed << setprecision(6);
    for (int i = 0; i < MAX_ITERATION; ++i)
    {
        // 2. 使用当前参数和数据，计算损失函数
        loss = mean_square_error(data, params);
        // i 固定三位宽度输出，loss 固定六位小数位数输出
        cout << "iter: " << setw(3) << i << ", loss: ";
        cout << loss << endl;

        // 3. 计算梯度，使用梯度下降的方法更新参数
        update_params(data, params);
    }
    cout << "Iteration Finished!" << endl;

    // 输出回归后的参数值：
    cout << "params:" << endl;
    for (int i = 0; i < PARAMS_NUM; ++i)
    {
        cout << params[i] << endl;
    }

    return 0;
}