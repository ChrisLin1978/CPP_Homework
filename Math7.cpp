/*
輸入n代表音軌音量，和n個整數k代表音軌音量大小，大傳社的麵條同學為了避免音量過大或小，需將最大的音量設為100，其他音量等比縮放，請輸出所有音軌
example in : 10 1 2 3 4 5 6 7 8 9 10
example out : 10 20 30 40 50 60 70 80 90 100
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    int max = 0;
    float multiply;

    cin >> n;
    int k[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> k[i];
        if (k[i] > max)
            max = k[i];
    }

    multiply = 100.0f / (float)max;

    for (int i = 0; i < n; ++i)
    {
        cout << k[i] * multiply << " ";
    }

    return 0;
}