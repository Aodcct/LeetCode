/*
法一：暴力枚举
复杂度分析： 时间O(n^2) 空间O(1)
法二：哈希（空间换时间）*
复杂度分析： 时间O(n) 空间O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> _map;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            //printf("%d %d\n", nums[i], complement);  
            if(_map.find(nums[i]) != _map.end() && _map[nums[i]] != i)
            {
                //printf("?\n");
                ans.push_back(_map[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            //if(nums[i] != complement)
            _map[complement] = i;
        }
        return ans;
    }
};