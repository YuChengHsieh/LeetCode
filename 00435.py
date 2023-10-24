class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda a: a[0], reverse = True)
        ans = [intervals[0]]
        cnt = 0
        for start,end in intervals[1:]:
            if ans[-1][0] >= end: ans.append([start,end])
            else: cnt += 1
        return cnt