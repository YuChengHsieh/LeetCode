# 1d dp (AC)
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        t_len = len(t)
        # DP[i] => indicate there are DP[i] ways to match t[:i-1] in s[:i-1] plus cur cursor s[i]
        DP = [0 for _ in range(t_len+1)]
        DP[0] = 1
        hash_map = {}
        # larger indexs should place first
        for i in range(t_len,0,-1):
            if hash_map.get(t[i-1]) is None:
                hash_map[t[i-1]] = []
            hash_map[t[i-1]].append(i)
        
        for char in s:
            if hash_map.get(char) is not None:
                for str_idx in hash_map[char]:
                    DP[str_idx] += DP[str_idx-1]
        return DP[t_len]

# 2d dp (AC)
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        t_len = len(t)
        s_len = len(s)
        DP = [[0 for _ in range(t_len+1)] for _ in range(s_len+1)]
        for i in range(s_len):
            DP[i][0]=1
        # tabular
        # DP[i][j] => indicates there are DP[i][j] ways to match t[:j-1] in s[:i-1]
        for i in range(1,s_len+1):
            for j in range(1,t_len+1):
                if s[i-1] == t[j-1]:
                    DP[i][j] =  DP[i-1][j] + DP[i-1][j-1]
                else:
                    DP[i][j] += DP[i-1][j]

        return DP[s_len][t_len]