// studentClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "my_class.hpp"

const int AMOUNT_OF_GRADES = 29;

int main()
{
	//The purpose of this client console application is simply to create an object student with my name and my number in class 
	//and then calculate my average grade.
	//This should demonstrate the idea behind dynamic linked libraries.
	float grade{};
	int num = 5;
	std::string name = "Veselina Velkova";
	Student Vesi(num, name);
	for (int i = 0; i < AMOUNT_OF_GRADES; ++i)
	{
		std::cin >> grade;
		Vesi.addNewGrade(grade);
	}

	std::cout << Vesi.getAverageGrade();
}
