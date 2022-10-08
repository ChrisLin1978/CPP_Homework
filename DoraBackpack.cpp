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
    std::list<Item *> itemList;
    public:
    void Add(Item * item, int maxWeight)
    {
        for (std::list<Item *>::iterator it = itemList.begin(); it != itemList.end(); ++it) 
        {
            if (item == (*it))
                return;
        }

        int totalWeight = TotalWeight();
        if (totalWeight + item->weight > maxWeight)
            return;

        itemList.push_back(item);
    }

    int TotalPrice()
    {
        if (itemList.empty())
            return 0;

        int totalPrice = 0;
        for (std::list<Item *>::iterator it = itemList.begin(); it != itemList.end(); ++it) 
        {
            totalPrice += (*it)->price;
        }
        return totalPrice;
    }

    int TotalWeight()
    {
        if (itemList.empty())
            return 0;

        int totalWeight = 0;
        for (std::list<Item *>::iterator it = itemList.begin(); it != itemList.end(); ++it) 
        {
            totalWeight += (*it)->weight;
        }
        return totalWeight;
    }

    bool IsSameGroup(ItemGroup * compareGroup)
    {
        if (itemList.size() != compareGroup->itemList.size())
            return false;

        int sameCount = 0;
        for (std::list<Item *>::iterator it1 = itemList.begin(); it1 != itemList.end(); ++it1) 
        {
            for (std::list<Item *>::iterator it2 = compareGroup->itemList.begin(); it2 != compareGroup->itemList.end(); ++it2) 
            {
                if ((*it1)->weight == (*it2)->weight && (*it1)->price == (*it2)->price)
                {
                    sameCount++;
                    break;
                }
            }
        }

        return sameCount == itemList.size() ? true : false;
    }
};

class Combination
{
    private:
    std::list<ItemGroup *> itemGroupList;
    ItemGroup * currentItemGroup = 0;
    ItemGroup * bestPriceGroup;

    public:
    void BeginCombination(std::list<Item *> & itemList, int maxWeight)
    {
        for (std::list<Item *>::iterator it1 = itemList.begin(); it1 != itemList.end(); ++it1) 
        {
            if (currentItemGroup == 0)
                currentItemGroup = new ItemGroup();
            currentItemGroup->Add((*it1), maxWeight);
            std::list<Item *> remainiItemList;
            for (std::list<Item *>::iterator it2 = itemList.begin(); it2 != itemList.end(); ++it2) 
            {
                if ((*it1) == (*it2))
                    continue;
                remainiItemList.push_back((*it2));
            }
            if (remainiItemList.empty())
                return;

            BeginCombination(remainiItemList, maxWeight);

            AddGroup(currentItemGroup);
            currentItemGroup = 0;
        }
    }

    void AddGroup(ItemGroup * addItemGroup)
    {
        if (addItemGroup == 0)
            return;

        for (std::list<ItemGroup *>::iterator it = itemGroupList.begin(); it != itemGroupList.end(); ++it) 
        {
            ItemGroup * temp = (*it);
            if (temp == 0)
                continue;

            if (temp->IsSameGroup(addItemGroup))
                return;
        }

        if (itemGroupList.empty())
            bestPriceGroup = addItemGroup;
        else
        {
            if (addItemGroup->TotalPrice() > bestPriceGroup->TotalPrice())
                bestPriceGroup = addItemGroup;
        }

        itemGroupList.push_back(addItemGroup);
    }

    void DebugPrint()
    {
        int count = 0;
        for (std::list<ItemGroup *>::iterator it1 = itemGroupList.begin(); it1 != itemGroupList.end(); ++it1) 
        {
            if ((*it1) == 0)
                continue;
            cout << count + 1 << "\n";
            for (std::list<Item *>::iterator it2 = (*it1)->itemList.begin(); it2 != (*it1)->itemList.end(); ++it2) 
            {
                cout << (*it2)->weight << " " << (*it2)->price << "\n";
            }
            count++;
        }
    }

    ItemGroup * BestPriceConbination()
    {
        if (bestPriceGroup != 0)
        {
            cout << "最佳組合\n";
            for (std::list<Item *>::iterator it = bestPriceGroup->itemList.begin(); it != bestPriceGroup->itemList.end(); ++it) 
            {
                Item * tempItem = (*it);
                cout << "重量 : " << tempItem->weight << "價值 : " << tempItem->price << "\n";
            }
        }    
        return bestPriceGroup;
    }
};

int main()
{
    std::list<Item *> itemList;
    Combination combination;
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

    combination.BeginCombination(itemList, backpack.maxWeight);
    combination.DebugPrint();
    combination.BestPriceConbination();

    return 0;
}