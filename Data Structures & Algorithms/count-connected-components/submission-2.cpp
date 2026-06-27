class DSU {
    vector<int> Parent, Size;

public:
    DSU(int n) {
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

    void Union(int a, int b) {
        int pa = find(a), pb = find(b);
        if(Size[pa] >= Size[pb]) {
            Size[pa] += Size[pb];
            Parent[pb] = pa;
        }
        else {
            Size[pb] += Size[pa];
            Parent[pa] = pb;
        }
    }

    int getComps() {
        int comps = 0;
        for(int i=0;i<Parent.size();i++)
            if(Parent[i] == i)
                comps++;
        return comps;
    } 
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto edge:edges)
            dsu.Union(edge[0],edge[1]);
        return dsu.getComps();
    }
};
