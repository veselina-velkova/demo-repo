/**
 * @file reverse_words.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<iostream>

std::vector<std::string> readInput()
{
    std::vector<std::string> lines;
    std::string input{};
    std::string singleWord{};

    getline(std::cin, input);
    //With do-while we would keep 'end' also in the vector.
    while(input != "end")
    {
        std::istringstream words (input);
        while(words >> singleWord)
        {
            lines.emplace_back(singleWord);
        }
        words.clear();
        words.str("");
        getline(std::cin, input);
        //Not sure if it is needed to clear our stream since we won't reuse it and it will die when it goes 
        //out of scope.
    } 
    return lines;
}

void print(const std::vector<std::string>& input)
{
    for(auto it = input.begin(); it != input.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> input = readInput();
    std::reverse(input.begin(), input.end());
    //We can use the function reverse from the algorithm library and there is no need to write our own implementation
    //since it won't be more optimal. 
    //The problem I see is that now input is not const, so if we will need the original input later in the task
    //we could make a copy.
    print(input);

    return 0;
}