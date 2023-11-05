# # sliding window o(n^2)
# class Solution:
#     def checkInclusion(self, s1: str, s2: str) -> bool:
#         s1_map = [0 for _ in range(26)]
#         for char in s1:
#             s1_map[ord(char)-ord('a')] += 1
        
#         s1_len = len(s1)
#         s2_len = len(s2)
#         for i in range(s2_len-s1_len+1):
#             s2_map = [0 for _ in range(26)]
#             for j in range(s1_len):
#                 s2_map[ord(s2[i+j])-ord('a')] +=1
#             if s1_map == s2_map:
#                 return True
#         return False

# # sliding window + two pointer o(n^1)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_map = [0 for _ in range(26)]
        s1_len,s2_len = len(s1),len(s2)
        for char in s1:
            s1_map[ord(char)-ord('a')] += 1
        
        s2_map = [0 for _ in range(26)]
        s2_cnt = -s1_len
        # check whether s2[s2_cnt:i] is a permutation of s1
        for i in range(s2_len):
            # update the right pointer of window 
            s2_map[ord(s2[i])-ord('a')] += 1
            if i >= s1_len:
                # update the left pointer of window 
                s2_map[ord(s2[s2_cnt])-ord('a')] -= 1
            if s1_map == s2_map:
                return True
            s2_cnt += 1

        return False

if __name__ == '__main__':
    a = Solution()
    print(a.checkInclusion('',''))