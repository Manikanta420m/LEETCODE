class Solution:
    def countAndSay(self, n: int) -> str:
        if(n==1):
            return '1'
        def RLE(s):
            cur_char=s[0]
            cur_frq=1
            res=""
            for i in s[1:]:
                if(i==cur_char):
                    cur_frq+=1
                else:
                    res+=f"{cur_frq}{cur_char}"
                    cur_char=i
                    cur_frq=1
            res+=f"{cur_frq}{cur_char}"
            return res
            
        s='1'
        for i in range(n-1):
            s=RLE(s)
        return s
