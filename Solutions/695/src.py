
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(x, y, grid):
            
            def check(dx, dy, n, m):
                if(dx < 0 or dx >= n):
                    return False
                if(dy < 0 or dy >= m):
                    return False
                return True
            
            cnt = 1
            grid[x][y] = 0

            dir = [[0, -1], [0, 1], [-1, 0], [1, 0]]
            for i in range(4):
                dx = x + dir[i][0]
                dy = y + dir[i][1]
                if(check(dx, dy, len(grid), len(grid[0])) == True and grid[dx][dy] == 1):
                    cnt += dfs(dx, dy, grid)
            return cnt

        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j] == 1):   
                    ans = max(ans, dfs(i, j, grid))
                    
        return ans