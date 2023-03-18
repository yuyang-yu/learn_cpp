#include <algorithm> //for std::max_element
#include <array>     //for std::array
#include <iostream>
#include <string_view> //for std::string_view

struct Student
{
    std::string_view name;
    int point;
};

auto comp{
    [](const auto &a, const auto &b)
    {
        return a.point < b.point;
    }};

int main()
{
    std::array<Student, 8> arr{
        {{"Albert", 3},
         {"Ben", 5},
         {"Christine", 2},
         {"Dan", 8}, // Dan has the most points (8).
         {"Enchilada", 4},
         {"Francis", 1},
         {"Greg", 3},
         {"Hagrid", 5}}};

    auto found{std::max_element(arr.begin(), arr.end(), comp)};

    if (found != arr.end())
    {
        std::cout << found->name << " has the most point (" << found->point << ")\n";
    }
    else
    {
        std::cout << "Can not found the most point\n";
    }

    return 0;
}