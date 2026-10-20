class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)

        def is_cyclically_sortable(block: list[int]) -> bool:
            k = len(block)
            if k <= 1:
                return True

            # Count the number of drops where block[i] > block[i + 1]
            drops = 0
            for i in range(k - 1):
                if block[i] > block[i + 1]:
                    drops += 1

            # Check cyclic boundary drop
            if block[-1] > block[0]:
                drops += 1

            # A cyclic shift of a sorted array can have at most 1 drop
            return drops <= 1

        def can_sort_with_k(k: int) -> bool:
            prev_max = float('-inf')

            for start in range(0, n, k):
                block = nums[start : start + k]

                # 1. Block must be individually rotatable to non-decreasing order
                if not is_cyclically_sortable(block):
                    return False

                # 2. Block's minimum must be >= previous block's maximum
                block_min = min(block)
                block_max = max(block)

                if block_min < prev_max:
                    return False

                prev_max = block_max

            return True

        # Find all divisors of n
        divisors = []
        d = 1
        while d * d <= n:
            if n % d == 0:
                divisors.append(d)
                if d * d != n:
                    divisors.append(n // d)
            d += 1

        # Check each divisor and sum valid ones
        total_sum = 0
        for k in divisors:
            if can_sort_with_k(k):
                total_sum += k

        return total_sum