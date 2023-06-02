/**
 * @file bus.cpp
 * @author Veselina Velkova (veselina.velkova@strypes.eu)
 * @brief 
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************/

//function to choose bus position for the least positive amount of time
#include<vector>
#include<iostream>

const int MINUTES_PER_HOUR = 60;
const int N_MAX = 20;
const int N_MIN = 0;

int countDigits(const int num)
{
    int copyNum = num;
    int digits{};
    while(copyNum != 0)
    {
        copyNum /= 10;
        ++digits; 
    }
    return digits;
}

std::vector<int> readBuses(const int size)
{
    std::vector<int> buses (size);
    for(auto it = buses.begin(); it != buses.end(); ++it)
    {
        std::cin >> *it;
    }
    return buses;
}

bool isValidTime(const int time)
{
    int digits = countDigits(time);
    if(digits > 4 || digits < 0)
    {
        return false;
    }
    int hours = time / 100;
    int minutes = time % 100;
    if(hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
    {
        return false;
    }
    return true;
}

int convertToMinutes(const int time)
{
    if(!isValidTime(time))
    {
        throw std::invalid_argument("Invalid Bus Time!");
    }
    int timeInMinutes{};
    int hours = time / 100;
    int minutes = time % 100;
    timeInMinutes = hours * MINUTES_PER_HOUR + minutes;
    return timeInMinutes;
}

int positionChosenBus(const std::vector<int>& buses, const int trainTime)
{
    int position = 1;
    int trainInMinutes = convertToMinutes(trainTime);
    int bestWaitingTime = trainInMinutes - convertToMinutes(buses.front());
    for(auto it = buses.begin() + 1; it != buses.end(); ++it)
    {
        int busInMinutes = convertToMinutes(*it);
        int waitingTime = trainInMinutes - busInMinutes;
        if(waitingTime < 0)
        {
            continue;
            //The bus arrives after the train and we will miss it.
        }
        else if(bestWaitingTime < 0)
        {
            bestWaitingTime = waitingTime;
            position = it - buses.begin() + 1;
            continue;
            //Here we are going to catch if the first bus arrives after the train.
            //Except it, there are no other chances to have negative best time, because in the first if-clause
            //we have continue if the time is negative.
            //If we have a negative result in the end, it would mean that all the buses arrive after the
            //train departs and like this the input would be incorrect.
        }
        else if (waitingTime < bestWaitingTime)
        {
            bestWaitingTime = waitingTime;
            position = it - buses.begin() + 1;
        }
    }
    if(bestWaitingTime < 0)
    {
        throw std::invalid_argument("There are no buses which arrive before the train departure.");
    }
    return position;
}

int main()
{
    int size{};
    do{
    std::cin >> size;
    } while (size > N_MAX || size < N_MIN);
    std::vector<int> buses = readBuses(size);
    int trainTime{};
    std::cin >> trainTime;
    std::cout << positionChosenBus(buses, trainTime);

    return 0;
}