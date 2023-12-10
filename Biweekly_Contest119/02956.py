class Solution:
    def findIntersectionValues(self, nums1: list[int], nums2: list[int]) -> list[int]:
        set1 = set(nums1)
        set2 = set(nums2)
        
        ans = [0]*2
        for i,num in enumerate(nums1[::-1]):
            if num in set2:
                ans[0] += 1
        for i,num in enumerate(nums2[::-1]):
            if num in set1:
                ans[1] += 1
        
        return ans
        
        