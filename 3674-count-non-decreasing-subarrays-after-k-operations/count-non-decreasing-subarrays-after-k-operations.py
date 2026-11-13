from array import array

class Solution:
    def countNonDecreasingSubarrays(self, nums: list[int], k: int) -> int:
        n = len(nums)
        LOG = n.bit_length()

        # Prefix sum of original array
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        # --------------------------------
        # 1. Next Greater Element
        # --------------------------------

        nge = array('i', [n]) * n
        stack = []

        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[i]:
                stack.pop()

            if stack:
                nge[i] = stack[-1]

            stack.append(i)

        # --------------------------------
        # 2. Binary Lifting
        # --------------------------------

        nxt = [nge]
        sm = [
            array('q', (
                nums[i] * (nge[i] - i)
                for i in range(n)
            ))
        ]

        for j in range(1, LOG):
            prev_nxt = nxt[j - 1]
            prev_sm = sm[j - 1]

            curr_nxt = array('i', [n]) * n
            curr_sm = array('q', [0]) * n

            for i in range(n):
                mid = prev_nxt[i]

                if mid < n:
                    curr_nxt[i] = prev_nxt[mid]
                    curr_sm[i] = prev_sm[i] + prev_sm[mid]
                else:
                    curr_sm[i] = prev_sm[i]

            nxt.append(curr_nxt)
            sm.append(curr_sm)

        # --------------------------------
        # 3. Calculate sum of prefix maxima
        # --------------------------------

        def get_max_sum(l, r):
            total = 0
            cur = l

            for j in range(LOG - 1, -1, -1):
                pos = nxt[j][cur]

                if pos <= r:
                    total += sm[j][cur]
                    cur = pos

            # Remaining segment
            total += nums[cur] * (r - cur + 1)

            return total

        # --------------------------------
        # 4. Sliding Window
        # --------------------------------

        ans = 0
        l = 0

        for r in range(n):

            while l <= r:
                original_sum = prefix[r + 1] - prefix[l]

                cost = get_max_sum(l, r) - original_sum

                if cost <= k:
                    break

                l += 1

            ans += r - l + 1

        return ans
