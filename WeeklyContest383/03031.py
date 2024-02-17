# h function
class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        def z_function(word):
            left = 0; right = 0
            z_func = [0]*len(word)
            for i in range(1,len(word)):
                # have repeated prefix string, no need to traverse again
                if i < right:
                    z_func[i] = min(right-i,z_func[i-left])
                # traverse to get prefix string 
                while i+z_func[i] < len(word) and word[z_func[i]] == word[i+z_func[i]]:
                    z_func[i] += 1
                # update left and right pointer 
                if i+z_func[i] > right:
                    left = i
                    right = i+z_func[i]
            return z_func
        
        z_func = z_function(word)
        ans = 1
        while ans*k < len(word):
            if(z_func[ans*k] >= len(word)-(ans*k)): return ans
            ans += 1
        return ans

from math import ceil
# kmp
class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        def cal_lps(word):
            idx = 1; prev = 0
            lps = [0]*len(word)

            while idx < len(word):
                if word[idx] == word[prev]:
                    lps[idx] = prev+1
                    idx += 1; prev += 1
                elif prev == 0: idx += 1
                else: prev = lps[prev-1]
            return lps

        lps = cal_lps(word)
        val = lps[-1]

        while val > 0 and (len(word)-val)%k != 0:
            val = lps[val-1]
        
        return ceil((len(word)-val)/k)
