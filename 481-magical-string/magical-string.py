class Solution:
    def magicalString(self, n: int) -> int:
        ms = [1,2,2]

        chanceof1 = True
        for i in range(2, n):
            if chanceof1:
                ms += [1]*ms[i]
                chanceof1 = False
            else:
                ms += [2]*ms[i]
                chanceof1 = True

        count = 0
        for i in range(n):
            if ms[i]==1:
                count += 1

        return count
