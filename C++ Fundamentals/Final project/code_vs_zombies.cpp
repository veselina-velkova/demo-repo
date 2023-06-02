/**
 * @file code_vs_zombies.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

constexpr double UNITS_PER_STEP_ZOMBIE = 400.0;
constexpr double UNITS_PER_STEP_ASH = 1000.0;
constexpr int SHOOTING_RADIUS = 2000;
struct Zombie
{
    int zombieId{};
    std::pair<int, int> coordinates{};
    std::pair<int, int> nextCoordinates{};
};

struct Human
{
    int humanId{};
    std::pair<int, int> coordinates{};
};

//We will need the function below to calculate the distances between zombies and humans.
int dist(int x1, int y1, int x2, int y2)
{
    return floor(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

//The idea is to protect the human, who is in greatest danger.
//We do not have to go to him, since we can protect him from 2000 units distance.
void findTheMinDistBetweenPersonAndAZombie(const std::vector<Human>& humans, std::pair<int, int>& target,
                                        const std::vector<Zombie>& zombies, int AshX, int AshY)
{
    int minDist = INT32_MAX;
    //The distance is maximum sqrt(16000^2 + 9000^2), which is rounding to 18358. So INT32_MAX is absolutely enough
    //for our purposes and there is no need to use unsigned long long int
    for(auto& human : humans)
    {
        const Zombie* closestZombie;
        int zombieMinDist = INT32_MAX; 
        //In zombieMinDist we will keep the distance to the closest zombie for the current person.
        for(auto& zombie : zombies)
        {
            int currDist = dist(human.coordinates.first, human.coordinates.second, zombie.coordinates.first, zombie.coordinates.second);
            if(currDist < zombieMinDist)
            {
                zombieMinDist = currDist;
                closestZombie = &zombie;
            }
        }
        if(zombieMinDist < minDist)
        {
            //We have to check is it possible to save him. Aka to go there before the zombie.
            int distToAsh = dist(human.coordinates.first, human.coordinates.second, AshX, AshY);
            if((zombieMinDist / UNITS_PER_STEP_ZOMBIE) >= std::max((distToAsh - SHOOTING_RADIUS), 0) / UNITS_PER_STEP_ASH)
            {
                //Because we should kill the thread, not just stick with the person.
                target.first = closestZombie->coordinates.first;
                target.second = closestZombie->coordinates.second;
                minDist = zombieMinDist;
            }
        }
    }
}

bool isAshClosestToAllZombies(int AshX, int AshY, const std::vector<Zombie>& zombies, const std::vector<Human>& humans)
{
    for(auto& zombie : zombies)
    {
        int distZombieAsh = dist(AshX, AshY, zombie.coordinates.first, zombie.coordinates.second);
        for(auto& human : humans)
        {
            if(dist(human.coordinates.first, human.coordinates.second, 
                        zombie.coordinates.first, zombie.coordinates.second) < distZombieAsh)
            {
                return false;
            }
        }
    }
    return true;
}

void positionAshCentral(std::pair<int, int>& target, const std::vector<Zombie>& zombies)
{
    double xPos{};
    double yPos{}; //Double because we will calculate average x and y, so we will devide.
    for(auto& zombie : zombies)
    {
        xPos += zombie.nextCoordinates.first;
        yPos += zombie.nextCoordinates.second;
    }
    int size = zombies.size();
    xPos /= size;
    yPos /= size;
    target.first = xPos;
    target.second = yPos;
}

void readInput(int& AshX, int& AshY, std::vector<Human>& humans, std::vector<Zombie>& zombies)
{
    humans.clear();
    zombies.clear();
    std::cin >> AshX >> AshY;
    std::cin.ignore();
    int human_count{};
    std::cin >> human_count;
    std::cin.ignore();
    humans.resize(human_count);
    for (auto& human : humans) 
    {
        std::cin >> human.humanId >> human.coordinates.first >> human.coordinates.second;
        std::cin.ignore();
    }
    int zombie_count{};
    std::cin >> zombie_count;
    std::cin.ignore();
    zombies.resize(zombie_count);
    for (auto& zombie : zombies) 
    {
        std::cin >> zombie.zombieId >> zombie.coordinates.first >> zombie.coordinates.second;
        std::cin >> zombie.nextCoordinates.first >> zombie.nextCoordinates.second; 
        std::cin.ignore();
    }
}

int main()
{
    std::vector<Human> humans;
    std::vector<Zombie> zombies;
    int x{};
    int y{};
    // game loop
    while (1) {
        readInput(x,y, humans, zombies);
        std::pair<int, int> target{};
        if(!isAshClosestToAllZombies(x, y, zombies,humans))
        {
            findTheMinDistBetweenPersonAndAZombie(humans, target, zombies, x, y);
        }
        else
        {
            positionAshCentral(target, zombies);
        }
        std::cout << target.first <<" "<<target.second << std::endl; 
    }
}
//NOTE: Prefer return values compared to out parameters when returning values from a method!
//For futute improvements - try to iterate over the ideas shared at the end of the Final Project Defense recording.
//Dijkstra; Try to go as many steps as possible ahead of the current moment!