#  Travelling Salesman Problem (TSP)

The travelling salesman problem (TSP) asks the following question:
"Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?"
It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science.
TSP can be modelled as an undirected weighted graph, such that cities are the graph's vertices, paths are the graph's edges, and a path's distance is the edge's weight.
It is a minimization problem starting and finishing at a specified vertex after having visited each other vertex exactly once.
Often, the model is a complete graph (i.e. each pair of vertices is connected by an edge).

#### Variables
* `n` : Number of nodes in graph
* `dist` : Distance between each pair of nodes in graph.

#### Parameters
* `pos` : Starting node (Current position)
* `bitmask` : Binary representation for nodes that has been visited `1` or not `0`.

#### Results
Shortest route length
