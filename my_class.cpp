#include "my_class.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void student::resizeGrades()
{
    float* newGrades = new float [currentCapacity*2];
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
    numberGrades = 0;
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

bool student::areGrades()
{
    return bool(numberGrades);
}

float student::getAverageGrade()
{
    if(!areGrades())
    {
        cout<<"Can not give average for zero grades."<<endl;
        return -1;
    }
    else
    {
        return sum / numberGrades;
    } 
}

float student::getMaxGrade()
{
    if(!areGrades())
    {
        cout << "Can not find maximum grade out of zero grades." << endl;
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
    if(!areGrades())
    {
        cout << "Can not find minimum grade out of zero grades." << endl;
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
    cout << Petar.areGrades() << endl;
    Petar.addNewGrade(5.5);
    Petar.addNewGrade(3.2);
    Petar.addNewGrade(6.00);
    Petar.addNewGrade(5.2);
    Petar.addNewGrade(4.6);
    Petar.addNewGrade(2.2);
    cout << Petar.areGrades() << endl;;
    cout << Petar.getAverageGrade() << endl;
    cout << Petar.getMaxGrade() << endl;
    cout << Petar.getMinGrade() << endl;
    
    return 0;
}