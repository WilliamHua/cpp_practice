/* 
 * http://www.psychicorigami.com/2007/04/17/tackling-the-travelling-salesman-
 * problem-part-one/ 
 * TLDR: Stochastic hill climbing to solve traveling salesman problem
 */ 

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> traversal;
vector< vector<int> > distances; //distance matrix between two cities
int cityNums = 10;

vector< vector<int> > genDistances(int numCities){
    vector< vector<int> > cities(numCities, vector<int>(numCities));
    for(int i = 0; i < numCities; i++){
        for(int j = 0; j < i; j++){ 
            cities[i][j] = rand() % 10000 + 1; //range of random
            //dist between a and b in this case is same as dist between b and a
            cities[j][i] = cities[i][j]; 
        }
    }
    return cities;
}

int genDistance(vector<int> traversal, vector< vector<int> > distances){
    int sum = 0;
    for(int i = 1; i < traversal.size(); i++){
       sum += distances[traversal[i-1]][traversal[i]];
    }
    return sum;
}

vector<int> swap(vector<int> data, int a, int b){
    vector<int> new_data(data.size());
    new_data = data;
    int x = new_data.at(a);
    new_data.at(a) = new_data.at(b);
    new_data.at(b) = x;
    return new_data;
}

vector<int> randSolution(){
    int path[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //cityNums
    vector<int> randPath(&path[0], &path[0] + 10); //cityNums FIXME: get length of array
    random_shuffle(randPath.begin(), randPath.end());
    return randPath;
}

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
    //for(int x = 0; x < 1000; x++) {
        distances = genDistances(cityNums);
        traversal = randSolution(); 
        originalSolution = genDistance(traversal, distances);
        traversal = climbHill(10000, traversal, distances);
        newSolution = genDistance(traversal, distances); 

        //if(newSolution > originalSolution) {
            cout << "The original solution had a distance of: " << originalSolution << endl;
            cout << "The new solution has a distance of: " << newSolution << endl;
        //}
    //}
    return 0;
}

