#include <vector>

class Solution {
private:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) cnt[i] = 0;
        }
    };

    int n, K;
    std::vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (1LL * left.prod * right.prod) % K;

        for (int r = 0; r < K; ++r) {
            res.cnt[r] += left.cnt[r];
        }

        for (int r = 0; r < K; ++r) {
            if (right.cnt[r] > 0) {
                int combined_rem = (1LL * left.prod * r) % K;
                res.cnt[combined_rem] += right.cnt[r];
            }
        }

        return res;
    }

    void build(int node, int start, int end, const std::vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % K;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % K;
            for (int i = 0; i < K; ++i) tree[node].cnt[i] = 0;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void query(int node, int start, int end, int l, int r, int& running_prod, int target_x, int& total_count) {
        if (l <= start && end <= r) {
            for (int r_val = 0; r_val < K; ++r_val) {
                if (tree[node].cnt[r_val] > 0) {
                    if ((1LL * running_prod * r_val) % K == target_x) {
                        total_count += tree[node].cnt[r_val];
                    }
                }
            }
            running_prod = (1LL * running_prod * tree[node].prod) % K;
            return;
        }
        int mid = start + (end - start) / 2;
        if (l <= mid) {
            query(2 * node, start, mid, l, r, running_prod, target_x, total_count);
        }
        if (r > mid) {
            query(2 * node + 1, mid + 1, end, l, r, running_prod, target_x, total_count);
        }
    }

public:
    std::vector<int> resultArray(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
        n = nums.size();
        K = k;
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);

        std::vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);

            int total_count = 0;
            int running_prod = 1;
            query(1, 0, n - 1, start, n - 1, running_prod, x, total_count);

            result.push_back(total_count);
        }

        return result;
    }
};