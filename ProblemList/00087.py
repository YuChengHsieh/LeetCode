# backtracking (WA)
# class Solution:
#     def isScramble(self, s1: str, s2: str) -> bool:
#         if len(s1) == 1:
#             return True if s1 == s2 else False
#         def rec(str_,start,end):
#             for cnt,i in enumerate(range(start+1,end)):
#                 # no swap
#                 str_1 = str_[:start]+str_[start:i]+str_[i:end]+str_[end:]
#                 if end-i>1:
#                     ret = rec(str_1,i,end)
#                     if ret: return True
#                 if i-start>1:
#                     ret = rec(str_1,start,i)
#                     if ret: return True
#                 # after swap
#                 str_2 = str_[:start]+str_[i:end]+str_[start:i]+str_[end:]
#                 if (end-cnt-1)-start>1: 
#                     ret = rec(str_2,start,end-cnt-1) 
#                     if ret: return True
#                 if end-(end-cnt-1)>1:
#                     ret = rec(str_2,end-cnt-1,end)
#                     if ret: return True
                
#                 if str_1 == s2 or str_2 == s2:
#                     return True

#             return False
#         return self.rec(s1,0,len(s1))

# backtracking (TLE)
# class Solution:
#     def isScramble(self, s1: str, s2: str) -> bool:
#         self.dict = {}
#         def rec(str_):
#             if len(str_) == 1:
#                 return set(str_)
#             tmp_set = set()
#             for i in range(1,len(str_)):
#                 ret_set1 = rec(str_[:i])
#                 ret_set2 = rec(str_[i:])
#                 for str1 in ret_set1:
#                     for str2 in ret_set2:
#                         tmp_set.add(str1+str2)
#                         tmp_set.add(str2+str1)
#             return tmp_set
#         all_poss = rec(s1)
#         return True if s2 in all_poss else False

# backtracking + DP
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        dict_ = {}
        def rec(s1,s2):
            s_len = len(s1)
            print(s1,s2,dict_)
            if s_len == 1:
                dict_[(s1,s2)] = s1 == s2
                return s1 == s2
            if (s1,s2) in dict_:
                return dict_[(s1,s2)]
            
            for i in range(1,s_len):
                # non-swap string
                match_1 = rec(s1[:i],s2[:i]) and rec(s1[i:],s2[i:])   
                # swap string
                match_2 = rec(s1[:i],s2[s_len-i:]) and rec(s1[i:],s2[:s_len-i])
                
                if match_1 or match_2:
                    dict_[(s1,s2)] = True
                    return True    

            dict_[(s1,s2)] = False
            return False
        
        return rec(s1,s2)

if __name__ == '__main__':
    a = Solution()
    # print(a.isScramble('a','a'))
    print(a.isScramble('bcd','cdb'))
    # print(a.isScramble('great','rgeat'))
    # print(a.isScramble('abcde','caebd'))
    # print(a.isScramble('abcd','badc'))
    # print(a.isScramble('abcdbdacbdac','bdacabcdbdac'))
    # print(a.isScramble('abcdefghijklmn','efghijklmncadb'))