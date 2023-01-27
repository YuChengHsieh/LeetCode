class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        prefix,test_prefix = '',''
        out = False
        if len(strs) == 1:
            return strs[0]
        if not all(strs):
            return ''
        for index in range(200):
            try:
                test_prefix += strs[0][index]
                for str_ in strs[1:]:
                    if str_[:index+1] != test_prefix:
                        out = True
                        break
                if out:
                    return prefix
                    
                prefix = test_prefix
            except:
                break
        
        return prefix

if __name__ == '__main__':
    a = Solution()
    print(a.longestCommonPrefix(strs = ["reflower","flow","flight"]))
    print(a.longestCommonPrefix(strs = ["dog","racecar","car"]))
    print(a.longestCommonPrefix(strs = ["a"]))      