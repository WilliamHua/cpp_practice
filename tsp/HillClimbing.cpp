#include <iostream>
#include <vector>
#include <functional>

#include "HillClimbing.h"

/**
 * Swaps a and b from input vector, and returns the new vector
 * 
 * @param data      input vector to swap from
 * @param a         index of first thing to switch
 * @param b         index of the second thing to switch
 */
std::vector<int> HillClimbing::swap(const std::vector<int>& data, int a, int b){
    std::vector<int> new_data(data.size());
    new_data = data;
    int x = new_data.at(a);
    new_data.at(a) = new_data.at(b);
    new_data.at(b) = x;
    return new_data;
}

std::vector<int> HillClimbing::climbHill(std::function<int(const std::vector<int>&)> costFunction, int numIterations, std::vector<int> traversal){
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
