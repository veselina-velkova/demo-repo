/**
 * @file unused.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include<string>
#include<set>
#include<iostream>

constexpr char BEGIN_LETTER = 'a';
constexpr char END_LETTER = 'z';

std::string readInput()
{
    std::string line{};
    getline(std::cin, line);
    return line;
}

std::set<char> foundLetters(const std::string& input)
{
    std::set<char> letters{};
    for(char el : input)
    {
        //The input will contain only lower case letters.
        letters.insert(el);
    }
    return letters;
}

void printResult(const std::set<char>& foundLetters)
{
    char letter = BEGIN_LETTER;
    while(letter != (END_LETTER + 1))
    {
        if(foundLetters.find(letter) == foundLetters.end())
        {
            std::cout << letter;
        }
        ++letter;
    }
    std::cout << std::endl;
}

int main()
{
    std::string input = readInput();
    std::set<char> letters = foundLetters(input);
    printResult(letters);

    return 0;
}