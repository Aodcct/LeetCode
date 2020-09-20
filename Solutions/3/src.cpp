/*
【注意】区别子序列（不连续）与子串（连续）

法一：暴力法
要检查一个字符串是否有重复字符，我们可以使用集合。我们遍历字符串中的所有字符，并将它们逐个放入 set 中。在放置一个字符之前，我们检查该集合是否已经包含它。如果包含，我们会返回 false。循环结束后，我们返回 true。
复杂度分析： 时间O(n^3) 空间O(k)=O(min(m,n))
法二：优化的滑动窗口*
复杂度分析： 时间O(2n) 空间O(k)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int maxlen = 0, len = 0;
        map<char, int> _map;
        for(int i = 0, j = 0; j < s.size(); j++)
        {
            if(_map[s[j]])
            {
                // printf("%c %d maxlen is %d len is %d!\n", s[j], _map[s[j]], maxlen, len);
                if(_map[s[j]] > i) // !
                    i = _map[s[j]];
                maxlen = max(maxlen, len);
                len = j - i + 1;
            }
            else
                len++;
            _map[s[j]] = j + 1;
            // printf("%c %d %d maxlen is %d len is %d\n", s[j], i, j,  maxlen, len);
        }
        maxlen = max(maxlen, len);
        return maxlen;
    }
};