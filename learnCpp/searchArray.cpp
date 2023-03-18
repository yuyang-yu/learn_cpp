// #include <iostream>
// #include <iterator>
// #include <limits>

// int getUserInput()
// {
//     int input{};
//     do
//     {
//         std::cout << "Enter a number between 1 and 9:";
//         std::cin >> input;
//         if (!std::cin)
//         {
//             std::cin.clear();
//         }
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     } while (input < 1 || input > 9);
//     return input;
// }

// void searchArray(const int array[], int number)
// {
//     for (int i = 0; i < static_cast<int>(sizeof(array) / sizeof(array[0])); i++)
//     {
//         std::cout << array[i] << ' ';
//     }
//      std::cout << '\n';
//     for (int i = 0; i < static_cast<int>(sizeof(array) / sizeof(array[0])); i++)
//     {
//         if (number == array[i])
//         {
//             std::cout << "The number " << number << " has index " << i << '\n';
//         }
//     }
// }

// int main()
// {
//     constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};
//     int number{getUserInput()};
//     searchArray(array, number);

//     return 0;
// }

#include<iostream>
#include<iterator>
#include<limits>

// int main()
// {
//     int number{};
//     std::cout << "Enter a number between 1 and 9: ";
//     std::cin >> number;

//     if(!std::cin)
//         std::cin.clear();

//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
// }