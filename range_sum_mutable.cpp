class NumArray {
public:
    vector<int> t;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        t.resize(2 * n);
        build(nums);
    }
    
    void build(vector<int> arr) {
        for(int x = 0; x < n; x++) {
            t[x + n] = arr[x];
        }
        for(int x = n - 1; x > 0; x--) {
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }
    
    void update(int pos, int value) {
        for (t[pos += n] = value; pos > 1; pos >>= 1) {
            t[pos >> 1] = t[pos] + t[pos ^ 1];
        }
    }
    
    int sumRange(int l, int r) {
        int res = 0;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                res += t[l++];
            }
            if(!(r & 1)) {
                res += t[r--];
            }
        }
        return res;
    }
};