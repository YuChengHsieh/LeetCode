import math
class Solution:
    def countAnagrams(self, s: str) -> int:
        mod = 10**9+7
        ans = 1
        cnt = [0]*26
        for ch in s:
            if ch == " ":
                total = 0
                divisor = 1 
                for i in range(26):
                    total += cnt[i]
                    if cnt[i] < 2: continue
                    divisor *= math.factorial(cnt[i])
                # print(divisor,total,cnt)
                ans *= math.factorial(total)//divisor
                ans %= mod
                cnt = [0]*26
            else:
                cnt[ord(ch)-ord('a')] += 1
        else:
            total = 0
            divisor = 1 
            for i in range(26):
                total += cnt[i]
                if cnt[i] < 2: continue
                divisor *= math.factorial(cnt[i])
            # print(divisor,total,cnt)
            ans *= math.factorial(total)//divisor
            ans %= mod
    
        return ans
