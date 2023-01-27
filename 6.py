class Solution:
    def convert(self, s: str, numRows: int) -> str:
        li = ['' for _ in range(numRows)]
        
        direction = {0:1,1:-1}
        current_direction = 0
        cur_raw=0
        
        if numRows == 1:
            return s
        
        else:
            
            for char in s:
                li[cur_raw] += char
                if (current_direction == 0 and cur_raw == numRows-1) or (current_direction == 1 and cur_raw == 0):
                    current_direction = int((current_direction+1)%2)
                
                cur_raw += direction[current_direction]

            ret_str = ''
            for str in li:
                ret_str += str
            
            return ret_str
        
if __name__ == '__main__':
    a = Solution()
    print(a.convert('PAYPALISHIRING',3))
    print(a.convert('PAYPALISHIRING',4))
    print(a.convert('ABC',1))