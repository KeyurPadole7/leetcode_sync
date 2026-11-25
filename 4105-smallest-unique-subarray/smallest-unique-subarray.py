from collections import Counter

class Solution:
    def smallestUniqueSubarray(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Two large primes and bases for collision-free rolling hash
        MOD1, BASE1 = 1_000_000_007, 131_542_391
        MOD2, BASE2 = 1_000_000_009, 265_443_576
        
        # Precompute prefix hashes and powers
        pref1 = [0] * (n + 1)
        pref2 = [0] * (n + 1)
        pow1 = [1] * (n + 1)
        pow2 = [1] * (n + 1)
        
        for i, val in enumerate(nums):
            pref1[i + 1] = (pref1[i] * BASE1 + val) % MOD1
            pref2[i + 1] = (pref2[i] * BASE2 + val) % MOD2
            pow1[i + 1] = (pow1[i] * BASE1) % MOD1
            pow2[i + 1] = (pow2[i] * BASE2) % MOD2
            
        def has_unique_subarray(length: int) -> bool:
            counts = Counter()
            p1, p2 = pow1[length], pow2[length]
            
            for i in range(n - length + 1):
                h1 = (pref1[i + length] - pref1[i] * p1) % MOD1
                h2 = (pref2[i + length] - pref2[i] * p2) % MOD2
                counts[(h1, h2)] += 1
                
            return any(freq == 1 for freq in counts.values())

        # Binary search for the minimum length
        low, high = 1, n
        while low < high:
            mid = (low + high) // 2
            if has_unique_subarray(mid):
                high = mid
            else:
                low = mid + 1
                
        return low