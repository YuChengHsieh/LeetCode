# DP TLE
# class Solution:
#     def minWindow(self, s: str, t: str) -> str:
#         s_len = len(s)
#         DP = []
#         for i in range(s_len):
#             tmp = []
#             for j in range(s_len):
#                 if i == j:
#                     tmp.append({})
#                 else:
#                     tmp.append(False)
#             DP.append(tmp)

#         t_dict = {}
#         for char in t:
#             if t_dict.get(char) is None:
#                 t_dict[char] = 0
#             t_dict[char] += 1

#         for i in range(s_len):# length of sub string 
#             for j in range(s_len-i):# start position
#                 if i == 0:
#                     if t_dict.get(s[j]) is not None:
#                         DP[j][j][s[j]] = 1
#                 else:
#                     DP[j][j+i] = DP[j+1][j+i]
#                     if t_dict.get(s[j]) is not None:
#                         if DP[j][j+i].get(s[j]) is None:
#                             DP[j][j+i][s[j]] = 1
#                         elif DP[j][j+i][s[j]] < t_dict[s[j]]:
#                             DP[j][j+i][s[j]] += 1
#                 if DP[j][j+i] == t_dict:
#                     return s[j:j+i+1]
#         return ''

# hash map plus sliding window
# class Solution:
#     def minWindow(self, s: str, t: str) -> str:
#         if len(s) == 1:
#             return s if len(t) == 1 and s == t else ''
#         t_set = set(t)
#         s_dict = {}
#         for i in range(len(s)):
#             if s[i] in t_set:
#                 s_dict[i] = s[i]
        
#         t_dict = {}
#         for char in t:
#             if t_dict.get(char) is None:
#                 t_dict[char] = 0
#             t_dict[char] += 1
        
#         min_length,min_start,min_end,start,end = 1000000,-1,-1,-1,-1
#         point_list = list(s_dict.keys())
        
#         if len(point_list) == 1 and len(t) == 1:
#             return t
        
#         for i,start in enumerate(point_list):
#             ans_dict = {}
#             if ans_dict.get(s_dict[start]) is None:
#                 ans_dict[s_dict[start]] = 0
#             ans_dict[s_dict[start]] += 1
#             for end in point_list[i+1:]:
#                 if end - start > min_length:
#                     break
#                 if ans_dict.get(s_dict[end]) is None:
#                     ans_dict[s_dict[end]] = 0
#                 ans_dict[s_dict[end]] += 1
#                 valid = True
#                 for key in t_dict.keys():
#                     if ans_dict.get(key) is None or  ans_dict[key] < t_dict[key]:
#                         valid = False
#                         break
#                 if valid:
#                     if end - start < min_length:
#                         min_length,min_start,min_end = end - start,start,end
#                     break
#             ans_dict[s_dict[start]] -= 1

#         return '' if min_length == 1000000 else s[min_start:min_end+1]

# easy DP (MLE)
# class Solution:
#     def minWindow(self, s: str, t: str) -> str:
#         t_set = set(t)
#         s_dict = {}
#         for i in range(len(s)):
#             if s[i] in t_set:
#                 s_dict[i] = s[i]
#         s_keys = list(s_dict.keys())
#         len_sKeys = len(s_keys)
#         DP = []
#         for i in range(len_sKeys):
#             DP.append([{} for _ in range(len_sKeys)])

#         t_dict = {}
#         for char in t:
#             if t_dict.get(char) is None:
#                 t_dict[char] = 0
#             t_dict[char] += 1

#         min_length,min_start,min_end = 1000000,-1,-1
#         for i in range(len_sKeys):# length of sub string 
#             for j in range(len_sKeys-i):# start position
#                 if s_keys[j+i] - s_keys[j] > min_length:
#                     continue
#                 if i == 0:
#                     if s_dict.get(s[s_keys[j]]) is None:
#                         DP[j][j][s[s_keys[j]]] = 1
#                 else:
#                     DP[j][j+i] = DP[j+1][j+i]
#                     if DP[j][j+i].get(s[s_keys[j]]) is None:
#                         DP[j][j+i][s[s_keys[j]]] = 1
#                     elif DP[j][j+i][s[s_keys[j]]] < t_dict[s[s_keys[j]]]:
#                         DP[j][j+i][s[s_keys[j]]] += 1
#                 if DP[j][j+i] == t_dict and s_keys[j+i] - s_keys[j] < min_length:
#                     min_length = s_keys[j+i] - s_keys[j]
#                     min_start = s_keys[j]
#                     min_end = s_keys[j+i]
#         return '' if min_length == 1000000 else s[min_start:min_end+1]

# hash map and two pointer
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_set = set(t)
        s_len = len(s)
        t_len = len(t)
        s_dict = {}
        for i in range(s_len):
            if s[i] in t_set:
                s_dict[i] = s[i]
        s_keys = list(s_dict.keys()) # idx that contains t's character in s
        
        t_list = [0 for _ in range(128)] # if all element <= 0 => can compare minimum length else no
        for char in t:
            t_list[ord(char)] += 1 
        
        min_length,min_str,start_idx,end_idx,required = 1000000,'',0,-1,t_len
        # required : 0 if sliding window contains all of t's character else equals to number of missing characters
        while end_idx < len(s_keys):
            if required == 0:
                if s_keys[end_idx] - s_keys[start_idx] < min_length:
                    min_length = s_keys[end_idx] - s_keys[start_idx]
                    min_str = s[s_keys[start_idx]:s_keys[end_idx]+1]
                t_list[ord(s[s_keys[start_idx]])] += 1
                if t_list[ord(s[s_keys[start_idx]])] > 0:
                    required += 1
                start_idx += 1
            else:
                if required != 0:
                    end_idx += 1
                if end_idx == len(s_keys):
                    break
                t_list[ord(s[s_keys[end_idx]])] -= 1
                if t_list[ord(s[s_keys[end_idx]])] >= 0:
                    required -= 1
            # print(s_keys[start_idx],s_keys[end_idx],t_list[ord('A'):ord('C')+1])
        return min_str 

if __name__ == '__main__':
    a = Solution()
    print(a.minWindow("ADOBECODEBANC","ABC"))
    print(a.minWindow("ab","a"))
    print(a.minWindow("aaaaaaaaaaaabbbbbcdd","abcdd"))

                        
                        
                    
        