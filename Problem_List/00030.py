class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        check_words = {}
        for word in words:
            if check_words.get(word) is None:
                check_words[word] = 1
            else:
                check_words[word] += 1
        
        s_len = len(s)
        word_len = len(words[0])
        word_totalLen = word_len*len(words)
        ans_list = []
        for start_idx in range(s_len-word_totalLen+1):
            ans_words = {}
            tmp_startIdx = start_idx
            for tmp_endIdx in range(start_idx+word_len,start_idx+word_totalLen+1,word_len): # sliding window
                if check_words.get(s[tmp_startIdx:tmp_endIdx]) is None: # don't have same words
                    break
                else:
                    ans_words[s[tmp_startIdx:tmp_endIdx]] = 1 if ans_words.get(s[tmp_startIdx:tmp_endIdx]) is None \
                        else ans_words[s[tmp_startIdx:tmp_endIdx]] + 1
                tmp_startIdx = tmp_endIdx
            else:
                if ans_words == check_words:
                    ans_list.append(start_idx)
        
        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.findSubstring("barfoothefoobarman",["foo","bar"]))
    print(a.findSubstring("wordgoodgoodgoodbestword",["word","good","best","word"])) 
    print(a.findSubstring("barfoofoobarthefoobarman",["bar","foo","the"])) 