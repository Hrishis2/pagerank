## November 13th 2023

### Goals 
1. Finish function to read in CSV into 2D adjacency matrix (Not completed)

### Tasks Complete
Both kpura3 and hrishis2 were unable to complete this task due to the volume of work they had for their other courses this week, 
yet aim to complete the function by the following week.

### Issues encountered (Questions for mentors)
Is it best to store the adjacency matrix as a 2D array? Would it be better to instead have an edge list, as a large number of pages in the Pagerank algorithm will not be connected?
For example, there are several links with 0s as connections. Would it be best to instead have an edge list, which also then makes the actual algorithm for choosing a random link traversal easier.

### Plans for next week
Conclude whether an edge list or an adjacency matrix is most accurate to the algorithm
Finish the function to read in the CSV
Work towards concluding the pagerank algorithm

## November 26th 2023

### Goals 
1. Finish CSV to Edge List* (changed from last week to better accomodate our goals, completed)
2. Finish PageRank using Random Surfer principles (completed)
3. Finish algorithm to parse results and return 3 highest ranking websites and one lowest ranked website (completed)
   
### Tasks Complete
Hrishis2 and kpura3 were able to complete all of the functions necessary for the project, working on the project over break as well. There were some discrepencies in terms of the "expected solution" defined by the test cases, so to fix these inaccuracies the group used the power iteration method on a normalized Markov matrix as suggested by the source linked by TA Blaine Hill. The group then rewrote test cases using the actual expected solutions.

### Issues encountered (Questions for mentors)
The random surfer algorithm has a lot of randomness in terms of which link to follow, when to choose a new link at random (damping), etc. This has made it so that our medium sized data (50 sites) has some issues with what the least ranking site should be. Sometimes all tests pass, sometimes they don't because of what we define to be the "least ranking" site. Instead there are several possible least ranking sites, rather than one clear site. How can we fix this? We tried increasing the iterations to 1,000,000,000 iterations, but still it isn't always the same answer.

The following code was used to verify that our page rank algorithm works:
```

# Online Python - IDE, Editor, Compiler, Interpreter
import numpy as np
import numpy.linalg as la
import matplotlib.pyplot as plt
def power_iteration(M, x):
    # Perform power iteration and return steady state vector xstar
    xc = x.copy()
    for i in range(100) :
        #print(xc)
        xc = M @ xc
    return xc
A = np.array([[0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0],
[1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,1,0,0,0,1,0,0,0],
[1,0,0,1,1,1,0,0,0,0,1,0,0,1,1,1,1,0,0,0,1,0,1,1,1],
[0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0],
[1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0],
[0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,1,0],
[1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,0],
[1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0],
[0,0,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1],
[1,1,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,0],
[1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,1,1,0,0,1],
[0,1,0,0,1,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1,1,1,0,1,1],
[0,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,1,0,0,0,1],
[1,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,1,0,0,1],
[0,0,0,0,1,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,0],
[1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0],
[0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1],
[0,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1],
[0,0,0,1,0,0,1,0,1,1,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0],
[1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,1,0],
[0,1,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,1],
[0,0,1,1,0,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,0,0],
[1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1],
[0,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,1],
[0,1,1,0,1,1,0,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0]]).T
M2 = A.copy().astype(float)
# Convert entries in M2 below
for i in range(len(M2)) :
    x = np.sum(M2[:,i])
    if (x != 0) :
        M2[:,i] = A[:,i] / x 
    #print(M2[:,i])
init = np.zeros((1, len(A)))
init[0] = 100
print(power_iteration(M2, init))

```

### Plans for next week
Fix definitions on least ranking site, and top three sites


## December 4th 2023

### Goals 
1. 
   
### Tasks Complete
The following updated code was used to verify that our page rank algorithm works especially with our Second Largest and Largest dataset:
```
# Online Python - IDE, Editor, Compiler, Interpreter
import numpy as np
import numpy.linalg as la
import csv

with open('data.csv', 'r') as f:
    reader = csv.reader(f)
    data = list(reader)
data_array = np.array(data, dtype=float)
print(data_array.shape)


def power_iteration(M, x):
    # Perform power iteration and return steady state vector xstar
    xc = x.copy()
    for i in range(100000) :
        #print(xc)
        xc = M @ xc
    return xc
A = data_array.T
print(A.shape)
M2 = A.copy().astype(float)
print(M2.shape)
# Convert entries in M2 below
for i in range(len(M2)) :
    x = np.sum(M2[:,i])
    if (x != 0) :
        M2[:,i] = A[:,i] / x
    #print(M2[:,i])
init = np.zeros(len(A))
init[0] = 100
print(power_iteration(M2, init))
```

### Issues encountered (Questions for mentors)

### Plans for next week


