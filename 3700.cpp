class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    vector<long long> multiplyMatVec(const Matrix& A, const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;
                sum = (sum + A[i][j] * v[j]) % MOD;
            }
            res[i] = sum;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        long long m = r - l + 1;

        // n >= 3 by constraints, but still keeping these safe:
        if (n == 1) return m % MOD;
        if (n == 2) return (m * (m - 1)) % MOD;

        int S = 2 * m;  // states: [UP(1..m), DOWN(1..m)]

        auto upId = [&](int x) { return x - 1; };           // 0..m-1
        auto downId = [&](int x) { return m + (x - 1); };   // m..2m-1

        Matrix T(S, vector<long long>(S, 0));

        // From UP(x) -> DOWN(y) for y < x
        for (int x = 1; x <= m; x++) {
            int from = upId(x);
            for (int y = 1; y < x; y++) {
                int to = downId(y);
                T[to][from] = 1;
            }
        }

        // From DOWN(x) -> UP(y) for y > x
        for (int x = 1; x <= m; x++) {
            int from = downId(x);
            for (int y = x + 1; y <= m; y++) {
                int to = upId(y);
                T[to][from] = 1;
            }
        }
        vector<long long> init(S, 0);

        for (int x = 1; x <= m; x++) {
            init[upId(x)] = x - 1;     
            init[downId(x)] = m - x;   
        }
        Matrix P = power(T, n - 2);
        vector<long long> finalState = multiplyMatVec(P, init);

        long long ans = 0;
        for (long long val : finalState) {
            ans = (ans + val) % MOD;
        }  

        return (int)ans;
    }
};
