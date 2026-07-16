class Solution(object):
    def gcdSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        prefixGcd = []

        currentMax = 0

        for num in nums:

            currentMax = max(currentMax, num)

            prefixGcd.append(gcd(num, currentMax))

        prefixGcd.sort()

        left = 0
        right = len(prefixGcd) - 1

        answer = 0

        while left < right:

            answer += gcd(prefixGcd[left], prefixGcd[right])

            left += 1
            right -= 1

        return answer
