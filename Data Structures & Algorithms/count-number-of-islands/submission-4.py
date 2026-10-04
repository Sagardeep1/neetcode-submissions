class Solution:
    def __init__(self):
        self.vis = []

    def dfs(self, grid, r, c):
        if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == "0" or self.vis[r][c] == True:
            return
        self.vis[r][c] = True
        for dr, dc in ((0,-1), (1,0), (0,1), (-1,0)):
            self.dfs(grid, r+dr, c+dc)
        return

    
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        self.vis = [[False] * n for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '0' or self.vis[i][j] == True:
                    continue
                ans += 1
                #print(i,j)
                self.dfs(grid, i, j)
        
        return ans
        