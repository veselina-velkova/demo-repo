//@file: test_my_class.hpp
//@author: Veselina Velkova (veselina.velkova@strypes.eu)
//@brief: Header file for the test_my_class.cpp file, which contains all the unit test cases.
//@version: 0.1
//@date: 21.04.2023

#include<iostream>
#pragma once

const int MIN_GRADES = 5;
const int MAX_GRADES = 20;

class TestClass
{
    private:
    std::string name;
    int number;
    int numberGrades;
    int currentCapacity = 5;
    float sum = 0.0;
    float* grades = new float [currentCapacity];

    public:
    TestClass();
    TestClass(int num, std::string full_name);
    ~TestClass();

    /* Methods */
    
};