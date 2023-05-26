//@file: my_class.cpp
//@author: Veselina Velkova (veselina.velkova@strypes.eu)
//@description: This contains the implementation of the student class.
//@version: 0.1
//@date: 18.04.2023

#include "my_class.h"
#include <iostream>

student::student()
{
    while(true)
    {
        std::cout << "What is student's number in class?" << '\n';
        std::cin >> number;
        if(!std::cin)
        {
            std::cerr << "Read invalid data for student's number in class!"<<std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            break;
        }
    }    
    std::cin.ignore();
    while(true)
    {
        std::cout << "What's the student's name?" << '\n';
        getline(std::cin, name);
        if(!std::cin)
        {
            std::cerr << "Read invalid data for the student's name!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            break;
        }
    }
    grades.resize(MIN_GRADES);
}

student::student(int num, const std::string& full_name)
{
    number = num;
    name = full_name;
    grades.resize(MIN_GRADES);
}

int student::getNumber()
{
    return number;
}

std::string student::getName()
{
    return name;
}

void student::setNumber(int num)
{
    number = num;
}

void student::setName(const std::string& new_name)
{
    name.clear();
    name = new_name;
}
    
int student::getNumberGrades()
{
    return grades.size();
}

void student::addNewGrade(float grade)
{
    if(getNumberGrades() == MAX_GRADES)
    {
        std::cerr << "This student has enough grades. " << std::endl;
        return;
    }
    grades.push_back(grade);
    sum += grade;
}

bool student::areGradesRecieved()
{
    return grades.empty();
}

float student::getAverageGrade()
{
    if(!areGradesRecieved())
    {
        throw std::logic_error("Cannot calculate average when no grades present.");
    }
    return (sum / getNumberGrades());
}

float student::getMaxGrade()
{
    if(!areGradesRecieved())
    {
        throw std::logic_error("Cannot find maximum grade when no grades exist yet.");
    }
    float maxGrade = grades.front();
    for(float grade : grades)
    {
        if(grade > maxGrade)
        {
            maxGrade = grade;
        }
    }
    return maxGrade;
}

float student::getMinGrade()
{
    if(!areGradesRecieved())
    {
        throw std::logic_error("Cannot find minimum grade when no grades exist yet.");
    }
    float minGrade = grades.front();
    for(float grade : grades)
    {
        if(grade < minGrade)
        {
            minGrade = grade;
        }
    }
    return minGrade;
}

std::vector<float> student::getGrades()
{
    for (auto it = grades.begin(); it != grades.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return grades;
}

int main()
{
    return 0;
}