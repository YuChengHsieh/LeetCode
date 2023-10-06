import heapq
class Solution:
    def scheduleCourse(self, courses: list[list[int]]) -> int:
        courses.sort(key = lambda l: (l[1],l[0]))
        cur_time = 0
        pq = []
        for duration,deadline in courses:
            cur_time += duration
            heapq.heappush(pq,-duration)
            if cur_time > deadline:
                cur_time -= -heapq.heappop(pq)
        return len(pq)