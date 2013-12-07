#include <iostream>
#include <vector>
#include <functional>

#include <tsp.h>

/**
 * Genetic Algorithm with no cross-mutation
 * Select top 50%, randomly mutate them, 
 * choose the best at the end of iteration cycle
 */
struct GA {
   
    public:
        GA(int a=100000, int b = 10, int c=100000, float d=.1): 
            popSize(a), popDim(b), numIterations(c), mutationRate(d) {};
        void genPop();
        std::vector<int> optimize(std::function<int(const std::vector<int>&)> costFunction, std::vector<int> traversal);

     private:
        int popSize;
        int popDim;
        int numIterations;
        float mutationRate;
        vector< vector<int> > pop;
};
