class Solution:
    def countHillValley(self, nums: list[int]) -> int:
        val = 0 # 1: increase, -1 decrease, 0 non of them
        cnt = 0
        for i in range(len(nums)-1):
            if nums[i+1]-nums[i] > 0:
                if val == -1:
                    cnt += 1
                val = 1
            elif nums[i+1]-nums[i] < 0:
                if val == 1:
                    cnt += 1
                val = -1
        return cnt
            