#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "City.h"

/**
 * FIXME: static initializer
 * Generates distance matrix for distances between city a
 * and city b
 */
void City::genDistances() {
    std::vector< std::vector<int> > cities(cityNums, std::vector<int>(cityNums, 0));
    for(int i = 0; i < cityNums; i++) {
        for(int j = 0; j < i; j++) {
            cities[i][j] = rand() % 10000 + 1; //range of distances
            //dist a -> b == b -> a
            cities[j][i] = cities[i][j];
        }
    }

    //for (int i = 0; i < cityNums; i++) {
    //    for (int j = 0; j < cityNums; j++) {
    //        std::cout << cities[i][j] << ' ';
    //    }
    //    std::cout << std::endl;
    //}
    this->distances = cities;
}

/**
 * Calculates distance given a traversal path
 * FIXME: once gen distances is fixed make this one argument only
 * @param traversal         the path between the cities
 */
int City::getDistance(const std::vector<int>& traversal) {
    int sum = 0;
    for( int i = 1; i < traversal.size(); i++) {
        sum += this->distances[traversal[i-1]][traversal[i]];
    }
    return sum;
}

/** 
 * Initializes a random traversal path
 */
std::vector<int> City::randSolution() {
    int path[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //FIXME
    std::vector<int> randPath(&path[0], &path[0] + (sizeof(path)/sizeof(*path))); 
    random_shuffle(randPath.begin(), randPath.end());
    return randPath;
}



