class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        word = tuple(s.strip())
        n = 0
        i = len(word) - 1
        while i >= 0:
            if word[i] == ' ':
                return n
            else:
                n += 1
                i -=1

        return n