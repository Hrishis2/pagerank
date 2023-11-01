#include <catch2/catch_test_macros.hpp>
#include "pagerank.h"

TEST_CASE("Smallest - PageRank test for 5 elements", "[weight=5]")
{
  std::vector<int> expected = {2,1,4,0,3}; //expected order of smallest dataset
  std::vector<std::vector<bool>> adjacency_matrix = csvToAdjacency("../../data/smallest.csv");
  std::vector<float> out = pageRankAlgorithm(adjacency_matrix, 100, 0.85); //passing in adjacency matrix, 100 iterations, and damping factor of 0.85 
  REQUIRE(out.at(0) < 14.5);
  REQUIRE(out.at(0) > 13.5);
  REQUIRE(out.at(1) < 25.0);
  REQUIRE(out.at(1) > 24.0);
  REQUIRE(out.at(2) < 31.7);
  REQUIRE(out.at(2) > 30.7);
  REQUIRE(out.at(3) < 11);
  REQUIRE(out.at(3) > 9);
  REQUIRE(out.at(4) < 21);
  REQUIRE(out.at(4) > 19);
  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); 
  REQUIRE(sum > 99.9);
}

TEST_CASE("Second Smallest - PageRank test for 25 elements", "[weight=5]")
{
  std::vector<int> top3 = {18, 5, 4}; //exepected top 3 ranked pages of second smallest dataset
  int lowest = 7; //lowest ranked page of second smallest dataset
  std::vector<std::vector<bool>> adjacency_matrix = csvToAdjacency("../../data/second_smallest.csv");
  std::vector<float> out = pageRankAlgorithm(adjacency_matrix, 100, 0.85); //passing in adjacency matrix, 100 iterations, and damping factor of 0.85 
  std::vector<float> three_largest_one_smallest = getTopThreeAndLowest(out);
   
  REQUIRE(three_largest_one_smallest.at(0) == out.at(18));
  REQUIRE(three_largest_one_smallest.at(1) == out.at(5));
  REQUIRE(three_largest_one_smallest.at(2) == out.at(4));
  REQUIRE(three_largest_one_smallest.at(3) == out.at(7));
  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); 
  REQUIRE(sum > 99.9);
}

TEST_CASE("Medium - PageRank test for 50 elements", "[weight=5]")
{
  std::vector<int> top3 = {50, 19, 24};
  int lowest = 3;
  std::vector<std::vector<bool>> adjacency_matrix = csvToAdjacency("../../data/second_smallest.csv");
  std::vector<float> out = pageRankAlgorithm(adjacency_matrix, 100, 0.85); //passing in adjacency matrix, 100 iterations, and damping factor of 0.85 
  std::vector<float> three_largest_ranks = getTopThreeAndLowest(out);
  REQUIRE(three_largest_ranks.at(0) == out.at(50));
  REQUIRE(three_largest_ranks.at(1) == out.at(19));
  REQUIRE(three_largest_ranks.at(2) == out.at(24));
  REQUIRE(three_largest_ranks.at(3) == out.at(3));
  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); 
  REQUIRE(sum > 99.9);
}
