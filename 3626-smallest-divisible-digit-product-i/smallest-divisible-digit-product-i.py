class Solution:

    def smallestNumber(self, n: int, t: int) -> int:
        i = n
        #
        while True:
            temp = i
            m = 1

            while temp > 0:
                m *= temp % 10
                temp //= 10

            if m % t == 0:
                return i

            i += 1