/* 
 * Stochastic Hill Climbing
 * http://www.psychicorigami.com/2007/04/17/tackling-the-travelling-salesman-
 * problem-part-one/ 
 * 
 * Simulated Annealing
 * http://www.codeproject.com/Articles/26758/Simulated-Annealing-Solving-the-Travelling-Salesma
 */ 

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

#include "City.h"

using namespace std::placeholders;

//std::vector<int> traversal;
//std::vector< std::vector<int> > distances; 
//int cityNums = 10;

//I want to be able to output the results to a csv too

/**
 * Swaps a and b from input vector, and returns the new vector
 * 
 * @param data      input vector to swap from
 * @param a         index of first thing to switch
 * @param b         index of the second thing to switch
 */
std::vector<int> swap(const std::vector<int>& data, int a, int b) {
    std::vector<int> new_data(data.size());
    new_data = data;
    int x = new_data.at(a);
    new_data.at(a) = new_data.at(b);
    new_data.at(b) = x;
    return new_data;
}

std::vector<int> climbHill(std::function<int(const std::vector<int>&)> costFunction, int numIterations, std::vector<int> traversal){
    int counter = 0;
    std::vector<int> new_traversal;
    while(counter < numIterations){
        int y = rand() % traversal.size();
        int x = rand() % traversal.size();
        while(x == y) y = rand() % traversal.size();
        new_traversal = swap(traversal, x, y);
        if(costFunction(new_traversal) < costFunction(traversal)){
            counter = 0;
            traversal = new_traversal;
        }else{
            counter++;
        }
    }
    return traversal;
}

int main(){
    srand(time(NULL));
    
    City test(10);
    test.genDistances();
    std::vector<int> traversal = test.randSolution(); 
    int oldSolution = test.getDistance(traversal);
    for (int i : traversal) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    traversal = climbHill(std::bind(&City::getDistance, test, _1), 10000, traversal);
    int newSolution = test.getDistance(traversal);
    
    for (int i : traversal) {
        std::cout << i << " ";
    }

    std::cout << "The original solution had a distance of: " << oldSolution << std::endl;
    std::cout << "The new solution has a distance of: " << newSolution << std::endl;
    return 0;
}

