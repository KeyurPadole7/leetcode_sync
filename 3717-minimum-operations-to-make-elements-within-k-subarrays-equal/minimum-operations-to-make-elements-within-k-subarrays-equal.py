from typing import List
import heapq

class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:

        class DualHeap:
            def __init__(self):
                self.small = []  # Max heap (negative values)
                self.large = []  # Min heap

                self.delayed = {}

                self.small_size = 0
                self.large_size = 0

                self.small_sum = 0
                self.large_sum = 0

            def prune_small(self):
                while self.small:
                    num = -self.small[0]

                    if self.delayed.get(num, 0) == 0:
                        break

                    heapq.heappop(self.small)

                    self.delayed[num] -= 1

                    if self.delayed[num] == 0:
                        del self.delayed[num]

            def prune_large(self):
                while self.large:
                    num = self.large[0]

                    if self.delayed.get(num, 0) == 0:
                        break

                    heapq.heappop(self.large)

                    self.delayed[num] -= 1

                    if self.delayed[num] == 0:
                        del self.delayed[num]

            def balance(self):

                self.prune_small()
                self.prune_large()

                if self.small_size > self.large_size + 1:

                    num = -heapq.heappop(self.small)

                    self.small_size -= 1
                    self.large_size += 1

                    self.small_sum -= num
                    self.large_sum += num

                    heapq.heappush(self.large, num)

                    self.prune_small()

                elif self.small_size < self.large_size:

                    num = heapq.heappop(self.large)

                    self.large_size -= 1
                    self.small_size += 1

                    self.large_sum -= num
                    self.small_sum += num

                    heapq.heappush(self.small, -num)

                    self.prune_large()

            def add(self, num):

                self.prune_small()

                if not self.small or num <= -self.small[0]:

                    heapq.heappush(self.small, -num)

                    self.small_size += 1
                    self.small_sum += num

                else:

                    heapq.heappush(self.large, num)

                    self.large_size += 1
                    self.large_sum += num

                self.balance()

            def remove(self, num):

                self.prune_small()

                median = -self.small[0]

                self.delayed[num] = self.delayed.get(num, 0) + 1

                if num <= median:

                    self.small_size -= 1
                    self.small_sum -= num

                    if num == median:
                        self.prune_small()

                else:

                    self.large_size -= 1
                    self.large_sum -= num

                    if self.large and num == self.large[0]:
                        self.prune_large()

                self.balance()

            def cost(self):

                self.prune_small()

                median = -self.small[0]

                return (
                    median * self.small_size - self.small_sum
                    + self.large_sum - median * self.large_size
                )

        n = len(nums)

        # Step 1: Calculate cost of each window of size x

        dh = DualHeap()

        for i in range(x):
            dh.add(nums[i])

        costs = [dh.cost()]

        for i in range(x, n):

            dh.remove(nums[i - x])
            dh.add(nums[i])

            costs.append(dh.cost())

        # Step 2: DP
        # prev[i] = minimum cost to select j-1 windows
        # from first i elements

        INF = float('inf')

        prev = [0] * (n + 1)

        for j in range(1, k + 1):

            curr = [INF] * (n + 1)

            for i in range(1, n + 1):

                # Skip current element
                curr[i] = curr[i - 1]

                # Select window ending at i-1
                if i >= x:

                    curr[i] = min(
                        curr[i],
                        prev[i - x] + costs[i - x]
                    )

            prev = curr

        return prev[n]