#include <vector>
#include <iostream>
#include <math.h>

#include "Anneal.h"

std::vector<int> Anneal::swap(const std::vector<int>& data, int a, int b) {
    std::vector<int> new_data(data.size());
    new_data = data;
    int x = new_data.at(a);
    new_data.at(a) = new_data.at(b);
    new_data.at(b) = x;
    return new_data;
}
std::vector<int> Anneal::optimize(std::function<int(const std::vector<int>&)> costFunction, std::vector<int> traversal) {
    int x;
    int y;
    std::vector<int> new_traversal;
    while(this->temp > this->absTemp) {
        x = rand() % traversal.size();
        y = rand() % traversal.size();
        new_traversal = swap(traversal, x, y);
        this->deltaDistance = costFunction(new_traversal) - costFunction(traversal);
        if(deltaDistance < 0 || exp(-1*(this->deltaDistance) / this->temp) > 
                (static_cast <float> (rand()) / static_cast <float> (rand()))) {
            traversal = new_traversal;
        }
                
        this-> temp *= this->coolingRate;
    }
    return traversal;
}
