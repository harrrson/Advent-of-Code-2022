//
// Created by harrry on 01.12.22.
//

#include <iostream>
#include <fstream>
#include <set>

#include "myconfig.h"

bool haveUniqueChars(std::string in){
    std::set<char> chars{};
    for(int i{0};i<in.size()-1;i++){
        if(in.find(in[i],i+1) != std::string::npos) return false;
    }
    return true;
}

void part1(std::ifstream& input){
    constexpr int chunkSize{4};
    std::string line;
    int position{0};
    std::getline(input, line);
    while(not haveUniqueChars(line.substr(position, chunkSize)) and position < line.size()-chunkSize) position++;
    std::cout<<position+chunkSize<<'\n';
}
void part2(std::ifstream& input){
    constexpr int chunkSize{14};
    std::string line;
    int position{0};
    std::getline(input, line);
    while(not haveUniqueChars(line.substr(position, chunkSize)) and position < line.size()-chunkSize) position++;
    std::cout<<position+chunkSize<<'\n';
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