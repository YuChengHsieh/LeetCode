# class Solution:
#     def longestPalindrome(self, s: str) -> str:
#         self.s = s
#         self.s_len = len(s)
#         for i in reversed(range(len(s))):
#             ret_str = self.find(i+1)
#             if ret_str != '':
#                 return ret_str
    
#     def find(self,subStr_len):
#         start_idx = 0
#         while start_idx+subStr_len <= self.s_len:
#             if self.s[start_idx:start_idx+subStr_len] == self.s[start_idx:start_idx+subStr_len][::-1]:
#                 return self.s[start_idx:start_idx+subStr_len]
#             start_idx += 1
#         return ''

# DP solution
class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_len = len(s)
        dp_list = []
        final = ''
        for _ in range(s_len):
            dp_list.append([False for _ in range(s_len)])
        
        for sub_len in range(s_len+1):
            start_idx = 0
            while start_idx+sub_len < s_len:
                if s[start_idx] == s[start_idx+sub_len]:
                    if sub_len <= 1 or dp_list[start_idx+1][start_idx+sub_len-1]:
                        dp_list[start_idx][start_idx+sub_len] = True
                        if len(final) < sub_len+1:
                            final = s[start_idx:start_idx+sub_len+1]
                start_idx += 1
        
        return final
if __name__ == '__main__':
    a = Solution()
    print(a.longestPalindrome('babad'))
    print(a.longestPalindrome('dbdbd'))