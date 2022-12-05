//
// Created by harrry on 01.12.22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <stack>
#include <sstream>

#include "myconfig.h"


constexpr std::size_t firstStackPos = 1;
constexpr std::size_t stackSpacing = 4;
constexpr std::size_t nOfStacks = 9;

using StackArray = std::array<std::stack<char>, nOfStacks>;

StackArray getStacksFromInput(std::ifstream& input){
    std::array<std::vector<char>,nOfStacks> buffer{};
    std::string line;
    int result{};
    while(std::getline(input, line)){
        if(line.empty()) break;
        if('1' == line[firstStackPos]) continue;
        for(std::size_t i{0}; i<nOfStacks; i++){
             if(' ' == line[firstStackPos + stackSpacing * i]) continue;
             if(line.size()<=(firstStackPos + stackSpacing * i)) break;
             buffer[i].push_back(line[firstStackPos + stackSpacing * i]);
        }
    }
    StackArray stacks{};
    for(std::size_t i{0}; i<nOfStacks; i++){
        for(auto it = buffer[i].rbegin(); it != buffer[i].rend(); it++){
            stacks[i].push(*it);
        }
    }
    return stacks;
}

void part1(std::ifstream& input){
    std::string line;
    std::stringstream result{};
    auto stacks = getStacksFromInput(input);
    std::stringstream ss{};
    std::string dump;
    int count, stackFrom, stackTo;
    while(std::getline(input, line)){
        if(line.empty()) continue;
        ss<<line;
        ss>>dump>>count>>dump>>stackFrom>>dump>>stackTo;
        ss.clear();
        for(int i{0}; i < count; i++){
            stacks[stackTo-1].push(stacks[stackFrom-1].top());
            stacks[stackFrom-1].pop();
        }
    }
    for(std::size_t i{0}; i<nOfStacks; i++){
        result<<stacks[i].top();
    }
    std::cout<<"Result: "<<result.str()<<'\n';
}
void part2(std::ifstream& input){
    std::string line;
    std::stringstream result{};
    auto stacks = getStacksFromInput(input);
    std::stringstream ss{};
    std::string dump;
    std::stack<char> tmpStack{};
    int count, stackFrom, stackTo;

    while(std::getline(input, line)){
        if(line.empty()) continue;
        ss<<line;
        ss>>dump>>count>>dump>>stackFrom>>dump>>stackTo;
        ss.clear();
        stackFrom--;
        stackTo--;
        for(int i{0}; i < count; i++){
            tmpStack.push(stacks[stackFrom].top());
            stacks[stackFrom].pop();
        }
        for(int i{0}; i < count; i++){
            stacks[stackTo].push(tmpStack.top());
            tmpStack.pop();
        }
    }
    for(std::size_t i{0}; i<nOfStacks; i++){
        result<<stacks[i].top();
    }
    std::cout<<"Result: "<<result.str()<<'\n';
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