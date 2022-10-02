/*
輸入n，輸出底為2n-1高為n的數字1金字塔
example in : 3
example out :
1
111
11111
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int count = (i + 1) * 2 - 1;
        for (int j = 0; j < count; j++)
        {
            cout << 1;
        }
        cout << '\n';
    }

    cin >> n;

    return 0;
}