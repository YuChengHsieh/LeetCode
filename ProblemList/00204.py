class Solution:
    def countPrimes(self, n: int) -> int:
        nums = [True for _ in range(n)]
        cnt = 0
        for i in range(2,n):
            if nums[i]:
                cnt += 1
                for j in range(i*2,n,i):
                    nums[j] = False
        return cnt