#include <iostream>
using namespace std;

// 余弦相似度
double cosine_similarity(double a[], double b[], int n);
// 距离度量（欧几里得/曼哈顿/汉明）
double distance(double a[], double b[], int n, const char type[] = "Euclidean");
double distance(char a[], char b[], const char type[]);
// 杰卡德相似系数
double jaccard_similarity_coefficient(char a[], char b[]);

int main()
{
    // 1. 余弦相似度

    // 数据格式：两个三维向量
    {
        double a[3] = {};
        double b[3] = {};
        cout << "------------------------------------------" << endl;
        cout << "             Cosine Similarity            " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        cout << "Please input the second vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }
        cout << "The cosine similarity is: " << cosine_similarity(a, b, 3) << endl;
    }

    // 2. 欧几里得距离

    // 数据格式：两个三维坐标
    {
        double a[3] = {};
        double b[3] = {};
        cout << "------------------------------------------" << endl;
        cout << "           Euclidean Distance             " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        cout << "Please input the second vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }
        cout << "The euclidean distance is: " << distance(a, b, 3) << endl;
        // cout << "The euclidean distance is: " << distance(a, b, 3, "Euclidean") << endl;
    }

    // 3. 曼哈顿距离

    // 数据格式：两个三维坐标
    {
        double a[3] = {};
        double b[3] = {};
        cout << "------------------------------------------" << endl;
        cout << "           Manhattan Distance             " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        cout << "Please input the second vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }
        cout << "The manhattan distance is: " << distance(a, b, 3, "Manhattan") << endl;
    }

    // 4. 汉明距离

    // 数据格式：两个字符串
    {
        char a[100] = {};
        char b[100] = {};
        cout << "------------------------------------------" << endl;
        cout << "            Hamming Distance              " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first string: " << endl;
        cin.get(); // 读取换行符（cin.getline()之前需要先读取换行符，否则会直接读取换行符，导致输入错误）
        cin.getline(a, 100);
        cout << "Please input the second string: " << endl;
        cin.getline(b, 100);
        cout << "The hamming distance is: " << distance(a, b, "Hamming") << endl;
    }

    // 5. 杰卡德相似系数

    // 数据格式：两个小写字母集合（非空），已经按照字典序排好序
    {
        char a[100] = {};
        char b[100] = {};
        cout << "------------------------------------------" << endl;
        cout << "       Jaccard Similarity Coefficient     " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first set: " << endl;
        cin >> a;
        cout << "Please input the second set: " << endl;
        cin >> b;
        cout << "The jaccard similarity coefficient is: " << jaccard_similarity_coefficient(a, b) << endl;
    }

    return 0;
}

/****************** TODO ******************/

double cosine_similarity(double a[], double b[], int n) {
    double temp1 = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    double temp2 = sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]) * sqrt(b[0]*b[0] + b[1]*b[1] + b[2]*b[2]);
    return temp1 / temp2;
}

double distance(double a[], double b[], int n, const char type[]) {
    if (type == "Euclidean") {
        double sum1 = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]);
        return sqrt(sum1);
    }
    else if (type == "Manhattan") {
        double sum2 = abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]);
        return sum2;
    }
    else {
        return 114514;
    }
}

double distance(char a[], char b[], const char type[]) {
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != b[i]) {
            count++;
        }
        if (a[i] == '\0' || b[i] == '\0') {
            break;
        }
    }
    return count;
}

double jaccard_similarity_coefficient(char a[], char b[]) {
    int intersection = 0;//交集
    int union_set = 0;//并集
    int i = 0, j = 0;
    while (a[i] != '\0' && b[j] != '\0') {
        if (a[i] == b[j]) {
            intersection++;
            union_set++;
            i++;
            j++;
        }
        else if (a[i] < b[j] || b[j] == '\0') {
            union_set++;
            i++;
        }
        else {
            union_set++;
            j++;
        }
    }
    while (a[i] != '\0') { ++union_set; ++i; }
    while (b[j] != '\0') { ++union_set; ++j; }

    return (double)intersection / union_set;
}

/**************** TODO-END ****************/