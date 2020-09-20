/*
法一：暴力法
法二：动态规划
复杂度分析： 时间O(n^2) 空间O(n^2)  空间复杂度优化？
法三：中心扩展法
法四：Manacher（马拉车）算法*
*/

class Solution {
public:
    string longestPalindrome(string s) {
        bool P[1024][1024];
        string ans;
        int maxlen = 1;
        memset(P, false, sizeof(P) );
        if(s.size() != 0) ans.assign(s, 0, 1);
        for(int i = 0; i < s.size(); i++)
        {
            P[i][i] = true;
            if(i + 1 < s.size() && s[i] == s[i + 1] )
            {
                P[i][i + 1] = true;
                if(2 > maxlen)
                {
                    maxlen = 2;
                    ans.assign(s, i, 2);
                }
            }
        }
        for(int len = 3; len <= s.size(); len++)
        {
            for(int i = 0; i <= s.size() - len; i++)
            {
                int left = i, right = i + len - 1;
                if(P[left + 1][right - 1] == true && s[left] == s[right])
                {
                    P[left][right] = true;
                    if(len > maxlen)
                    {
                        maxlen = len;
                        ans.assign(s, i, maxlen);
                    }
                }
            }
        }
        return ans;
    }
};
