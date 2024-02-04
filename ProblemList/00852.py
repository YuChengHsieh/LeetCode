# Peak finding
class Solution:
    def peakIndexInMountainArray(self, arr: list[int]) -> int:
        # BS
        start,end = 0,len(arr)-1
        while start <= end:
            mid = start + (end-start)//2
            if ((mid-1 >= 0 and arr[mid] > arr[mid-1]) or mid-1<0) and ((mid+1 < len(arr)  and arr[mid] > arr[mid+1]) or mid+1 > len(arr)):
                return mid
            elif mid-1 >= 0 and arr[mid-1] >= arr[mid]:
                end = mid-1
            else:
                start = mid+1
        return mid

class Solution:
    def peakIndexInMountainArray(self, arr: list[int]) -> int:
        # BS
        start,end = 0,len(arr)-1
        while start <= end:
            mid = start + (end-start)//2
            if arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]:
                return mid
            elif mid-1 >= 0 and arr[mid-1] >= arr[mid]:
                end = mid-1
            else:
                start = mid+1
        return mid