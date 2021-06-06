class Solution{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity){
        vector<pair<pair<int,int>,int>> arr;
        int s=INT_MAX;
        int e=INT_MIN;
        for(int i=0;i<trips.size();i++){
            arr.push_back({{trips[i][1],trips[i][2]},trips[i][0]});
        }
        sort(begin(arr),end(arr));
        unordered_map<int,vector<int>> insert;
        unordered_map<int,vector<int>> remove;
        for(auto&it:arr){
            insert[it.first.first].push_back(it.second);
            remove[it.first.second].push_back(it.second);
            s=min(s,it.first.first);
            e=max(e,it.first.second);
        }
        int tot=0;
        for(int i=s;i<=e;i++){
            for(auto&it:insert[i]){
                tot+=it;
            }
            for(auto&it:remove[i]){
                tot-=it;
            }
            if(tot>capacity){
                return false;
            }
        }
        return true;
    }
};