class Solution{
public:
    string get_mails(string s){
        string ans="";
        bool local_name=true;
        bool plus=false;
        for(auto&it:s){
            if(plus and it!='@'){
                continue;
            }
            if(it=='.'){
                if(local_name){
                    continue;
                }
                ans+=it;
            }
            else if(it=='@'){
                plus=false;
                local_name=false;
                ans+=it;
                continue;
            }else if(it=='+'){
                plus=true;
                continue;
            }else{
                ans+=it;
            }
        }
        return ans;
    }
    int numUniqueEmails(vector<string>& emails){
        set<string> ans;
        for(auto&it:emails){
            ans.insert(get_mails(it));
        }
        return ans.size();
    }
};