# binary search
from collections import defaultdict
class Solution:
    def count_trip(self,time):
        trip = 0
        for i in self.set_:
           trip +=  self.hash_map[i]*(time//i)
        return trip
    def minimumTime(self, times: list[int], totalTrips: int) -> int:
        # DP = [0 for _ in range(len(time))]
        self.hash_map = defaultdict(lambda: 0)
        self.set_ = set()
        for time in times:
            self.hash_map[time] += 1
            self.set_.add(time)
        
        start = 0; end = totalTrips*max(self.set_)
        while start <= end:
            mid = (start+end)//2
            # given time, count the total amount of trip
            trip = self.count_trip(mid)
            if trip >= totalTrips: # if trip == total_trip, we should reduce the time to find the minimal time(maybe trip at time-1 is equal to time)
                end = mid-1
            else:
                start = mid+1
        return start