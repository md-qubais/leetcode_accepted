
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> A = {head->val}, dp = {0};
        int i = 0;
        head = head->next;
        while (head) {
            while (i && head->val != A[i])
                i = dp[i - 1];
            i += head->val == A[i];
            A.push_back(head->val);
            dp.push_back(i);
            head = head->next;
        }
        return dfs(root, 0, A, dp);
    }

    bool dfs(TreeNode* root, int i, vector<int>& A, vector<int>& dp) {
        if (!root) return false;
        while (i && root->val != A[i])
            i = dp[i - 1];
        i += root->val == A[i];
        return i == dp.size() || dfs(root->left, i, A, dp) || dfs(root->right, i, A, dp);
    }
};