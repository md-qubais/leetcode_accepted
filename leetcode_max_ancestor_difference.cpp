class Tree{
public:
    int maximum;
    int minimum;
    int absolute_diff;
    bool is_leaf;
    Tree(){
        maximum=0;
        minimum=0;
        absolute_diff=0;
        is_leaf=true;
    }
};
class Solution{
public:
    Tree max_diff(TreeNode* root){
        Tree temp;
        if(!root){
            return temp;
        }
        Tree left=max_diff(root->left);
        Tree right=max_diff(root->right);
        if(left.is_leaf and right.is_leaf){
            temp.maximum=root->val;
            temp.minimum=root->val;
            temp.absolute_diff=0;
            temp.is_leaf=false;
            return temp;
        }
        if(left.is_leaf){
            //make on right
            temp.maximum=max(root->val,right.maximum);
            temp.minimum=min(root->val,right.minimum);
            temp.absolute_diff=max(right.absolute_diff,abs(root->val - right.maximum));
            temp.absolute_diff=max(temp.absolute_diff,abs(root->val - right.minimum));
            temp.is_leaf=false;
            return temp;
        }
        if(right.is_leaf){
            //make on left
            temp.maximum=max(root->val,left.maximum);
            temp.minimum=min(root->val,left.minimum);
            temp.absolute_diff=max(left.absolute_diff,abs(root->val - left.maximum));
            temp.absolute_diff=max(temp.absolute_diff,abs(root->val - left.minimum));
            temp.is_leaf=false;
            return temp;
        }
        int Max=max(root->val,max(left.maximum,right.maximum));
        int Min=min(root->val,min(left.minimum,right.minimum));
        temp.maximum=Max;
        temp.minimum=Min;
        temp.absolute_diff=max(left.absolute_diff,right.absolute_diff);
        temp.absolute_diff=max(temp.absolute_diff,max(abs(root->val-Max),abs(root->val-Min)));   
        temp.is_leaf=false;
        return temp;
    }
    int maxAncestorDiff(TreeNode* root){
        return max_diff(root).absolute_diff;
    }
};