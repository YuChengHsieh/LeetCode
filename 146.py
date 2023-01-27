class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.queue = []
        self.dict = {}

    def get(self, key: int) -> int:
        if self.dict.get(key) is None:
            return -1
        else:
            val = self.dict[key]
            # update key to most recent used key
            del self.dict[key]
            self.dict[key] = val
            return self.dict[key]

    def put(self, key: int, value: int) -> None:
        if self.dict.get(key) is not None:
            del self.dict[key]
            self.dict[key] = value
        else:
            if self.size+1 > self.capacity:
                for del_key in self.dict:
                    del self.dict[del_key]
                    break
                self.size -= 1
            self.dict[key] = value
            self.size += 1
        return

if __name__ == '__main__':
    a = LRUCache(2)
    a.put(1,1)
    a.put(2,2)
    a.get(1)
    a.put(3,3)