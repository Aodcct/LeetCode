class Solution {
public:
    string ans[31];
    Solution() { Init(); }
    void Init()
    {
        for(int i = 0; i < 31; i++)
            ans[i] = "";
        ans[1] = "1";
        for(int i = 2; i < 31; i++)
        {
            int index = 0;
            while(index < ans[i-1].size() )
            {
                char num = ans[i-1][index];
                int cnt = 1;
                // printf("i %d %c\n", i, num);
                index++;
                while(index < ans[i-1].size() && ans[i-1][index] == ans[i-1][index-1] )
                {
                    cnt++;
                    index++;
                }
                ans[i].append(1, '0' + cnt);
                ans[i].append(1, num);
            }
        }
    }
    string countAndSay(int n) {
        return ans[n];
    }
};