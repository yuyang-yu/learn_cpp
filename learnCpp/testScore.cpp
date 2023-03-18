// #include <iostream>

// enum class NameOfStudents
// {
//     tom,
//     bob,
//     bill,
//     max_students,
// };

// int main()
// {
//     int testScore[static_cast<int>(NameOfStudents::max_students)]{};
//     testScore[static_cast<int>(NameOfStudents::bill)] = 88;

//     std::cout << testScore[static_cast<int>(NameOfStudents::tom)] << '\n';
//     std::cout << testScore[static_cast<int>(NameOfStudents::bob)] << '\n';
//     std::cout << testScore[static_cast<int>(NameOfStudents::bill)] << '\n';

//     return 0;
// }

#include <iostream>

namespace nameOfStudents
{
    enum NameOfStudents
    {
        tom,
        bob,
        bill,
        max_students,
    };
} // namespace nameOfStudents

int main()
{
    int testScore[nameOfStudents::max_students]{};

    testScore[nameOfStudents::bill] = 88;

    std::cout << testScore[nameOfStudents::tom] << '\n';
    std::cout << testScore[nameOfStudents::bob] << '\n';
    std::cout << testScore[nameOfStudents::bill] << '\n';

    return 0;
}