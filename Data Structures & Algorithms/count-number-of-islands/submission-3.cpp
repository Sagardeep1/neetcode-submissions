class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) {
        Parent.resize(n+1);
        Size.resize(n+1);
        for(int i=0;i<=n;i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

        int find(int node) {
            if(Parent[node] != node) {
                Parent[node] = find(Parent[node]);
            }
            return Parent[node];
        }

        bool unionBySize(int ind1, int ind2) {
            int p1 = find(ind1);
            int p2 = find(ind2);
            if(p1 == p2) return false;
            if(Size[p1] >= Size[p2]) {
                Size[p1] += Size[p2];
                Parent[p2] = p1;
            }
            else {
                Size[p2] += Size[p1];
                Parent[p1] = p2;
            }
            return true;
        }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        DSU dsu(ROWS * COLS);
        auto index = [&](int r, int c) {
            return r * COLS + c;
        };
        auto isValid = [&](int r, int c) {
            if(r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c] == '1')
                return true;
            return false;
        };
        for(int i=0;i<ROWS;i++) {
            for(int j=0;j<COLS;j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    for(auto& vec:directions) {
                        int x = i + vec[0];
                        int y = j + vec[1];
                        if(isValid(x,y)) {
                            if(dsu.unionBySize(index(i,j), index(x,y)))
                                islands--;
                        }
                    }
                }
            }
        }
        return islands;
    }
};
