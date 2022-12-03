//
// Created by harrry on 01.12.22.
//

#include <iostream>
#include <fstream>
#include <unordered_set>

#include "myconfig.h"

constexpr char diff{'X'-'A'};

int getPriority(char item){
    return (item <= 'Z') ? item - 'A' + 27 : item - 'a'+1;
}

void part1(std::ifstream& input){
    std::string line;
    int result{};
    while(std::getline(input, line)){
        if(line.empty()) continue;
        auto halfPos = line.size()/2;
        auto firstComp = line.substr(0,halfPos), secondComp = line.substr(halfPos);
        std::cout<<firstComp<<" "<<secondComp<<'\n';
        std::unordered_set<char> firstCompItems{firstComp.begin(), firstComp.end()}, secondCompItems{secondComp.begin(), secondComp.end()};
        std::string similarItems{};
        for(auto item : secondCompItems){
            if(firstCompItems.contains(item)) {
                std::cout << "Similar item: " << item << ", priority: " << getPriority(item)<<'\n';
                result += getPriority(item);
            }
        }
    }
    std::cout<<"Result: "<<result<<'\n';
}
void part2(std::ifstream& input){
    int result{};
    std::string firstElf, secondElf, thirdElf;
    while(std::getline(input, firstElf)){
        std::getline(input, secondElf);
        std::getline(input, thirdElf);
        std::unordered_set<char> firstElfItems(firstElf.begin(), firstElf.end()), secondElfItems(secondElf.begin(), secondElf.end()), thirdElfItems(thirdElf.begin(), thirdElf.end());
        for(auto item : firstElfItems){
            if(secondElfItems.contains(item) and thirdElfItems.contains(item)){
                std::cout << "Similar item: " << item << ", priority: " << getPriority(item)<<'\n';
                result += getPriority(item);
                break;
            }
        }
    }
    std::cout<<"Result: "<<result<<'\n';
}

int main(){
    std::ifstream input{INPUT_PATH};
    if(not input){
        std::cout<<"Cannot open file: "<<INPUT_PATH<<'\n';
    }
    std::cout<<"***** Advent of Code: Day "<<AOC_DAY<<" *****\n";

    std::cout<<"Part 1 output:\n"
               "**********************************\n\n";
    part1(input);

    input.clear();
    input.seekg(0);
    std::cout<<"\n**********************************\n"
               "Part 2 output:\n"
               "**********************************\n\n";
    part2(input);
    std::cout<<"\n**********************************\n";

    return 0;
}