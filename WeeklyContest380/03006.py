class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> list[int]:
        # kmf
        s_len = len(s); a_len = len(a); b_len = len(b)
        a_lps = [0]*a_len; b_lps = [0]*b_len

        def build_map(needle,lps):
            prev = 0; idx = 1
            while idx < len(needle):
                if needle[prev] == needle[idx]: 
                    lps[idx] = prev + 1
                    prev += 1; idx += 1
                elif prev == 0:
                    idx += 1
                else:
                    prev = lps[prev-1]
            return lps
        
        def count_idx(haystack,needle,lps):
            ret = []
            haystack_idx = 0
            needle_idx = 0
            while haystack_idx < len(haystack):
                if haystack[haystack_idx] == needle[needle_idx]:
                    haystack_idx += 1
                    needle_idx += 1
                elif needle_idx == 0:
                    haystack_idx += 1
                else:
                    needle_idx = lps[needle_idx-1]

                if needle_idx == len(needle):
                    ret.append(haystack_idx-needle_idx)
                    needle_idx = lps[needle_idx-1]
            return ret
        
        a_lps = build_map(a,a_lps)
        b_lps = build_map(b,b_lps)
        a_idxs = count_idx(s,a,a_lps)
        b_idxs = count_idx(s,b,b_lps)
        
        ans = []
        for a_idx in a_idxs:
            for b_idx in b_idxs:
                if abs(b_idx-a_idx) <= k:
                    ans.append(a_idx)
                    break
        return ans
            