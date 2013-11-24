/* 
 * http://www.psychicorigami.com/2007/04/17/tackling-the-travelling-salesman-problem-part-one/ 
 * The traveling salesman problem is
 *
 */ 

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> traversal;
vector< vector<int> > distances;

vector< vector<int> > getDistances(int x, int y){
    vector< vector<int> > cities(x, vector<int>(y));
    for(int i = 0; i < x*y; i++){
        for(int j = 0; j < x*y; j++){ 
            cities[i][j] = rand() % 1000 + 1;
        }
    }
    return cities;
}


//Define a traversal as a set of cities (encoded with ints)
//Define a distance matrix where, given the two cities, returns the distance
void swap(vector<int>& data, int a, int b){
    int x = data.at(a);
    data.at(a) = data.at(b);
    data.at(b) = x;
}

int main(){
    distances = getDistances(10, 10);
    for(int x = 0; x < distances.size(); x++){
        cout << distances[0][x] << endl; 
    }
    //print out all of this 
    return 0;
}

