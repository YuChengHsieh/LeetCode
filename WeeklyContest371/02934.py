import heapq
class Solution:
    def minOperations(self, nums1: list[int], nums2: list[int]) -> int:
        if max(nums1) == nums1[-1] and max(nums2) == nums2[-1]: return 0
        if max(nums1) != nums1[-1] and max(nums2) != nums2[-1]: return -1
        n = len(nums1)
        
        orig_nums1 = nums1.copy()
        orig_nums2 = nums2.copy()
        
        pq1 = []
        pq2 = []
        
        for i in range(n):
            heapq.heappush(pq1,(-nums1[i],i))
            heapq.heappush(pq2,(-nums2[i],i))
        
        # move first
        cnt1 = 0
        while max(nums1) != nums1[-1] or max(nums2) != nums2[-1]:
            try:
                _, max1_idx = heapq.heappop(pq1)
            except:
                cnt1 = float("inf")
                break

            tmp = nums2[max1_idx]
            nums2[max1_idx] = nums1[max1_idx]
            nums1[max1_idx] = tmp
            cnt1 += 1
        
        # move second         
        cnt2 = 0
        while max(orig_nums1) != orig_nums1[-1] or max(orig_nums2) != orig_nums2[-1]:
            try:
                _, max2_idx = heapq.heappop(pq2)
            except:
                cnt2 = float("inf")
                break

            tmp = orig_nums2[max2_idx]
            orig_nums2[max2_idx] = orig_nums1[max2_idx]
            orig_nums1[max2_idx] = tmp
            cnt2 += 1
        
        return min(cnt1,cnt2) if min(cnt1,cnt2) != float("inf") else -1
            