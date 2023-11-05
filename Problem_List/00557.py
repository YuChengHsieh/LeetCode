class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([ tmp_s[::-1] for tmp_s in s.split(" ")])