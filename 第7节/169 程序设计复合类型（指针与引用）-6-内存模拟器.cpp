#include <iostream>
#define BLOCK_NUM 200    // 盘块数量
#define INSTR_LENGTH 100 // 指令最大长度
using namespace std;

int memory[BLOCK_NUM] = {}; // 模拟内存

/****************** TODO ******************/

bool BlockManager(char instr[])
{
    static int block[BLOCK_NUM];
    static bool inited = false;
    if (!inited)
    {
        for (int t = 0; t < BLOCK_NUM; ++t)
            block[t] = -147483648; // 未申请
        inited = true;
    }

    string command;
    int i = 0;

    // 跳过前导空格
    while (instr[i] == ' ')
    {
        i++;
    }
    // 读取命令
    while (instr[i] != '\0' && instr[i] != ' ')
    {
        command += instr[i];
        i++;
    }

    if (command == "q")
    {
        return false;
    }

    if (command == "new")
    { // 申请：未申请(-147483648) -> 已申请(147483648)
        int location = 0, num = 0;

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            location = location * 10 + (instr[i] - '0');
            i++;
        }

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            num = num * 10 + (instr[i] - '0');
            i++;
        }

        if (location < 0 || num <= 0 || location + num > BLOCK_NUM)
        {
            cout << "失败" << endl;
            return true;
        }

        // 先检查
        for (int j = location; j < location + num; j++)
        {
            if (block[j] != -147483648)
            {
                cout << "失败" << endl;
                return true;
            }
        }
        // 再执行
        for (int j = location; j < location + num; j++)
        {
            block[j] = 147483648;
        }
        cout << "成功" << endl;
        return true;
    }

    if (command == "free")
    { // 释放：已申请(147483648) -> 已释放(66666)
        int location = 0, num = 0;

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            location = location * 10 + (instr[i] - '0');
            i++;
        }

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            num = num * 10 + (instr[i] - '0');
            i++;
        }

        if (location < 0 || num <= 0 || location + num > BLOCK_NUM)
        {
            cout << "失败" << endl;
            return true;
        }

        // 先检查
        for (int j = location; j < location + num; j++)
        {
            if (block[j] != 147483648)
            {
                cout << "失败" << endl;
                return true;
            }
        }
        // 再执行
        for (int j = location; j < location + num; j++)
        {
            block[j] = 66666; // 标记为已释放，后续不可读写、不可再次释放（保持你的逻辑）
        }
        cout << "成功" << endl;
        return true;
    }

    if (command == "read")
    {
        int location = 0;

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            location = location * 10 + (instr[i] - '0');
            i++;
        }

        if (location < 0 || location >= BLOCK_NUM)
        {
            cout << "失败" << endl;
            return true;
        }

        if (block[location] == 147483648)
        {
            cout << "成功 ";
            cout << memory[location] << endl;
        }
        else
        {
            cout << "失败" << endl;
        }
        return true;
    }

    if (command == "write")
    {
        int location = 0, value = 0;

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            location = location * 10 + (instr[i] - '0');
            i++;
        }

        while (instr[i] == ' ')
        {
            i++;
        }
        while (instr[i] >= '0' && instr[i] <= '9')
        {
            value = value * 10 + (instr[i] - '0');
            i++;
        }

        if (location < 0 || location >= BLOCK_NUM)
        {
            cout << "失败" << endl;
            return true;
        }

        if (block[location] == 147483648)
        {
            memory[location] = value;
            cout << "成功" << endl;
        }
        else
        {
            cout << "失败" << endl;
        }
        return true;
    }

    // 未知命令
    cout << "失败" << endl;
    return true;
}

/**************** TODO-END ****************/

int main()
{
    char instr[INSTR_LENGTH] = {}; // 输入的指令
    cin.getline(instr, INSTR_LENGTH);

    while (BlockManager(instr)) {
        cin.getline(instr, INSTR_LENGTH);
    }

    return 0;
}