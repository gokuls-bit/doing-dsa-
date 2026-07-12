/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    const freq = new Array(26).fill(0);

    // Count frequency of every character
    for (let char of s) {
        const index = char.charCodeAt(0) - 97;
        freq[index]++;
    }

    // Find first character with frequency 1
    for (let i = 0; i < s.length; i++) {
        const index = s.charCodeAt(i) - 97;

        if (freq[index] === 1) {
            return i;
        }
    }

    return -1;
};
