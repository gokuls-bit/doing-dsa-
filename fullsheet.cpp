
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) return 0;

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }

        return ans;
    }
};

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (dp[j] != -1 &&
                    abs((long long)nums[i] - nums[j]) <= target) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {

            string s = to_string(num);

            for (char c : s)
                ans.push_back(c - '0');
        }

        return ans;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (abs(sum - target) < abs(closest - target))
                    closest = sum;

                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else
                    return sum;
            }
        }

        return closest;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right--;
        }

        return nums[left];
    }
};

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;

        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if (forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }

            if (backward >= 0 && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {

                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                    return false;
            }
        }

        return st.empty();
    }
};

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > nums[(i + 1) % n])
                count++;
        }

        return count <= 1;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            while (j < m && haystack[i + j] == needle[j])
                j++;

            if (j == m)
                return i;
        }

        return -1;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long ans = 0;

        for (int i = 31; i >= 0; i--) {

            if ((dvd >> i) >= dvs) {

                ans += (1LL << i);
                dvd -= (dvs << i);
            }
        }

        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int asteroid : asteroids) {

            if (currMass < asteroid)
                return false;

            currMass += asteroid;
        }

        return true;
    }
};

class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());

        int total = 0;

        for (int i = 0; i < cost.size(); i++) {

            if ((i + 1) % 3 != 0)
                total += cost[i];
        }

        return total;
    }
};

class Solution {
public:
    int numOfWays(int n) {

        const long long MOD = 1e9 + 7;

        long long aba = 6;
        long long abc = 6;

        for (int i = 2; i <= n; i++) {

            long long newAba =
                (aba * 3 + abc * 2) % MOD;

            long long newAbc =
                (aba * 2 + abc * 2) % MOD;

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};

class Solution {
public:

    int digitSum(int n) {

        int sum = 0;

        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for (int num : nums) {
            ans = min(ans, digitSum(num));
        }

        return ans;
    }
};

class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for (int i = 0; i < word.size(); i++) {

            char c = word[i];

            if (islower(c)) {

                lastLower[c - 'a'] = i;
            }
            else {

                int idx = c - 'A';

                if (firstUpper[idx] == -1)
                    firstUpper[idx] = i;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {

            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {

                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char> seen;

        int strength = 0;

        for (char c : password) {

            if (seen.count(c))
                continue;

            seen.insert(c);

            if (islower(c))
                strength += 1;
            else if (isupper(c))
                strength += 2;
            else if (isdigit(c))
                strength += 3;
            else
                strength += 5;
        }

        return strength;
    }
};

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        vector<int> ans;

        for (int num : nums) {

            if (freq[num] < k) {

                ans.push_back(num);
                freq[num]++;
            }
        }

        return ans;
    }
};

class Solution {
public:

    int calc(vector<int>& start1,
             vector<int>& dur1,
             vector<int>& start2,
             vector<int>& dur2) {

        int earliestEnd = INT_MAX;

        for (int i = 0; i < start1.size(); i++) {
            earliestEnd =
                min(earliestEnd,
                    start1[i] + dur1[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < start2.size(); i++) {

            ans = min(ans,
                max(earliestEnd,
                    start2[i]) + dur2[i]);
        }

        return ans;
    }

    int earliestFinishTime(
        vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration) {

        int landFirst =
            calc(landStartTime,
                 landDuration,
                 waterStartTime,
                 waterDuration);

        int waterFirst =
            calc(waterStartTime,
                 waterDuration,
                 landStartTime,
                 landDuration);

        return min(landFirst, waterFirst);
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<bool> visited(n, false);

        queue<int> q;

        q.push(0);
        visited[0] = true;

        int farthest = 0;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            if (i == n - 1)
                return true;

            int start =
                max(i + minJump,
                    farthest + 1);

            int end =
                min(i + maxJump,
                    n - 1);

            for (int j = start;
                 j <= end;
                 j++) {

                if (s[j] == '0') {

                    visited[j] = true;
                    q.push(j);
                }
            }

            farthest = end;
        }

        return false;
    }
};
