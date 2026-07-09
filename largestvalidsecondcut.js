function countWays(nums) {
    const MOD = 1000000007;
    const n = nums.length;

    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    const total = prefix[n];
    let ans = 0;

    for (let i = 1; i <= n - 2; i++) {

        let left = i + 1;
        let right = n - 1;
        let last = i;

        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (prefix[mid] <= prefix[i] + total / 2) {
                last = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (last > i) {
            ans = (ans + (last - i)) % MOD;
        }
    }

    return ans;
}
