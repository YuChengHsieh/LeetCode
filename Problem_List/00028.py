# class Solution:
#     def strStr(self, haystack: str, needle: str) -> int:
#         needle_idx = 0
#         haystack_idx = 0
#         needle_len = len(needle)
#         haystack_len = len(haystack)
#         while haystack_idx < haystack_len:
#             if haystack[haystack_idx] == needle[needle_idx]:
#                 needle_idx += 1
#             else:
#                 if needle_idx > 0:
#                     haystack_idx -= needle_idx
#                 needle_idx = 0
                
            
#             if needle_idx == needle_len:
#                 return haystack_idx-needle_len+1
            
#             haystack_idx += 1
            
#         return -1

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        needle_len = len(needle)
        for i in range(len(haystack)-needle_len+1):
            if haystack[i:i+needle_len] == needle:
                return i
        return -1

# kmp
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # kmf
        len_ = len(haystack)
        sub_len = len(needle)
        lps = [0]*sub_len

        def build_map():
            prev = 0; idx = 1
            while idx < sub_len:
                if needle[prev] == needle[idx]: 
                    lps[idx] = prev + 1
                    prev += 1; idx += 1
                elif prev == 0:
                    idx += 1
                else:
                    prev = lps[prev-1]
        
        build_map()
        haystack_idx = 0
        needle_idx = 0
        while haystack_idx < len_:
            if haystack[haystack_idx] == needle[needle_idx]:
                haystack_idx += 1
                needle_idx += 1
            elif needle_idx == 0:
                haystack_idx += 1
            else:
                needle_idx = lps[needle_idx-1]
            
            if needle_idx == sub_len: return haystack_idx-needle_idx
        
        return -1

if __name__ == '__main__':
    a = Solution()
    print(a.strStr("sadbutsad","sad"))
    print(a.strStr("leetcode","leeeto"))

