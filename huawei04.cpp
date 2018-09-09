#include <iostream>
#include <string>

using namespace std;

/*
连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

输入：连续输入字符串(输入2次,每个字符串长度小于100)
输出：输出到长度为8的新字符串数组
*/
int main41()
{
    int length = 2;
    string str_in[length];
    for(int i=0; i<length; i++)
    {
        cin >> str_in[i];
    }
    for(int i=0; i<length; i++)
    {
        string str = str_in[i];
        while(str.size() > 8)
        {
            cout << str.substr(0, 8) << endl;  //主要是截取字符串函数substr()的使用方法和append()函数
            str = str.substr(8);
        }
        cout << str.append(8-str.size(), '0') << endl;
    }
    return 0;
}
