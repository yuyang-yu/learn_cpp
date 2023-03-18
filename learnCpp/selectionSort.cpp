#include <iostream>
#include <iterator> //for std::size
#include <utility>  //for std::swap

int main()
{
    int array[]{30, 50, 20, 10, 40};
    constexpr int length{static_cast<int>(std::size(array))};

    // sort the array
    for (int startIndex = 0; startIndex < length - 1; startIndex++)
    {
        int minIndex{startIndex};
        for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
        {
            if (array[currentIndex] < array[minIndex])
            {
                minIndex = currentIndex;
            }
        }
        std::swap(array[minIndex], array[startIndex]);
    }

    // print the array
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i] << ' ';
    }
    
    std::cout << '\n';

    return 0;
}