class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        l = text.split(" ")
        can = len(l)
        for s in l:
            for c in brokenLetters:
                if(c in s):
                    can-=1
                    break
        return can
                    
        