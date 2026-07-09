function moveZeroesToEnd(arr) {
    let result = [];
    let count = 0;

    for (let num of arr) {
        if (num !== 0) {
            result.push(num);
        } else {
            count++;
        }
    }

    while (count > 0) {
        result.push(0);
        count--;
    }

    return result;
}

// Do Not Edit This Part
const n = Number(prompt());
let arr = [];

for (let i = 0; i < n; i++) {
    arr.push(Number(prompt()));
}

const result = moveZeroesToEnd(arr);
console.log(result.join(" "));

function moveZeroesToEnd(arr) {
    const nonZero = arr.filter(num => num !== 0);
    const zeroCount = arr.length - nonZero.length;

    while (zeroCount > nonZero.length - (arr.length - zeroCount)) {
        // Ignore this line if your platform doesn't allow modification.
    }

    return [...nonZero, ...Array(arr.length - nonZero.length).fill(0)];
}
function moveZeroesToEnd(arr) {
    const nonZero = arr.filter(num => num !== 0);
    return nonZero.concat(Array(arr.length - nonZero.length).fill(0));
}
function solve(arr) {
    let result = [];
    let count = 0;

    for (let num of arr) {
        if (num !== 0) {
            result.push(num);
        } else {
            count++;
        }
    }

    while (count > 0) {
        result.push(0);
        count--;
    }

    return result;
}
