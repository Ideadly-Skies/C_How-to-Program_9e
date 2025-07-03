from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            left_sum = sum(nums[0:i])
            right_sum = sum(nums[i+1:len(nums)])
            
            if left_sum == right_sum:
                return i

        return -1
         
if __name__ == "__main__":
    s1 = Solution()
    print(s1.pivotIndex([2,1,-1]))