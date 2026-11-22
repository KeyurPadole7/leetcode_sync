class Solution:
    def checkString(self, s: str) -> bool:
        findb = False
        for ch in s:
            if ch == 'a' and findb:
                return False
            if ch == 'b' and not findb:
                findb = True

        return True
            