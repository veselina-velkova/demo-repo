/*
*We are going to use string for the types of garbage and for the position in the collection.
*We are going to use list, because we can easily push back or push front.
*We are going to use array for the final collection, as we know that it has 3 elements.
*We are going to use vector for the input, because the size is chosen by the user.
*/
#include<list>
#include<string>
#include<vector>
#include<array>
#include<iostream>

constexpr int CONTAINERS_COUNT = 3;
constexpr auto GLASS_NAME = "glass";
constexpr auto METAL_NAME = "metal";
constexpr auto PLASTIC_NAME = "plastic";
constexpr auto FRONT_NAME = "front";

//We use enums when we have selected multiple choices.
enum CONTAINERS
{
    //Like this we can give them as indexes in the array (0-2).
    GLASS,
    METAL,
    PLASTIC,
    UNKNOWN
};

enum class location {FRONT, BACK};

struct garbage
{
    CONTAINERS type;
    location dir = location::FRONT;
};

//The structure of the solution should be 1) Input 2) Solution 3) Output
std::vector<garbage> readInput()
{
    int size{};
    std::cin >> size;
    std::vector<garbage> entries (size);

    std::string strType{};
    std::string strDir{};
    for (garbage& entry : entries) //We pass it by referance, because otherwise it makes temporary copy.
    //And we do not actually fill the vector.
    {
        std::cin >> strType >> strDir;
        entry.dir = (strDir == FRONT_NAME ? location::FRONT : location::BACK);
        if(strType == GLASS_NAME)
        {
            entry.type = GLASS;
        }
        else if (strType == METAL_NAME)
        {
            entry.type = METAL;
        }
        else if (strType == PLASTIC_NAME)
        {
            entry.type = PLASTIC;
        }
        else
        {
            entry.type = UNKNOWN;
        }
    }
    return entries;
}

std::array<std::list<int>, CONTAINERS_COUNT> sortGarbage (const std::vector<garbage>& entries)
{
    std::array<std::list<int>, CONTAINERS_COUNT> collections;
    int uniqueID = 1;
    for(const garbage& entry : entries)
    {
        if (entry.type == UNKNOWN)
        {
            continue;
        }
        else
        {
            int idx = entry.type;
            if(entry.dir == location::FRONT)
            {
                collections[idx].push_front(uniqueID);
            }
            else
            {
                collections[idx].push_back(uniqueID);
            }
            ++uniqueID;
        }
    }
    return collections;
}

void print(const std::array<std::list<int>, CONTAINERS_COUNT>& collections)
{
    const std::array<std::string, CONTAINERS_COUNT> name = {GLASS_NAME, METAL_NAME, PLASTIC_NAME};
    int index = 0;
    for(const auto& collect : collections)
    {
        if(!collect.empty())
        {
            std::cout << name[index] << " - "; 
            for(const int num : collect)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        ++index;
    }
}

int main()
{
    const std::vector<garbage> entries = readInput();
    const std::array<std::list<int>, CONTAINERS_COUNT> collection = sortGarbage(entries);
    print(collection);

    return 0;
}