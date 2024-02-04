# Top Down DP, o(n^2), TLE
class Solution:
    def mostPoints(self, questions: list[list[int]]) -> int:
        dp = [0 for _ in range(len(questions))]
        for i in range(len(questions)):
            for j in range(i):
                if i-j > questions[j][1]:
                    dp[i] = max(dp[i],dp[j])
            dp[i] +=  questions[i][0]
        return max(dp)

# Memorization Problem, skip or take
class Solution:
    def mostPoints(self, questions: list[list[int]]) -> int:
        dp = [-1 for _ in range(len(questions))]
        def rec(idx):
            if idx >= len(questions): return 0
            if dp[idx] != -1: return dp[idx]
            dp[idx] = max(rec(idx+1),rec(idx+questions[idx][1]+1)+questions[idx][0])
            return dp[idx]
        return rec(0)

# Bottom up DP o(n)
class Solution:
    def mostPoints(self, questions: list[list[int]]) -> int:
        dp = [0 for _ in range(len(questions))]
        dp[-1] = questions[-1][0]
        for i in range(len(questions)-2,-1,-1):
            next_ = i+questions[i][1]+1 if i+questions[i][1]+1<len(questions) else i
            dp[i] = max(dp[i+1],dp[next_]+questions[i][0])
        return max(dp)