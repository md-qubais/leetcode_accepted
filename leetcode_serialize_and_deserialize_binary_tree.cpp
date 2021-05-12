class Codec{
public:

    void preorder(TreeNode*root,string &ans){
        if(!root){
            ans+="n ";
            return;
        }
        ans+=to_string(root->val)+" ";
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

    string serialize(TreeNode* root){
        if(!root){
            return "";
        }
        string ans="";
        preorder(root,ans);
        return ans;
    }

    TreeNode* buildtree(vector<int>&arr,int&i){
        if(i>=arr.size()){
            return NULL;
        }
        if(arr[i]==INT_MIN){
            i++;
            return NULL;
        }
        TreeNode*root=new TreeNode(arr[i++]);
        root->left=buildtree(arr,i);
        root->right=buildtree(arr,i);
        return root;
    }

    TreeNode* deserialize(string data){
        if(data=="" or data.length()==0){
            return NULL;
        }
        vector<int> arr;
        //extract the numbers from the string;
        for(int i=0;i<data.length();i++){
            string temp="";
            if(data[i]=='n') arr.push_back(INT_MIN);
            else if((data[i]>='0' and data[i]<='9') or data[i]=='-'){
                while((data[i]>='0' and data[i]<='9') or data[i]=='-'){
                    temp+=data[i];
                    i++;
                }
                i--;
                stringstream str(temp);
                int n;
                str>>n;
                arr.push_back(n);
            }
        }
        int i=0;
        return buildtree(arr,i);
    }

};


