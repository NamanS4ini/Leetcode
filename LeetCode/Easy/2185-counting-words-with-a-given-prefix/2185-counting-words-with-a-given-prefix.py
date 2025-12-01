class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count = 0
        for s in words:
            if(s.find(pref) == 0):
                count+=1
        return count