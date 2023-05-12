#include<vector>
#include<algorithm>
#include<iostream>

std::vector<int> fillElements(const int count)
{
    std::vector<int> nums (count);
    for(auto it = nums.begin(); it != nums.end(); ++it)
    {
        std::cin >> *it;
    }
    return nums;
}

int elementsMaxAbsDifference(std::vector<int>& nums)
{
    //When the vector is sorted we shouldn't call abs() every time. We know that the next element is equal or bigger.
    //Like this we also ignore the initial order of the numbers, because we care only about their values.
    std::sort(nums.begin(), nums.end());

    int minDiff = nums.back() - nums.front(); 
    //This is the biggest possible difference. 
    //If maxDiff is 0, this means that all elements in the vector are equal.
    if(minDiff == 0)
    {
        return minDiff;
    }
    int currDiff {};

    for(auto it = nums.begin() + 1; it != nums.end(); ++it)
    {
        currDiff = *it - *(it-1);
        if(currDiff < minDiff)
        {
            minDiff = currDiff;
        }
    }
    return minDiff;
}

int main()
{
    int count {};
    std::cin >> count;

    std::vector<int> numbers = fillElements(count);
    std::cout << elementsMaxAbsDifference(numbers) << std::endl;

    return 0;
}