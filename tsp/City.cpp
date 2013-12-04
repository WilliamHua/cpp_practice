#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
struct City {

    /**
     * FIXME: turn this into void and set it into an instance variable
     * Generates distance matrix for distances between city a
     * and city b
     */
    std::vector< std::vector<int> > genDistances(int numCities) {
        std::vector< std::vector<int> > cities(numCities, std::vector<int>(numCities));
        for(int i = 0; i < numCities; i++) {
            for(int j = 0; j < i; j++) {
                cities[i][j] = rand() % 10000 + 1; //range of distances
                //dist a -> b == b -> a
                cities[j][i] = cities[i][j];
            }
        }
        return cities;
    }

    /**
     * Swaps a and b from input vector, and returns the new vector
     * 
     * @param data      input vector to swap from
     * @param a         index of first thing to switch
     * @param b         index of the second thing to switch
     */
    std::vector<int> swap(std::vector<int> data, int a, int b) {
        std::vector<int> new_data(data.size());
        new_data = data;
        int x = new_data.at(a);
        new_data.at(a) = new_data.at(b);
        new_data.at(b) = x;
        return new_data;
    }

    /**
     * Calculates distance given a traversal path
     * FIXME: once gen distances is fixed make this one argument only
     * @param traversal         the path between the cities
     */
    int getDistance(std::vector<int> traversal, std::vector< std::vector<int> > distances) {
        int sum = 0;
        for( int i = 1; i < traversal.size(); i++) {
            sum += distances[traversal[i-1]][traversal[i-1]];
        }
        return sum;
    }

    std::vector<int> randSolution() {
        //FIXME: fix this shit
        int path[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //FIXME
        std::vector<int> randPath(&path[0], &path[0] + 10); //FIXME: get length of array isntead of 10
        random_shuffle(randPath.begin(), randPath.end());
        return randPath;
    }

};

int main() {
    std::cout << "test" << std::endl; 
    return 0;
}

