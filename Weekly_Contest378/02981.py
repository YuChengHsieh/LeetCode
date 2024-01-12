class Solution:
    def maximumLength(self, s: str) -> int:
        left = right = 0
        n = len(s)
        dict_ = {}
        
        for i in range(n):
            for j in range(i,n):
                if s[j] == s[i]:
                    if s[i:j+1] not in dict_: dict_[s[i:j+1]] = 0
                    dict_[s[i:j+1]] += 1
                else: break
        
        max_len = 0
        for key,val in dict_.items():
            if val >= 3: max_len = max(max_len,len(key))
        
        return max_len if max_len != 0 else -1