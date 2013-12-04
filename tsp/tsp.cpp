/* 
 * Stochastic Hill Climbing
 * http://www.psychicorigami.com/2007/04/17/tackling-the-travelling-salesman-
 * problem-part-one/ 
 * 
 * Simulated Annealing
 * http://www.codeproject.com/Articles/26758/Simulated-Annealing-Solving-the-Travelling-Salesma
 */ 

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "City.h"

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

//std::vector<int> swap(std::vector<int> data, int a, int b) {
//    std::vector<int> new_data(data.size());
//    new_data = data;
//    int x = new_data.at(a);
//    new_data.at(a) = new_data.at(b);
//    new_data.at(b) = x;
//    return new_data;
//}
//
//std::vector<int> climbHill(int (*costFunction)(std::vector<int>, std::vector< std::vector <int> >), int numIterations, std::vector<int> traversal, std::vector< std::vector<int> > distances){
//    int counter = 0;
//    std::vector<int> new_traversal;
//    while(counter < numIterations){
//        int y = rand() % 10;//(sizeof(traversal)/sizeof(*traversal)); //FIXME: hack
//        int x = rand() % 10;//(sizeof(traversal)/sizeof(*traversal));
//        while(x == y) y = rand() % 10;//(sizeof(traversal) / sizeof(*traversal));
//        new_traversal = swap(traversal, x, y);
//        if((*costFunction)(new_traversal, distances) < (*costFunction)(traversal, distances)){
//            counter = 0;
//            traversal = new_traversal;
//        }else{
//            counter++;
//        }
//    }
//    return traversal;
//}

int main(){
    srand(time(NULL));
    //int originalSolution;
    //int newSolution;
    
    //City test(10);
    //test.genDistances();
    //std::vector<int> traversal = test.randSolution(); 
    //distances = genDistances(cityNums);
    //traversal = randSolution(); 
    //originalSolution = genDistance(traversal, distances);
    //traversal = climbHill(10000, traversal, distances);
    //newSolution = genDistance(traversal, distances); 

    //cout << "The original solution had a distance of: " << originalSolution << endl;
    //cout << "The new solution has a distance of: " << newSolution << endl;
    return 0;
}

