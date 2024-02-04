from collections import defaultdict,deque

class Solution:
    def numBusesToDestination(self, routes: list[list[int]], source: int, target: int) -> int:
        # BFS store stop(o(10^5))
        bus = defaultdict(list)
        for i,route in enumerate(routes):
            for stop in route:
                bus[stop].append(i)

        if len(bus[target]) == 0: return -1

        queue = []
        queue.append((source,0,set()))
        
        while len(queue) != 0:
            stop, cnt, visited = queue.pop(0)
            if cnt > len(routes): break
            if stop == target: return cnt
            visited.add(stop)
            total_bus = bus[stop]

            for bus_no in total_bus:
                for next_stop in routes[bus_no]:
                    if next_stop not in visited:
                        visited.add(next_stop)
                        queue.append((next_stop,cnt+1,visited))
            
        return -1

class Solution:
    def numBusesToDestination(self, routes: list[list[int]], source: int, target: int) -> int:
        # BFS store stop(o(500) faster )
        if source == target: return 0
        bus = defaultdict(list)
        for i,route in enumerate(routes):
            for stop in route:
                bus[stop].append(i)

        queue = deque()
        visited = set()
        for bus_no in bus[source]:
            queue.append((bus_no,1))
        
        while len(queue) != 0:
            bus_no , cost = queue.popleft()
            if target in routes[bus_no]: return cost

            for next_stop in routes[bus_no]:
                for next_bus in bus[next_stop]:
                    if next_bus not in visited:
                        visited.add(next_bus)
                        queue.append((next_bus,cost+1))
        return -1



