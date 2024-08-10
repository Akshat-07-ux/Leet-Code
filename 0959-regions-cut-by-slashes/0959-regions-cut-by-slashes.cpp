class Solution {
public:
    int findParent(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = findParent(parent, parent[i]);
        }
        return parent[i];
    }
    
    void unionSet(vector<int>& parent, vector<int>& rank, int i, int j) {
        int rootI = findParent(parent, i);
        int rootJ = findParent(parent, j);
        if (rootI != rootJ) {
            if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            } else if (rank[rootI] < rank[rootJ]) {
                parent[rootI] = rootJ;
            } else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int totalCells = n * n * 4;  // Each cell has been divided into 4 parts.
        vector<int> parent(totalCells);
        vector<int> rank(totalCells, 0);
        
        for (int i = 0; i < totalCells; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int root = 4 * (i * n + j);
                char val = grid[i][j];
                
                if (val == '/') {
                    unionSet(parent, rank, root + 0, root + 3);  // Top-left with Bottom-right
                    unionSet(parent, rank, root + 1, root + 2);  // Top-right with Bottom-left
                } else if (val == '\\') {
                    unionSet(parent, rank, root + 0, root + 1);  // Top-left with Top-right
                    unionSet(parent, rank, root + 2, root + 3);  // Bottom-left with Bottom-right
                } else {
                    unionSet(parent, rank, root + 0, root + 1);  // Union all four parts
                    unionSet(parent, rank, root + 1, root + 2);
                    unionSet(parent, rank, root + 2, root + 3);
                }
                
                // Union current cell with the right cell
                if (j + 1 < n) {
                    unionSet(parent, rank, root + 1, 4 * (i * n + j + 1) + 3);  // Right side of current with Left side of right cell
                }
                
                // Union current cell with the bottom cell
                if (i + 1 < n) {
                    unionSet(parent, rank, root + 2, 4 * ((i + 1) * n + j) + 0);  // Bottom side of current with Top side of bottom cell
                }
            }
        }
        
        int regions = 0;
        for (int i = 0; i < totalCells; ++i) {
            if (findParent(parent, i) == i) {
                regions++;
            }
        }
        
        return regions;
    }
};
