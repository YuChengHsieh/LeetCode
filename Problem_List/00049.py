# class Solution:
#     def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        
#         str_dict = []
#         ret_list = []
#         dict_cnt = 0
#         for str_ in strs:
#             char_dict = {}
#             for char in str_:
#                 if char_dict .get(char) is None:
#                     char_dict [char] = 0
#                 char_dict[char] += 1
            
#             for j,dict_ in enumerate(str_dict):
#                 if char_dict == dict_:
#                     ret_list[j].append(str_)
#                     break
#             else:
#                 str_dict.append(char_dict)
#                 ret_list.append([str_])
#                 dict_cnt += 1
        
#         return ret_list

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        
        str_dict = {}
        ret_list = []
        for str_ in strs:
            sorted_str = tuple(sorted(str_))
            if str_dict.get(sorted_str) is not None:
                ret_list[str_dict[sorted_str]].append(str_)
            else:
                ret_list.append([str_])
                str_dict[sorted_str] = len(ret_list)-1
        
        return ret_list

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        dict_ = {}
        for s in strs:
            cnt = [0]*26
            for ch in s:
                cnt[ord(ch)-ord('a')] += 1
            if tuple(cnt) not in dict_: dict_[tuple(cnt)] = []
            dict_[tuple(cnt)].append(s)
        
        ans = []
        for val in dict_.values():
            ans.append(val)
        return ans

if __name__ == '__main__':
    a = Solution()
    print(a.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
    print(a.groupAnagrams([""]))
    print(a.groupAnagrams(["a"]))
    
        
                