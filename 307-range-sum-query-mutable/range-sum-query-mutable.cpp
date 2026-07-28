class NumArray {
public:
    vector<int> bit, nums;
    int n;

    NumArray(vector<int>& arr) {
        n = arr.size();
        nums = arr;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            add(i + 1, arr[i]);
    }

    void add(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += index & (-index);
        }
    }

    int sum(int index) {
        int s = 0;
        while (index > 0) {
            s += bit[index];
            index -= index & (-index);
        }
        return s;
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        add(index + 1, diff);
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */