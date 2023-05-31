#include<limits>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include "my_class.h"
#include "test_my_class.hpp"

#define _USE_MATH_DEFINES

#define IS_TRUE(x) {if(!(x)) std::cout<<__FUNCTION__<<" failed on line "<<__LINE__<<std::endl;}

#define TEST_CLASS_POSITIVE_DOUBLE (M_PI)
#define TEST_CLASS_NEGATIVE_DOUBLE (-M_PI)

#define TEST_CLASS_POSITIVE_FLOAT (5.5)
#define TEST_CLASS_NEGATIVE_FLOAT (-3.5)
#define TEST_CLASS_BIG_POSITIVE_FLOAT (14.3)

#define TEST_CLASS_POSITIVE_INT (6)
#define TEST_CLASS_NEGATIVE_INT (-4)

#define TEST_CLASS_NOT_THAT_LARGE_POS_INT (31650)
#define TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT (-31650)

#define TEST_CLASS_LARGE_POSITIVE_INT (std::numeric_limits<int>::max())
#define TEST_CLASS_LARGE_NEGATIVE_INT (std::numeric_limits<int>::min())

#define TEST_CLASS_UNSIGNED_LONG_LONG_INT (std::numeric_limits<unsigned long long int>::max())
#define TEST_CLASS_LONG_LONG_INT_NEGATIVE (std::numeric_limits<long long int>::min())

#define TEST_CLASS_INVALID_STRING ("I AM @ very Long NAmE")
#define TEST_CLASS_VALID_STRING_DASH ("Anna-Maria Toneva")
#define TEST_CLASS_VALID_STRING ("Veselina Velkova")

#define TEST_CLASS_CHAR_LETTER ('A')
#define TEST_CLASS_CHAR_NUMBER ('5')
#define TEST_CLASS_CHAR_SYMBOL ('@')

TestClass::TestClass()
{
   name = "";
   number = 0;
   grades.reserve(MIN_GRADES);
   std::cout << std::endl << "Test Class Default Constructor Created." << std::endl;
}

void TestClass :: test_getNumber()
{
   std::cout << '\n' << "Testing student::getNumber()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_getNumber();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_getNumber();
   std::cout << "END" << '\n';
}

void TestClass :: test_valid_getNumber()
{ 
   name = TEST_CLASS_VALID_STRING;
   
   //UT: Without dash in the name. Positive int for student's number.
   number = TEST_CLASS_POSITIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: Without dash in the name. Negative int for student's number.
   number = TEST_CLASS_NEGATIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: Without dash in the name. Large positive int for student's number.
   number = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_try_catch_getNumber(number, name);

   //UT: Without dash in the name. Large negative int for student's number.
   number = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: Without dash in the name. Corner case large negative int for student's number.
   number = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: Without dash in the name. Corner case large positive int for student's number.
   number = TEST_CLASS_LARGE_POSITIVE_INT;
   check_try_catch_getNumber(number, name);

   name.clear();
   name = TEST_CLASS_VALID_STRING_DASH;

   //UT: With dash in the name. Positive int for student's number.
   number = TEST_CLASS_POSITIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: With dash in the name. Negative int for student's number.
   number = TEST_CLASS_NEGATIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: With dash in the name. Large positive int for student's number.
   number = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_try_catch_getNumber(number, name);

   //UT: With dash in the name. Large negative int for student's number.
   number = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: With dash in the name. Corner case large negative int for student's number.
   number = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(number, name);

   //UT: With dash in the name. Corner case large positive int for student's number.
   number = TEST_CLASS_LARGE_POSITIVE_INT;
   check_try_catch_getNumber(number, name);
}

