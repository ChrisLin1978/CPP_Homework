/*
Problem
所謂回文數(Palidrome Number)是指一個像12321這樣對稱的數列，也就是從前頭讀跟從後頭讀是相同的數字，另外中文也有這樣回文的作法，像是「上海自來水來自海上」等
給定一個整數x，請判斷x是否為回文數，是請印出True，反之則印出False

Examples
輸入: x = 121
輸出: True
輸入: x = 123
輸出: False
*/

#include <iostream>
using namespace std;

bool LeftCheck(string & number, int index)
{
    int leftIndex = index - 1;
    if (leftIndex < 0)
        return true;
    int num1 = (int)number[index];
    int num2 = (int)number[leftIndex];
    if (num1 - 1 == num2)
        return true;
    return false;
}

bool RightCheck(string & number, int index)
{
    int rightIndex = index + 1;
    if (rightIndex >= number.length())
        return true;
    int num1 = (int)number[index];
    int num2 = (int)number[rightIndex];
    if (num1 - 1 == num2)
        return true;
    return false;
}

int main()
{
    char c;

    cout << "x = ";
    string inputNumber;
    cin >> inputNumber;

    int length = inputNumber.length();
    if (length < 3 || length % 2 == 0)
    {
        cout << "False";
        return 0;
    }
    else
    {
        int middleIndex = length / 2;
        int leftIndex = middleIndex;
        int rightIndex = middleIndex;
        while (true)
        {
            if (leftIndex < 0 || rightIndex >= length)
            {
                cout << "True";
                break;
            }

            if (LeftCheck(inputNumber, leftIndex) == false ||
                RightCheck(inputNumber, rightIndex) == false)
            {
                cout << "False";
                break;
            }

            leftIndex--;
            rightIndex++;
        }
    }

    return 0;
}