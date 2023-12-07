#include <catch2/catch_test_macros.hpp>
#include "../src/pagerank.h"

float epsilon = 0.1;

TEST_CASE("Smallest - PageRank test for 5 elements", "[weight=5]")
{
  std::vector<int> order = {2,1,4,0,3}; //expected order of smallest dataset
  std::vector<float> expected = {14.18836101, 24.47935002, 31.15132003, 9.94470026, 20.22110004};
  std::vector<std::vector<int>> edge_list = csvToEdgeList("../../data/smallest.csv");
  std::vector<float> out = pageRankAlgorithm(edge_list, 1000000, 0.85); //passing in adjacency matrix, 1000000 iterations, and damping factor of 0.85 
  REQUIRE(expected.at(0) - epsilon <= out.at(0));
  REQUIRE(expected.at(0) + epsilon >= out.at(0));

  REQUIRE(expected.at(1) - epsilon <= out.at(1));
  REQUIRE(expected.at(1) + epsilon >= out.at(1));

  REQUIRE(expected.at(2) - epsilon <= out.at(2));
  REQUIRE(expected.at(2) + epsilon >= out.at(2));

  REQUIRE(expected.at(3) - epsilon <= out.at(3));
  REQUIRE(expected.at(3) + epsilon >= out.at(3));

  REQUIRE(expected.at(4) - epsilon <= out.at(4));
  REQUIRE(expected.at(4) + epsilon >= out.at(4));

  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); //total of page ranks should be between 100.1 and 99.9 
  REQUIRE(sum > 99.9);
}

TEST_CASE("Second Smallest - PageRank test for 25 elements", "[weight=5]")
{
  std::vector<int> top3 = {19, 6, 5}; //exepected top 3 ranked pages of second smallest dataset
  std::vector<float> expected = {5.12197971, 5.07976007, 5.05029011};
  int lowest = 8; //lowest ranked page of second smallest dataset
  float low = 2.19516015;
  std::vector<std::vector<int>> edge_list = csvToEdgeList("../../data/second_smallest.csv");
  std::vector<float> out = pageRankAlgorithm(edge_list, 1000000, 0.85); //passing in adjacency matrix, 1000000 iterations, and damping factor of 0.85 
  std::vector<float> three_largest_one_smallest = getTopThreeAndLowest(out);
   
  REQUIRE(expected.at(0) - epsilon <= out.at(top3.at(0) - 1));
  REQUIRE(expected.at(0) + epsilon >= out.at(top3.at(0) - 1));

  REQUIRE(expected.at(1) - epsilon <= out.at(top3.at(1) - 1));
  REQUIRE(expected.at(1) + epsilon >= out.at(top3.at(1) - 1));

  REQUIRE(expected.at(2) - epsilon <= out.at(top3.at(2) - 1));
  REQUIRE(expected.at(2) + epsilon >= out.at(top3.at(2) - 1));

  REQUIRE(low - epsilon <= out.at(lowest - 1));
  REQUIRE(low + epsilon >= out.at(lowest - 1));

  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); //total of page ranks should be between 100.1 and 99.9 
  REQUIRE(sum > 99.9);
}

TEST_CASE("Medium - PageRank test for 50 elements", "[weight=5]")
{
  std::vector<int> top3 = {50, 44, 19};
  std::vector<float> expected = {2.57139386, 2.40783842, 2.39595446};
  int lowest = 3;
  float low = 1.40674751;
  std::vector<std::vector<int>> edge_list = csvToEdgeList("../../data/medium.csv");
  std::vector<float> out = pageRankAlgorithm(edge_list, 1000000, 0.85); //passing in adjacency matrix, 1000000 iterations, and damping factor of 0.85 
  std::vector<float> three_largest_ranks = getTopThreeAndLowest(out);

  REQUIRE(expected.at(0) - epsilon <= out.at(top3.at(0) - 1));
  REQUIRE(expected.at(0) + epsilon >= out.at(top3.at(0) - 1));

  REQUIRE(expected.at(1) - epsilon <= out.at(top3.at(1) - 1));
  REQUIRE(expected.at(1) + epsilon >= out.at(top3.at(1) - 1));

  REQUIRE(expected.at(2) - epsilon <= out.at(top3.at(2) - 1));
  REQUIRE(expected.at(2) + epsilon >= out.at(top3.at(2) - 1));

  REQUIRE(low - epsilon <= out.at(lowest - 1));
  REQUIRE(low + epsilon >= out.at(lowest - 1));

  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); //total of page ranks should be between 100.1 and 99.9 
  REQUIRE(sum > 99.9);
}

TEST_CASE("Second largest - PageRank test for 100 elements", "[weight=5]")
{
  std::vector<int> top3 = {85, 6, 39};
  std::vector<float> expected = {1.2494699, 1.23439798, 1.17824421};
  int lowest = 30;
  float low = 0.66564211;
  std::vector<std::vector<int>> edge_list = csvToEdgeList("../../data/second_largest.csv");
  std::vector<float> out = pageRankAlgorithm(edge_list, 1000000, 0.85); //passing in adjacency matrix, 1000000 iterations, and damping factor of 0.85 
  std::vector<float> three_largest_ranks = getTopThreeAndLowest(out);

  REQUIRE(expected.at(0) - epsilon <= out.at(top3.at(0) - 1));
  REQUIRE(expected.at(0) + epsilon >= out.at(top3.at(0) - 1));

  REQUIRE(expected.at(1) - epsilon <= out.at(top3.at(1) - 1));
  REQUIRE(expected.at(1) + epsilon >= out.at(top3.at(1) - 1));

  REQUIRE(expected.at(2) - epsilon <= out.at(top3.at(2) - 1));
  REQUIRE(expected.at(2) + epsilon >= out.at(top3.at(2) - 1));

  REQUIRE(low - epsilon <= out.at(lowest - 1));
  REQUIRE(low + epsilon >= out.at(lowest - 1));

  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); //total of page ranks should be between 100.1 and 99.9 
  REQUIRE(sum > 99.9);
}

TEST_CASE("Largest - PageRank test for 250 elements", "[weight=5]")
{
  std::vector<int> top3 = {163, 151, 2};
  std::vector<float> expected = {0.46330587 , 0.46142061, 0.45962973};
  int lowest = 203;
  float low = 0.33517946;
  std::vector<std::vector<int>> edge_list = csvToEdgeList("../../data/largest.csv");
  std::vector<float> out = pageRankAlgorithm(edge_list, 1000000, 0.85); //passing in adjacency matrix, 1000000 iterations, and damping factor of 0.85 
  std::vector<float> three_largest_ranks = getTopThreeAndLowest(out);

  REQUIRE(expected.at(0) - epsilon <= out.at(top3.at(0) - 1));
  REQUIRE(expected.at(0) + epsilon >= out.at(top3.at(0) - 1));

  REQUIRE(expected.at(1) - epsilon <= out.at(top3.at(1) - 1));
  REQUIRE(expected.at(1) + epsilon >= out.at(top3.at(1) - 1));

  REQUIRE(expected.at(2) - epsilon <= out.at(top3.at(2) - 1));
  REQUIRE(expected.at(2) + epsilon >= out.at(top3.at(2) - 1));

  REQUIRE(low - epsilon <= out.at(lowest - 1));
  REQUIRE(low + epsilon >= out.at(lowest - 1));

  float sum = 0;
  for (float x : out) {
    sum += x;
  }
  REQUIRE(sum < 100.1); //total of page ranks should be between 100.1 and 99.9 
  REQUIRE(sum > 99.9);
}