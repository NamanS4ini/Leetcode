class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        right = 1
        while(right < len(words)):
            set1 = Counter(words[right - 1])
            set2 = Counter(words[right])
            if(set1 == set2):
                del words[right]
            else:
                right += 1
        return words
        