# save memory DP o(h*w)
class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        prev = triangle[0]
        cur = triangle[0]
        height = len(triangle)

        for h in range(1,height):
            cur = []
            cur_width = len(triangle[h])
            for i in range(cur_width):
                if i == 0:  
                # most left route
                    """  
                         1
                        /
                       2   3
                      /
                     4   5   6
                    /
                   7   8   9   10     
                    """
                    cur.append(prev[i]+triangle[h][i])
                elif i == cur_width-1:
                # most right route
                    """  
                     1
                      \
                   2   3
                        \
                 4   5   6
                          \
               7   8   9   10     
                    """
                    cur.append(prev[i-1]+triangle[h][i])
                else:
                    # encounter in same node, choose the minimum cnt of two routes
                    """  
                     1
                    / \
                   2   3
                    \   \
                 4   5   6
                      \ /
               7   8   9   10
                    encounter in 9, choose min(1+2+5,1+3+6)     
                    """
                    val = min(prev[i-1]+triangle[h][i],prev[i]+triangle[h][i])
                    cur.append(val)
            prev = cur
        return min(cur)