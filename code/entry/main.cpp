#include "../src/pagerank.h"
#include <iostream>
#include <vector>
int main() {
    std::vector<std::vector<int>> edge_list = csvToEdgeList("../../data/largest.csv");
    std::vector<float> out = pageRankAlgorithm(edge_list, 62500, 0.85); //passing in adjacency matrix, 62500 iterations, and damping factor of 0.85
    for (size_t i = 0; i < out.size(); i++) {
        std::cout << "Page " << i << " has rank " << out.at(i) << std::endl;
    }
}
