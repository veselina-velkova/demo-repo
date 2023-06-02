/**
 * @file decryption.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

//message consists of ascii 32 and a-z
//print the largest group that can be decrypted
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>

const std::string END_SECOND_PART_INPUT = "[encryptions]";
const std::string END_THIRD_PART_INPUT = "[end]";

std::string readInput(std::vector<std::string>& messages, std::vector<std::string>& tables)
{
    std::string currLine{};
    std::string beginning{};
    getline(std::cin, beginning);
    while(true)
    {
        getline(std::cin, currLine);
        if(currLine != END_SECOND_PART_INPUT)
        {
            messages.emplace_back(currLine);
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        getline(std::cin, currLine);
        if(currLine != END_THIRD_PART_INPUT)
        {
            tables.emplace_back(currLine);
        }
        else
        {
            break;
        }
    }
    return beginning;
}

std::string decryption(const std::string& message, const std::string& encryptionTable)
{
    std::map<char, char> decryptionTable{};
    for(auto it = encryptionTable.begin(); it != encryptionTable.end(); ++it)
    {
        int index = it - encryptionTable.begin();
        decryptionTable[encryptionTable[index]] = char('a' + index);
    }
    std::string originalMessage = "";
    for(const char ch : message)
    {
        if(!isalpha(ch))
        {
            originalMessage += ch;
        }
        else
        {
            originalMessage += decryptionTable.at(ch);
            //We don't use try and catch, because logically it shouldn't throw exception. 
        }
    }
    return originalMessage;
}

std::vector<std::string> findLargestGroupDecrypted(const std::string& start, 
                    const std::vector<std::string>& messages, const std::vector<std::string>& encryptions)
{
    //My logic here is to use a map which connects an index of an encryption to a vector of the indexes
    //of the messages which could be decrypted by it.
    //We will have a vector of all the decrypted messages.
    std::map<int, std::vector<int>> findDecryption{};
    std::vector<std::string> result{};
    const int size = start.size();
    for(auto it = messages.begin(); it != messages.end(); ++it)
    {
        int indexMessage = it - messages.begin();
        bool encryptionFound = false;
        for(auto iter = encryptions.begin(); iter != encryptions.end(); ++iter)
        {
            int indexEnctyption = iter - encryptions.begin();
            std::string decrypted = decryption(*it, *iter);
            if(decrypted.substr(0, size) != start)
            {
                continue;
            }
            else
            {
                findDecryption[indexEnctyption].push_back(indexMessage);
                encryptionFound = true;
                result.emplace_back(decrypted);
                break;
            }
        }
        if(!encryptionFound)
        {
            result.emplace_back(*it);
        }
    }
    int largestGroup = 0;
    int indexLargestGroup = 0;
    for(auto& [key, value] : findDecryption)
    {
        if(value.size() > largestGroup)
        {
            indexLargestGroup = key;
            largestGroup = value.size();
        }
    }
    std::vector<std::string> finalResult{};
    finalResult.reserve(largestGroup);
    for(auto it = result.begin(); it != result.end(); ++it)
    {
        int index = it - result.begin();
        if(std::find(findDecryption.at(indexLargestGroup).begin(), findDecryption.at(indexLargestGroup).end(), 
                                                        index) != findDecryption.at(indexLargestGroup).end())
        {
            finalResult.emplace_back(*it);
        }
    }
    return finalResult;
}

void print(const std::vector<std::string>& result)
{
    for(auto& message : result)
    {
        std::cout << message << '\n';
    }
    std::cout << std::endl;
}

int main()
{
    std::string start{};
    std::vector<std::string> messages{};
    std::vector<std::string> encryptionTables{};
    start = readInput(messages, encryptionTables);
    std::vector<std::string> result = findLargestGroupDecrypted(start, messages, encryptionTables);
    print(result);
    return 0;
}