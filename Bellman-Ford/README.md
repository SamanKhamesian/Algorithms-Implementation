# Bellman-Ford

The Bellman–Ford algorithm is an algorithm that computes shortest paths 
from a single source vertex to all of the other vertices in a weighted digraph.
It is slower than Dijkstra's algorithm for the same problem, but more versatile,
as it is capable of handling graphs in which some of the edge weights are negative numbers.


#### Input parameters
* `n` : Number of nodes in graph
* `m` : Number of edges in graph
* `start` : Starting node (Source node)

#### Results
* `dis` : Array of minimum distances from source node to the others.
* `parent` : Array of parents for the shortest path between source node and target node.
* `hasNegativeCycle` : bool - `True` If a negative edge cycle exists, otherwise `False`.
