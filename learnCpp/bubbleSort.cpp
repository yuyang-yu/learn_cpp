#include <iostream>
#include <iterator> // for std::size
#include <utility>

int main()
{
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int length{static_cast<int>(std::size(array))}; // C++17
                                                              //  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable

    // Step through each element of the array except the last
    for (int iteration{0}; iteration < length - 1; ++iteration)
    {
        // Account for the fact that the last element is already sorted with each subsequent iteration
        // so our array "ends" one element sooner
        int endOfArrayIndex{length - iteration};

        bool swapped{false}; // Keep track of whether any elements were swapped this iteration

        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{0}; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it
            if (array[currentIndex] > array[currentIndex + 1])
            {
                // Swap them
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }

        // If we haven't swapped any elements this iteration, we're done early
        if (!swapped)
        {
            // iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
            std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
            break;
        }
    }

    // Now print our sorted array as proof it works
    // for (int index{0}; index < length; ++index)
    //     std::cout << array[index] << ' ';

    for (auto &&i : array)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}