# Using Hash Maps (collections.Counter)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m = len(s1)
        n = len(s2)
        if m > n:
            return False
        
        freq1 = Counter(s1)
        freq2 = Counter(s2[:m])
        
        if freq1 == freq2:
            return True
        
        for i in range(m, n):
            freq2[s2[i]] += 1

            # Decrement and remove key if count drops to 0
            leftChar = s2[i-m]
            freq2[leftChar] -= 1
            if freq2[leftChar] == 0:
                del freq2[leftChar]
            
            if freq1 == freq2:
                return True

        return False
        