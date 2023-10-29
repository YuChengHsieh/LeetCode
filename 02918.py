class Solution:
    def minSum(self, nums1: list[int], nums2: list[int]) -> int:
        m,n = len(nums1),len(nums2)
        nums1_zero = nums1.count(0); nums2_zero = nums2.count(0)
        nums1_sum = sum(nums1); nums2_sum = sum(nums2)
        if nums1_sum+nums1_zero > nums2_sum+nums2_zero and nums2_zero == 0: return -1
        if nums2_sum+nums2_zero > nums1_sum+nums1_zero and nums1_zero == 0: return -1
        return max(nums1_sum+nums1_zero,nums2_sum+nums2_zero)