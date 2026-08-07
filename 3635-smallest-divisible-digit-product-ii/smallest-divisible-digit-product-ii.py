class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        # Precomputed (f2, f3, f5, f7) for digits 0..9
        DIGIT_FACTORS = [
            (0, 0, 0, 0),  # 0
            (0, 0, 0, 0),  # 1
            (1, 0, 0, 0),  # 2
            (0, 1, 0, 0),  # 3
            (2, 0, 0, 0),  # 4
            (0, 0, 1, 0),  # 5
            (1, 1, 0, 0),  # 6
            (0, 0, 0, 1),  # 7
            (3, 0, 0, 0),  # 8
            (0, 2, 0, 0),  # 9
        ]

        # Step 1: Prime factorization of t
        c2 = c3 = c5 = c7 = 0
        while t % 2 == 0: c2 += 1; t //= 2
        while t % 3 == 0: c3 += 1; t //= 3
        while t % 5 == 0: c5 += 1; t //= 5
        while t % 7 == 0: c7 += 1; t //= 7

        if t > 1:
            return "-1"  # t contains a prime factor > 7

        # O(1) calculation for minimum digits needed to cover required 2s and 3s
        def min_len_23(r2: int, r3: int) -> int:
            if r2 <= 0 and r3 <= 0:
                return 0
            r2 = max(0, r2)
            r3 = max(0, r3)
            c8, rem2 = divmod(r2, 3)
            c9, rem3 = divmod(r3, 2)
            if rem2 == 2 and rem3 == 1:
                extra = 2  # digits '2' and '6'
            elif rem2 > 0 or rem3 > 0:
                extra = 1  # single digit ('2', '3', '4', or '6')
            else:
                extra = 0
            return c8 + c9 + extra

        # Generates the lexicographically smallest suffix string
        def get_best_suffix(r2: int, r3: int, r5: int, r7: int, target_len: int) -> str:
            r2, r3, r5, r7 = max(0, r2), max(0, r3), max(0, r5), max(0, r7)

            c8, rem2 = divmod(r2, 3)
            c9, rem3 = divmod(r3, 2)

            digits = ['8'] * c8 + ['9'] * c9 + ['5'] * r5 + ['7'] * r7

            if rem2 == 1 and rem3 == 0:
                digits.append('2')
            elif rem2 == 2 and rem3 == 0:
                digits.append('4')
            elif rem2 == 0 and rem3 == 1:
                digits.append('3')
            elif rem2 == 1 and rem3 == 1:
                digits.append('6')
            elif rem2 == 2 and rem3 == 1:
                digits.extend(['2', '6'])

            while len(digits) < target_len:
                digits.append('1')

            digits.sort()
            return "".join(digits)

        n = len(num)

        # Step 2: Check if num itself is valid
        if '0' not in num:
            tot2 = tot3 = tot5 = tot7 = 0
            for ch in num:
                f2, f3, f5, f7 = DIGIT_FACTORS[ord(ch) - 48]
                tot2 += f2; tot3 += f3; tot5 += f5; tot7 += f7
            if tot2 >= c2 and tot3 >= c3 and tot5 >= c5 and tot7 >= c7:
                return num

        # Step 3: Fast precomputation of prefix factor requirements
        pref2 = [0] * (n + 1)
        pref3 = [0] * (n + 1)
        pref5 = [0] * (n + 1)
        pref7 = [0] * (n + 1)

        pref2[0], pref3[0], pref5[0], pref7[0] = c2, c3, c5, c7
        first_zero_idx = n

        for i in range(n):
            digit = ord(num[i]) - 48
            if digit == 0:
                first_zero_idx = i
                break
            f2, f3, f5, f7 = DIGIT_FACTORS[digit]
            pref2[i + 1] = pref2[i] - f2
            pref3[i + 1] = pref3[i] - f3
            pref5[i + 1] = pref5[i] - f5
            pref7[i + 1] = pref7[i] - f7

        # Step 4: Backtracking Search (Right to Left)
        for i in range(n - 1, -1, -1):
            if i > first_zero_idx:
                continue

            req2 = pref2[i]
            req3 = pref3[i]
            req5 = pref5[i]
            req7 = pref7[i]
            avail_len = n - 1 - i

            curr_digit = ord(num[i]) - 48 if i != first_zero_idx else 0

            for d in range(curr_digit + 1, 10):
                f2, f3, f5, f7 = DIGIT_FACTORS[d]
                n2, n3, n5, n7 = req2 - f2, req3 - f3, req5 - f5, req7 - f7

                min_needed = min_len_23(n2, n3) + (n5 if n5 > 0 else 0) + (n7 if n7 > 0 else 0)

                if min_needed <= avail_len:
                    prefix = num[:i] + str(d)
                    suffix = get_best_suffix(n2, n3, n5, n7, avail_len)
                    return prefix + suffix

        # Step 5: If no solution of length n exists, construct longer solution
        min_needed = min_len_23(c2, c3) + max(0, c5) + max(0, c7)
        target_len = max(n + 1, min_needed)
        return get_best_suffix(c2, c3, c5, c7, target_len)