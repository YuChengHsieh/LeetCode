class Solution:
    def canSortArray(self, nums: list[int]) -> bool:
        
        def cal_bit(num):
            cnt = 0
            while num != 0:
                cnt += 1
                num &= (num-1)
            return cnt
        
        for i in range(1,len(nums)):
            idx = i-1
            tmp_val = nums[i]
            while idx >= 0 and tmp_val < nums[idx]  and cal_bit(tmp_val) == cal_bit(nums[idx]): idx -= 1

            if (idx >= 0 and tmp_val >= nums[idx]) or (idx+1 < len(nums) and tmp_val <= nums[idx+1]):
                nums.pop(i)
                nums.insert(idx+1,tmp_val)
            else: return False
            
        return True if sorted(nums) == nums else False
                