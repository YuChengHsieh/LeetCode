class Solution:
    def makeEqual(self, words: list[str]) -> bool:
        dict_ = {}

        for word in words:
            for ch in word:
                if ch not in dict_: dict_[ch] = 0
                dict_[ch] += 1

        for val in dict_.values():
            if val%len(words) != 0: return False
        return True