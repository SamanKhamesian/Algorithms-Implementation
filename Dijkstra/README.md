# Dijkstra

Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.
The algorithm exists in many variants; Dijkstra's original variant found the shortest path between two nodes, but a more common variant fixes a single node as the `source` node and finds shortest paths from the source
to all other nodes in the graph, producing a shortest path tree.

#### Variables
* `n` : Number of nodes in graph
* `m` : Number of edges in graph
* `list` : List of pair numbers (list[i] contains some pairs like (j, w) that means `i` is connected to `j` with `w`, where `w` represents the weights between `i` and `j`)

#### Parameters
* `start` : Starting node (Source node)

#### Results
* `dis` : Array of minimum distances from source node to the others.
