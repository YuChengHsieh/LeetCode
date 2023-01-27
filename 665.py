class Solution:
    def checkPossibility(self, nums: list[int]) -> bool:
        cnt = 0
        nums_len = len(nums)
        # max_num = max(nums)
        for i in range(1,nums_len):
            if nums[i] - nums[i-1] < 0:
                cnt += 1
                """
                    .i-1
                i-2 /\    i+1
               ---./  \  /.---
                       \/ 
                        .i
                """
                if (i-2>=0 and i+1<nums_len and nums[i-2] > nums[i] and nums[i-1] > nums[i+1])  or cnt >= 2:
                    return False
        return True

