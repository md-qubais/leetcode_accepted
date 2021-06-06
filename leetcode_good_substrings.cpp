class Solution {
public:
    int countGoodSubstrings(string s){
        if(s.length()<3){
            return 0;
        }
        unordered_map<char,int> freq;
        int ans=0;
        int i=0;
        while(i<3){
            freq[s[i++]]++;
        }
        if(freq.size()==3){
            ans++;
        }
        int j=i;
        i=0;
        while(j<s.length()){
            freq[s[i]]--;
            if(freq[s[i]]==0){
                freq.erase(s[i]);
            }
            i++;
            freq[s[j]]++;
            if(freq.size()==3){
                ans++;
            }
            j++;
        }
        return ans;
    }
};