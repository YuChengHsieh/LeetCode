class Solution:
    def sortSentence(self, s: str) -> str:
        splited_s = s.split(" ")
        splited_s.sort(key = lambda s: int(s[-1]))
        splited_s = [s[:-1] for s in splited_s]
        return " ".join(splited_s)