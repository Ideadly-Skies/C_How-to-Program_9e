from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_altitude = 0 
        altitude = 0
        
        for g in gain:
            altitude += g
            max_altitude = max(altitude, max_altitude)
        
        return max_altitude 

if __name__ == "__main__":
    s1 = Solution()