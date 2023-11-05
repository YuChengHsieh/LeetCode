# backtracking TLE  time complexity : o((words length)^2*words[i] length), suitable for words length << words[i] length
# words length : 1~10^4, words[i] length : 1~30
# class Solution:
#     def findAllConcatenatedWordsInADict(self, words: list[str]) -> list[str]:
#         words.sort(key = lambda a : -len(a))
#         anslist = []
#         def rec(idx,word,tmp_str):
#             if word == '':
#                 anslist.append(tmp_str)
#                 return True

#             for str_ in words[idx+1:]:
#                 if word[:len(str_)] == str_:
#                     tmp_str += str_
#                     win = rec(idx,word[len(str_):],tmp_str)
#                     if win:
#                         return True
#                     tmp_str = tmp_str[:-len(str_)]
#             return False

#         for i,word in enumerate(words):
#             rec(i,word,'')
#         return anslist

# DP solution, time complexity: o(words length* (words[i] length)^2) 
# words length : 1~10^4, words[i] length : 1~30
class Solution:
    def findAllConcatenatedWordsInADict(self, words: list[str]) -> list[str]:
        words_set = set(words)
        ans_list = []
        for word in words_set:
            word_len = len(word)+1
            dp = [False for _ in range(word_len)]
            dp[0] = True
            for i in range(word_len-1):# start index
                if not dp[i]:
                    continue
                for j in range(i+1,word_len): # end index
                    if j-i < word_len-1 and word[i:j] in words_set: # check word[i:j] in set or not (o(1) checking time)
                        dp[j] = True
                if dp[word_len-1]:
                    ans_list.append(word)
                    break

        return ans_list
            
            

if __name__ == '__main__':
    a = Solution()
    print(a.findAllConcatenatedWordsInADict(["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]))
    print(a.findAllConcatenatedWordsInADict(["cat","dog","catdog"]))
    print(a.findAllConcatenatedWordsInADict(["cat","dog",'catd','og',"catdog"]))
        