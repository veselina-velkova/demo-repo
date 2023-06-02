/**
 * @file odd_occurrences.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<iostream>

std::vector<std::string> readInput()
{
    std::string input{};
    getline(std::cin, input);

    std::vector<std::string> words;
    std::istringstream stream (input);
    std::string singleWord{};
    while(stream >> singleWord)
    {
        words.emplace_back(singleWord);
    }
    return words;
}

std::string turnToLowerCase(const std::string& word)
{
    std::string newWord = "";
    for(auto& ch : word)
    {
        //I think it will be faster to change directly the word, but I had a problem with the const keys.
        newWord += tolower(ch);
    }
    return newWord;
}

std::map<std::string, size_t> countOccurrences(const std::vector<std::string>& words, std::queue<std::string>& sequence)
{
    std::map<std::string, size_t> countingOccurrences{};
    for(auto& word : words)
    {
        const std::string key = turnToLowerCase(word);
        if(countingOccurrences[key]==0)
        {
            sequence.push(key);
        }
        ++countingOccurrences[key];
    }
    return countingOccurrences;
}

void print(const std::map<std::string, size_t>& countingOccurrences, std::queue<std::string>& sequence)
{
    while(!sequence.empty())
    {
        const std::string key = sequence.front();
        try
        {
            if(countingOccurrences.at(key) % 2 == 1)
            {
                std::cout << key << " ";
            }
        }
        catch (std::out_of_range)
        {
            std::cerr << "Unexpected error with the elements in the queue." << std::endl;
        }
        sequence.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> input = readInput();
    std::queue<std::string> sequence{};
    std::map<std::string, size_t> countingOccurrences = countOccurrences(input, sequence);
    print(countingOccurrences, sequence);
    return 0;
}