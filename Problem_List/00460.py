class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.cnt_dicts = [{}] # self.cnt_dicts[0] locates keys where their couunt is 0, self.cnt_dicts[1] locates keys where their couunt is 1
        self.key_dict = {} # key -> (value,count)
        
    def add_cnt(self,key: int, cnt: int) -> None:
        # if count exceed length of self.cnt_dicts, append dicts in self.cnt_dicts
        if cnt+1 >= len(self.cnt_dicts):
            self.cnt_dicts.append({})
        del self.cnt_dicts[cnt][key]
        # key's count += 1
        self.cnt_dicts[cnt+1][key] = 1
        return
    # o(1)
    def get(self, key: int) -> int:
        if self.key_dict.get(key) is not None:
            value,cnt = self.key_dict[key]
            self.add_cnt(key,cnt)
            self.key_dict[key] = (value,cnt+1)
            return value
        else:
            return -1
    # o(1)
    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        def get_first_key(dicts):# basically o(1)
            for i,dict_ in enumerate(dicts):
                for key in dict_:
                    return i,key
        
        # put new value in already exist key
        if self.key_dict.get(key) is not None:
            _,cnt = self.key_dict[key]
            self.add_cnt(key,cnt)
            self.key_dict[key] = (value,cnt+1)
        # put new value in new key
        else:
            # delete less frequent key
            if self.size +1 > self.capacity:
                cnt,del_key = get_first_key(self.cnt_dicts)
                del self.key_dict[del_key]
                del self.cnt_dicts[cnt][del_key]
                self.size -= 1
            # new insertion, count = 0
            self.key_dict[key] = (value,0)
            self.cnt_dicts[0][key] = 1
            self.size += 1
        return

if __name__ == '__main__':
    lfu = LFUCache(2)
    