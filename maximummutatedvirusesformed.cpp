#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int maxMutatedViruses(int N, vector<int>& contamination_levels) {
    const int MAXL = 105;
    const int NEG = -1e9;

    vector<int> freq(MAXL, 0);

    for (int x : contamination_levels) {
        freq[x]++;
    }

    // dp[level][a][b]
    // level = current contamination level being processed
    // a = how many viruses of current level are already used
    // b = how many viruses of next level are already used
    int dp[MAXL][3][3];

    for (int i = 0; i < MAXL; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = NEG;
            }
        }
    }

    dp[1][0][0] = 0;

    for (int level = 1; level <= 100; level++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {

                if (dp[level][a][b] == NEG) continue;

                if (freq[level] < a || freq[level + 1] < b) continue;

                int remaining = freq[level] - a;

                // t = number of consecutive groups formed:
                // (level, level+1, level+2)
                int maxT = remaining;
                maxT = min(maxT, freq[level + 1] - b);
                maxT = min(maxT, freq[level + 2]);

                // t only needs to be checked up to 2
                // because 3 of same type can be turned into one identical group
                for (int t = 0; t <= maxT && t < 3; t++) {

                    int rem = remaining - t;

                    // make groups of same contamination level
                    int sameGroups = rem / 3;

                    dp[level + 1][b + t][t] = max(
                        dp[level + 1][b + t][t],
                        dp[level][a][b] + t + sameGroups
                    );
                }
            }
        }
    }

    int ans = 0;

    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            ans = max(ans, dp[101][a][b]);
        }
    }

    return ans;
}

int main() {
    int V;
    cin >> V;

    vector<int> contamination_levels(V);
    for (int i = 0; i < V; i++) {
        cin >> contamination_levels[i];
    }

    int result = maxMutatedViruses(V, contamination_levels);
    cout << result << endl;

    return 0;
}
