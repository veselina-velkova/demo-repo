//@file: my_class.h
//@author: Veselina Velkova
//@brief: This file contains the prototypes of the functions in the student class.
//@date: 18.04.2023

#pragma once
#include<string>

//These constants are useful because in real life students can not have infinite number of grades.
//Usually, for each subject there is minimum and maximum number of grades that each student should have. 
const int MIN_GRADES = 5;
const int MAX_GRADES = 20;

class student
{
    std::string name;
    int number;
    int numberGrades;
    int currentCapacity = 5;
    float sum = 0.0;
    float* grades = new float [currentCapacity];

    void resizeGrades();

    public:
    student();
    int getNumber();
    std::string getName();
    void setNumber(int num);
    void setName(std::string newName);
    int getNumberGrades();
    void addNewGrade(float grade);
    bool areGrades();
    float getAverageGrade();
    float getMaxGrade();
    float getMinGrade();
    float* getGrades();
    ~student();
};