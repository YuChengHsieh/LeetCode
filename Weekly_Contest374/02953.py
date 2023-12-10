class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        ans = 0 
        len_word = len(word)

        for i in range(1,27):
            if i*k > len_word: break
            prev = ' '
            check = [0]*26
            left = right = 0
            while right <= len_word:
                if right - left == i*k:
                    for char_cnt in check:
                        if char_cnt not in [0,k]: break
                    else:
                        ans += 1
                    check[ord(word[left])-ord('a')] -= 1
                    left += 1
                
                if right == len_word: break
                if abs(ord(word[right]) - ord(prev)) > 2:
                    check = [0]*26
                    left = right
    
                prev = word[right]
                check[ord(word[right])-ord('a')] += 1
                right += 1  
        return ans