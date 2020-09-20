/*
法一:暴力法
法二：双指针法

思路
　  1.首先假设我们找到能取最大容积的纵线为 i, j (假定i < j)，那么得到的最大容积 C = min( ai , aj ) * ( j- i) ； 
    2.下面我们看这么一条性质： 
　　①: 在 j 的右端没有一条线会比它高！假设存在 k |( j < k && ak > aj) ，那么 由 ak > aj，所以 min(ai, aj, ak) =min(ai, aj) ，所以由i, k构成的容器的容积C’ = min(ai, aj) * (k - i) > C，与C是最值矛盾，所以得证j的后边不会有比它还高的线； 
　　②:同理，在i的左边也不会有比它高的线；这说明什么呢？如果我们目前得到的候选： 设为 x, y两条线（x< y)，那么能够得到比它更大容积的新的两条边必然在[x, y]区间内并且 ax’ >= ax , ay’ >= ay; 
	
	因此,取最左边直线和最右边直线,如果有比当前容积大的取法,必定在当前区间内.因此,不断缩小区间去寻求可能的比当前容积大的情形,并排除不存在比当前容积大的区间,直到不能缩小,最终求得最大容积.


    先取最左边直线和最右边直线, 这种情况用（0, n-1)表示。下一步，考虑减少一个单位的宽度的情况，这时候有两种选择：（0, n-2）和（1, n-1）。对比这两种情况，如果线条的高度height[0] < height[n-1]，也就说是第0根线条是“短板”，那么（0, n-2）的容积肯定会比（0, n-1）的容积小（前者容积为height[0]乘以宽度，后者的“短板”肯定小于或等于height[0]，而宽度变小），因此（0, n-2）的情况可以不用比较，直接否定了所有左端为 0 的情况.因此,下一步将区间缩小到(1, n-1），依次类推。时间复杂度为O(n)。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int ret = min(height[left], height[right] ) * (right - left);
        while(left < right)
        {
            //printf("i %d %d  j %d %d\n", left, height[left], right, height[right]);
            if(height[left] < height[right])
                left++;
            else if(height[left] > height[right])
                right--;
            else 
                left++, right--;
            ret = max(ret, (min(height[left], height[right] ) * (right - left) ) );
        }
        return ret;
    }
};