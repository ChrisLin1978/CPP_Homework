/*
Problem
有一位愛探險的Dora要出遠門，希望能從想帶的物品中找出最有價值的帶法，你能幫幫她嗎?

Input
輸入有多⾏：
第一行是有幾樣物品(N)和背包的最大承重量(W)。
接下來是各個物品的重量和價值。

Output
輸出格式
輸出最大價值

Examples
輸入範例1
4 12
3 20
4 45
9 70
12 85
輸出範例1
the best solution is: 90
*/

#include <iostream>
#include <list>
using namespace std;

class Backpack
{
    /* data */
    public: int itemCount;
    public: int maxWeight;
};

class Item
{
    public: int weight;
    public: int price;
};

class ItemGroup
{
    public:
    std::list<Item *> itemGroupList;
    public:
    void Add(Item * item, int maxWeight)
    {
        for (std::list<Item *>::iterator it = itemGroupList.begin(); it != itemGroupList.end(); ++it) 
        {
            if (item == (*it))
                return;
        }

        int totalPrice = TotalPrice();
        if (totalPrice + item->price > maxWeight)
            return;

        itemGroupList.push_back(item);
    }

    int TotalPrice()
    {
        if (itemGroupList.empty())
            return 0;

        int totalPrice = 0;
        for (std::list<Item *>::iterator it = itemGroupList.begin(); it != itemGroupList.end(); ++it) 
        {
            totalPrice += (*it)->price;
        }
        return totalPrice;
    }
};

void Combination(std::list<ItemGroup *> & itemGroupList, ItemGroup & itemGroup, std::list<Item *> & itemList, int maxWeight)
{
    for (std::list<Item *>::iterator it1 = itemList.begin(); it1 != itemList.end(); ++it1) 
    {
        itemGroup.Add((*it1), maxWeight);
        std::list<Item *> remainiItemList;
        for (std::list<Item *>::iterator it2 = itemList.begin(); it2 != itemList.end(); ++it2) 
        {
            if ((*it1) == (*it2))
                continue;
            remainiItemList.push_back((*it2));
        }
        if (remainiItemList.empty())
            return;

        Combination(itemGroupList, itemGroup, remainiItemList, maxWeight);
        itemGroupList.push_back(&itemGroup);
    }
}

int main()
{
    std::list<Item *> itemList;
    std::list<ItemGroup *> itemGroupList;
    ItemGroup itemGroup;
    Backpack backpack;
    cout << "請輸入道具數量與最大承受重量\n";
    cin >> backpack.itemCount >> backpack.maxWeight;
    cout << "輸入的道具數量為 : " << backpack.itemCount << "\n";
    cout << "輸入的最大重量為 : " << backpack.maxWeight << "\n";
    for (int i = 0; i < backpack.itemCount; ++i)
    {
        cout << "請輸入第" << i + 1 << "個道具的重量與價值\n";
        Item * item = new Item();
        cin >> item->weight >> item->price;
        itemList.push_back(item);
    }

    Combination(itemGroupList, itemGroup, itemList, backpack.maxWeight);

    int count = 0;
    for (std::list<ItemGroup *>::iterator it1 = itemGroupList.begin(); it1 != itemGroupList.end(); ++it1) 
    {
        cout << count + 1 << "\n";
        for (std::list<Item *>::iterator it2 = (*it1)->itemGroupList.begin(); it2 != (*it1)->itemGroupList.end(); ++it2) 
        {
            cout << (*it2)->weight << " " << (*it2)->price << "\n";
        }
        count++;
    }
    /*for (std::list<Item *>::iterator it1 = itemList.begin(); it1 != itemList.end(); ++it1) 
    {
        ItemGroup * itemGroup = new ItemGroup();
        itemGroup->Add((*it1), backpack.maxWeight);
        for (std::list<Item *>::iterator it2 = itemList.begin(); it2 != itemList.end(); ++it2) 
        {
            if ((*it1) == (*it2))
                continue;

            itemGroup->Add((*it2), backpack.maxWeight); 
        }
        itemGroupList.push_back(itemGroup);
    }*/

    return 0;
}