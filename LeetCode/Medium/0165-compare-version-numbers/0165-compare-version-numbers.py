class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split(".")
        l2 = version2.split(".")

        length = len(l1) if len(l1) > len(l2) else len(l2)

        for i in range(length):
            v1 = int(l1[i]) if i < len(l1) else 0
            v2 = int(l2[i]) if i < len(l2) else 0

            if(v1 > v2):
                return 1
            elif(v2 > v1):
                return -1
    
        return 0