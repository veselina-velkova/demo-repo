#include<vector>
#include<array>
#include<algorithm>

#include<iostream>

//This function fills a vector with integers from the standart input.
std::vector<int> fillVector(const int size)
{
    std::vector<int> vec (size);
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cin >> *it;
    }
    return vec;
}

std::vector<int> mostFrequent (const std::vector<int>& nums)
{
    int digit{};

    //For each different digit we count how many times we can find it in nums.
    std::array<int, 10> digits;
    for (auto it = digits.begin(); it != digits.end(); ++it)
    {
        digit = it - digits.begin();
        *it = std::count(nums.begin(), nums.end(), digit);
    }

    //We find how many times the most frequent is found.
    int* mostFreq = std::max_element(digits.begin(), digits.end());

    //And we find the elements which are found this amount of times.
    //Using this array digits we guarantee that in max the elements will be sorted in ascending order.
    std::vector <int> max;
    for (auto it = digits.begin(); it != digits.end(); ++it)
    {
        if (*it == *mostFreq)
        {
            digit = it - digits.begin();
            max.emplace_back(digit);
        }
    }
    return max;
}

void print(const std::vector<int>& sequence)
{
    for (int digit : sequence)
    {
        std::cout << digit << " ";
    }
}


int main()
{
    int count {};
    std::cin >> count;
    std::vector <int> numbers = fillVector(count);

    std::vector <int> max = mostFrequent(numbers);
    print(max);
    
    return 0;
}