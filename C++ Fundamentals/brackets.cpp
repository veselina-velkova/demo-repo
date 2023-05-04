#include<vector>
#include<string>
#include<iostream>

std::vector<char> readInput()
{
    std::string input;
    std::cin>>input;
    std::vector<char> brackets;

    for(auto it = input.begin(); it != input.end(); ++it)
    {
        brackets.emplace_back(*it);
    }

    return brackets;
}

bool isValid(const std::vector<char>& brackets)
{
    std::vector<char> temp;
    char prev = brackets.front();
    if(prev == ']' || prev == '}' || prev == ')')
    {
        //We can not start with a closing bracket.
        return false;
    }
    temp.push_back(prev);

    for(auto it = brackets.begin() + 1; it != brackets.end(); ++it)
    {
        prev = temp.back(); 
        if(prev == '[' && *it == '{')
        {
            return false;
        }
        if(prev == '(' && (*it == '[' || *it == '{'))
        {
            return false;
        }
        //Like this we forbid to open higher class brackets within lower ones.
        //We don't need to check for the closing ones, because a closing bracket can be only of the type 
        //of the last open one.
        if(*it == ')' && prev != '(')
        {
            return false;
        }
        else if(*it == ']' && prev != '[')
        {
            return false;
        }
        else if(*it == '}' && prev != '{')
        {
            return false;
        }
        else if(*it == ']' || *it == '}' || *it == ')')
        {
            temp.pop_back();
            continue;
            //Here we remove the bracket, which already found its match.
        }
        else
        {
            temp.push_back(*it);
        }
    }
    return temp.empty();
    //Because in the end every bracket should have its match.
}

int main()
{
    std::vector<char> brackets = readInput();
    if(isValid(brackets))
    {
        std::cout << "valid" << std::endl;
    }
    else
    {
        std::cout << "invalid" << std::endl;
    }

    return 0;
}