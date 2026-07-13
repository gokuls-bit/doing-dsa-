/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    const digits = "123456789";
    const result = [];

    for (let length = 2; length <= 9; length++) {
        for (let start = 0; start + length <= 9; start++) {
            const num = Number(digits.substring(start, start + length));

            if (num >= low && num <= high) {
                result.push(num);
            }
        }
    }

    return result.sort((a, b) => a - b);
};
