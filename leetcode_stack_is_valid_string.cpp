class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(auto&it:s){
            st.push(it);
            if(!st.empty()){
                string temp="";
                int count=0;
                while(!st.empty() and count<3){
                    temp=st.top()+temp;
                    st.pop();
                    count++;
                }
                if(temp=="abc"){
                    continue;
                }else{
                    for(auto&it:temp){
                        st.push(it);
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};