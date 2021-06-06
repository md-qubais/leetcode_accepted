class FreqStack {
public:
    unordered_map<int,int> freq;
    map<int,list<int>> st;
    FreqStack() {       
    }

    void push(int val) {
        freq[val]++;
        st[freq[val]].push_back(val);
    }
    int pop(){   
        auto it=st.rbegin();
        int num=st[it->first].back();
        st[it->first].remove(num);
        if(st[it->first].size()==0){
            st.erase(it->first);
        }
        freq[num]--;
        return num;
    }
};