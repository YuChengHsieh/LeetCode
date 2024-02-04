class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        dict_ = {}
        max_sublen = -1

        for i in range(len(s)):
            if s[i] not in dict_: dict_[s[i]] = i
            else: max_sublen = max(max_sublen,i-dict_[s[i]]-1)
        return max_sublen