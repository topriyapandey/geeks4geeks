class Solution:
    def countSubsets(self, arr):
        MOD = 10**9 + 7
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        cnt = [0] * 31
        for x in arr:
            cnt[x] += 1
        masks = {}
        for x in range(2, 31):
            t = x
            mask = 0
            ok = True
            for i, p in enumerate(primes):
                c = 0
                while t % p == 0:
                    t //= p
                    c += 1
                if c > 1:
                    ok = False
                    break
                if c == 1:
                    mask |= (1 << i)
            if ok:
                masks[x] = mask

        dp = [0] * (1 << 10)
        dp[0] = 1
        for x in range(2, 31):
            if cnt[x] == 0 or x not in masks:
                continue
            mask = masks[x]
            new = dp[:]
            for s in range(1 << 10):
                if dp[s] and (s & mask) == 0:
                    new[s | mask] = (new[s | mask] + dp[s] * cnt[x]) % MOD
            dp = new
        ans = (sum(dp) - 1) % MOD
        ans = (ans * pow(2, cnt[1], MOD)) % MOD
        return ans