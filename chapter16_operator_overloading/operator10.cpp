#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <string_view> // C++17
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char &operator[](std::string_view name);
};

char &GradeMap::operator[](std::string_view name)
{
    auto found{std::find_if(m_map.begin(), m_map.end(),
                            [&](const auto &student) { // this is a lambda
                                return (student.name == name);
                            })};

    if (found != m_map.end())
    {
        return found->grade;
    }

    // otherwise create a new StudentGrade for this student and add
    // it to the end of our vector.
    m_map.push_back({std::string{name}});

    // and return the element
    return m_map.back().grade;
}

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}

//we can use map(#include<map>)

// int main()
// {
//     // std::map can be initialized
//     std::map<std::string, char> grades{
//         {"Joe", 'A'},
//         {"Frank", 'B'}};

//     // and assigned
//     grades["Susan"] = 'C';
//     grades["Tom"] = 'D';

//     std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
//     std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

//     return 0;
// }