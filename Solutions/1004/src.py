# 一开始用dp 超时。。。
# 法一：滑动窗口

class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        cnt = [0] * 2
        i = 0
        j = 0
        ret = 0
        while i < len(A):
            cnt[A[i]] += 1
            i += 1
            while j < len(A) and cnt[0] > K:
                cnt[A[j]] -= 1
                j += 1
            ret = max(ret, i - j) # or ret = max(ret, cnt[0] + cnt[1])
        return ret