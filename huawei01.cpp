#include <iostream>
#include <string>

using namespace std;

/*
    计算字符串最后一个单词的长度，单词以空格隔开
    输入：一行字符串，非空，长度小于5000
    输出：整数N，最后一个单词的长度
*/
int main01(int argc, char *argv[])
{
    string s;
    while(getline(cin, s))
    {
        int length=0, flag=1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(flag && s[i]==' ')
            {
                continue;
            }
            else if(s[i]!=' ')
            {
                flag = 0;
                ++length;
            }
            else
            {
                break;
            }
        }
        cout << length << endl;
    }
    return 0;
}
