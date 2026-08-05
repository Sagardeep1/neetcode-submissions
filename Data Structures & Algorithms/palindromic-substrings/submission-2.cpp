class Solution {
public:
    vector<int> manacher(string& s) {
        string temp = "#";
        for(char ch:s) {
            temp += string(1,ch) + "#";
        }
        int n = temp.size();
        vector<int> p(n,0);
        int l = 0, r = 0;
        for(int i=0;i<n;i++) {
            p[i] = i < r ? min(r-i, p[l+r-i]) : 0;
            while(i+p[i]+1 < n && i-p[i]-1 >= 0
                && temp[i+p[i]+1] == temp[i-p[i]-1])
                p[i]++;
            if(i+p[i] > r) {
                l = i-p[i], r = i+p[i];
            }
        }
        return p;
    }

    int countSubstrings(string s) {
        vector<int> p = manacher(s);
        int ans = 0;
        for(int rad:p)
            ans += (rad + 1) / 2;
        return ans;
    }
};
