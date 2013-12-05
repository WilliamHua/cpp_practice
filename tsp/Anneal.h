#include <iostream>
#include <vector>
#include <functional>

struct Anneal {
    public:
        float temp;
        float coolingRate;
        float deltaDistance;
        float absTemp;

    public: 
        Anneal(float a=10000.0, float b=.9999, float c=0.0001): 
            temp(a), coolingRate(b), absTemp(c){};
        std::vector<int> swap(const std::vector<int>& data, int a, int b);
        std::vector<int> optimize(std::function<int(const std::vector<int>&)> costFunction, std::vector<int> traversal);
};
