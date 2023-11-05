import heapq
class Solution:
    def reorganizeString(self, s: str) -> str:
        cnt = {}
        for char in s:
            if not cnt.get(char):
                cnt[char] = 0
            cnt[char] += 1
        
        pq = []
        for key,val in cnt.items():
            heapq.heappush(pq,(-val,key))
        ans = ''
        while len(pq) > 1:
            val_a,key_a = heapq.heappop(pq)
            val_b,key_b = heapq.heappop(pq)

            ans += key_a+key_b
            if val_a+1<0: heapq.heappush(pq,(val_a+1,key_a))
            if val_b+1<0: heapq.heappush(pq,(val_b+1,key_b))
        
        if len(pq) == 1: 
            val_a,key_a = heapq.heappop(pq)
            return '' if val_a != -1 else ans+key_a
        else:
            return ans
