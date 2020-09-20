class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() < 3)
            return 0;
        
        int *maxLeft = (int*)malloc(height.size() * sizeof(int) );
        memset(maxLeft, 0, sizeof(maxLeft) );
        for(int i = 1; i < height.size(); i++)
        {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        int *maxRight = (int*)malloc(height.size() * sizeof(int) );
        memset(maxRight, 0, sizeof(maxRight) );
        for(int i = height.size() - 2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i] < min(maxLeft[i], maxRight[i]) )
                ans += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return ans;
    }
};