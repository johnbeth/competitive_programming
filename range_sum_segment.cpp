class NumArray {

public:
    vector<int> t;
    int n;


    NumArray(vector<int> nums) {
        n = nums.size();
        t.clear();
        t.resize(2 * n, 0);
        for (int i = 0; i < n; i++) {
            t[i + n] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void update(int pos, int value) {
        // for (t[pos += n] = value; pos > 1; pos >>= 1) {
        //     t[pos >> 1] = t[pos] + t[pos ^ 1];
        // }

        pos += n;
        t[pos] = value;
        while (pos > 0) {
            int left = pos;
            int right = pos;
            if (pos % 2 == 0) {
                right = pos + 1;
            } else {
                left = pos - 1;
            }
            t[pos / 2] = t[left] + t[right];
            pos /= 2;
        }
    }

    int sumRange(int l, int r) {
        l += n;
        r += n;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
                sum += t[l];
                l++;
            }
            if ((r % 2) == 0) {
                sum += t[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};