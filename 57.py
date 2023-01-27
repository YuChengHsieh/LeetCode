class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        
        if len(intervals) == 0:
            intervals.append(newInterval)
            return intervals
        
        intervals_flatten = [num for interval in intervals for num in interval]
        
        start_val,end_val = newInterval[0],newInterval[1]
        
        start_index = self.BST(intervals_flatten,newInterval[0])
        end_index = self.BST(intervals_flatten,newInterval[1])
        
        change_interval = []
        if start_index%2 == 0: #at left interval
            change_interval.append(start_val)
            start_rmIdx = start_index//2-1 if start_val == intervals[start_index//2-1][1] else start_index//2
        else: #at right interval
            change_interval.append(intervals[start_index//2][0])
            start_rmIdx = start_index//2
            
        if end_index%2 == 1 or (end_index//2 < len(intervals) and end_val == intervals[end_index//2][0]): #at right interval
            change_interval.append(intervals[end_index//2][1])
            end_rmIdx = end_index//2
        else: #at right interval
            change_interval.append(end_val)
            end_rmIdx = end_index//2 -1

        # generate ret list
        del intervals[start_rmIdx:end_rmIdx+1]
        intervals.insert(start_rmIdx,change_interval)
        return intervals
        
    def BST(self, nums_list: list, target: int):

        start_idx,end_idx = 0, len(nums_list)-1
        
        while start_idx <= end_idx:
            mid_idx = (start_idx+end_idx)//2
            mid_val = nums_list[mid_idx]
            
            if mid_val == target:
                return mid_idx
            elif target < mid_val:
                end_idx = mid_idx-1
            else:
                start_idx = mid_idx+1
        
        return start_idx 
        
if __name__ == '__main__':
    a = Solution()
    print(a.insert([[1,5]],[2,7]))
    print(a.insert([[1,3],[6,9]],[2,5]))
    print(a.insert([[1,2],[3,5],[6,7],[8,10],[12,16]],[4,8]))
    