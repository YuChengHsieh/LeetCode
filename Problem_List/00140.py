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
                    rec(s[i+1:],tmp_str+tmp_s+' ')
            return
        rec(s,'')
        return ans

class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
        ans = []
        from collections import defaultdict
        words = defaultdict(lambda:[])

        for word in wordDict:
            words[word[0]].append(word)

        def rec(start_idx,tmp_str):
            if start_idx == len(s):
                ans.append(tmp_str[:-1])
                return
            
            for word in words[s[start_idx]]:
                if s[start_idx:start_idx+len(word)] == word:
                    rec(start_idx+len(word),tmp_str+word+' ')
        rec(0,'')
        return ans