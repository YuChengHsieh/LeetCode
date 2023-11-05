class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        char_dict = {']':'[','}':'{',')':'('}
        for char in s:
            if char == '[' or char == '{' or char =='(':
                stack.append(char)
            else:
                try:
                    assert char_dict[char] == stack[-1]
                    stack.pop()
                except:
                    return False
        
        return True if stack == [] else False

if __name__ == '__main__':
    a = Solution()
    print(a.isValid("()[]{}"))
    print(a.isValid("(]"))