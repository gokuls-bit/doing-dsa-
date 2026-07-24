class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();

        int baseOnes = 0;

        for (char c : s) {
            if (c == '1') {
                baseOnes++;
            }
        }

        vector<pair<char, int>> runs;

        for (int i = 0; i < n;) {

            int j = i;

            while (j < n && s[j] == s[i]) {
                j++;
            }

            runs.push_back({s[i], j - i});

            i = j;
        }

        int bestGain = 0;

        for (int i = 1; i + 1 < runs.size(); i++) {

            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                bestGain = max(
                    bestGain,
                    runs[i - 1].second + runs[i + 1].second
                );
            }
        }class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));

        dp[0][0] = true;

        for (int value : nums) {

            for (int taken = 2; taken >= 0; taken--) {

                for (int x = 0; x < MAXX; x++) {

                    if (dp[taken][x]) {

                        dp[taken + 1][x ^ value] = true;
                    }
                }
            }
        }

        int answer = 0;

        for (int x = 0; x < MAXX; x++) {

            if (dp[1][x] || dp[3][x]) {

                answer++;
            }
        }

        return answer;
    }
};class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));

        dp[0][0] = true;

        for (int value : nums) {

            for (int taken = 2; taken >= 0; taken--) {

                for (int x = 0; x < MAXX; x++) {

                    if (dp[taken][x]) {

                        dp[taken + 1][x ^ value] = true;
                    }
                }
            }
        }

        int answer = 0;

        for (int x = 0; x < MAXX; x++) {

            if (dp[1][x] || dp[3][x]) {

                answer++;
            }
        }

        return answer;
    }
};

        return baseOnes + bestGain;
    }
};
