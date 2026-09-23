# O(N*K)
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # mp = {}
        mp = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for ch in s:
                count[ord(ch) - ord('a')] += 1
            key = tuple(count)
            # if key not in mp:
            #     mp[key] = []
            mp[key].append(s)
        return list(mp.values())

        