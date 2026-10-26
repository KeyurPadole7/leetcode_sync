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

        return ms[:n].count(1)
