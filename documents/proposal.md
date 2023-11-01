## Academic Reference

The alogrithm that we are implementing for this project is Google's Pagerank algorithm, created by Larry Page and Sergey Brin.


(https://dl.acm.org/doi/pdf/10.1145/1052934.1052938) - The article from the proposed list of algorithms to support our algorithm

(https://www.cs.bu.edu/fac/crovella/cs132-book/L19PageRank.html) - Boston University resource for teaching the algorithm

(https://research.google/pubs/pub334/) - The founders' very own paper on the algorithm, for conceptual analysis, understanding the math behind the algorithm, and to explore the impact of the algorithm.

## Algorithm Summary

The Pagerank algorithm is designed to evaluate the importance of a webpage in accordance to search engine rankings. The algorithm assigns a score to every single webpage in the network based on the number of links pointing towards the webpage, and the importance of the webpages that link to the webpage. Yet, since each website's rank depends on the rank of other websites, the random surfing model is used on a graph of connected components representing the network. At any certain node, the probability that the random surfer will continue following links is defined as the damping factor. The remaining probability is that the surfer will jump to a random node. After several dozen iterations of the random surfer model, the number of visits per node should be representative of a page's rank. The number of visits are normalized across all pages to provide the rank for each page.
