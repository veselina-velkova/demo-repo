/**
 * @file my_class.h
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#pragma once
#include<string>
#include<vector>

//These constants are useful because in real life students can not have infinite number of grades.
//Usually, for each subject there is minimum and maximum number of grades that each student should have. 
const int MIN_GRADES = 5;
const int MAX_GRADES = 20;
const float LOWEST_GRADE = 2.f;
const float HIGHEST_GRADE = 6.f;
class Student
{
   std::string name{};
   int number{};
   float sum{};
   std::vector<float> grades{};
   bool isValidName(const std::string& new_name);
   bool isValidGrade(const float grade);

   public:
   Student(const int num, const std::string& full_name);

   int getNumber();
   std::string getName();
   int getNumberGrades();
   std::vector<float> getGrades();

   void setNumber(int num);
   void setName(const std::string& newName);
   
   /* Class Methods */
   void addNewGrade(float grade);
   bool areGradesRecieved();
   float getAverageGrade();
   float getMaxGrade();
   float getMinGrade();
};