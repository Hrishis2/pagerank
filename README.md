## Academic Reference

The alogrithm that we are implementing for this project is Google's Pagerank algorithm, created by Larry Page and Sergey Brin.


(https://dl.acm.org/doi/pdf/10.1145/1052934.1052938) - The article from the proposed list of algorithms to support our algorithm

(https://www.cs.bu.edu/fac/crovella/cs132-book/L19PageRank.html) - Boston University resource for teaching the algorithm

(https://research.google/pubs/pub334/) - The founders' very own paper on the algorithm, for conceptual analysis, understanding the math behind the algorithm, and to explore the impact of the algorithm.

## Algorithm Summary

The Pagerank algorithm is designed to evaluate the importance of a webpage in accordance to search engine rankings. The algorithm assigns a score to every single webpage in the network based on the number of links pointing towards the webpage, and the importance of the webpages that link to the webpage. Yet, since each website's rank depends on the rank of other websites, the random surfing model is used on a directed graph of connected components representing the network. At any certain node, the probability that the random surfer will continue following links is defined as the damping factor. The remaining probability is that the surfer will jump to a random node. After several dozen iterations of the random surfer model, the number of visits per node should be representative of a page's rank. The number of visits are normalized across all pages to provide the rank for each page. The expected runtime for this algorithm should be approximately O(n + l) where n is the number of pages and l is the number of links.

## Function I/O

The Pagerank algorithm we wish to implement uses an adjacency matrix stored as a 2D vector. So therefore, a helper function is to be implemented for converting a CSV file to a vector of booleans representing a link between pages (true meaning a link is present).

1. `std::vector<std::vector<bool>> csvToAdjacency(std::string infile)`
```
@param infile -- the path to the processed CSV as an adjacency matrix
@return the vector representing the adjacency matrix in the CSV as a 2D vector of booleans
```
This basic function is to take in the CSV file path. A 2D vector is initialized, and character by character the CSV file is read to the the vector. The first row of headers is ignored, but following that each row is pushed back to the 2D vector one by one. If a zero is met, then the value false is pushed back to the row vector, and if a one is met then true is pushed back. The resulting adjacency matrix is then returned.

2. `std::vector<float> pageRankAlgorithm(std::vector<std::vector<bool>> adjacencyMatrix, int numOfIterations, double damping)`
```
@param adjacencyMatrix -- the vector representing the adjacency matrix of the network
@param numOfIterations -- the number of times our random surfer should move/jump.
The number of iteration should be greater than 0, yet values greater than 20 work best
@param damping -- the probability that the surfer will follow a link, as opposed to jumping to a random page. This value should be between [0, 1] inclusive
@return a vector representing the normalized rank of each page in the network
```
This is the main function of this project. This function takes in the adjacency matrix and proceeds to declare a vector of ints counting the number of times each page is visited in this algorithm. The "surfer" will then begin at a random page. A random float value will determine if the surfer is to jump or follow a link. If the the random float value between 0 and 1 is below the damping factor then the surfer will continue to follow links. Otherwise, it will jump to a random page. Each time the surfer visits a page, that page's visit count is incremented. After completing the number of iterations, the vector is normalized according to the number of iterations performed and stored in a vector of floats, which is then returned.

3. `std::vector<float> getTopThreeAndLowest(std::vector<float> rankings)`
```
@param rankings -- the vector representing the ranks of each page in the network
@return a vector where indices [0:2] are the largest, second largest,
and third largest ranks respectively, and index [3] represents the smallest rank
```
To confirm that the PageRank algorithm works, we decided to create a helper function used by the test cases that takes the vector of ranks for each page and returns a vector of the top three largest ranks, and the lowest rank. Instead of having two different functions for each leading to worse runtime complexity, this function just provides a vector of four floats, where the first three are the highest ranks, and the final element is the lowest rank. This is done iteratively by traversing through each rank and keeping track of the largest, second largest, third largest, and lowest rank.

## Data Description
Our test datasets are adjacency matrices with different amounts of pages or sites as listed in our CSV files. The corresponding test datasets contain 5, 25, 50, 100, and 250 sites. For the smallest dataset, we decided to provide the order of the five webpages in terms of rank to fully finalize that this algorithm works. This ensures that when testing our algorithm we can check the ranks outputted with the ones calculated. For the rest of the datasets, we decide to provide the top three most important sites and the least important site. As on the internet sites don't often have links to themselves, we decided to remove values of one along the right diagonal manually for the adjacency matrix CSVs, as such values would mean links to self. The code to create adjacency matrices in CSV files of any length is written below. Note that python was used due to the robust numpy library that allows for such matrix generation:
```
import numpy as np
f = open("path.csv", "a")
n = 250
array = np.random.randint(low=0, high=2, size=(n, n))
for i in range(len(array)):
  f.write("Site " + str(i) + ",")
for row in m:
  f.write("\n");
  for col in row:
    f.write(col + ",")
print(array)
f.close()
```
