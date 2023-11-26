#include "pagerank.h"

std::vector<std::vector<int>> csvToAdjacency(std::string const & fileName) {
    std::ifstream file(fileName);
    std::vector<std::vector<int>> ret;
    int read;
    char discard;
    if (file.is_open()) {
        file.ignore(256, '\n'); //Discard first line, just site numbers
        // ret.push_back(std::vector<int>());
        // int site_num = 0;
        // int link_num;
        // char comma_or_line;
        // while (!file.eof() && !file.fail()) {
        //     if (file.peek() == '\n') {
        //         ret.push_back(std::vector<int>());
        //         site_num++;
        //         link_num = 0;
        //         file.ignore(1);
        //     } else {
        //         file >> read >> comma_or_line;
        //         if (read == 1) {
        //             ret.at(site_num).push_back(link_num); 
        //         }
        //         if (comma_or_line == '\n') {
        //             ret.push_back(std::vector<int>());
        //             site_num++;
        //             link_num = 0;
        //         } else {
        //             link_num++;
        //         }
        //     } 
        // }
        int site_num = 0;
        int link_num = 0;
        ret.push_back(std::vector<int>());
        while (!file.eof() && !file.fail()) {
            file.get(discard);
            if (file.eof() || file.peek() == EOF) {
                break;
            }
            if (discard == '\n') {
                ret.push_back(std::vector<int>());
                site_num++;
                link_num = 0;
                continue;
            }
            if (discard == '1') {
                ret.at(site_num).push_back(link_num);
                link_num++;
            } else if (discard == '0') {
                link_num++;
            }   
        }
        
    } else {
        throw std::invalid_argument("Not a proper file path");
    }
    return ret;
}

std::vector<float> pageRankAlgorithm(std::vector<std::vector<int>> adjacencyMatrix, int n, float d) {
    return std::vector<float>();
}

std::vector<float> getTopThreeAndLowest(std::vector<float> results) {
    return std::vector<float>();
}
