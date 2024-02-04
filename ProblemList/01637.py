class Solution:
    def maxWidthOfVerticalArea(self, points: list[list[int]]) -> int:
        points.sort(key = lambda x: x[0])
        ans = 0

        for i in range(1,len(points)):
            if points[i][0]-points[i-1][0] > ans: ans = points[i][0]-points[i-1][0]
        return ans