#include <iostream>
#include <vector>

struct HillClimbing{
    public:
        std::vector<int> climbHill(std::function<int(const std::vector<int>&)> costFunction, int numIterations, std::vector<int> traversal);
        std::vector<int> swap(const std::vector<int>& data, int a, int b);
};
