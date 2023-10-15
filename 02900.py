# greedy
class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: list[str], groups: list[int]) -> list[str]:
        ans = [words[0]]
        for i in range(1,len(groups)):
            if groups[i] != groups[i-1]: ans.append(words[i])
        return ans