#include <catch2/catch_test_macros.hpp>
#include "pagerank.h"

TEST_CASE("Smallest - PageRank test for 5 elements", "[weight=5]")
{
  std::vector<int> expected = {2,1,4,0,3};
  std::vector<std::vector<int>> adjacency_matrix = csvToAdjacency("../../data/smallest.csv");
  std::vector<float> out = pageRankAlgorithm(adjacency_matrix, 100, 0.85);
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
  std::vector<int> top3 = {18, 5, 4};
  int lowest = 7;
  std::vector<std::vector<int>> adjacency_matrix = csvToAdjacency("../../data/second_smallest.csv");
  std::vector<float> out = pageRankAlgorithm(adjacency_matrix, 100, 0.85);
  std::vector<float> three_largest_ranks = getTopThree(out);
  REQUIRE(three_largest_ranks.at(0) == out.at(18));
  REQUIRE(three_largest_ranks.at(1) == out.at(5));
  REQUIRE(three_largest_ranks.at(2) == out.at(4));
  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); 
  REQUIRE(sum > 99.9);
}

