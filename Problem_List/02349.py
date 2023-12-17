from collections import defaultdict
class NumberContainers:

    def __init__(self):
        self.num_dict = defaultdict(list)
        self.idx_dict = {}

    @staticmethod
    def BS(li:list, val:int) -> int:
        start = 0; end = len(li)-1

        while start <= end:
            mid = start + (end-start)//2
            if li[mid] < val: start = mid+1
            else: end = mid-1
        return start

    def change(self, index: int, number: int) -> None:
        if index in self.idx_dict:
            num = self.idx_dict[index]
            del_idx = self.BS(self.num_dict[num],index)
            self.num_dict[num].pop(del_idx)
        
        insert_idx = self.BS(self.num_dict[number],index)
        self.num_dict[number].insert(insert_idx,index)
        self.idx_dict[index] = number

    def find(self, number: int) -> int:
        return self.num_dict[number][0] if number in self.num_dict and len(self.num_dict[number]) > 0 else -1