#include<string>
#include<iostream>

std::string readInput()
{
    //Here I understand from the description that we enter just 1 line text.
    std::string input{};
    getline(std::cin, input);
    return input; 
}

void titleCase(std::string& input)
{
    for(auto it = input.begin(); it != input.end(); ++it)
    {
        if(!isalpha(*it))
        {
            continue;
        }
        else if(isalpha(*(it-1)))
        {
            //The previous symbol is also a letter.
            continue;
        }
        else
        {
            //Start of new word.
            *it = toupper(*it);
        }
    }
}

void print(const std::string& input)
{
    std::cout << input << std::endl; 
    //Not sure if we need a separate function for such a basic operation.
}

int main()
{
    std::string input = readInput();
    titleCase(input);
    print(input);

    return 0;
}