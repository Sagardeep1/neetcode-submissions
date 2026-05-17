class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1,mid;
        while(l <= r) {
            mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) {
                if(nums[0] > nums[mid]) r = mid-1;
                else if(nums[0] <= target) r = mid-1;
                else l = mid+1;
            }
            else {
                if(nums[mid] > nums[n-1]) l = mid+1;
                else if(nums[n-1] >= target) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};
