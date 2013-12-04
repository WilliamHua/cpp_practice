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
using namespace std;

vector<int> traversal;
vector< vector<int> > distances; 
int cityNums = 10;

//I want to be able to output the results to a csv too

vector<int> climbHill(int numIterations, vector<int> traversal, vector< vector<int> > distances){
    int counter = 0;
    vector<int> new_traversal;
    while(counter < numIterations){
        int y = rand() % cityNums;
        int x = rand() % cityNums;
        while(x == y) y = rand() % cityNums;
        new_traversal = swap(traversal, x, y);
        if(genDistance(new_traversal, distances) < genDistance(traversal, distances)){
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
    int originalSolution;
    int newSolution;
    distances = genDistances(cityNums);
    traversal = randSolution(); 
    originalSolution = genDistance(traversal, distances);
    traversal = climbHill(10000, traversal, distances);
    newSolution = genDistance(traversal, distances); 

    cout << "The original solution had a distance of: " << originalSolution << endl;
    cout << "The new solution has a distance of: " << newSolution << endl;
    return 0;
}

