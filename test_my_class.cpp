//@file: test_my_class.cpp
//@author: Veselina Velkova (veselina.velkova@strypes.eu)
//@brief: This file contains all unit test cases.
//@version: 0.1
//@date: 21.04.2023

#include<iostream>
#include "my_class.h"

#define IS_TRUE(x) {if(!(x)) std::cout<<__FUNCTION__<<" failed on line "<<__LINE__<<std::endl;}

#define TEST_CLASS_POSITIVE_DOUBLE (3.141592653589793238462643383279502884197169)
#define TEST_CLASS_NEGATIVE_DOUBLE (-3.141592653589793238462643383279502884197169)

#define TEST_CLASS_POSITIVE_FLOAT (5.5)
#define TEST_CLASS_NEGATIVE_FLOAT (-3.5)

#define TEST_CLASS_POSITIVE_INT (6)
#define TEST_CLASS_NEGATIVE_INT (-4)

#define TEST_CLASS_STRING ("I AM a very Long NAmE.")
#define TEST_CLASS_CHAR_LETTER ('A')
#define TEST_CLASS_CHAR_NUMBER ('5')
#define TEST_CLASS_CHAR_SYMBOL ('@')

TestClass::TestClass()
{
    cout << "What is student's number in class?" << endl;
    cin >> number;
    cout << "What's the student's name?" << endl;
    cin.ignore();
    getline(cin, name);
    numberGrades = 0;
}

TestClass::TestClass(int num, std::string full_name)
{
    number = num;
    name = full_name;
}

TestClass::~TestClass()
{
    delete[] grades;
    grades = nullptr;
}
