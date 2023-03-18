#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main()
{
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    // Ask the user what to search for.
    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    auto found{std::find_if(arr.begin(), arr.end(), [search](std::string_view str)
                            {
    // Search for @search rather than "nut".
    return (str.find(search) != std::string_view::npos); // Error: search not accessible in this scope 
    })};

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}