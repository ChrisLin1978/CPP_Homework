/*
輸入n，n個整數的k和n個整數的l，輸出(輸入的k)地偶數位數和加上(輸入的l)第偶數位數合。
example in : 5 1 2 3 4 5 6 7 8 9 10
example out : (2+4+7+9=)22
*/
#include <iostream>
#include <math.h>
using namespace std;

int FillArray(int * array, int length, int total, int * mergeArray, int & mergeIndex)
{
    for (int i = 0; i < length; ++i)
    {
        cin >> array[i];
        if ((i + 1) % 2 == 0)
        {
            total += array[i];
            mergeArray[mergeIndex] = array[i];
            mergeIndex++;
        }
    }
    return total;
}

int main()
{
    int n;

    cin >> n;
    int array1[n];
    int array2[n];
    int merge[n / 2 * 2];
    int total = 0;
    int mergeIndex = 0;

    total = FillArray(array1, n, total, merge, mergeIndex);
    total = FillArray(array2, n, total, merge, mergeIndex);

    string output;
    for (int i = 0; i < mergeIndex; ++i)
    {
        output += to_string(merge[i]);
        output += i == mergeIndex - 1 ? "=" : "+";
    }

    cout << "(" << output << ")" << total;
    
    return 0;
}