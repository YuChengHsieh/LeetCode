class Solution:
    def sortArrayByParityII(self, nums: list[int]) -> list[int]:
        n = len(nums)
        odd_cnt = 1
        for i in range(0,n,2):
            if nums[i]%2 == 1:
                while odd_cnt < n and nums[odd_cnt]%2 == 1:
                    odd_cnt += 2
                nums[i],nums[odd_cnt] = nums[odd_cnt],nums[i]
        return nums