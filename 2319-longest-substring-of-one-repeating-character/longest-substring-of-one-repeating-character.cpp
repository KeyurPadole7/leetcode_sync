struct Node {
    int max_len = 0;
    int prefix_len = 0;
    int suffix_len = 0;
    char left_char = 0;
    char right_char = 0;
};

class Solution {
    vector<Node> tree;
    string str;

    Node merge(const Node& left, const Node& right, int left_len, int right_len) {
        Node parent;
        parent.left_char = left.left_char;
        parent.right_char = right.right_char;

        // Base max length from children
        parent.max_len = max(left.max_len, right.max_len);

        // Check if characters at the boundary match
        if (left.right_char == right.left_char) {
            parent.max_len = max(parent.max_len, left.suffix_len + right.prefix_len);
        }

        // Calculate prefix length
        if (left.prefix_len == left_len && left.right_char == right.left_char) {
            parent.prefix_len = left.prefix_len + right.prefix_len;
        } else {
            parent.prefix_len = left.prefix_len;
        }

        // Calculate suffix length
        if (right.suffix_len == right_len && left.right_char == right.left_char) {
            parent.suffix_len = right.suffix_len + left.suffix_len;
        } else {
            parent.suffix_len = right.suffix_len;
        }

        return parent;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, str[start], str[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        
        int left_len = mid - start + 1;
        int right_len = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_len, right_len);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            str[idx] = ch;
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }

        int left_len = mid - start + 1;
        int right_len = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_len, right_len);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;
        int k = queryIndices.size();
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].max_len);
        }

        return ans;
    }
};