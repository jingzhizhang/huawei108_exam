#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

/*
    内部排序：
        插入排序：直接插入排序、折半插入排序、希尔排序
        交换排序：冒泡排序、快速排序
        选择排序：简单选择排序、堆排序
        归并排序
        基数排序
    外部排序：
        多路平衡归并
        败者树
        置换-选择排序
        最佳归并树
*/

/*
    随机数生成：
    (low,up) #define Random (rand()%(up-low+1)) + low - 1
    [low,up) #define Random (rand()%(up-low)) + low
    (low,up] #define Random (rand()%(up-low))+ low + 1
    [low,up] #define Random (rand()%(up-low+1)) + low
*/
template<typename T>
T randT(T Lower, T Upper)
{
    T temp;
    if(Lower>Upper)
    {
        temp = Upper;
        Upper = Lower;
        Lower = temp;
    }
    return rand() / (double)RAND_MAX*(Upper-Lower+1)+Lower;
}


void printVector_sort(vector<int> &test_vec)
{
    for(int i=0; i<10; i++)
    {
        cout << test_vec[i] << " ";
    }
    cout << endl;
}


int main_sort()
{
    srand((unsigned)time(NULL));  //设定随机种子
    vector<int> test_vec;
    int start=10, end=100;
    for(int i=0; i<10; i++)
    {
        test_vec.push_back(randT<int>(start, end));
    }
    printVector_sort(test_vec);
}
