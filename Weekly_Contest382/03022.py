class Solution:
    def minOrAfterOperations(self, nums: list[int], k: int) -> int:
        ans = 0
        for i in range(30,-1,-1):
            
            cur = (1<<30) -1
            cnt = 0
            target = ans | (1 << i) -1 
            print(ans, (1 << i) -1, target)
            for num in nums:
                cur &= num
                if cur | target == target:
                    cnt += 1
                    cur = (1<<30) -1

            if len(nums)-cnt > k:
                ans += (1 << i)
        return ans