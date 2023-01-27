# o(n^2)
# class Solution:
#     def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
#         """
#         Do not return anything, modify nums1 in-place instead.
#         """
#         nums1_len = m+n
#         nums2_len = n
#         nums1_idx = 0
#         nums2_idx = 0
#         nums1_end = m
        
#         while nums2_idx != nums2_len:
#             if nums1_idx == nums1_end:
#                 for i in range(nums1_idx,nums1_len):
#                     nums1[i] = nums2[nums2_idx]
#                     nums2_idx += 1 
#                 break      
#             elif nums1[nums1_idx] > nums2[nums2_idx]:
#                 for i in range(nums1_end,nums1_idx,-1):
#                     nums1[i] = nums1[i-1]
#                 nums1[nums1_idx] = nums2[nums2_idx]
#                 nums1_end += 1
#                 nums2_idx += 1
#             nums1_idx += 1 
#         print(nums1)

# o(n)
class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        idx = m+n-1
        nums1_idx,nums2_idx = m-1,n-1

        while nums2_idx >= 0:
            if nums1_idx >= 0 and nums1[nums1_idx] > nums2[nums2_idx]:
                nums1[idx] = nums1[nums1_idx]
                nums1_idx -= 1
            else:
                nums1[idx] = nums2[nums2_idx]
                nums2_idx -= 1
            idx -= 1
        print(nums1)
        
if __name__ == '__main__':
    a = Solution()
    a.merge([1,2,3,0,0,0],3,[2,5,6],3)
    a.merge([1],1,[],0)
    a.merge([0],0,[1],1)
    a.merge([4,5,6,0,0,0],3,[1,2,3],3)