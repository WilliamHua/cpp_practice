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
vector< vector<int> > cities(int x, int y){
    vector< vector<int> > cities(x, vector<int>(y));
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
    vector<int> test(4, 100);
    test.at(0) = 50;
    cout << "Original first: " << test.at(0) << endl;
    cout << "Original second: " << test.at(1) << endl;
    swap(test, 0, 1);
    cout << test.at(0) << endl;
    cout << test.at(1) << endl;
    return 0;
}

