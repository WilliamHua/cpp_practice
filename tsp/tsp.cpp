/* 
 * http://www.psychicorigami.com/2007/04/17/tackling-the-travelling-salesman-
 * problem-part-one/ 
 * TLDR: Stochastic hill climbing to solve traveling salesman problem
 */ 

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> traversal;
vector< vector<int> > distances; //distance matrix between two cities

vector< vector<int> > genDistances(int numCities){
    vector< vector<int> > cities(numCities, vector<int>(numCities));
    for(int i = 0; i < numCities; i++){
        for(int j = 0; j < i; j++){ 
            cities[i][j] = rand() % 1000 + 1;
            //dist between a and b in this case is same as dist between b and a
            cities[j][i] = cities[i][j]; 
        }
    }
    return cities;
}

int genDistance(vector<int> traversal, vector< vector<int> > distances){
    int sum = 0;
    for(int i = 1; i < traversal.size(); i++){
       sum += distances[i-1][i];
    }
    return sum;
}

void swap(vector<int>& data, int a, int b){
    int x = data.at(a);
    data.at(a) = data.at(b);
    data.at(b) = x;
}

vector<int> randSolution(){
}

vector<int> climbHill(){
}

int main(){
    srand(time(NULL));
    distances = genDistances(10);
    for(int x = 0; x < distances.size(); x++){
        for(int y = 0; y < distances[0].size(); y++){
            cout << distances[x][y] << " "; 
        }
        cout << endl;
    }

    int solution[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> randSolution(begin(solution), end(solution));
    //print out all of this 
    return 0;
}

