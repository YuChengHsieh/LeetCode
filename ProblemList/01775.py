class Solution:
    def minOperations(self, nums1: list[int], nums2: list[int]) -> int:
        nums1_cnt = [0]*6
        nums2_cnt = [0]*6

        for num in nums1:
            nums1_cnt[num-1] += 1
        
        for num in nums2:
            nums2_cnt[num-1] += 1

        sum1 = sum(nums1)
        sum2 = sum(nums2)

        if sum1 > sum2:
            large_sum = sum1; small_sum = sum2
            large_cnt = nums1_cnt; small_cnt = nums2_cnt
        elif sum1 < sum2:
            large_sum = sum2; small_sum = sum1
            large_cnt = nums2_cnt; small_cnt = nums1_cnt
        else: return 0

        large_idx = 5; small_idx = 0
        ans = 0 
        large_changed = sum(large_cnt)-large_cnt[0]
        small_changed = sum(small_cnt)-small_cnt[5]
        while large_sum > small_sum:
            if large_changed == 0 and small_changed == 0: return -1
            while large_idx >= 0 and large_cnt[large_idx] == 0:
                large_idx -= 1
            while small_idx <= 5 and small_cnt[small_idx] == 0:
                small_idx += 1
            if small_idx < 5-large_idx:
                small_sum += 5-small_idx
                small_cnt[small_idx] -= 1
                small_changed -= 1
            else:
                large_sum -= large_idx
                large_cnt[large_idx] -= 1
                large_changed -= 1
            
            ans += 1
        return ans
        