class Solution {
public:
    string minRemoveToMakeValid(string str){
        int count=0;
        stack<string> s;
        int remove_forward=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                string temp="(";
                count++;
                s.push(temp);
                continue;
            }
            if(str[i]==')'){
                if(count>0){
                    count--;
                    string temp="";
                    temp+=")";
                    while(s.top()=="("){
                        temp=s.top()+temp;
                        s.pop();
                    }
                    s.push(temp);
                }else{
                    remove_forward++;
                }
                continue;
            }
            string temp="";
            temp+=str[i];
            s.push(temp);
        }
        pair<string,int> ans_forward=make_pair("",count);
        while(!s.empty()){
            ans_forward.first=s.top()+ans_forward.first;
            s.pop();
        }
        count=0;
        int remove_backward=0;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]==')'){
                count++;
                string temp="";
                temp+=")";
                s.push(temp);
                continue;
            }
            if(str[i]=='('){
                if(count>0){
                    count--;
                    string temp="(";
                    while(s.top()==")"){
                        temp+=s.top();
                        s.pop();
                    }
                    s.push(temp);
                }else{
                    remove_backward++;
                }
                continue;
            }
            string temp="";
            temp+=str[i];
            s.push(temp);
        }
        pair<string,int> ans_backward=make_pair("",count);
        while(!s.empty()){
            ans_backward.first+=s.top();
            s.pop();
        }
        if(ans_backward.second>0){
            if(ans_forward.second>0){
                return "";
            }
            return ans_forward.first;
        }
        if(ans_forward.second>0){
            if(ans_backward.second>0){
                return "";
            }
            return ans_backward.first;
        }
        if(remove_backward<remove_forward){
            return ans_backward.first;
        }
        return ans_forward.first;
    }
};