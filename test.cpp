#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> splitstr(string str_input)
{
    vector<int> nums;
    char *s_input = (char *)str_input.c_str();
    const char * split = ",";
    char *p = strtok(s_input, split);
    int a;
    while(p != NULL)
    {
        sscanf(p, "%d", &a);
        nums.push_back(a);
        p=strtok(NULL, split);
    }
    return nums;
}

int main()
{
    int num;
    cin >> num;
    vector<int> x_data;
    vector<int> y_data;
    while(num--)
    {
        string s;
        cin >> s;
        vector<int> data = splitstr(s);
        x_data.push_back(data[0]);
        y_data.push_back(data[1]);

    }
    for (int i=0; i<x_data.size();i++)
    {
        cout << x_data[i] << endl;
    }
}

