/**
 * @file minesweeper.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include<vector>
#include<array>
#include<iostream>

constexpr char MINE_MARKER = '!';
struct cell
{
    cell()
    {
        row = 0;
        col = 0;
    }
    cell(int inputRow, int inputCol)
    {
        row = inputRow;
        col = inputCol;
    }
    int row{};
    int col{};
};

std::vector<std::vector<char>> readInput()
{
    int rows{};
    int cols{};
    std::cin >> rows >> cols;
    std::vector<std::vector<char>> matrix (rows, std::vector<char>(cols));
    
    for(auto& row : matrix)
    {
        for(char& el : row)
        {
            std::cin >> el;
        }
    }
    return matrix;
}

std::vector<cell> generateMines(const std::vector<std::vector<char>>& matrix)
{
    std::vector<cell> mines;
    //Below we can do just ordinary for loops through the matrix.
    for(auto it = matrix.begin(); it != matrix.end(); ++it)
    {
        for(auto iter = (*it).begin(); iter != (*it).end(); ++iter)
        {
            if(*iter == MINE_MARKER)
            {
                cell mine;
                mine.row = it - matrix.begin();
                mine.col = iter - (*it).begin();
                mines.push_back(mine);
            }
        }
    }
    return mines;
}

bool isInside(const std::vector<std::vector<char>>& matrix, const cell& Cell)
{
    if(Cell.col < 0 || Cell.row < 0)
    {
        return false;
    }
    if (matrix.size() <= Cell.row)
    {
        return false;
    }
    if (matrix.front().size() <= Cell.col)
    {
        return false;
    }
    return true;
}

//In the original solution they did this with the askii codes of the numbers, but i think it would be
//better to use int, because we do not have any restrictions about the sizes of the matrix, nor for
//the amount of mines.
std::vector<std::vector<int>> expandMines(const std::vector<std::vector<char>>& matrix, 
                                          const std::vector<cell>& mines)
{
    std::vector<std::vector<int>> result (matrix.size(), std::vector<int>(matrix.front().size(), 0));
    constexpr int COUNT_CELLS_NEAR_MINE = 9;
    const std::array<cell, COUNT_CELLS_NEAR_MINE> dirs
    {
        cell(0,0), //curr pos
        cell(0,1), //right
        cell(0,-1), //left
        cell(1,0), //down
        cell(1,1), //down right
        cell(1,-1), //down left 
        cell(-1,0), //up
        cell(-1,-1), //up left
        cell(-1,1) //up right
    };
    for(const cell& mine : mines)
    {
        for (const cell& direction : dirs)
        {
            cell currCELL = mine;
            currCELL.row += direction.row;
            currCELL.col += direction.col;
            if(isInside(matrix, currCELL))
            {
                ++result[currCELL.row][currCELL.col];
            }
        }
    }
    return result;
}

void printExpandedMatrix(const std::vector<std::vector<int>>& result)
{
    for(const auto& row : result)
    {
        for(const int el : row)
        {
            std::cout << el << " ";
        }
        std::cout << std :: endl;
    }
}

int main()
{
    const std::vector<std::vector<char>> matrix = readInput();
    const std::vector<cell> mines = generateMines(matrix);
    const std::vector<std::vector<int>> output = expandMines(matrix, mines);
    printExpandedMatrix(output);

    return 0;
}