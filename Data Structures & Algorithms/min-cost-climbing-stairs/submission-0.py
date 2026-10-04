class Solution:
    def __init__(self):
        self.dp = []

    def recursion(self, cost, ind):
        if self.dp[ind] != -1:
            return self.dp[ind]
        if ind == 0 or ind == 1:
            return 0
        self.dp[ind] = min(cost[ind-2] + self.recursion(cost, ind-2), cost[ind-1] + self.recursion(cost, ind-1))
        return self.dp[ind]


    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        self.dp = [-1] * (n + 1)
        ans = self.recursion(cost, n)
        return ans