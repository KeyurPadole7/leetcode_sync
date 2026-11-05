from bisect import bisect_left

class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        count = 0

        for x in arr1:
            idx = bisect_left(arr2, x)

            if idx < len(arr2) and arr2[idx] - x <= d:
                continue

            if idx > 0 and x - arr2[idx - 1] <= d:
                continue

            count += 1

        return count