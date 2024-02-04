class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        size = len(nums1)
        if size%2 == 0:
            return (nums1[int(size/2)]+nums1[int(size/2)-1])/2
        else:
            return nums1[int(size//2)]