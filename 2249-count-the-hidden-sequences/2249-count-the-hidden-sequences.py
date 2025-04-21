class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        mini,maxi=0,0
        ans=0
        for i in differences:
            ans+=i
            mini=min(mini,ans)
            maxi=max(maxi,ans)
        res=(upper-lower)-(maxi-mini)+1
        return max(0,res)

