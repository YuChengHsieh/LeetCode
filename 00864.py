# Bit operation and BFS
"""
    keys: _ _ _ _ _ _ 
    six digit present at most six keys
"""
class Solution:
    def shortestPathAllKeys(self, grid: list[str]) -> int:
        col_len = len(grid)
        row_len = len(grid[0])
        queue = []
        key_hash = {}
        bit = 0
        for i in range(col_len):
            for j in range(row_len):
                if ord(grid[i][j])- ord('a') >= 0 and ord(grid[i][j])- ord('a') < 26:
                    key_hash[grid[i][j]] = bit
                    bit += 1
                elif grid[i][j] == '@':
                    start_pt = (i,j,0,0)
        visited = [[[False for _ in range(1<<len(key_hash))] for _ in range(row_len)] for _ in range(col_len)]
        queue.append(start_pt)
        while len(queue) != 0:
            x,y,step,keys = queue.pop(0)
            # print(x,y,step,bin(keys))
            
            if x < 0 or x >= col_len or y < 0 or y >= row_len or grid[x][y] == '#':
                continue
            # find key
            elif ord(grid[x][y])- ord('a') >= 0 and ord(grid[x][y])- ord('a') < 6 and not keys >> key_hash[grid[x][y]] & 1:
                keys += 1 << key_hash[grid[x][y]] 
                if keys == (1 << len(key_hash))-1: # contain all keys
                    return step
            
            #find lock
            elif ord(grid[x][y])- ord('A') >= 0 and ord(grid[x][y])- ord('A') < 6 and not keys >> key_hash[grid[x][y].lower()] & 1:
                # if grid[x][y].lower() not in keys:
                    continue
            
            if visited[x][y][keys]:
                continue
            
            visited[x][y][keys] = True
            step += 1
            queue.append((x-1,y,step,keys))
            queue.append((x+1,y,step,keys))
            queue.append((x,y-1,step,keys))
            queue.append((x,y+1,step,keys))
        return -1
            