/**
 * @file miners.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include<map>
#include<string>
#include<queue>
#include<iostream>

const std::string STOP_WHILE_LOOP = "stop";
constexpr int EMPTY = 0;

//Here I am not sure is it a good idea to read the input and sum the quantities in the same function.
//But like this we can use the functionalities of the map.
std::map<std::string, int> extractInput(std::queue<std::string>& keepOrderResources)
{
    std::map<std::string, int> resources{};
    while(true)
    {
        std::string resource{};
        int quantity{};
        std::cin >> resource;
        if(resource == STOP_WHILE_LOOP)
        {
            break;
        }
        std::cin >> quantity;
        if(resources[resource] == EMPTY)
        {
            keepOrderResources.push(resource);
        }
        resources[resource] += quantity;
    }
    return resources;
}

//Here we can empty the real queue and there is no problem, because its function was just to help us.
void print(const std::map<std::string, int>& results, std::queue<std::string>& keepOrder)
{
    while(!keepOrder.empty())
    {
        std::string resource = keepOrder.front();
        std::cout << resource << " -> " << results.at(resource) << '\n';
        keepOrder.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::queue<std::string> keepOrderResources{};
    std::map<std::string, int> input = extractInput(keepOrderResources);
    print(input, keepOrderResources);

    return 0;
}