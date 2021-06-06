class compare{
public:
    bool operator()(pair<char,int> p1,pair<char,int> p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
};
class Solution {
public:
    string reorganizeString(string s){
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        unordered_map<char,int> freq;
        for(auto&it:s){
            freq[it]++;
        }
        for(auto&it:freq){
            pq.push({it.first,it.second});
        }
        string ans="";
        while(!pq.empty()){
            if(pq.top().second==0) pq.pop();
            else{
                pair<char,int> temp=pq.top();
                pq.pop();
                temp.second--;
                pq.push(temp);
                if(ans.length()==0){
                    ans+=temp.first;
                }else{
                    if(ans[ans.length()-1]==temp.first){
                        return "";
                    }else{
                        ans+=temp.first;
                    }
                }
            }
        }
        return ans;
    }
};