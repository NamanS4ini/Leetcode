class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        for fruit in fruits:
            for i in range(len(baskets)):
                if(baskets[i] >= fruit):
                    baskets.pop(i)
                    break

        return len(baskets)

        