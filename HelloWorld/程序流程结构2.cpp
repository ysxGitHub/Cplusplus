#include <iostream>

using namespace std;

int main(void)
{
    int a;
    // switch中 判断只能是整型和字符型
    cout << "请输入分数" << endl;
    cin >> a;

    switch (a)
    {
    case 5:
        cout << "优秀" << endl;
        break;
    case 4:
        cout << "良好" << endl;
        break;
    case 3:
        cout << "中等" << endl;
        break;
    case 2:
        cout << "不及格" << endl;
        break;
    case 1:
        cout << "差" << endl;
        break;
    default:
        cout << "极差" << endl;
        break;
    }

    return 0;
}