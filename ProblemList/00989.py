# class Solution:
#     def addToArrayForm(self, num: list[int], k: int) -> list[int]:
#         k = [int(i) for i in list(str(k))]
#         carry = False
#         ans = []
#         num_idx,k_idx = len(num)-1,len(k)-1
        
#         while num_idx>=0 and k_idx>=0:
#             val = num[num_idx]+k[k_idx]+1 if carry else num[num_idx]+k[k_idx]
#             if val >= 10:
#                 carry=True
#                 val -= 10
#             else:
#                 carry = False
#             ans.insert(0,val)
#             num_idx -= 1
#             k_idx -= 1
        
#         while num_idx >= 0:
#             val = num[num_idx]+1 if carry else num[num_idx]
#             if val >= 10:
#                 carry=True
#                 val -= 10
#             else:
#                 carry = False
#             ans.insert(0,val)
#             num_idx -= 1
        
#         while k_idx >= 0:
#             val = k[k_idx]+1 if carry else k[k_idx]
#             if val >= 10:
#                 carry=True
#                 val -= 10
#             else:
#                 carry = False
#             ans.insert(0,val)
#             k_idx -= 1
        
#         if carry:
#             ans.insert(0,1)
#         return ans

# faster method
class Solution:
    def addToArrayForm(self, num: list[int], k: int) -> list[int]:
        carry = False
        num_idx = len(num)-1
        
        while num_idx>=0:
            if carry == False and k == 0:
                break
            val = num[num_idx]+k%10+1 if carry else num[num_idx]+k%10
            if val >= 10:
                carry=True
                val -= 10
            else:
                carry = False
            num[num_idx] = val
            num_idx -= 1
            k//=10
        
        while k>0:
            val = k%10+1 if carry else k%10
            if val >= 10:
                carry=True
                val -= 10
            else:
                carry = False
            num.insert(0,val)
            k//=10
        
        if carry:
            num.insert(0,1)
        return num