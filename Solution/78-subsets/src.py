class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        output = [[]]
        n = len(nums)
        
        for num in nums:
            output += [curr + [num] for curr in output]
        
        return output