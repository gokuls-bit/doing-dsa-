class Solution(object):
    def sumAndMultiply(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        MOD = 10**9 + 7
        n = len(s)

        # prefix sum of non-zero digits
        pref = [0] * (n + 1)

        # next non-zero index
        nxt = [n] * (n + 1)
        last = n

        for i in range(n - 1, -1, -1):
            pref[i + 1] = pref[i] + (0 if s[i] == '0' else int(s[i]))
            if s[i] != '0':
                last = i
            nxt[i] = last

        ans = []

        for l, r in queries:

            digit_sum = pref[r + 1] - pref[l]

            x = 0

            i = nxt[l]

            while i <= r:
                x = (x * 10 + (ord(s[i]) - 48)) % MOD
                if i == r:
                    break
                i = nxt[i + 1]

            ans.append((x * digit_sum) % MOD)

        return ans
