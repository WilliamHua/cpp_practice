#include <iostream>
#include <vector>

struct City {
    int cityNums;
    std::vector<int> traversal;
    std::vector< std::vector<int> > distances; 

    public:
        City(int c=10): cityNums(c){};
        std::vector<int> randSolution();
        void genDistances();
        int getDistance(const std::vector<int>& traversal);
        //friend std::ostream& operator<<(ostream&, const City&) {
        //    for 
        //}
};


