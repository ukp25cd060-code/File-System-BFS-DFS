# File System Representation and Search Using BFS and DFS

**Challenge:** 17-B09 — Data Structures and Algorithms  
**Language:** C

## Aim
To represent a file system as a graph using an adjacency matrix and search for a specified file using Breadth-First Search (BFS) and Depth-First Search (DFS).

## Concepts
- Each file or directory is represented as a graph vertex (node).
- A connection between two files/directories is represented as an edge.
- The adjacency matrix stores the connections.
- BFS uses a queue and visits nodes level by level.
- DFS uses recursion and explores a path before backtracking.

## Files
- `main.c` — Complete C source code.
- `sample_input.txt` — Sample input.
- `sample_output.txt` — Expected output for the sample input.

## Compile and run
Using GCC:

```bash
gcc main.c -o file_search
./file_search
```

On Windows:

```bash
gcc main.c -o file_search.exe
file_search.exe
```

## Sample graph
The sample uses five nodes: Root, Documents, Images, Report, and Notes.
The graph is undirected, so each connection appears in both directions in the adjacency matrix.

## Complexity
For an adjacency matrix, both BFS and DFS take O(V^2) time, where V is the number of vertices. The adjacency matrix uses O(V^2) space.

## Notes
- Enter node names as one word (no spaces).
- Enter `0` or `1` for each adjacency-matrix entry.
- Starting node numbers are 1-based.
