#BFS + Dijkstra's algorithm
class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        cost_list = [[] for _ in range(n)]
        for from_,to,price in flights:
            cost_list[from_].append((to,price))
            
        min_cost = [1000000 for _ in range(n)] #minimum cost from src to every node (single source shortest path)
        queue = []
        queue.append((src,0,0)) #now_pos, now_cost, now_k

        while len(queue) != 0:
            cur_pos,cost,now_k = queue.pop(0)
            if now_k > k+1: # pass through more than k+1 shop (we count destination as a shop too)
                break
            elif now_k == k+1 and cur_pos != dst:# only let cur_pos == dst in
                continue
            for next_pos,price in cost_list[cur_pos]:
                # Dijkstra's algorithm
                if cost+price < min_cost[next_pos]: #if current cost + price less than minimum cost to go to next_pos, then we push queue
                    min_cost[next_pos] = cost+price
                    queue.append((next_pos,cost+price,now_k+1))
        
        return -1 if min_cost[dst] == 1000000 else min_cost[dst]


if __name__ == '__main__':
    a = Solution()
    print(a.findCheapestPrice(4,[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]],0,3,1))
    print(a.findCheapestPrice(3,[[0,1,100],[1,2,100],[0,2,500]],0,2,1))
    print(a.findCheapestPrice(3,[[0,1,100],[1,2,100],[0,2,500]],0,2,0))
    print(a.findCheapestPrice(15,[[10,14,43],[1,12,62],[4,2,62],[14,10,49],[9,5,29],[13,7,53],[4,12,90],[14,9,38],[11,2,64],[2,13,92],[11,5,42],[10,1,89],[14,0,32],[9,4,81],[3,6,97],[7,13,35],[11,9,63],[5,7,82],[13,6,57],[4,5,100],[2,9,34],[11,13,1],[14,8,1],[12,10,42],[2,4,41],[0,6,55],[5,12,1],[13,3,67],[3,13,36],[3,12,73],[7,5,72],[5,6,100],[7,6,52],[4,7,43],[6,3,67],[3,1,66],[8,12,30],[8,3,42],[9,3,57],[12,6,31],[2,7,10],[14,4,91],[2,3,29],[8,9,29],[2,11,65],[3,8,49],[6,14,22],[4,6,38],[13,0,78],[1,10,97],[8,14,40],[7,9,3],[14,6,4],[4,8,75],[1,6,56]],1,4,10))