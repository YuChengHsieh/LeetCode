from sortedcontainers import SortedSet
class FoodRatings:
    def __init__(self, foods: list[str], cuisines: list[str], ratings: list[int]):
        self.cuisine_dict = {}
        self.n = len(foods)
        self.reverse_dict = {}

        for i in range(self.n):
            if cuisines[i] not in self.cuisine_dict: self.cuisine_dict[cuisines[i]] = \
            ({},SortedSet())
            self.cuisine_dict[cuisines[i]][0][foods[i]] = ratings[i]
            self.cuisine_dict[cuisines[i]][-1].add((-ratings[i],foods[i]))
            self.reverse_dict[foods[i]] = cuisines[i]

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine = self.reverse_dict[food]
        
        origRating = self.cuisine_dict[cuisine][0][food]
        self.cuisine_dict[cuisine][-1].remove((-origRating,food))

        self.cuisine_dict[cuisine][0][food] = newRating
        self.cuisine_dict[cuisine][-1].add((-newRating,food))
        

    def highestRated(self, cuisine: str) -> str:
        return self.cuisine_dict[cuisine][-1][0][-1]