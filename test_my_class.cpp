#include<limits>
#include<cmath>
#include<iostream>
#include "my_class.h"
#include "test_my_class.hpp"

#define _USE_MATH_DEFINES

#define IS_TRUE(x) {if(!(x)) std::cout<<__FUNCTION__<<" failed on line "<<__LINE__<<std::endl;}

#define TEST_CLASS_POSITIVE_DOUBLE (M_PI)
#define TEST_CLASS_NEGATIVE_DOUBLE (-M_PI)

#define TEST_CLASS_POSITIVE_FLOAT (5.5)
#define TEST_CLASS_NEGATIVE_FLOAT (-3.5)

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
   std::string name = TEST_CLASS_VALID_STRING;
   
   //UT: Without dash in the name. Positive int for student's number.
   int num = TEST_CLASS_POSITIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: Without dash in the name. Negative int for student's number.
   num = TEST_CLASS_NEGATIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: Without dash in the name. Large positive int for student's number.
   num = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_try_catch_getNumber(num, name);

   //UT: Without dash in the name. Large negative int for student's number.
   num = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: Without dash in the name. Corner case large negative int for student's number.
   num = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: Without dash in the name. Corner case large positive int for student's number.
   num = TEST_CLASS_LARGE_POSITIVE_INT;
   check_try_catch_getNumber(num, name);

   name.clear();
   name = TEST_CLASS_VALID_STRING_DASH;

   //UT: With dash in the name. Positive int for student's number.
   num = TEST_CLASS_POSITIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: With dash in the name. Negative int for student's number.
   num = TEST_CLASS_NEGATIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: With dash in the name. Large positive int for student's number.
   num = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_try_catch_getNumber(num, name);

   //UT: With dash in the name. Large negative int for student's number.
   num = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: With dash in the name. Corner case large negative int for student's number.
   num = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(num, name);

   //UT: With dash in the name. Corner case large positive int for student's number.
   num = TEST_CLASS_LARGE_POSITIVE_INT;
   check_try_catch_getNumber(num, name);
}

void TestClass :: check_try_catch_getNumber(const int num, const std::string& name)
{
   try
   {
      std::cout << "Testing with student's name: " << name << " and number: " << num << '\n';
      student test_student(num, name);
      IS_TRUE(test_student.getNumber() == num);
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
}

void TestClass :: test_invalid_getNumber()
{
   std::string invalid_name = TEST_CLASS_INVALID_STRING;
   int num;

   //UTs: Invalid string for student's name and valid int for student's number.
   num = TEST_CLASS_POSITIVE_INT;
   check_try_catch_getNumber(num, invalid_name);
   
   num = TEST_CLASS_NEGATIVE_INT;
   check_try_catch_getNumber(num, invalid_name);

   num = TEST_CLASS_LARGE_POSITIVE_INT;
   check_try_catch_getNumber(num, invalid_name);
   
   num = TEST_CLASS_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(num, invalid_name);

   num = TEST_CLASS_NOT_THAT_LARGE_POS_INT;
   check_try_catch_getNumber(num, invalid_name);
   
   num = TEST_CLASS_NOT_THAT_LARGE_NEGATIVE_INT;
   check_try_catch_getNumber(num, invalid_name);

   //We are going to check with just one of the valid strings for student's name, because we will already
   //know if they work correctly from the GOOD case scenario.
   name.clear();
   std::string name = TEST_CLASS_VALID_STRING;

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
   std::string name;
   int number = TEST_CLASS_POSITIVE_INT;

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

void TestClass :: check_setNumber(const int number, const std::string& name)
{
   try
   {
      std::cout << "Testing with student's "
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
   
}

void TestClass :: test_valid_setNumber()
{
   //Here the student's name doesn't matter, so that we are going to use valid string for student's name 
   //without a dash.
   std::string name = TEST_CLASS_VALID_STRING;
   int number;

   //UT: Valid string for student's name. Valid positive int for student's number.
   number = TEST_CLASS_POSITIVE_INT;

}

void TestClass :: test_invalid_setNumber()
{

}

int main()
{
   TestClass myTest;
   myTest.test_getNumber();
   myTest.test_getName();

   return 0;
}