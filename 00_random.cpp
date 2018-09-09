#include <iostream>
#include <time.h>

using namespace std;

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
    srand((unsigned)time(NULL));
    return rand() / (double)RAND_MAX*(Upper-Lower)+Lower;
}


void Test()
{
    cout << randT<int>(5, 10) << endl;
}
