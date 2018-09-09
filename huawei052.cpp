#include <iostream>
#include <list>
#include <bitset>

using namespace std;

//递归输出二进制函数
void BinaryRecursion(int n)
{
 int a;
 a=n%2;
 n=n>>1;
 if (n==0)
  ;
 else
  BinaryRecursion(n);
 cout<<a;
}


//使用容器转换二进制
void BinaryVector(int n)
{
 int temp;
 temp=n;
 list<int> L;
 while(temp!=0)
 {
  L.push_front(temp%2);
  temp=temp>>1;
 }
 for (list<int>::iterator iter=L.begin();iter!=L.end();iter++ )
  cout<<*iter;
     cout<<endl;
}


//一般方法，32位，逐步与1做与运算。
void Binarycout(int n)
{
 for (int i=31;i>=0;i--)
 {
  cout<<((n>>i)&1);
 }
 cout<<endl;
}


//使用bitset转换二进制
void BinaryBitset(int n)
{
  cout<<bitset<sizeof(int)*8>(n)<<endl;
}

int main052_1()
{
 int a=1045,b=2;
 int c;
 c=a+b;
 cout<<"BinaryRecursion(c)：";
 BinaryRecursion(c);
BinaryVector(c);
 cout<<"Binarycout(c):";
 Binarycout(c);
 cout<<"BinaryBitset(c):";
 BinaryBitset(c);
// cout<<"BinaryChar(c):";
// BinaryChar(c);
 //cout〈 return 0;
}
