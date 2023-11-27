/**
 * @file Pagerank.h
 * Contains your declaration of the interface for the Pagerank class.
 */

#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Pagerank {
    public:
        
    private:
};

std::vector<std::vector<int>> csvToEdgeList(std::string const & fileName);

std::vector<float> pageRankAlgorithm(std::vector<std::vector<int>> edgeList, int n, float d);

std::vector<float> getTopThreeAndLowest(std::vector<float> results);