void TestClass :: check_try_catch_getNumber(const int number, const std::string& name)
{
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << number << '\n';
      student test_student(number, name);
      IS_TRUE(test_student.getNumber() == number);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_invalid_getNumber()
{
   std::string invalid_name = TEST_CLASS_INVALID_STRING;

   //UTs: Invalid string for student's name and valid int for student's number.
   number = TEST_CLASS_POSITIVE_INT;
   check_try_catch_getNumber(number, invalid_name);
   
   number = TEST_CLASS_NEGATIVE_INT;
   check_try_catch_getNumber(number, invalid_name);

   number = TEST_CLASS_LARGE_POSITIVE_INT;
   check_try_catch_getNumber(number, invalid_name);
   
   number = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(number, invalid_name);

   number = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_try_catch_getNumber(number, invalid_name);
   
   number = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(number, invalid_name);

   //We are going to check with just one of the valid strings for student's name, because we will already
   //know if they work correctly from the GOOD case scenario.
   name.clear();
   name = TEST_CLASS_VALID_STRING;

   //UT: Valid name and positive double for student's number.
   double double_number = TEST_CLASS_POSITIVE_DOUBLE;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << double_number << '\n';
      student test_student(double_number, name);
      IS_TRUE(test_student.getNumber() == (int) double_number);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and negative double for student's number.
   double_number = TEST_CLASS_NEGATIVE_DOUBLE;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << double_number << '\n';
      student test_student(double_number, name);
      IS_TRUE(test_student.getNumber() == (int) double_number);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and positive float for student's number.
   float float_number = TEST_CLASS_POSITIVE_FLOAT;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << float_number << '\n';
      student test_student(float_number, name);
      IS_TRUE(test_student.getNumber() == (int) float_number);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and negative float for student's number.
   float_number = TEST_CLASS_NEGATIVE_FLOAT;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << float_number << '\n';
      student test_student(float_number, name);
      IS_TRUE(test_student.getNumber() == (int) float_number);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and letter char for student's number.
   char character = TEST_CLASS_CHAR_LETTER;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << character << '\n';
      student test_student(character, name);
      IS_TRUE(test_student.getNumber() == (int) character);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and symbol char for student's number.
   character = TEST_CLASS_CHAR_SYMBOL;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << character << '\n';
      student test_student(character, name);
      IS_TRUE(test_student.getNumber() == (int) character);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and digit char for student's number.
   character = TEST_CLASS_CHAR_NUMBER;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << character << '\n';
      student test_student(character, name);
      IS_TRUE(test_student.getNumber() == (int) character);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and int overflow for student's number.
   size_t max_value = TEST_CLASS_UNSIGNED_LONG_LONG_INT;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << max_value << '\n';
      student test_student(max_value, name);
      IS_TRUE(test_student.getNumber() == (int) max_value);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }

   //UT: Valid name and int underflow for student's number.
   long long int min_value = TEST_CLASS_LONG_LONG_INT_NEGATIVE;
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << min_value << '\n';
      student test_student(min_value, name);
      IS_TRUE(test_student.getNumber() == (int) min_value);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
}  

void TestClass :: test_getName()
{
   std::cout << '\n' << "Testing student::getName()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_getName();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_getName();
   std::cout << "END" << '\n';
}

