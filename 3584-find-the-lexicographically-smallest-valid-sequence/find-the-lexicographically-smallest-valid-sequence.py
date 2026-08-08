class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n, m = len(word1), len(word2)
        
        # Step 1: Precompute last valid matching index from right to left
        last = [-1] * m
        ptr = n - 1
        for j in range(m - 1, -1, -1):
            while ptr >= 0 and word1[ptr] != word2[j]:
                ptr -= 1
            last[j] = ptr
            ptr -= 1  # Move past the matched character
        
        # Step 2: Left-to-right greedy search
        ans = []
        used_change = False
        i = 0
        
        for j in range(m):
            while i < n:
                is_match = (word1[i] == word2[j])
                
                if is_match:
                    # If we already used a change, ensure the rest can be matched
                    if used_change:
                        if j + 1 == m or last[j + 1] > i:
                            ans.append(i)
                            i += 1
                            break
                    else:
                        # Haven't used a change yet; matching current char leaves change available
                        ans.append(i)
                        i += 1
                        break
                else:
                    # Character mismatch: attempt using our 1 change here
                    if not used_change:
                        if j + 1 == m or last[j + 1] > i:
                            ans.append(i)
                            used_change = True
                            i += 1
                            break
                i += 1
        
        return ans if len(ans) == m else []