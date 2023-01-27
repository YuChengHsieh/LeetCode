# o(n)
# class Solution:
#     def gcdOfStrings(self, str1: str, str2: str) -> str:
#         def gcd(a,b):
#             if b == 0:
#                 return a
#             else:
#                 return gcd(b,a%b)
        
#         str1_len = len(str1)
#         str2_len = len(str2)
#         gcdlen_of2str = gcd(str1_len,str2_len) 
        
#         gcd_str = str1[:gcdlen_of2str]

#         for i in range(0,str1_len,gcdlen_of2str):
#             if str1[i:i+gcdlen_of2str] != gcd_str:
#                 return ''
#         for i in range(0,str2_len,gcdlen_of2str):
#             if str2[i:i+gcdlen_of2str] != gcd_str:
#                 return ''
#         return gcd_str

# o(1) concise sol
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def gcd(a,b):
            if b == 0:
                return a
            else:
                return gcd(b,a%b)
        
        str1_len = len(str1)
        str2_len = len(str2)
        gcdlen_of2str = gcd(str1_len,str2_len) 
        
        gcd_str = str1[:gcdlen_of2str]
        return '' if gcd_str + str1 != str1 + gcd_str or \
            gcd_str + str2 != str2 + gcd_str else gcd_str

if __name__ == '__main__':
    a = Solution()
    print(a.gcdOfStrings('ABCABC','ABC'))
    print(a.gcdOfStrings('ABABAB','AB'))