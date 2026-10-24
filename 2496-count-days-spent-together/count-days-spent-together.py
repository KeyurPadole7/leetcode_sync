class Solution:
    def countDaysTogether(self, aA: str, lA: str, aB: str, lB: str) -> int:
        md = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


        def sb(s1, s2):
            if(s1[0:2]==s2[0:2]):
                return int(s2[3:5]) - int(s1[3:5]) + 1
            else:
                i = int(s1[0:2])
                j = int(s2[0:2])
                sum = md[i] - int(s1[3:5]) + 1
                i+=1
                while(i<j):
                    sum += md[i]
                    i += 1
                sum += int(s2[3:5])

                return sum

        start = max(aA, aB)
        end = min(lA, lB)

        if end < start:
            return 0
        else:
            return sb(start, end)



