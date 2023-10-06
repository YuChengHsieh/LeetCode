class MyHashMap:

    def __init__(self):
        self.list = [-1]*1000001

    def put(self, key: int, value: int) -> None:
        self.list[key] = value

    def get(self, key: int) -> int:
        return self.list[key]

    def remove(self, key: int) -> None:
        self.list[key] = -1
