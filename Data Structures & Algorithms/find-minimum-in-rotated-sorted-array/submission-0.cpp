class Solution {
public:
    int findMin(vector<int> &nums) {
         int n = nums.size();
         if(n == 1) return nums[0];
         else if(n == 2) return min(nums[0],nums[1]);
         else if(nums[0] < nums[n-1]) return nums[0];
         int l=0,r=n-1,mid;
         while(l < r) {
            mid = (l+r)/2;
            if(nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid])
                return nums[mid];
            else if(nums[mid+1] < nums[mid])
                return nums[mid+1];
            else if(nums[mid] > nums[n-1])
                l = mid+1;
            else r = mid-1;
         }
         return nums[mid];
    }
};
