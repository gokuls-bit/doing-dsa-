class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxValue = *max_element(nums.begin(), nums.end());

        vector<long long> frequency(maxValue + 1, 0);

        for (int value : nums) {
            frequency[value]++;
        }

        // divisibleCount[d] = numbers divisible by d
        vector<long long> divisibleCount(maxValue + 1, 0);

        for (int divisor = 1; divisor <= maxValue; divisor++) {

            for (int multiple = divisor; multiple <= maxValue; multiple += divisor) {

                divisibleCount[divisor] += frequency[multiple];
            }
        }

        // exactPairs[d] = pairs whose gcd is exactly d
        vector<long long> exactPairs(maxValue + 1, 0);

        for (int divisor = maxValue; divisor >= 1; divisor--) {

            long long count = divisibleCount[divisor];

            exactPairs[divisor] = count * (count - 1) / 2;

            for (int multiple = divisor * 2;
                 multiple <= maxValue;
                 multiple += divisor) {

                exactPairs[divisor] -= exactPairs[multiple];
            }
        }

        vector<long long> prefix(maxValue + 1, 0);

        for (int i = 1; i <= maxValue; i++) {

            prefix[i] = prefix[i - 1] + exactPairs[i];
        }

        vector<int> answer;

        for (long long query : queries) {

            int gcdValue = lower_bound(
                prefix.begin() + 1,
                prefix.end(),
                query + 1
            ) - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};
