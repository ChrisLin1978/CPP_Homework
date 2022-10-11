/*
Problem
設計一個程式用此方法計算 (x1,y1) 到 (x2,y2) 所圍成的矩形上(包括邊上)的所有數字和。

Input
第一行輸入兩個正整數 n,m，表示給定一個 n×m 的網格 (定義左上角的座標為 (0,0)，右下角的座標為 (n−1,m−1))。

接下來共有 n 行，每行輸入 m 個正整數 ai,j。

接下來輸入一個正整數 Q，表示有 Q 組查詢。

接下來將有 Q 行，每一行依序輸入四個整數 x1,y1,x2,y2，表示查詢 (x1,y1) 到 (x2,y2) 所圍成的矩形上(包括邊上)的所有數字和。

Examples
範例輸入1
5 5
1 2 3 4 5
5 4 3 2 1
1 1 1 1 1
1 1 1 1 1
2 2 2 2 2
5
0 0 0 0
0 0 4 4
0 0 1 1
2 3 3 4
2 2 4 2

範例輸出1
1
50
12
6
3

Constraints
不會超過long long

Solution
C++
Reference
https://codeforces.com/group/H0qY3QmnOW/contest/383582/problem/H2
*/

#include <iostream>>
using namespace std;

int Total(int array[][], int startX, int startY, int endX, int endY)
{
    int total = 0;
    for (int i = startX; i <= endX; ++i)
    {
        for (int j = startY; j <= endY; ++j)
        {
            total += array[i][j];
        }
    }
    return total;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int array[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> array[i][j];
        }
        cout << "\n";
    }

    int queryCount;
    cin >> queryCount;
    int queryArray[queryCount][4];
    for (int i = 0; i < queryCount; ++i)
    {
        cin >> queryArray[i][0] >> queryArray[i][1] >> queryArray[i][2] >> queryArray[i][3];
        cout << "\n";
    }

    for (int i = 0; i < queryCount; ++i)
    {
        if (queryArray[i][0] < 0 || queryArray[i][0] >= m ||
            queryArray[i][1] < 0 || queryArray[i][1] >= n ||
            queryArray[i][2] < 0 || queryArray[i][2] >= m ||
            queryArray[i][3] < 0 || queryArray[i][3] >= n)
        {
            cout << "Index out of range\n";
        }
        else
        {
            int total = Total(array, queryArray[i][0], queryArray[i][1], queryArray[i][2], queryArray[i][3]);
            cout << total;
        }
    }
}