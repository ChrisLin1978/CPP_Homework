/*
輸入n，和n個整數的k，將他們取平均(浮點數無條件捨去取到小數點後3位)
example in : 3 4 5 7
example out : 5.333
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cin >> n;
    int k;
    float total = 0.0f;

    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        total += k;
    }

    float avg = total / n;
    cout << setprecision(4) << avg;

    return 0;
}