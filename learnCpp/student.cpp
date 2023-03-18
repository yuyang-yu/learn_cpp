#include <algorithm> //for std::sort
#include <iostream>
#include <vector>
#include <string>

struct Student
{
    std::string name;
    int grade;
};

int getNumberOfStudents()
{
    int number{};
    do
    {
        std::cout << "How many student you want to enter? ";
        std::cin >> number;
    } while (number <= 0);
    return number;
}

std::vector<Student> getStudents()
{
    int numberOfStudent(getNumberOfStudents());
    
    // Create a vector with numberOfStudents elements.
    std::vector<Student> vec(static_cast<std::vector<Student>::size_type>(numberOfStudent));

    int studentNumber{1};
    for (auto &&i : vec)
    {
        std::cout << "Enter name # " << studentNumber << ": ";
        std::getline(std::cin >> std::ws, i.name);
        std::cout << "Enter grade # " << studentNumber << ": ";
        std::cin >> i.grade;

        ++studentNumber;
    }

    return vec;
}

bool compareGradeOfStudent(const Student &a, const Student &b)
{
    return (a.grade > b.grade);
}

int main()
{
    auto students{getStudents()};

    // sort by grade
    std::sort(students.begin(), students.end(), compareGradeOfStudent);

    for (auto &&i : students)
    {
        std::cout << i.name << " got a grade of " << i.grade << '\n';
    }

    return 0;
}