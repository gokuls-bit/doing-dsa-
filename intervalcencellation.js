/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // Execute immediately
    fn(...args);

    // Execute repeatedly every t milliseconds
    const intervalId = setInterval(() => {
        fn(...args);
    }, t);

    // Return cancellation function
    return function cancelFn() {
        clearInterval(intervalId);
    };
};
