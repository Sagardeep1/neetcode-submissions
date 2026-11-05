class Solution {
    List<HashMap<Integer, Boolean>> dp = new ArrayList<>();

    private boolean rec_func(int[] nums, int ind, int sum) {
        if (sum == 0)
            return true;
        else if (sum < 0)
            return false;
        if(ind >= nums.length) {
            return false;
        }
        if (dp.get(ind).containsKey(sum))
            return dp.get(ind).get(sum);
        boolean res = rec_func(nums, ind+1, sum-nums[ind]) ||
            rec_func(nums, ind+1, sum);
        dp.get(ind).put(sum, res);
        return res;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;
        if (sum % 2 == 1)
            return false;
        for(int i=0;i < nums.length; i++){
            dp.add(new HashMap<Integer, Boolean>());
        }
        return rec_func(nums,0,sum/2);
    }
}
