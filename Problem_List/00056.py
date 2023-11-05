class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        prev_start, prev_end = intervals[0][0],intervals[0][1]
        ret_list = [[prev_start,prev_end]]
        idx = 0
        for start,end in intervals[1:]:
            if start <= prev_end and end > prev_end: #interval overlap
                ret_list[idx][0] = prev_start
                ret_list[idx][1] = end
            elif start > prev_end:
                ret_list.append([start,end])
                idx += 1
            prev_start, prev_end = ret_list[idx][0],ret_list[idx][1]
        return ret_list

if __name__ == '__main__':
    a = Solution()
    print(a.merge([[1,3],[2,6],[8,10],[15,18]]))
    print(a.merge([[1,4],[4,5]]))
    print(a.merge([[0,2],[1,4],[3,5]]))