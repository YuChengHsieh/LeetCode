class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        n = len(points)
        ans = 0
        points.sort(key = lambda a: (a[0],-a[1]))
        for i in range(n):
            for j in range(i+1,n):
                if points[i][0] <= points[j][0] and points[i][1] >= points[j][1]:
                    if i+1 == j: ans += 1
                    else:
                        for k in range(i+1,j):
                            if points[i][0] <= points[k][0] <= points[j][0] and points[i][1] >= points[k][1] >= points[j][1]: break
                        else:
                            ans += 1
        return ans