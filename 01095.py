# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        # pick finding
        start = 0; end = mountain_arr.length()-1
        while start < end:
            mid = start+(end-start)//2
            val = mountain_arr.get(mid)
            if mid+1 < mountain_arr.length() and \
            val < mountain_arr.get(mid+1): start = mid+1
            else: end = mid
        if mountain_arr.get(start) == target: return start
        top = start
        
        # find val
        start = 0; end = top-1
        while start <= end:
            mid = start+(end-start)//2
            val = mountain_arr.get(mid) 
            if val < target: start = mid+1 
            elif val > target: end = mid -1
            else: return mid
        
        start = top+1; end = mountain_arr.length()-1
        while start <= end:
            mid = start+(end-start)//2
            val = mountain_arr.get(mid) 
            if val < target: end = mid -1 
            elif val > target: start = mid+1 
            else: return mid
        return -1