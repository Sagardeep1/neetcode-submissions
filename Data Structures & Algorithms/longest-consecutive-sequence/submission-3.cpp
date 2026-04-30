class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 1;
        map<int,bool> present;
        for(auto& num:nums) {
            present[num] = true;
        }
        for(auto& num:nums){
            if(present[num-1]) continue;
            int temp = 0;
            for(int i=num;;i++) {
                cout<<i<<" ";
                if(!present[i])
                    break;
                temp++;
            }
            cout<<endl;
            //cout<<temp<<" ";
            ans = max(ans,temp);
        }
        return ans;
    }
};
