#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
unordered_map<int,bool> placed;
void queens_box_ch_permutation(int n,int i=0,int j=0,int asf=0,string ans=""){
     if(j==n){
       if(asf==n){
       	 cout<<ans<<endl;
         cout<<endl;
       }
       return;
    }
	if(i==n){
		ans+='\n';
		queens_box_ch_permutation(n,0,j+1,asf,ans);
		return;
	}
	//yes that box says it will consider the queen(any queen)
	for(int k=1;k<=n;k++){
		if(!placed[k]){
			placed[k]=true;
			queens_box_ch_permutation(n,i+1,j,asf+1,ans+"q"+to_string(k)+"\t");
			placed[k]=false;
		}
	}

	//no the box will say that it wont consider the queen(any queen)
	queens_box_ch_permutation(n,i+1,j,asf,ans+"-"+"\t");
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	queens_box_ch_permutation(n);
	return 0;
}