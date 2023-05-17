#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>

std::string readInput()
{
    std::string input{};
    getline(std::cin, input);
    return input;
}

std::vector<std::string> parseStrings(const std::string& input)
{
    std::vector<std::string> separatedStr;
    std::string singleStr{};
    std::istringstream stream(input);
    while(stream >> singleStr)
    {
        separatedStr.emplace_back(singleStr);
    }
    return separatedStr;
}

std::vector<int> extractNumbers (const std::vector<std::string>& separatedWords)
{
    std::vector<int> numbers (separatedWords.size());
    for(auto element : separatedWords)
    {
        int num{};
        for(char ch : element)
        {
            if(!isdigit(ch))
            {
                continue;
            }
            else
            {
                num *= 10;
                num += (int)(ch - '0');
            }
        }
        numbers.push_back(num);
    }
    return numbers;
}

int maxElement(const std::string& input)
{
    std::vector<int> numbers = extractNumbers(parseStrings(input));
    return *(std::max_element(numbers.begin(), numbers.end()));
}

int main()
{
    const std::string input = readInput();
    std::cout << maxElement(input) <<std::endl;
    return 0;
}