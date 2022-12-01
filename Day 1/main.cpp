//
// Created by harrry on 01.12.22.
//

#include <iostream>
#include <fstream>
#include <set>

#include "myconfig.h"

void part1(std::ifstream& input){
    std::set<int> results{};
    std::string line{};
    int calories{};
    int maxCalories{};
    while(std::getline(input, line)){
        if(line.empty()){
            if(maxCalories < calories) maxCalories = calories;
            calories = 0;
            continue;
        }
        calories+=std::stoi(line);
    }
    if(maxCalories < calories) maxCalories = calories;
    std::cout<<maxCalories<<'\n';
}
void part2(std::ifstream& input){
    std::set<int> results{};
    std::string line{};
    int calories{};
    int maxCalories[3]{};
    while(std::getline(input, line)){
        if(line.empty()){
            if(maxCalories[0] < calories){
                maxCalories[2] = maxCalories[1];
                maxCalories[1] = maxCalories[0];
                maxCalories[0] = calories;
            }else if(maxCalories[1] < calories){
                    maxCalories[2] = maxCalories[1];
                    maxCalories[1] = calories;
            }else if(maxCalories[2] < calories){
                maxCalories[2] = calories;
            }
            calories = 0;
            continue;
        }
        calories+=std::stoi(line);
    }
    if(maxCalories[0] < calories){
        maxCalories[2] = maxCalories[1];
        maxCalories[1] = maxCalories[0];
        maxCalories[0] = calories;
    }else if(maxCalories[1] < calories){
        maxCalories[2] = maxCalories[1];
        maxCalories[1] = calories;
    }else if(maxCalories[2] < calories){
        maxCalories[2] = calories;
    }
    std::cout<<maxCalories[0]<<'\n'
             <<maxCalories[1]<<'\n'
             <<maxCalories[2]<<'\n'
             <<maxCalories[2]+maxCalories[1]+maxCalories[0]<<'\n'<<'\n';
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