class Solution:
    def minimumFuelCost(self, roads: list[list[int]], seats: int) -> int:
        n = len(roads)+1
        graph = [set() for _ in range(n)]
        visited_node = set()
        fuel = 0
        for node1,node2 in roads:
            graph[node1].add(node2)
            graph[node2].add(node1)
        
        def rec(node):
            people = 1
            fuel = 0
            visited_node.add(node)
            for next_node in graph[node]:
                if next_node not in visited_node:
                    # people means number of people rides, fuel means already exhaust fuels
                    ret_people, ret_fuel = rec(next_node)
                    people += ret_people; fuel += ret_fuel

            # need at least how many cars start from this node to parent node
            car = max(0,people-1)//seats+1
            if node != 0:
                # calculate fuels exhausted from cur node to parent node
                fuel += car
            return (people,fuel)

        return rec(0)[1]