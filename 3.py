class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_size = 0
        cursor = 0
        strlength = len(s)
        while max_size <= len(s[cursor:]) and cursor < strlength:
            al = []
            al.append(s[cursor])
            size = 1
            for i in range(cursor+1,strlength):
                if s[i] in al:
                    break
                size += 1
                al.append(s[i])
            if size > max_size:
                max_size = size
            cursor += 1
        return max_size

if __name__ == '__main__':
    a = Solution()
    print(a.lengthOfLongestSubstring("pwwkew"))