#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

/*
    查找：静态查找——》无需动态地修改查找表（用于查找的数据集合）；动态查找——》需要动态地插入或删除的查找表
    线性结构：顺序查找、二分查找、分块查找
    树形结构：二叉排序树、二叉平衡树、B树（插入、查处难、查找的过程）、B+树（概念为主）
    散列结构：散列表（散列表构造、冲突处理方法及详细的处理过程、查找成功和查找失败的平均查找长度、散列查找的特征和性能分析）
    字符串模式匹配：next数组的构造方法
*/

// 创建线性查找表
void createVector(int *test_arr, int length, int &key, vector<int> &test_vec)
{
    test_vec.push_back(key);  //设置哨兵
    for(int i=0; i<length; i++)
    {
        test_vec.push_back(test_arr[i]);
    }
}

// 输出线性查找表
void printVector(vector<int> &test_vec)
{
    for(int i=0; i<test_vec.size(); i++)
    {
        cout << test_vec[i] << " ";
    }
    cout << endl;
}

// 无序表顺序查找，查找成功平均长度(n+1)/2，查找失败平均长度为n+1
int find_inorder_unsort(vector<int> &test_vec_unsort, int &key)
{
    for(int i=test_vec_unsort.size()-1; i>=0; i--)
    {
        if(test_vec_unsort[i] == key)
        {
            return i;  // 如果查找失败返回0，因为0被设置为key
        }
    }
}

// 有序表顺序查找，可以略微减少查找失败平均长度：n/2+n/(n+1)，使用判定树推导出来的
int find_inorder_sort(vector<int> &test_vec_sort, int &key)
{
    int length = test_vec_sort.size();
    for(int i=1; i<length; i++)
    {
        if(key < test_vec_sort[1])
            return 0;
        if(key > test_vec_sort[length-1])
            return 0;
        if(test_vec_sort[i] == key)
        {
            return i;
        }
        else if(key>test_vec_sort[i] && key<test_vec_sort[i+1])
        {
            return 0;
        }
    }
}

// 有序表二分查找，循环实现
int find_binary_recurrent(vector<int> &test_vec_sort, int key)
{
    int low=1;
    int high = test_vec_sort.size()-1;
    int mid = low;
    while (low<high)
    {
        mid = (low+high) / 2;
        if(test_vec_sort[mid]==key)
            return mid;
        else if(test_vec_sort[mid]>key)
            high = mid-1;
        else
            low = mid+1;
    } // 查找不成功时，low=high
    return 0;
}

// 有序表二分查找，递归实现
int find_binary_recursion(vector<int> &test_vec_sort, int key)
{

}

int main()
{
    //无序表数据创建
    int test_arr_unsort[] = {88, 24, 72, 61, 21, 6, 32, 11, 8, 31, 22, 83, 78, 54};
    int key_unsort = 32;
    vector<int> test_vec_unsort;
    createVector(test_arr_unsort, 14, key_unsort, test_vec_unsort);

    //有序表数据创建
    int test_arr_sort[] = {7, 10, 13, 16, 19, 29, 32, 33, 37, 41, 43};
    int key_sort = 41;
    vector<int> test_vec_sort;
    createVector(test_arr_sort, 11, key_sort,  test_vec_sort);

    //测试查找
    //无序表顺序查找
    int res1 = find_inorder_unsort(test_vec_unsort, key_unsort);
    if(res1 == 0)
        cout << key_unsort << " has not found~" << endl;
    else
        cout << key_unsort << " has found at position " << res1 << endl;

    //有序表顺序查找
    int res2 = find_inorder_sort(test_vec_sort, key_sort);
    if(res2 == 0)
        cout << key_sort << " has not found~" << endl;
    else
        cout << key_sort << " has found at position " << res2 << endl;

    //有序表二分查找
    int res3 = find_binary_recurrent(test_vec_sort, key_sort);
    if(res3 == 0)
        cout << key_sort << " has not found~" << endl;
    else
        cout << key_sort << " has found at position " << res3 << endl;

}
