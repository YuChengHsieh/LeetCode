class Solution:
    def maximumSetSize(self, nums1: list[int], nums2: list[int]) -> int:
        
        nums1_set = set(nums1)
        nums2_set = set(nums2)
        
        nums1_rm = max(0,len(nums1_set)-len(nums1)//2)
        nums2_rm = max(0,len(nums2_set)-len(nums2)//2)
        total_rm = nums1_rm + nums2_rm
        combined_set = set(nums1_set.union(nums2_set))
        
        total_rm = max(0, total_rm-(len(nums1_set)+len(nums2_set) - len(combined_set)))
        return len(combined_set) -total_rm
        