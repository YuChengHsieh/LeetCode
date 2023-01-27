# backtracking (TLE)
# class Solution:
#     def climbStairs(self, n: int) -> int:
#         return 1 if n == 0 or n == 1 else self.climbStairs(n-2)+self.climbStairs(n-1)

# DP (kind of Fibonacci)
class Solution:
    def climbStairs(self, n: int) -> int:
        total_ways = [0 for _ in range(n+1)]
        total_ways[0] = 1
        total_ways[1] = 1
        for i in range(2,n+1):
            total_ways[i] = total_ways[i-1]+total_ways[i-2]
        return total_ways[n]
        

if __name__ == '__main__':
    a = Solution()
    print(a.climbStairs(2))
    print(a.climbStairs(4))
            