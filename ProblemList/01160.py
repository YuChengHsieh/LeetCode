class Solution:
    def countCharacters(self, words: list[str], chars: str) -> int:
        chars_dict = {}
        for char in chars:
            if char not in chars_dict: chars_dict[char] = 0
            chars_dict[char] += 1
        
        ans = 0
        for word in words:
            tmp_dict = chars_dict.copy()
            for char in word:
                if char not in tmp_dict or tmp_dict[char] == 0: break
                tmp_dict[char] -= 1
            else:
                ans += len(word)
        return ans