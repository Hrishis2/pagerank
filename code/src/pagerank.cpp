#include "pagerank.h"

std::vector<std::vector<int>> csvToEdgeList(std::string const & fileName) {
    std::ifstream file(fileName);
    std::vector<std::vector<int>> ret;
    int read;
    char discard;
    if (file.is_open()) {
        file.ignore(INT16_MAX, '\n'); //Discard first line, just site numbers
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

std::vector<float> pageRankAlgorithm(std::vector<std::vector<int>> edgeList, int n, float d) {
    //choose a random site to start on 
    //seed rand  
    std::vector<float> visits(edgeList.size(), 0);
    srand(time(NULL));
    int curr_site = rand() % edgeList.size();
    visits.at(curr_site)++;
    int next;
    //damping factor is the probability of following a link 
    //less than the damping factor * 100 shows the probability of 
    //following a link and greater than the damping factor * 100
    //shows the probability of starting at another random site 
    for (int i = 0; i < n; i++) {
        if (rand() % 100 + 1 <= d * 100) { //follows link
            next = rand() % edgeList.at(curr_site).size();
            curr_site = edgeList.at(curr_site).at(next);
        } else { //respawns
            next = rand() % edgeList.size();
            curr_site = next;
        }
        visits.at(curr_site)++;
    }
    //normalize visits vector 
    for (size_t j = 0; j < visits.size(); j++) {
        visits.at(j) = (visits.at(j) / float(n)) * float(100.0); 
    }

    return visits;
    
}

std::vector<float> getTopThreeAndLowest(std::vector<float> results) {
    std::vector<float> ret(4, 0.0);
    float min = INT16_MAX;
    for (float result : results) {
        if (result < min) min = result;
        if (result > ret[0]) {
            ret[2] = ret[1];
            ret[1] = ret[0];
            ret[0] = result;
        } else if (result > ret[1]) {
            ret[2] = ret[1];
            ret[1] = result;
        } else if (result > ret[2]) {
            ret[2] = result;
        }
    }
    ret[3] = min;
    return ret;
}
