class Solution{
public:
    int arrayNesting(vector<int>&arr){
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int size=0;
            int index=i;
            unordered_map<int,bool> visited;
            while(!visited[arr[index]]){
                size++;
                visited[arr[index]]=true;
                cout<<arr[index]<<" ";
                index=arr[index];
            }
            cout<<endl;
            ans=max(ans,size);
        }
        return ans;
    }
};