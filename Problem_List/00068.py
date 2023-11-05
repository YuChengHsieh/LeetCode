class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        ans = []
        tmp_strs = []
        cnt = 0; s_len = 0; str_len = 0
        while cnt < len(words):
            if s_len == 0:
                s_len += len(words[cnt])
            else:
                s_len += len(words[cnt])+1

            if s_len > maxWidth:
                s = ''
                total_space = maxWidth-str_len
                if len(tmp_strs) == 1:
                    s = tmp_strs[0]+' '*(maxWidth-len(tmp_strs[0]))
                else:
                    space = total_space//(len(tmp_strs)-1)
                    for i,str_ in enumerate(tmp_strs[:-1]):
                        s += str_
                        s += ' '*space 
                        if total_space%(len(tmp_strs)-1)>i:
                            s += ' '
                    s += tmp_strs[-1]
                s_len = 0; str_len = 0
                tmp_strs = []
                ans.append(s)
            else:
                str_len += len(words[cnt])
                tmp_strs.append(words[cnt])
                cnt += 1
        str_len = 0
        s = ''
        for str_ in tmp_strs[:-1]:
            str_len += len(str_)+1
            s += str_+' '
        str_len += len(tmp_strs[-1])
        s += tmp_strs[-1]+' '*(maxWidth-str_len)
        ans.append(s)
        return ans