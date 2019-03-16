# Depth-first search (DFS)

Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures.
One starts at the root (selecting some arbitrary node as the root in the case of a graph) and explores as far as possible along each branch before backtracking.

#### Variables
* `n` : Number of nodes in graph
* `m` : Number of edges in graph

#### Parameters
* `current` : Starting node
* `p` : Parent node (Initialize with -1 at the beginning)

#### Results
* `parent` : Array of parents for the path between source node and last visited node in graph.
