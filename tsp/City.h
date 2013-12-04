#include <iostream>
#include <vector>

struct City {
    int cityNums;
    std::vector<int> traversal;
    std::vector< std::vector<int> > distances; 

    public:
        City(int c=10): cityNums(c){};
        std::vector<int> swap(std::vector<int> data, int a, int b);
        std::vector<int> randSolution();
        std::vector< std::vector<int> > genDistances(int numCities);
        int getDistance(std::vector<int> traversal, std::vector< std::vector<int> > distances);
};


