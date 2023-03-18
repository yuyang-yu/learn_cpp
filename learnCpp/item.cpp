#include <array>
#include <numeric> //for std::accumlate
#include <iostream>

namespace item
{
    enum Item
    {
        healthYpotions,
        torches,
        arrows,
        maxItem
    };
} // namespace item

using Inventory = std::array<int, item::maxItem>;

int totalItemNum(Inventory &arr)
{
    return std::accumulate(arr.begin(), arr.end(), 0);
}

int main()
{
    Inventory arr{2, 5, 10};

    std::cout << "total: " << totalItemNum(arr) << '\n';
    std::cout << "torch: " << arr[item::Item::torches] << '\n';

    return 0;
}