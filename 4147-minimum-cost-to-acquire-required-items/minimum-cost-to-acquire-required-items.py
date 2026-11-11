class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        if costBoth<=cost1 and costBoth<=cost2:
            return max(need1, need2)*costBoth

        count = 0
        #if cost2 <= costBoth <= cost1:
        if costBoth<=cost1:
            if need1>=need2:
                return need1*costBoth
            else:
                return need1*costBoth + (need2-need1)*cost2

        #if cost1 <= costBoth <= cost2:
        if costBoth<=cost2:
            if need2>=need1:
                return need2*costBoth
            else:
                return need2*costBoth + (need1-need2)*cost1

        if costBoth>=cost1 and costBoth>=cost2:
            if need1>need2:
                return min(need2*costBoth + (need1-need2)*cost1, need2*cost2 + need1*cost1)
            else:
                return min(need1*costBoth + (need2-need1)*cost2, need1*cost1 + need2*cost2)

       