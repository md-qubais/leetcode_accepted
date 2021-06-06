class Solution {
public:
    bool isValidSerialization(string preorder){
        if(preorder.length()==1){
            if(preorder[0]=='#'){
                return true;
            }
            return false;
        }
        stack<int> num;
        stack<char> nodes;
        for(int i=0;i<preorder.size();i++){
            if(preorder[0]==','){
                continue;
            }
            if(preorder[i]=='#'){
                nodes.push('#');
                if(nodes.size()>=2 and num.size()>=1){
                    num.pop();
                    nodes.pop();
                    nodes.pop();
                }
                continue;
            }else{
                int j=i;
                while(preorder[j]!=','){
                    j++;
                }
                num.push(1);
                i=j;
            }
        }
        if(num.empty() and nodes.empty()){
            return true;
        }
        return false;
    }
};