void TestClass :: check_getName(const int number, const std::string& name)
{
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << number << '\n';
      student test_student(number, name);
      IS_TRUE(test_student.getName() == name);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_valid_getName()
{
   //Here the student's number doesn't matter so we are going to use just TEST_CLASS_POSITIVE_INT
   std::string name;
   int number = TEST_CLASS_POSITIVE_INT;

   //UT: Valid number for student's number. Valid string without dash.
   name = TEST_CLASS_VALID_STRING;
   check_getName(number, name);

   //UT: Valid number for student's number. Valid string with dash.
   name.clear();
   name = TEST_CLASS_VALID_STRING_DASH;
   check_getName(number, name);

   //UT: Valid number for student's number. Valid char for student's name.
   name.clear();
   name = TEST_CLASS_CHAR_LETTER;
   check_getName(number, name);
}

void TestClass :: test_invalid_getName()
{
   //Here the student's number doesn't matter so we are going to use just TEST_CLASS_POSITIVE_INT
   number = TEST_CLASS_POSITIVE_INT;

   //UT: Valid number for student's number. Invalid string for student's name.
   name = TEST_CLASS_INVALID_STRING;
   check_getName(number, name);

   //UT: Valid number for student's number. Invalid char for student's name.
   name.clear();
   name = TEST_CLASS_CHAR_NUMBER;
   check_getName(number, name);

   //UT: Valid number for student's number. Invalid char for student's name.
   name.clear();
   name = TEST_CLASS_CHAR_SYMBOL;
   check_getName(number, name);
}

void TestClass :: test_setNumber()
{
   std::cout << '\n' << "Testing student::setNumber()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_setNumber();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_setNumber();
   std::cout << "END" << '\n';
}

void TestClass :: check_setNumber(const int new_number)
{
   try
   {
      name = "";
      number = 0;
      std::cout << "Testing with student's name: " << name << " and student's number: " << number << '\n';
      student test_student(number, name);
      std::cout << "Setting new student's number: " << new_number <<'\n';
      test_student.setNumber(new_number);
      IS_TRUE(test_student.getNumber() == new_number);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
   
}

void TestClass :: test_valid_setNumber()
{
   //UT: Setting a valid positive int for student's number.
   number = TEST_CLASS_POSITIVE_INT;
   check_setNumber(number);

   //UT: Setting a valid negative int for student's number.
   number = TEST_CLASS_NEGATIVE_INT;
   check_setNumber(number);

   //UT: Setting a valid not that large positive int for student's number.
   number = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_setNumber(number);

   //UT: Setting a valid not that large negative int for student's number.
   number = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_setNumber(number);

   //UT: Setting a valid large positive int for student's number.
   number = TEST_CLASS_LARGE_POSITIVE_INT;
   check_setNumber(number);

   //UT: Setting a valid large negative int for student's number.
   number = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_setNumber(number);
}

void TestClass :: test_invalid_setNumber()
{
   //UT: Setting an invalid positive double for student's number.
   double double_number = TEST_CLASS_POSITIVE_DOUBLE;
   std::cout << "Trying to set for student's number: " << double_number << '\n';
   check_setNumber((int)double_number);

   //UT: Setting an invalid negative double for student's number.
   double_number = TEST_CLASS_NEGATIVE_DOUBLE;
   std::cout << "Trying to set for student's number: " << double_number << '\n';
   check_setNumber((int)double_number);

   //UT: Setting an invalid positive float for student's number.
   float float_number = TEST_CLASS_POSITIVE_FLOAT;
   std::cout << "Trying to set for student's number: " << float_number << '\n';
   check_setNumber((int)float_number);

   //UT: Setting a valid not that large negative int for student's number.
   float_number = TEST_CLASS_NEGATIVE_FLOAT;
   std::cout << "Trying to set for student's number: " << float_number << '\n';
   check_setNumber((int)float_number);

   //UT: Setting an invalid large positive int for student's number.
   size_t max_number = TEST_CLASS_UNSIGNED_LONG_LONG_INT;
   std::cout << "Trying to set for student's number: " << max_number << '\n';
   check_setNumber((int)max_number);

   //UT: Setting an invalid large negative int for student's number.
   long long int min_number = TEST_CLASS_LONG_LONG_INT_NEGATIVE;
   std::cout << "Trying to set for student's number: " << min_number << '\n';
   check_setNumber((int)min_number);

   //UT: Setting an invalid char for student's number.
   char symbol = TEST_CLASS_CHAR_LETTER;
   std::cout << "Trying to set for student's number: " << symbol << '\n';
   check_setNumber((int)symbol);

   symbol = TEST_CLASS_CHAR_NUMBER;
   std::cout << "Trying to set for student's number: " << symbol << '\n';
   check_setNumber((int)symbol);

   symbol = TEST_CLASS_CHAR_SYMBOL;
   std::cout << "Trying to set for student's number: " << symbol << '\n';
   check_setNumber((int)symbol);
}

void TestClass :: test_setName()
{
   std::cout << '\n' << "Testing student::setName()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_setName();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_setName();
   std::cout << "END" << '\n';
}

void TestClass :: test_valid_setName()
{
   std::string new_name;
   //UT: Testing with a valid string for student's name.
   new_name = TEST_CLASS_VALID_STRING;
   check_setName(new_name);

   //UT: Testing with a valid string with dash for student's name.
   new_name = TEST_CLASS_VALID_STRING_DASH;
   check_setName(new_name);

   //UT: Testing with a valid char letter for student's name.
   new_name = TEST_CLASS_CHAR_LETTER;
   check_setName(new_name);
}

void TestClass :: test_invalid_setName()
{
   std::string invalid_new_name;
   //UT: Testing with invalid string for student's name.
   invalid_new_name = TEST_CLASS_INVALID_STRING;
   check_setName(invalid_new_name);

   //UT: Testing with invalid char symbol for student's name.
   invalid_new_name = TEST_CLASS_CHAR_SYMBOL;
   check_setName(invalid_new_name);

   //UT: Testing with invalid numerical char for student's name.
   invalid_new_name = TEST_CLASS_CHAR_NUMBER;
   check_setName(invalid_new_name);
}

void TestClass :: check_setName(const std::string& new_name)
{
   name = " ";
   number = 0;
   student test_student(number, name);
   std::cout << "Testing with student's name: " << name << " and student's number: " << number << '\n';
   try
   {
      std::cout << "Setting new student's name: " << new_name <<'\n';
      test_student.setName(new_name);
      IS_TRUE(test_student.getName() == new_name);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_addNewGrade()
{
   std::cout << '\n' << "Testing student::addNewGrade()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_addNewGrade();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_addNewGrade();
   std::cout << "END" << '\n';
}

void TestClass :: test_valid_addNewGrade()
{
   number = TEST_CLASS_POSITIVE_INT;
   name = TEST_CLASS_VALID_STRING;
   student test_student(number, name);

   //UT: Trying to add a float grade, which is in the right scope.
   for(int i = test_student.getNumberGrades(); i < MAX_GRADES; ++i)
   {
      float new_grade = LOWEST_GRADE + (rand()/(RAND_MAX / (HIGHEST_GRADE - LOWEST_GRADE)));
      check_addNewGrade(test_student, new_grade);
   }
}

void TestClass :: test_invalid_addNewGrade()
{
   number = TEST_CLASS_POSITIVE_INT;
   name = TEST_CLASS_VALID_STRING;
   student test_student(number, name);

   //UT: Trying to add a numerical char for grade.
   char symbol = TEST_CLASS_CHAR_NUMBER;
   std::cout << "Trying to add as a grade the symbol: " << symbol << '\n';
   check_addNewGrade(test_student, symbol);

   //UT: Trying to add an alphabetical char for grade.
   symbol = TEST_CLASS_CHAR_LETTER;
   std::cout << "Trying to add as a grade the symbol: " << symbol << '\n';
   check_addNewGrade(test_student, symbol);

   //UT: Trying to add a char for grade.
   symbol = TEST_CLASS_CHAR_SYMBOL;
   std::cout << "Trying to add as a grade the symbol: " << symbol << '\n';
   check_addNewGrade(test_student, symbol);

   //UT: Trying to add a grade out of scope.
   float new_grade = TEST_CLASS_BIG_POSITIVE_FLOAT;
   std::cout << "Trying to add as a grade one, which is too high: " << new_grade << '\n';
   check_addNewGrade(test_student, new_grade);

   //UT: Trying to add a grade out of scope.
   new_grade = TEST_CLASS_NEGATIVE_FLOAT;
   std::cout << "Trying to add as a grade one, which is too low: " << new_grade << '\n';
   check_addNewGrade(test_student, new_grade);

   //UT: Trying to add too many grades.
   for(int i = test_student.getNumberGrades(); i <= MAX_GRADES; ++i)
   {
      new_grade = LOWEST_GRADE + (rand()/(RAND_MAX / (HIGHEST_GRADE - LOWEST_GRADE)));
      check_addNewGrade(test_student, new_grade);
   }
}

void TestClass :: check_addNewGrade(student& test_student, const float new_grade)
{
   int count_grades_received = test_student.getNumberGrades();
   try
   {
      std::cout << "Trying to add a new grade: " << new_grade << '\n';
      test_student.addNewGrade(new_grade);
      IS_TRUE(test_student.getNumberGrades() == (count_grades_received + 1));
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
   catch(const std::length_error& e1)
   {
      std::cerr << e1.what() << '\n';
   }   
}

void TestClass :: test_getAverageGrade()
{
   std::cout << '\n' << "Testing student::getAverageGrade()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_getAverageGrade();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_getAverageGrade();
   std::cout << "END" << '\n';
}

void TestClass :: test_valid_getAverageGrade()
{
   grades.clear();
   grades = {2, 2.5, 4.45, 6.00, 3.8, 5.6, 5.5, 7};
   std::random_shuffle(grades.begin(), grades.end());
   float avg_grade{};
   try
   {
      avg_grade = calculate_average(grades);
   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }

   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: Check if getAverageGrade calculates correctly the average of all the grades of a student, when 
   //they are present.
   for(float grade : grades)
   {
      check_addNewGrade(test_student, grade);
   }
   try
   {
      IS_TRUE(test_student.getAverageGrade() == avg_grade);
   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }
}

float TestClass :: calculate_average(std::vector<float>& grades)
{
   float sum{};
   int count{};
   for(float grade : grades)
   {
      if(grade >= LOWEST_GRADE && grade <= HIGHEST_GRADE)
      {
         sum += grade;
         ++count;
      }
   }
   if(count == 0)
   {
      throw std::logic_error("There should be grades in order to calculate their average.");
   }
   return (sum/count);
}

void TestClass :: test_invalid_getAverageGrade()
{
   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);
   float avg_grade{};

   //UT: Trying to get the average for a student without any grades.
   try
   {
      std::cout << "Trying to calculate the average for a student without any grades. " << '\n';
      IS_TRUE (test_student.getAverageGrade() == avg_grade);

   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }   
}

void TestClass :: test_getMaxGrade()
{
   std::cout << '\n' << "Testing student::getMaxGrade()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_getMaxGrade();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_getMaxGrade();
   std::cout << "END" << '\n';
}

void TestClass :: fill_with_random_grades(student& test_student)
{
   int count = 1 + (rand() / (RAND_MAX / (MAX_GRADES - 1)));
   for(int i = test_student.getNumberGrades(); i < count; ++i)
   {
      float new_grade = LOWEST_GRADE + (rand()/(RAND_MAX / (HIGHEST_GRADE - LOWEST_GRADE)));
      check_addNewGrade(test_student, new_grade);
      grades.push_back(new_grade);
   }
}

void TestClass :: test_valid_getMaxGrade()
{
   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: Testing if getMaxGrade works for student who has at least 1 grade.
   //We will get random number of grades and random grades in the wanted scope.
   grades.clear();
   fill_with_random_grades(test_student);
   try
   {
      std::cout << "Testing the correctness of the maximum grade when there is at least 1 grade. " <<'\n';
      IS_TRUE(test_student.getMaxGrade() == *(std::max_element(grades.begin(), grades.end())));
   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_invalid_getMaxGrade()
{
   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: Testing if getMaxGrade works for student who has no grades.
   grades.clear();
   try
   {
      std::cout << "Testing the correctness of the maximum element, when no grades are present. "<<'\n';
      IS_TRUE(test_student.getMaxGrade() == *(std::max_element(grades.begin(), grades.end())));
   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_getMinGrade()
{
   std::cout << '\n' << "Testing student::getMinGrade()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_getMinGrade();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_getMinGrade();
   std::cout << "END" << '\n';
}

void TestClass :: test_valid_getMinGrade()
{
   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: Testing if getMinGrade works for student who has at least 1 grade.
   //We will get random number of grades and random grades in the wanted scope.
   grades.clear();
   fill_with_random_grades(test_student);
   try
   {
      std::cout << "Testing the correctness of the minimum grade when there is at least 1 grade. " <<'\n';
      IS_TRUE(test_student.getMinGrade() == *(std::min_element(grades.begin(), grades.end())));
   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_invalid_getMinGrade()
{
   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: Testing if getMinGrade works for student who has no grades.
   grades.clear();
   try
   {
      std::cout << "Testing the correctness of the minimum element, when no grades are present. "<<'\n';
      IS_TRUE(test_student.getMinGrade() == *(std::min_element(grades.begin(), grades.end())));
   }
   catch(const std::logic_error& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_getGrades()
{
   std::cout << '\n' << "Testing student::getGrades()" << '\n';
   std::cout << "Testing GOOD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_valid_getGrades();
   std::cout << "END" << '\n';

   std::cout << "Testing BAD weather scenario." << '\n';
   std::cout << "START..." << '\n';
   test_invalid_getGrades();
   std::cout << "END" << '\n';
}

void TestClass :: test_valid_getGrades()
{
   name = TEST_CLASS_VALID_STRING;
   number = TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: We will check if the vector grades of the student class keeps the right grades in the right order.
   grades.clear();
   fill_with_random_grades(test_student);
   check_are_received_grades_the_same(test_student, grades);
}

void TestClass :: test_invalid_getGrades()
{
   name = TEST_CLASS_VALID_STRING;
   number =TEST_CLASS_POSITIVE_INT;
   student test_student(number, name);

   //UT: Check when no grades are received.
   grades.clear();
   check_are_received_grades_the_same(test_student, grades);
}

void TestClass :: check_are_received_grades_the_same(student& test_student, std::vector<float>& temp_grades)
{
   std::cout << "Testing if the student has the same amount of grades as we keep in the vector. " << '\n';
   IS_TRUE(temp_grades.size() == test_student.getNumberGrades());
   std::cout << "Comparing each grade..." << '\n';
   for(int i = 0; i < temp_grades.size(); ++i)
      {
         //getGrades is printing the student's grades.
         float student_grade = test_student.getGrades()[i];
         std::cout << "Comparing: " << temp_grades[i] << " and " << student_grade << "." << '\n'; 
         IS_TRUE(temp_grades[i] == student_grade);
      }
}

int main()
{
   TestClass myTest;
   myTest.test_getNumber();
   myTest.test_getName();
   myTest.test_setNumber();
   myTest.test_setName();
   myTest.test_addNewGrade();
   myTest.test_getAverageGrade();
   myTest.test_getMaxGrade();
   myTest.test_getMinGrade();
   myTest.test_getGrades();

   return 0;
}