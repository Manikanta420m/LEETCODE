class Solution:
    def countLargestGroup(self, n: int) -> int:
        f={}
        maxi,ans=0,0
        for i in range(1,n+1,1):
            suma=0
            while(i>0):
                suma+=i%10
                i//=10
            if suma in f:
                f[suma]+=1
            else:
                f[suma]=1
            maxi=max(maxi,f[suma])
        for i in f:
            if f[i]==maxi:
                ans+=1
        return ans

            