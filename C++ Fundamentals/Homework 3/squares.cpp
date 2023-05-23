#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<iostream>

bool isSquare(const int number)
{
    int squareRoot = (int) sqrt(number);
    if(squareRoot*squareRoot == number)
    {
        return true;
    }
    return false;
}

std::vector<int> readInput()
{
    std::string input{};
    getline(std::cin, input);
    std::vector<int> queueNumbers{};
    //Here I prefered using vector, because otherwise if I use queue, I will destroy it after the findSquares function.

    std::istringstream stream (input);
    int currNum{};
    while(stream >> currNum)
    {
        queueNumbers.push_back(currNum);
    }
    return queueNumbers;
}

std::priority_queue<int> findSquares(const std::vector<int>& numbers)
{
    std::priority_queue<int> squares{};
    for(int num : numbers)
    {
        if(isSquare(num))
        {
            squares.push(num);
        }
    }
    return squares;
}

//I will pass it here as a copy so that I don't destroy the original queue holding the squares.
void print(std::priority_queue<int> input)
{
    while(!input.empty())
    {
        std::cout << input.top()<<" ";
        input.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> input = readInput();
    std::priority_queue<int> squares = findSquares(input);
    print(squares);

    return 0;
}