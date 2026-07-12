/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
    const lines = input.split('\n');

    // pathLength[d] = total length of path up to depth d
    const pathLength = [];

    let maxLength = 0;

    for (const line of lines) {

        // Count tabs to determine depth
        let depth = 0;

        while (depth < line.length && line[depth] === '\t') {
            depth++;
        }

        // Remove tabs to get actual file/directory name
        const name = line.substring(depth);

        // Parent path length
        const parentLength = depth === 0 ? 0 : pathLength[depth - 1];

        // Current absolute path length
        const currentLength =
            parentLength +
            name.length +
            (depth === 0 ? 0 : 1); // +1 for '/'

        pathLength[depth] = currentLength;

        // A dot means this is a file
        if (name.includes('.')) {
            maxLength = Math.max(maxLength, currentLength);
        }
    }

    return maxLength;
};
