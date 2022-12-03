//
// Created by harrry on 01.12.22.
//

#include <iostream>
#include <fstream>
#include <set>

#include "myconfig.h"

constexpr char diff{'X'-'A'};

void part1(std::ifstream& input){
    std::string line{};
    int result{};
    while(std::getline(input, line)){
        if(line.empty()) continue;
        char hisC = line[0], myC = line[2];
        //Points for my selectiion
        result += myC -'W';
        //points for winner
        result += ((3+ myC - hisC + diff) % 3)*3;
    }
    std::cout<<"Result: "<<result<<'\n';
}
void part2(std::ifstream& input){
    std::string line{};
    int result{};
    while(std::getline(input, line)){
        if(line.empty()) continue;
        char hisC = line[0], resultC = line[2];
        //Points for winner
        result += (resultC -'X')*3;
        //points for selection
        result += (hisC-'A'+ resultC-'X' +2)%3 + 1;
//        std::cout<<"Line: "<<hisC<<resultC
//                 <<" Winner score: "<<(resultC -'X')*3
//                 <<" Piece score: "<<(hisC-'A'+ resultC-'X' +2)%3 + 1<<'\n';
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