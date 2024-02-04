class Solution:
    def findHighAccessEmployees(self, access_times: list[list[str]]) -> list[str]:
        access_times.sort(key=lambda a: int(a[-1]))
        ans = set()
        dict_ = {}
        for name,time in access_times:
            if name in ans: continue
            if name not in dict_:
                dict_[name] = [int(time)]
            else:
                dict_[name].append(int(time))
                if len(dict_[name]) <= 3: look = 0
                else: look = len(dict_[name])-3
                if len(dict_[name]) >= 3 and dict_[name][-1]-dict_[name][look] < 100: ans.add(name)
        return list(ans)