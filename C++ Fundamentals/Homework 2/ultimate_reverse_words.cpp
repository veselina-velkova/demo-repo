#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iostream>

std::string readInput()
{
    std::string input{};
    getline(std::cin, input);
    return input;
}

//The function below extracts the word from the string which contains also punctuation.
std::string extractWord(const std::string& input)
{
    std::string word{};
    for(char ch : input)
    {
        if(ch == '.' || ch == ':' || ch == '!' || ch == '?' || ch == ',' || ch == ';' || ch == '-')
        {
            continue;
        }
        else
        {
            word += ch;
        }
    }
    return word;
}

std::vector<size_t> getLengths(const std::string& input)
{
    std::vector<size_t> lengths;
    std::istringstream stream (input);
    std::string currStr{};
    while(stream >> currStr)
    {
        currStr = extractWord(currStr);
        if(currStr != "")
        {
            lengths.push_back(currStr.size());
        }        
    }
    return lengths;
}

std::vector<std::string> getWords(const std::string& input)
{
    std::vector<std::string> words;
    std::string singleWord{};
    std::istringstream stream (input);
    while(stream >> singleWord)
    {
        singleWord = extractWord(singleWord);
        if(singleWord != "")
        {
            words.emplace_back(singleWord);
        }
    }
    return words;
}

std::vector<std::string> reversingOrder(const std::string& input)
{
    std::vector<size_t> positions = getLengths(input);
    std::vector<std::string> words = getWords(input);
    for(auto it = positions.begin(); it != positions.end(); ++it)
    {
        size_t occurance = 0;
        //actualOccurance counts how many words with the same length we have before the current one
        size_t actualOccurance = count(positions.begin(), it, *it);
        size_t index = it - positions.begin();
        //With the for-loop below we go through it backwards.
        for (auto iter = positions.end() - 1; (iter - 1) != positions.begin(); --iter)
        {
            size_t newIndex = iter - positions.begin();
            if(newIndex == index)
            {
                //Even if we find a word with the same length before index, it won't matter, because 
                //we have already swapped it on earlier iteration of the first for-loop.
                break;
            }
            if (*iter == positions[index])
            {
                //If we have found a word with the same length.
                if(actualOccurance != occurance)
                {
                    ++occurance;
                    //We have already swapped it on earlier iteration of the first for-loop.
                    continue;
                }
                {
                    std::swap(words[index], words[newIndex]);
                    break;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return words;
}

std::string changeStr(const std::string& input)
{
    std::vector<std::string> correctOrder = reversingOrder(input);
    std::string finalStr = "";
    size_t position{};
    for(auto it = correctOrder.begin(); it != correctOrder.end(); ++it)
    {
        char ch = (*it).front();
        if(isupper(ch))
        {
            (*it)[0] = tolower(ch);
        }
        finalStr += *it;
        position += (*it).size();
        while(position < input.length() && !isalpha(input[position]))
        {
            //Here we add the non-reversable signs like punctuation.
            finalStr += input[position];
            ++position;
        }
    }
    finalStr[0] = toupper(finalStr[0]);
    return finalStr;
}

void print(const std::string& input)
{
    std::cout << input << std::endl;
}

int main()
{
    std::string input = readInput();
    input = changeStr(input);
    print(input);

    return 0;
}