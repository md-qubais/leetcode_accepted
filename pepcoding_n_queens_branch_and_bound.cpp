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
bool board[1000][1000];
bool column[1000];
bool left_diagonal[1000];
bool right_digaonal[1000];

void n_queen_branch_bound(int n,int rows=0,int cols=0,string asf=""){
	if(rows==n){
		cout<<asf+"."<<endl;
		return;
	}
	for(int i=cols;i<n;i++){
		if(!left_diagonal[rows+i] and !right_digaonal[rows-i+n-1] and !column[i] ){
			board[rows][i]=true;
			column[i]=true;
			left_diagonal[rows+i]=true;
			right_digaonal[rows-i+n-1]=true;
			n_queen_branch_bound(n,rows+1,0,asf+to_string(rows)+"-"+to_string(i)+", ");
			board[rows][i]=false;
			column[i]=false;
			left_diagonal[rows+i]=false;
			right_digaonal[rows-i+n-1]=false;
		}
	}

}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	n_queen_branch_bound(n);
	return 0;
}