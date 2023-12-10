import heapq
class SeatManager:
    def __init__(self, n: int):
        self.seats = [i for i in range(n,0,-1)]
        heapq.heapify(self.seats)
        self.first = 1

    def reserve(self) -> int:
        return heapq.heappop(self.seats)


    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.seats,seatNumber)
    
