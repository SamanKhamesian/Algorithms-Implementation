#  Bridges Check

An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components.
Like Articulation Points, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks.
For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the critical wires or connections.

#### Variables
* `n` : Number of nodes in graph
* `m` : Number of edges in graph
* `list` : List of neighbours for each node

#### Parameters
* `start` : Starting node (Current position)
* `dfsCount` : Depth of the search

#### Results
* `bridges` : Set of pairs like (`i`, `j`) that `i` and `j` are the nodes of the bridge
