class Solution:
    def canJump(self, nums: list[int]) -> bool:
        cur_pos = 0
        nums_len = len(nums)
        
        while cur_pos+nums[cur_pos] < nums_len-1:
            if nums[cur_pos] == 0:
                return False
            max_mv = 0
            next_pos = 0
            for idx in range(cur_pos+1,cur_pos+nums[cur_pos]+1):
                if idx+nums[idx] >= max_mv:
                    max_mv = idx+nums[idx]
                    next_pos = idx
            
            cur_pos = next_pos
        
        return True

if __name__ == '__main__':
    a = Solution()
    print(a.canJump([2,3,1,1,4]))
    print(a.canJump([3,2,1,0,4]))
    print(a.canJump([2,0]))
                    