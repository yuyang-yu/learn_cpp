#include<iostream>

struct Advertising
{
    int adsShown{};
    double clickThroughRatePercentage{};
    double averageEarningsPerClick{};
};

Advertising getAdvertising()
{
    Advertising temp{};
    std::cout << "How many ads you have shown to readers? ";
    std::cin >> temp.adsShown;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.clickThroughRatePercentage;
    std::cout << "How much you earned on average from each ad that was clicked? ";
    std::cin >> temp.averageEarningsPerClick;

    return temp;
}

void printAdvertising(const Advertising& ads)
{
    std::cout << "adsShown:" << ads.adsShown << '\n';
    std::cout << "clickThroughRatePercentage: " << ads.clickThroughRatePercentage << '\n';
    std::cout << "averageEarningsPerClick: " << ads.averageEarningsPerClick << '\n';

    std::cout << "Total money: " << ads.adsShown * ads.clickThroughRatePercentage * ads.averageEarningsPerClick << '\n';
}

int main()
{
    Advertising ads{getAdvertising()};
    std::cout << '\n';
    printAdvertising(ads);

    return 0;
}