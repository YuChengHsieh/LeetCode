class SummaryRanges:

    def __init__(self):
        self.list = []
        self.interval = []
        self.cur_add = -1

    def addNum(self, value: int) -> None:
        # BST o(log(len(self.list)))
        start = 0
        end = len(self.list)-1
        
        while start < end:
            mid = start + (end-start)//2
            if value == self.list[mid]:
                self.cur_add = -1
                break
            elif value > self.list[mid]:
                start = mid
            else:
                end = mid
            if start +1 == end and value > self.list[mid]:
                if value > self.list[end]:
                    self.list.insert(end+1,value)
                    self.cur_add = value
                elif value < self.list[end]:
                    self.list.insert(end,value)
                    self.cur_add = value
                else:
                    self.cur_add = -1
                break
        else:
            if len(self.list) == 0 or value < self.list[start]:
                self.list.insert(start,value)
                self.cur_add = value
            elif value > self.list[start]:
                self.list.insert(start+1,value)
                self.cur_add = value
            else:
                self.cur_add = -1
        self.calIntervals()
        return
       
    # def getIntervals(self) -> list[list[int]]:
    #     # o(len(self.list))
    #     list_len = len(self.list)
    #     if list_len == 0: return[]
    #     ret_list = []
    #     start,end = self.list[0],-1
    #     for i in range(list_len):
    #         if i+1 < list_len and self.list[i+1] == self.list[i]+1: # still in the same interval
    #             continue
    #         # add new interval
    #         end = self.list[i]
    #         ret_list.append([start,end])
    #         if i+1 < list_len:
    #             start = self.list[i+1]
    #     return ret_list 
    
    def calIntervals(self) -> list[list[int]]: # call func. every addition
        # o(len(self.list))
        interval_len = len(self.interval)
        if self.cur_add == -1:
            return self.interval
        if interval_len == 0:
            self.interval.append([self.cur_add,self.cur_add])
            return self.interval
        interval = 0
        while interval < interval_len:
            if self.cur_add < self.interval[interval][0]:
                # e.g(cur_add = 8 interval = [9,12]  result ==> [8,12])
                if self.cur_add == self.interval[interval][0]-1:
                    self.interval[interval][0] = self.cur_add
                else:
                    # e.g(cur_add = 7 interval = [9,12]  result ==> [7,7],[9,12])
                    self.interval.insert(interval,[self.cur_add,self.cur_add])
                break
                
            elif self.cur_add > self.interval[interval][1]:
                # e.g(cur_add = 3 interval = [1,2]  result ==> [1,3])
                if self.cur_add == self.interval[interval][1]+1:
                    self.interval[interval][1] = self.cur_add
                    # combine two interval. e.g(cur_add = 3 interval = [1,2] interval+1 = [4,5] result ==> [1,5])
                    if interval+1 < interval_len and self.cur_add+1 == self.interval[interval+1][0]: 
                        self.interval[interval][1] = self.interval[interval+1][1]
                        self.interval.pop(interval+1)
                        interval_len -= 1
                    break 
            else: # in the interval
                # e.g(cur_add = 10 interval = [9,12]  result ==> [9,12])
                break 
            interval += 1       
        else:
            # e.g(cur_add = 30 interval = [],no intervals greater than cur_add result ==> [30,30])
            self.interval.insert(interval,[self.cur_add,self.cur_add])
        return
    
    def getIntervals(self) -> list[list[int]]:
        return self.interval

if __name__ == '__main__':
    a = SummaryRanges()
    a.addNum(1)
    a.addNum(3)
    print(a.getIntervals())
    a.addNum(7)
    print(a.getIntervals())
    a.addNum(2)
    print(a.getIntervals())
    a.addNum(6)
    print(a.getIntervals())
    print(a.list)