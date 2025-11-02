#include <iostream>
#include <iomanip>
using namespace std;

class StudentInfo {
    /****************** TODO ******************/
private:
    bool invalid = false;

    static int string_length(const char* s) {
        int n = 0;
        while (s && s[n]) ++n;
        return n;
    }
    static bool all_digit(const char* s) {
        int n = string_length(s); if (n == 0) return false;
        for (int i = 0; i < n; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    }
    static bool string_equal(const char* a, const char* b) {
        int i = 0;
        for (; a[i] && b[i]; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return a[i] == '\0' && b[i] == '\0';
    }
    static const char* fucking_convert(const char* input_fucking_abbr_whynotletmeusestring) {
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Ari")) return "白羊座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Tau")) return "金牛座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Gem")) return "双子座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Cnc")) return "巨蟹座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Leo")) return "狮子座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Vir")) return "处女座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Lib")) return "天秤座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Sco")) return "天蝎座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Sgr")) return "射手座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Cap")) return "摩羯座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Agr")) return "水瓶座";
        if (string_equal(input_fucking_abbr_whynotletmeusestring, "Psc")) return "双鱼座";
        return nullptr;
    }

public:
    static const int MAX_NAME_LEN = 20;
    static const int MAX_NUMBER_LEN = 40;

    char name[MAX_NAME_LEN] = {};      // 学生姓名
    char number[MAX_NUMBER_LEN] = {};  // 学号
    char sex[100] = {};                // 性别
    char constellation[100] = {};      // 星座
    char hobby[100] = {};              // 爱好
    char sth_to_say[100] = {};         // 毕业赠言
    /**************** TODO-END ****************/

public:
    void inputStudentInfo();
    void printStudentInfo();
};

/****************** TODO ******************/
void StudentInfo::inputStudentInfo() {

    cin.getline(name, StudentInfo::MAX_NAME_LEN);


    cin.getline(number, StudentInfo::MAX_NUMBER_LEN);
    if (!(all_digit(number))) {
        invalid = true;
        return;
    }

    cin.getline(sex, 100);
    if (!(sex[0] == 'M' || sex[0] == 'F')) {
        invalid = true;
        return;
    }

    cin.getline(constellation, 100);
    if ((string_length(constellation) == 1 && constellation[0] == '\\') || fucking_convert(constellation) == nullptr) {
        constellation[0] = '\0';
    }

    cin.getline(hobby, 100);
    if (string_length(hobby) == 1 && hobby[0] == '\\') {
        hobby[0] = '\0';
    }

    cin.getline(sth_to_say, 100);
    if (string_length(sth_to_say) == 1 && sth_to_say[0] == '\\') {
        sth_to_say[0] = '\0';
    }

}

void StudentInfo::printStudentInfo(){
    if (invalid) {
        cout << "输入错误" << endl;
        return;
    }

    cout << "姓名：" << name << endl;
    cout << "学号：" << number << endl;
    cout << "性别：" << (sex[0] == 'M' ? "男" : "女") << endl;
    cout << "星座：";
    if (!constellation[0]) {
        cout << "无" << endl;
    }
    else {
        const char* cn = fucking_convert(constellation);
        cout << (cn ? cn : "无") << endl;
    }
    cout << "爱好：" << (hobby[0] ? hobby : "无") << endl;
    cout << "赠言：" << (sth_to_say[0] ? sth_to_say : "无") << endl;
}
/**************** TODO-END ****************/

int main()
{
    StudentInfo student;
    // 输入学生信息
    student.inputStudentInfo();
    // 输出学生信息
    student.printStudentInfo();

    return 0;
}