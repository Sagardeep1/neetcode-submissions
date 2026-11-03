from collections import deque

def isValid(grid, r, c):
    if r >= 0 and r < len(grid) and c >= 0 and c < len(grid[0]) and grid[r][c] == 1:
        return True
    return False

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n_fresh, n_rotten = 0, 0
        qu = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    n_fresh += 1
                elif grid[i][j] == 2:
                    n_rotten += 1
                    qu.append((i,j))
        if n_fresh == 0:
            return 0
        elif n_rotten == 0:
            return -1
        count, ans = 0, 0
        dr_x = (-1,0,1,0)
        dr_y = (0,1,0,-1)

        while len(qu):
            qu_len = len(qu)
            count += qu_len
            ans += 1
            for _ in range(qu_len):
                x, y = qu.popleft()
                for i in range(4):
                    dx = x+dr_x[i]
                    dy = y+dr_y[i]
                    if isValid(grid, dx, dy):
                        qu.append((dx, dy))
                        grid[dx][dy] = 2

        if count == n_rotten + n_fresh:
            return ans-1
        else:
            return -1
        