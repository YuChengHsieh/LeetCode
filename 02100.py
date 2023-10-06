# almost the same as 2420 o(n)
class Solution:
    def goodDaysToRobBank(self, security: list[int], time: int) -> list[int]:
        security_len = len(security)
        non_inc = [i for i in range(security_len) ]
        non_dec = [i for i in range(security_len) ]
        good_days = []

        for i in range(1,security_len):
            if security[i] <= security[i-1]:
                non_inc[i] = non_inc[i-1]
        
        for i in range(security_len-2,0,-1):
            if security[i] <= security[i+1]:
                non_dec[i] = non_dec[i+1]
        
        for i in range(time,security_len-time):
            if non_inc[i] <= i-time and non_dec[i] >= i+time:
                good_days.append(i)
        return good_days

if __name__ == '__main__':
    a = Solution()
    print(a.goodDaysToRobBank([1,1,1,1,1],0))