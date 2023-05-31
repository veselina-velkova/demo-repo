#include<string>
#include<vector>
#pragma once

class TestClass
{
   private:
   std::string name;
   int number;
   float sum = 0.0;
   std::vector<float> grades{};

   public:
   TestClass();

   /* Methods */
   void test_getNumber();
   void test_valid_getNumber();
   void test_invalid_getNumber();
   void check_try_catch_getNumber(const int num, const std::string& name);

   void test_getName();
   void test_valid_getName();
   void test_invalid_getName();
   void check_getName(const int number, const std::string& name);

   void test_setNumber();
   void test_valid_setNumber();
   void test_invalid_setNumber();
   void check_setNumber(const int new_number);

   void test_setName();
   void test_valid_setName();
   void test_invalid_setName();
   void check_setName(const std::string& new_name);

   void test_addNewGrade();
   void test_valid_addNewGrade();
   void test_invalid_addNewGrade();
   void check_addNewGrade(student& test_student, const float grade);
   
   void test_getAverageGrade();
   void test_valid_getAverageGrade();
   void test_invalid_getAverageGrade();
   float calculate_average(std::vector<float>& grades);

   void test_getMinGrade();
   void test_valid_getMinGrade();
   void test_invalid_getMinGrade();

   void test_getMaxGrade();
   void test_valid_getMaxGrade();
   void test_invalid_getMaxGrade();

   void test_getGrades();
   void test_valid_getGrades();
   void test_invalid_getGrades();
   void check_are_received_grades_the_same(student& test_student, std::vector<float>& temp_grades);
};