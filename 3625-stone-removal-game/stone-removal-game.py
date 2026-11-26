class Solution:
    def canAliceWin(self, n: int) -> bool:
        if n<10:
            return False
        if n<19:
            return True
        if n<27:
            return False
        if n<34:
            return True
        if n<40:
            return False
        if n<45:
            return True
        if n<49:
            return False
        else:
            return True