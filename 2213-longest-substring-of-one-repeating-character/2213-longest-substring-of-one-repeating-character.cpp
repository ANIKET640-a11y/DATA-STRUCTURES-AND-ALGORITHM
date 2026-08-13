class Solution {
    struct Node {
        int l, r;
        int lmx, rmx, mx;

        Node() {}

        Node(int l, int r) {
            this->l = l;
            this->r = r;
            lmx = rmx = mx = 1;
        }
    };

    vector<Node> tree;
    string s;

    void build(int node, int l, int r) {
        tree[node] = Node(l, r);

        if (l == r)
            return;

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        merge(node);
    }

    void merge(int node) {
        Node &cur = tree[node];
        Node &left = tree[node * 2];
        Node &right = tree[node * 2 + 1];

        cur.lmx = left.lmx;
        cur.rmx = right.rmx;
        cur.mx = max(left.mx, right.mx);

        int leftLen = left.r - left.l + 1;
        int rightLen = right.r - right.l + 1;

        // If the boundary characters are equal
        if (s[left.r] == s[right.l]) {

            // Entire left segment has same character
            if (left.lmx == leftLen)
                cur.lmx += right.lmx;

            // Entire right segment has same character
            if (right.rmx == rightLen)
                cur.rmx += left.rmx;

            // Join suffix of left + prefix of right
            cur.mx = max(cur.mx, left.rmx + right.lmx);
        }
    }

    void update(int node, int pos, char c) {
        if (tree[node].l == tree[node].r) {
            s[pos] = c;
            return;
        }

        int mid = (tree[node].l + tree[node].r) / 2;

        if (pos <= mid)
            update(node * 2, pos, c);
        else
            update(node * 2 + 1, pos, c);

        merge(node);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];

            update(1, index, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};