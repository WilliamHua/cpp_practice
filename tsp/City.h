#include <iostream>
#include <vector>

struct City {
    int cityNums;
    std::vector< std::vector<int> > distances; 

    public:
        City(int c=10): cityNums(c){srand(time(NULL));};
        std::vector<int> randSolution();
        void genDistances();
        int getDistance(const std::vector<int>& traversal);
        //friend std::ostream& operator<<(ostream&, const City&) {
        //    for 
        //}
};


