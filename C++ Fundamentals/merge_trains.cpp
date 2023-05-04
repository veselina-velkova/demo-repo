#include<vector>
#include<string>
#include<list>
#include<sstream>
#include<algorithm>
#include<iostream>

/*
My idea is to use string and concatenation for the AB-sequence (whether the railcar is from train A or 
train B). For the final configuration I will use list, so that I can push front the numbers. For the 
initial trains I am using vectors because I will only need pop_back() and the last elements.
*/

void readRailCars (std::vector<int>& vec)
{
    int n;

    std::string nums;
    getline(std::cin, nums);
    std::istringstream vec_stream (nums);
    
    while(vec_stream >> n)
    {
        vec.emplace_back(n);
    }
}

void merge(std::vector<int>& trainA, std::vector<int>& trainB, std::string& strConfig, std::list<int>& listConfig)
{
    int elementA;
    int elementB;

    while(!trainA.empty()||!trainB.empty())
    {
        if(trainA.empty())
        {
            elementB = trainB.back();
            trainB.pop_back(); 
            //Like this we ruin the initial vectors, which is not a problem with  the current task.
            //If needed, it is an option to pass it as a copy to the function.
            strConfig += 'B';
            listConfig.push_front(elementB);
        }
        else if (trainB.empty())
        {
            elementA = trainA.back();
            trainA.pop_back();
            strConfig += 'A';
            listConfig.push_front(elementA);
        }
        else
        {
            elementA = trainA.back();
            elementB = trainB.back();
            if(elementB < elementA)
            {
                strConfig += 'B';
                trainB.pop_back();
                listConfig.push_front(elementB);
            }
            else
            {
                strConfig += 'A';
                trainA.pop_back();
                listConfig.push_front(elementA);
            }
        }
    }
}

void print(const std::list<int>& lst) 
{
    for(auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> trainA;
    std::vector<int> trainB;
    readRailCars(trainA);
    readRailCars(trainB);

    std::string strFinalConfig {};
    std::list<int> listFinalConfig;

    merge(trainA, trainB, strFinalConfig, listFinalConfig);
    std::cout << strFinalConfig << std::endl;
    print(listFinalConfig);
    
    return 0;
}