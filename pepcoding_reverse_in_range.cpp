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

class ListNode{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val){
        this->val = val;
    }
};

ListNode *reverseInrange(ListNode *head, int n1,int n2){
    int count=1;
    ListNode*ans=head;
    ListNode*prev=NULL;
    while(count<n1){
        prev=head;
        head=head->next;
        count++;
    }
    ListNode*tail=head;
    ListNode*curr=head;
    ListNode*temp=NULL;
    head=head->next;
    while(count<n2){
        curr->next=temp;
        temp=curr;
        curr=head;
        head=head->next;
        count++;
    }
    curr->next=temp;
    tail->next=head;
    if(prev){
        prev->next=curr;
    }else{
        ans=curr;
    }
    return ans;
}

void printList(ListNode *node){
    ListNode *curr = node;
    while (curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n){
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0){
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int32_t main(){
    qubais_judge;
    IOS;
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    int n1,n2;
    cin>>n1>>n2;
    h1 = reverseInrange(h1,n1,n2);
    printList(h1);
    return 0;
}