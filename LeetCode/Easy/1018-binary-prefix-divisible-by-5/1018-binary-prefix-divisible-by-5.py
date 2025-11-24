class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        num = ""
        ans = [False] * len(nums)
        for i in range(len(nums)):
            num = num + str(nums[i])
            if(int(num, 2) % 5 == 0):
                ans[i] = True
        return ans