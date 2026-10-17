class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = []

        for i in range(len(nums)-1):
            if(i>0 and nums[i]==nums[i-1]):
                continue

            j = i+1
            k = len(nums)-1

            while(j<k):
                if (j>i+1 and nums[j]==nums[j-1]):
                    j += 1
                    continue
                if (k<len(nums)-1 and nums[k]==nums[k+1]):
                    k -= 1
                    continue

                if(nums[j]+nums[k] == -nums[i]):
                    ans.append([nums[i], nums[j], nums[k]])
                    j += 1
                elif(nums[j]+nums[k] < -nums[i]):
                    j += 1
                else:
                    k -= 1

        return ans