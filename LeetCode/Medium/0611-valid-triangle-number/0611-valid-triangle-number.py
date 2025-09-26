class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        
        result = 0
        nums.sort()

        for i in reversed(range(len(nums))):
            left = 0
            right = i - 1
            while left < right:
                if nums[left] + nums[right] > nums[i]:
                    result += (right - left)
                    right -= 1
                else:
                    left += 1
        
        return result