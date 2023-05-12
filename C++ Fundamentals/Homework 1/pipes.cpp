#include<vector>
#include<iostream>

const int INSTALATION_MAX = 1'000'000'000;
const int N_MAX = 500;
const int N_MIN = 0;
const int CHECK_UP_MIN = 0;
const int INSTALATION_MIN = 0;

bool isValid(const std::vector<int>& check_up, const std::vector<int>& instalation)
{
    if(check_up.size() != instalation.size())
    {
        //To work correctly, they should have equal amount of elements.
        return false;
    }
    for(auto it = check_up.begin(); it != check_up.end(); ++it)
    {
        int index = it - check_up.begin();
        if(*it >= instalation[index] || instalation[index] > INSTALATION_MAX || *it < CHECK_UP_MIN || instalation[index] <= INSTALATION_MIN)
        {
            std::cerr << "Invalid input. " << std::endl;
            return false;
        }
    }
    return true;
}

std::vector<int> readVector(const int size)
{
    std::vector<int> vec(size);
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cin >> *it;
    }
    return vec;
}

std::vector<int> calcLifetimes(const std::vector<int>& instalation, const std::vector<int>& check_up)
{
    const int size = instalation.size();
    std::vector<int> lifetime (size);
    for(auto it = instalation.begin(); it != instalation.end(); ++it)
    {
        int index = it - instalation.begin();
        int diff = *it - check_up[index];
        lifetime[index] = *it / diff;
    }
    return lifetime;
}

void print(const std::vector<int>& vec)
{
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n{};
    do{
        std::cout << "Please, enter a valid value for n: positive number less than or equal to 500. \n";
        std::cin >> n;
    } while (n > N_MAX || n <= N_MIN);
    
    std::vector<int> check_up = readVector(n);
    std::vector<int> instalation = readVector(n);
    if(!isValid(check_up, instalation))
    {
        throw std::invalid_argument("Incorrect input!");
    }
    std::vector<int> result = calcLifetimes(instalation, check_up);
    print(result);

    return 0;
}