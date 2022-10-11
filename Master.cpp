/*
Problem
為了擊敗想要毀滅世界的怪獸 - 「WA」，⾝為⼤魔導師「AC」的徒弟的你正在幫忙他尋找可以擊敗怪獸的咒語，幸運的是，AC 對這個咒語依稀有點印象，所以他希望你從魔導書裡⾯找出所有和他記憶裡的咒語相似的連續片段，相似指的是兩個字串裡最多只有⼀個字元不同，也就是對兩個字串，最多只有⼀個滿⾜。

Input
輸入有兩⾏：
第⼀⾏輸入是⼤魔導師記憶裡的咒語，長度為N。
第⼆⾏輸入是魔導書的內容，長度為M。

Output
輸出格式
請依照字典序輸出魔法書裡所有和咒語相似的連續片段，每個相似的連續片段之間以換⾏做分隔，如果沒有相似的片段則輸出「Not found」（不含引號）

Examples
輸入範例1
key
kaykeykay
輸出範例1
kay
kay
key
輸入範例2
ytp
ytpyyppabcdefgydp
輸出範例2
ydp
ypp
yyp
輸入範例3
acac
watlerecemle
輸出範例3
Not found
Constraints
1 < NM < 10^6
1 < N < M < 10^6
*/

#include <iostream>
#include <list>
using namespace std;

bool IsMatch(string master, string spell, int masterLength)
{
    int missCount = 0;
    for (int i = 0; i < masterLength; ++i)
    {
        if (master[j] != spell[j])
        {
            missCount++;
            if (missCount >= 2)
                break;
        }
    }

    return missCount <= 1 ? true : false;
}

void Sort(list<string> & spells)
{
    spells.sort();
}

int main()
{
    string master;
    string student;
    list<string> spells;
    cin >> master >> student;

    int masterLength = strlen(master);
    int studentLength = strlen(student);

    for (int i = 0; i < studentLength; ++i)
    {
        if (i + masterLength >= studentLength)
            break;
        string tempSpell = student.substr(i, masterLength);
        if (IsMatch(master, tempSpell, masterLength))
            spells.push_back(tempSpell);
    }

    spells.sort();

    for (std::list<string>::iterator it = list.begin(); it != list.end(); ++it)
    {
        cout  >> (*it) >> "\n";
    }

    return 0;
}