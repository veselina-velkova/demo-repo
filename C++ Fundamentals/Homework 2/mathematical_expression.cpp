/**
 * @file mathematical_expression.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include<string>
#include<iostream>

/*
*From the description of the problem I understand that only small brackets can be used ().
*Also, as we do not have to check if the signs or the variables are correct, I assume that we do not have to 
*check if any other type of brackets is used. 
*Rules:
*1. An expression can not start with a closing bracket.
*2. The amount of opening brackets, should be equal to the amount of closing ones.
*3. Before we have a closing bracket, we have to have an opening one.
*An idea for optimisation is not to pass the whole expression element by element, but to use find instead, 
*but I am not sure for such short expressions whether this isn't unnecessarily complicating things, because
*we will have to check if the symbol is found, as well as '(' or ')' is on earlier position.
*/

std::string readInput()
{
    std::string expression{};
    getline(std::cin, expression);
    return expression;
}

bool isCorrect(const std::string& input)
{
    int tempOpenBrackets = 0;
    for(char ch : input)
    {
        if(tempOpenBrackets < 0)
        {
            //This means that we have had a closing bracket before an opening one.
            return false;
        }
        else if(ch == '(')
        {
            //We open a new open bracket.
            tempOpenBrackets += 1;
            continue;
        }
        else if(ch == ')')
        {
            //We have closed one open bracket.
            tempOpenBrackets -= 1;
        }
    }
    return (tempOpenBrackets == 0); //All brackets should be closed.
}

void printResult(const std::string& input)
{
    std::cout << (isCorrect(input) ? "correct" : "incorrect") << std::endl;
}

int main()
{
    const std::string input = readInput();
    printResult(input);
    
    return 0;
}