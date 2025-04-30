class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans=0
        for i in nums:
            if not (int(math.log10(i))+1)&1:
                ans+=1
        return ans