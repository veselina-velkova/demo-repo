#include<string>
#include<vector>
#include<sstream>
#include<iostream>

struct result
{
    int sum{};
    std::string words{};
};

std::string readInput()
{
    std::string line;
    getline(std::cin, line);
    return line;
}

std::vector<std::string> parseStrings(const std::string& input)
{
    std::vector<std::string> result;
    std::string word;

    std::istringstream stream (input);
    while(stream >> word)
    {
        result.emplace_back(word);
    }
    return result;
}

result separateInput(const std::string& input)
{
    result finalResult;
    std::vector<std::string> temp = parseStrings(input);

    for(auto word : temp)
    {
        try
        {
            finalResult.sum += stoi(word);
        }
        catch(std::invalid_argument)
        {
            finalResult.words += word;
            finalResult.words += " ";
            //std::cerr << "Trying to convert non-numerical string to int." << std::endl;
        }
    }
    return finalResult;
}

void print(const result& data)
{
    std::cout << data.sum << '\n';
    std::cout << data.words << std::endl;
}

int main()
{
    const std::string input = readInput();
    const result separatedData = separateInput(input);
    print(separatedData);
    
    return 0;
}