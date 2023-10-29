# dp memorization
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod = 10**9+7
        mem = {}
        vowel_dict = {'a':('e'), 'e':('a','i'), 'i':('a','e','o','u'), 'o':('i','u'), 'u':('a')}

        def rec(char,n):
            if n == 1: return 1
            if (char,n) in mem: return mem[(char,n)]

            ans = 0
            for next_char in vowel_dict[char]:
                ans += rec(next_char,n-1)%mod
            mem[(char,n)] = ans%mod
            return mem[(char,n)]
        
        return sum([rec(char,n) for char in vowel_dict.keys()])%mod

# dp tabulation
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod = 10**9+7
        if n == 1: return 5
        prev_dp = [1,1,1,1,1]

        for _ in range(2,n+1):
            cur_dp = []
            # a
            cur_dp.append((prev_dp[1]+prev_dp[2]+prev_dp[4])%mod)
            # e
            cur_dp.append((prev_dp[0]+prev_dp[2])%mod)
            # i
            cur_dp.append((prev_dp[1]+prev_dp[3])%mod)
            # o
            cur_dp.append((prev_dp[2])%mod)
            # u
            cur_dp.append((prev_dp[2]+prev_dp[3])%mod)
            prev_dp = cur_dp
        return sum(cur_dp)%mod