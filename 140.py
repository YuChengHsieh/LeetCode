class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
        ans = []
        wordDict = set(wordDict)
        def rec(s,tmp_str):
            if len(s) == 0:
                ans.append(tmp_str[:-1])
            tmp_s = ""
            for i,char in enumerate(s):
                tmp_s += char
                if tmp_s in wordDict:
                    tmp_str += tmp_s+' '
                    rec(s[i+1:],tmp_str)
                    tmp_str = tmp_str[:-len(tmp_s)-1]
            return
        rec(s,'')
        return ans