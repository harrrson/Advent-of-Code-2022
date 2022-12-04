//
// Created by harrry on 01.12.22.
//

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

#include "myconfig.h"

bool fullyContains(int firstRangeDown, int firstRangeUp, int secondRangeDown, int secondRangeUp){
    return (firstRangeDown<=secondRangeDown and firstRangeUp>=secondRangeUp) or ((firstRangeDown>=secondRangeDown and firstRangeUp<=secondRangeUp));
}

bool partiallyContains(int firstRangeDown, int firstRangeUp, int secondRangeDown, int secondRangeUp){
    return (secondRangeDown>=firstRangeDown and secondRangeDown<=firstRangeUp) or (firstRangeDown>=secondRangeDown and firstRangeDown<=secondRangeUp) or
            (firstRangeUp>=secondRangeDown and firstRangeUp<=secondRangeUp) or (secondRangeUp>=firstRangeDown and secondRangeUp<=firstRangeUp);
}

std::tuple<int, int, int, int> splitToRangeElements(const std::string& line){
    auto it = line.find(',');
    std::string firstRange=line.substr(0,it), secondRange=line.substr(it+1);
    auto itFirstRange=firstRange.find('-');
    auto itSecondRange=secondRange.find('-');
    return {std::stoi(firstRange.substr(0,itFirstRange)), std::stoi(firstRange.substr(itFirstRange+1)),
            std::stoi(secondRange.substr(0,itSecondRange)), std::stoi(secondRange.substr(itSecondRange+1))};
}

void part1(std::ifstream& input){
    std::string line;
    int result{};
    while(std::getline(input, line)){
        auto [firstRangeDown, firstRangeUp, secondRangeDown, secondRangeUp] = splitToRangeElements(line);
        std::cout<<firstRangeDown<<' '<<firstRangeUp<<' '<<secondRangeDown<<' '<<secondRangeUp<<' '<<fullyContains(firstRangeDown,firstRangeUp,secondRangeDown,secondRangeUp)<<'\n';
        if(fullyContains(firstRangeDown,firstRangeUp,secondRangeDown,secondRangeUp)) result += 1;
    }
    std::cout<<"Result: "<<result<<'\n';
}
void part2(std::ifstream& input){
    int result{};
    std::string line;
    while(std::getline(input, line)){
        auto [firstRangeDown, firstRangeUp, secondRangeDown, secondRangeUp] = splitToRangeElements(line);
        std::cout<<firstRangeDown<<' '<<firstRangeUp<<' '<<secondRangeDown<<' '<<secondRangeUp<<' '<<partiallyContains(firstRangeDown,firstRangeUp,secondRangeDown,secondRangeUp)<<'\n';
        if(partiallyContains(firstRangeDown,firstRangeUp,secondRangeDown,secondRangeUp)) result += 1;
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