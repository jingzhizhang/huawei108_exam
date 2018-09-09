#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>

using namespace std;

int translate(char a)
{
    int num = 0;
    if(a=='A')
        num = 10;
    else if(a=='B')
        num = 11;
    else if(a=='C')
        num = 12;
    else if(a=='D')
        num = 13;
    else if(a=='E')
        num = 14;
    else if(a=='F')
        num=15;
    else
        num = (int)(a-'0');
    return num;
}

int main51()
{
    string s;
    while(cin >> s)
    {
        s = s.substr(2);
        int res = 0;
        for(int i=s.size()-1; i>=0; i--)
        {
            res = res + translate(s[i])*pow(16, s.size()-i-1);
        }
        cout << res << endl;
    }

}

int main52()
{
    int a;
    while(cin>>hex>>a)  //输入十六进制
    {
        cout << a << endl;
    }
}

int main53()
{

    char str[100];
    int i=0,count,sum;
    while(gets(str))//用于多次输入
    {
//        count=strlen(str);//计算字符串的长度
        count = 100;
        sum=0;
        for(i=count-1;i>=0;i--)//从十六进制个位开始，每位都转换成十进制
        {
        if(str[i]>='0'&&str[i]<='9')//数字字符的转换
        {
            sum+=(str[i]-48)*pow(16,count-i-1);
        }
        else if(str[i]>='A'&&str[i]<='F')//字母字符的转换
        {
            sum+=(str[i]-55)*pow(16,count-i-1);
        }
        }
        printf("%d\n",sum);
    }
    return 0;
}

//输出十六进制：cout << hex << a;
//输出八进制：cout << oct << a;
