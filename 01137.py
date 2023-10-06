# DP
class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0: return 0
        elif n == 1: return 1
        DP = [0 for _ in range(n+1)]
        DP[0] = 0; DP[1] = 1; DP[2] = 1
        for i in range(3,n+1):
            DP[i] = DP[i-3]+DP[i-2]+DP[i-1]
        return DP[n]

if __name__ == '__main__':
    a = Solution()
    print(a.tribonacci(1))
        