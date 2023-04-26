//@file: my_class.cpp
//@author: Veselina Velkova (veselina.velkova@strypes.eu)
//@description: This contains the implementation of the student class.
//@version: 0.1
//@date: 18.04.2023

#include "my_class.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void student::resizeGrades()
{
    float* newGrades = new float [currentCapacity*2];
    float* newGrades = new (std::nothrow) float [currentCapacity*2];
    if (!newGrades)
    {
        std::cerr << "Problems with allocating memory in the resizeGrades function." << endl;
        throw std::bad_alloc();
    }
    for (int i = 0; i < currentCapacity; i++)
    {
        newGrades[i] = grades[i];
    }
    delete[] grades;
    currentCapacity *= 2;
    grades = newGrades;
    newGrades = nullptr;
}

student::student()
{
    cout << "What is student's number in class?" << endl;
    cin >> number;
    cout << "What's the student's name?" << endl;
    cin.ignore();
    getline(cin, name);
    if (!(cin >> number))
    {
        cout << "VESI ERROR";
    }
    if (cin.fail())
    {
        cout << "YOLINA";
    }
    //cout << "What's the student's name?"  << endl;
    //cin >> name;
    //cin.ignore();
    // getline(cin, name);
    numberGrades = 0;
}

student::student(int num, std::string full_name)
{
    number = num;
    name = full_name;
}

int student::getNumber()
{
    return number;
}

string student::getName()
{
    return name;
}

void student::setNumber(int num)
{
    number = num;
}

void student::setName(string newName)
{
    name = newName;
}
    
int student::getNumberGrades()
{
    return numberGrades;
}

void student::addNewGrade(float grade)
{
    if(numberGrades == MAX_GRADES)
    {
        cout << "This student has enough grades. " << endl;
        return;
    }
    if(currentCapacity == numberGrades)
    {
        resizeGrades();
    }
    grades[numberGrades] = grade;
    sum += grade;
    numberGrades += 1;
}

bool student::areGradesRecieved()
{
    return bool(numberGrades);
}

float student::getAverageGrade()
{
    if(!areGradesRecieved())
    {
        cout<<"Cannot calculate average when no grades present."<<endl;
        return -1;
    }
    else
    {
        return (sum / numberGrades);
    } 
}

float student::getMaxGrade()
{
    if(!areGradesRecieved())
    {
        cout << "Cannot find maximum grade when no grades exist yet." << endl;
        return -1;
    }
    else
    {
        float maxGrade = grades[0];
        for(int i = 1; i < numberGrades; i++)
        {
            if(grades[i] > maxGrade)
            {
                maxGrade = grades[i];
            }
        }
        return maxGrade;
    }
}

float student::getMinGrade()
{
    if(!areGradesRecieved())
    {
        cout << "Cannot find minimum grade when no grades exist yet." << endl;
        return -1;
    }
    else
    {
        float minGrade = grades[0];
        for(int i = 1; i < numberGrades; i++)
        {
            if(grades[i] < minGrade)
            {
                minGrade = grades[i];
            }
        }
        return minGrade;
    }
}

float* student::getGrades()
{
    for (int i = 0; i < numberGrades; i++)
    {
        cout << grades[i] << " ";
    }
    cout << endl;
    return grades;
}

student::~student()
{
    delete[] grades;
    grades = nullptr;
}

int main()
{
    student Petar;
    cout << Petar.areGradesRecieved() << endl;
    Petar.addNewGrade(5.5);
    Petar.addNewGrade(3.2);
    Petar.addNewGrade(6.00);
    Petar.addNewGrade(5.2);
    Petar.addNewGrade(4.6);
    Petar.addNewGrade(2.2);
    cout << Petar.areGradesRecieved() << endl;;
    cout << Petar.getAverageGrade() << endl;
    cout << Petar.getMaxGrade() << endl;
    cout << Petar.getMinGrade() << endl;
    
    return 0;
}