# Peaking finding
class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        start,end = 0,len(nums)-1
        while start <= end:
            mid = start + (end-start)//2
            if ((mid-1 >= 0 and nums[mid] > nums[mid-1]) or mid-1<0) and ((mid+1 < len(nums)  and nums[mid] > nums[mid+1]) or mid+1 > len(nums)):
                return mid
            elif mid-1 >= 0 and nums[mid-1] >= nums[mid]:
                end = mid-1
            else:
                start = mid+1
        return mid