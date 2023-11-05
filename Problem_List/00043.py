class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        int_num1 = self.str2int(num1)
        int_num2 = self.str2int(num2)
        return str(int_num1*int_num2)
    
    def str2int(self,num: str):
        int_num = 0
        num_len = len(num)
        base = ord('0')
        for i in range(num_len):
            int_num += (ord(num[i])-base)*10**(num_len-i-1)
        return int_num
    
if __name__ == '__main__':
    a = Solution()
    print(a.multiply('2','3'))
    print(a.multiply('123','456'))