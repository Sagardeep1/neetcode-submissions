class DSU {
    vector<int> Parent, Size;
    int comps;

public:
    DSU(int n) {
        comps = n;
        Parent.resize(n);
        Size.resize(n);
        for(int i=0;i<n;i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node) {
        if(node != Parent[node]) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool Union(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) 
            return false;
        if(Size[pa] >= Size[pb]) {
            Size[pa] += Size[pb];
            Parent[pb] = pa;
        }
        else {
            Size[pb] += Size[pa];
            Parent[pa] = pb;
        }
        comps--;
        return true;
    }

    int getComps() {
        return comps;
    } 
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto edge:edges) {
            if(!dsu.Union(edge[0],edge[1]))
                return false;
        }
        if(dsu.getComps() == 1) return true;
        return false;
    }
};
