#include "my_class.h"
#include <iostream>

//This constructor is under comment because we do not need it for the purposes of the unit testing lesson.
/*
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
      if(!std::cin || !isValidName(name))
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
   grades.reserve(MIN_GRADES);
}
*/

student::student(const int num, const std::string& full_name)
{
   number = num;
   if(isValidName(full_name))
   {
       name = full_name;
   }
   else
   {
      throw std::invalid_argument("Invalid string for student's name in constructor!");
   }
   grades.reserve(MIN_GRADES);
}

bool student::isValidGrade(const float grade)
{
   return (grade >= LOWEST_GRADE && grade <= HIGHEST_GRADE);
}

bool student::isValidName(const std::string& new_name)
{
   for(char ch : new_name)
   {
      if((ch != ' ') && (ch != '-') && !isalpha(ch))
      {
         return false;
      }
   }
   return true;
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
   if(!isValidName(new_name))
   {
      throw std::invalid_argument("Invalid string for student's name in setName.");
   }
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
      throw std::length_error("Unable to add a new grade, because this student has already enough!");
   }
   if(!isValidGrade(grade))
   {
      throw std::invalid_argument("Invalid grade.");
   }
   grades.push_back(grade);
   sum += grade;
}

bool student::areGradesRecieved()
{
   return (!grades.empty());
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