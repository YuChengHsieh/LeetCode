# o(n^2) TLE
# class Solution:
#     def goodIndices(self, nums: list[int], k: int) -> list[int]:
#         num_len = len(nums)
#         non_incDP = {}
#         non_decDP = {}
#         # not enough length
#         if k >= num_len - k: return []
#         good_indice = []
        
#         # non-increasing
#         for i in range(1,k):
#             non_incDP[(i-1,i)] = nums[i]-nums[i-1] <= 0
#             for j in range(0,i-1):
#                 non_incDP[(j,i)] = non_incDP[(j,i-1)] and non_incDP[(i-1,i)]
        
#         # non-decreasing
#         for i in range(k+1,k+k):
#             non_decDP[(i-1,i)] = nums[i]-nums[i-1] >= 0
#             for j in range(k,i-1):
#                 non_decDP[(j,i)] = non_decDP[(j,i-1)] and non_decDP[(i-1,i)]

#         for i in range(k,num_len-k):
#             non_incDP[(i-1,i)] = nums[i]-nums[i-1] <= 0
#             non_decDP[(i+k-1,i+k)] = nums[i+k]-nums[i+k-1] >= 0
            
#             for j in range(i-k,i-1):
#                 non_incDP[(j,i)] = non_incDP[(j,i-1)] and non_incDP[(i-1,i)]
#                 non_decDP[(j+k,i+k)] = non_decDP[(j+k,i+k-1)] and non_decDP[(i+k-1,i+k)]
                
#             # for j in range(i,i+k-1):
#             #     non_decDP[(j,i+k)] = non_decDP[(j,i+k-1)] and non_decDP[(i+k-1,i+k)]
#             #  good indice
#             if k == 1 or (non_incDP[(i-k,i-1)] and non_decDP[(i+1,i+k)]):
#                 good_indice.append(i)

#         return good_indice

# o(n) 
class Solution:
    def goodIndices(self, nums: list[int], k: int) -> list[int]:
        nums_len = len(nums)
        # find left boundary of non increasing
        non_inc = [i for i in range(nums_len)]
        # find right boundary of non decreasing
        non_dec = [i for i in range(nums_len)]
        good_indice = []
        # if i index is non-increasing with i-1 index, set index i's boundary to i-1's
        for i in range(1,nums_len):
            if nums[i] - nums[i-1] <= 0:
                non_inc[i] = non_inc[i-1]
        # if i index is non-increasing with i+1 index, set index i's boundary to i+1's
        # non-decreasing if reverse
        for i in range(nums_len-2,0,-1):
            if nums[i] - nums[i+1] <= 0:
                non_dec[i] = non_dec[i+1]
        # check whether given idex's left and right boundary exceeds boundary of [non_dec[i],non_inc[i]], if within
        # then add i as good index
        for i in range(k,nums_len-k):
            if non_inc[i-1] <= i-k and non_dec[i+1] >= i+k:
                good_indice.append(i)

        return good_indice

if __name__ == '__main__':
    a = Solution()
    print(a.goodIndices([2,1,1,1,3,4,1],2))
    print(a.goodIndices([2,1,1,2],2))
    print(a.goodIndices([878724,201541,179099,98437,35765,327555,475851,598885,849470,943442],4))
    print(a.goodIndices([440043,276285,336957],1))