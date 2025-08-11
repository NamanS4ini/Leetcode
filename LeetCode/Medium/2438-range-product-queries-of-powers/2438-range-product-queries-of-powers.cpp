class Solution {
    const int MOD = 1e9 + 7;
    long long modpow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pow;
        int bit = 1;
        while (n) {
            int mod = n % 2;
            if (mod)
                pow.push_back(mod * bit);
            bit *= 2;
            n /= 2;
        }

        for (int i = 1; i < pow.size(); i++) {
            pow[i] = ((1LL * pow[i] * pow[i - 1]) % MOD);
        }
        vector<int> ans;
        for (vector<int> querie : queries) {
            int start = querie[0];
            int end = querie[1];
            if (start == 0) {
                ans.push_back(pow[end]);
            } else {
                long long numerator = pow[end];
                long long denominator = pow[start - 1];
                long long inv = modpow(denominator, MOD - 2);
                ans.push_back((numerator * inv) % MOD);
            }
        }
        return ans;
    }
};