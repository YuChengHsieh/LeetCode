class Solution:
    def destCity(self, paths: list[list[str]]) -> str:
        source = set()
        all_cities = set()

        for from_,to in paths:
            source.add(from_)
            all_cities.add(from_)
            all_cities.add(to)
        
        return list(all_cities-source)[0]
