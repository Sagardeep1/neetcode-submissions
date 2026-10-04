def isValid(grid, r, c):
    if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == -1:
        return False
    return True


class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        qu = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    qu.append((i,j))
        count = 0
        while qu:
            qu_len = len(qu)
            for _ in range(qu_len):
                r, c = qu.popleft()
                #grid[r][c] = count

                for dr, dc in ((-1, 0), (0, -1), (1,0), (0, 1)):
                    r_ = r + dr
                    c_ = c + dc
                    if not isValid(grid, r_, c_) or grid[r_][c_] <= count+1:
                        continue
                    grid[r_][c_] = count+1
                    qu.append((r_,c_))
            
            count += 1
        return