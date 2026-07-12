var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {

    const now = Date.now();

    // Check whether the key already exists and has not expired
    const existed =
        this.cache.has(key) &&
        this.cache.get(key).expiration > now;

    // Store new value and new expiration time
    this.cache.set(key, {
        value: value,
        expiration: now + duration
    });

    return existed;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {

    if (!this.cache.has(key)) {
        return -1;
    }

    const item = this.cache.get(key);

    if (item.expiration <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return item.value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {

    const now = Date.now();
    let count = 0;

    for (const [key, item] of this.cache) {

        if (item.expiration > now) {
            count++;
        } else {
            this.cache.delete(key);
        }
    }

    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache();
 *
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1);           // 42
 * timeLimitedCache.count();          // 1
 */
