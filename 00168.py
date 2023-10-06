class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ''
        while columnNumber !=0:
            ans = chr(int((columnNumber-1)%26)+ord('A'))+ans
            columnNumber = (columnNumber-1)//26
        return ans