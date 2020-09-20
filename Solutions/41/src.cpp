class Solution {
public:
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y; 
        y = temp;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != 0 && nums[i] != i + 1)
            {
                if(nums[i] < 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) 
                    nums[i] = 0;
                else
                    swap(nums[i], nums[nums[i] - 1]);
                // debug
                // for(int j = 0; j < nums.size(); j++)
                //     printf("%d ", nums[j]);
                // printf("\n");
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                return i + 1;
        }
        return nums.size() + 1;
    }
};