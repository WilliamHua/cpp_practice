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
#include "HillClimbing.h"
#include "Anneal.h"

using namespace std::placeholders;

//I want to be able to output the results to a csv too

//FIXME: for City, generate a list 1...n

int main(){
    City test(10);
    int oldSolution;
    int newSolution;
    std::cout << "Running 100 tests for hill climbing" << std::endl;

    for(int x = 0; x < 100; x++) {
        HillClimbing hc;
        test.genDistances();
        std::vector<int> traversal = test.randSolution(); 
        oldSolution = test.getDistance(traversal);
        traversal = hc.climbHill(std::bind(&City::getDistance, test, _1), 10000, traversal);
        newSolution = test.getDistance(traversal);
        if(oldSolution > newSolution) {
            std::cout << ".";
        } else {
            std::cout << "E";
        }
    }
    
    std::cout << std::endl << "Running 100 tests for simulated annealing" << std::endl;
    for(int x = 0; x < 100; x++) {
        Anneal an;
        test.genDistances();
        std::vector<int> traversal = test.randSolution();
        oldSolution = test.getDistance(traversal);
        traversal = an.optimize(std::bind(&City::getDistance, test, _1), traversal);
        newSolution = test.getDistance(traversal);
        if(oldSolution > newSolution) {
            //std::cout << ".";
            std::cout << "Old solution: " << oldSolution << std::endl;
            std::cout << "New solution: " << newSolution << std::endl;
        } else {
            std::cout << "E";
        }
    }
    std::cout << std::endl;
    return 0;
}

