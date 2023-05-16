#include<string>
#include<iostream>

void readInput(std::string& line, std::string& find, std::string& replace)
{
    getline(std::cin, line);
    getline(std::cin, find);
    getline(std::cin, replace);
}

void replaceAll(std::string& line, const std::string& find, const std::string& replace)
{
    const size_t findSize = find.size();
    size_t foundIndex = line.find(find);
    while(foundIndex != std::string::npos)
    {
        line.replace(foundIndex, findSize, replace);
        foundIndex = line.find(find, foundIndex + 1);
    }
}

void print(const std::string& input)
{
    std::cout << input << std::endl;
}

int main()
{
    std::string input{};
    std::string findStr{};
    std::string replaceStr{};

    readInput(input, findStr, replaceStr);
    replaceAll(input, findStr, replaceStr);
    print(input);

    return 0;
}