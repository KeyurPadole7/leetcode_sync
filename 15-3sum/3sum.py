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
                if(nums[j]+nums[k] == -nums[i]):
                    ans.append([nums[i], nums[j], nums[k]])
                    while j<k and nums[j]==nums[j+1]:
                        j += 1
                    while j<k and nums[k]==nums[k-1]:
                        k -= 1

                    k -= 1
                    j += 1
                elif(nums[j]+nums[k] < -nums[i]):
                    j += 1
                else:
                    k -= 1

        return ans