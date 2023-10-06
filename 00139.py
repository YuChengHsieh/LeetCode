class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = {}
        for word in wordDict:
            if not words.get(len(word)): words[len(word)] = []
            words[len(word)].append(word)

        dp = [False for _ in range(len(s)+1)]
        dp[0] = True

        for i in range(len(s)+1):
            for key,value in words.items():
                if i-key >= 0 and dp[i-key]:
                    dp[i] = dp[i-key] and (s[i-key:i] in value)
                if dp[i]: break
        return dp[-1] 