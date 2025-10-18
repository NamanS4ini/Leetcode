class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if(len(s) < 1):
            return 0
        roundup = -(2**31)
        rounddown = (2**31) - 1
        positive = True if s[0] != '-' else False
        if(s[0] == '-' or s[0] == '+'):
            s = s[1:]
        ans = "0"
        for c in s:
            if(c.isnumeric()):
                ans = ans + c
            else:
                break
        ans = int(ans) if positive else -int(ans)
        if(ans < roundup):
            return roundup
        if(ans > rounddown):
            return rounddown
        return ans
