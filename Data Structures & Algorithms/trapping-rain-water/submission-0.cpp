class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l_max(n,0), r_max(n,0);
        int ref = height[0];
        for(int i=1;i<n;i++) {
            l_max[i] = ref;
            ref = max(ref,height[i]);
        }
        ref = height[n-1];
        for(int i=n-2;i>=0;i--) {
            r_max[i] = ref;
            ref = max(ref,height[i]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++) {
            int local_max = min(l_max[i], r_max[i]);
            ans += max(0, local_max-height[i]);
        }
        return ans;
    }
};
