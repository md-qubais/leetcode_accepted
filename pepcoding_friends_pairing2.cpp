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
bool used[1000];
int c=0;
void friend_pairing(int n,int i=1,string asf=""){
	if(i>n){
		c++;
		cout<<c<<".";
		cout<<asf<<endl;
		return ;
	}
	if(used[i]==true){
		friend_pairing(n,i+1,asf);
		return;
	}
	used[i]=true;
	friend_pairing(n,i+1,asf+"("+to_string(i)+") ");
	used[i]=false;
	for(int j=i+1;j<=n;j++){
		if(!used[j]){
			used[i]=true;
			used[j]=true;
			friend_pairing(n,i+1,asf+"("+to_string(i)+","+to_string(j)+") ");
			used[i]=false;
			used[j]=false;
		}
	}
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	friend_pairing(n);
	return 0;
}