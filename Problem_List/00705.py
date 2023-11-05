class MyHashSet:

    def __init__(self):
        self.list = [False]*1000001

    def add(self, key: int) -> None:
        self.list[key] = True

    def remove(self, key: int) -> None:
        self.list[key] = False

    def contains(self, key: int) -> bool:
        return self.list[key] == True