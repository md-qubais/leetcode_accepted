class Solution {
public:
    void generate_permutation(string ans,int i,int n,int k){
        if(i==ans.length()){
            cout<<ans<<endl;
            return;
        }
        for(int j=i;j<ans.length();j++){
            swap(ans[i],ans[j]);
            getPermutation();
            swap(ans[i],ans[j]);
        }

    }
    string getPermutation(int n, int k){
        string ans="";
        for(int i=1;i<=n;i++){
            ans+=to_string(i);
        }
        generate_permutation(ans,0,n,k);
        return "";
    }
};