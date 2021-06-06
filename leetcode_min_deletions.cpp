class Solution {
public:
    static bool compare(pair<int,char> p1,pair<int,char> p2){
        return p1.first>p2.first;
    }
    int minDeletions(string s){
        vector<pair<int,char>> arr;
        unordered_map<char,int> freq;
        for(auto&it:s){
            freq[it]++;
        }
        for(auto&it:freq){
            arr.push_back({it.second,it.first});
        }
        int ans=0;
        sort(arr.begin(),arr.end(),compare);
        unordered_map<int,bool> marked;
        for(auto&it:arr){
            if(!marked[it.first]){
                marked[it.first]=true;
            }else{
                while(marked[it.first] and it.first>0){
                    ans++;
                    it.first--;
                }
                if(it.first>0) marked[it.first]=true;
            }
        }
        return ans;
    }
};