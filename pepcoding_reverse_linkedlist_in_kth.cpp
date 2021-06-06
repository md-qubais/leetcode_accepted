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

int length(ListNode*root){
    int len=0;
    while(root){
        root=root->next;
        len++;
    }
    return len;
}

vector<ListNode*> reverse_k(ListNode*head,int k){
    ListNode*tail=head;
    ListNode*curr=head;
    ListNode*prev=NULL;
    head=head->next;
    vector<ListNode*> arr(3);
    k=k-1;
    while(k--){
        curr->next=prev;
        prev=curr;
        curr=head;
        head=head->next;
    }
    curr->next=prev;
    arr[2]=head;
    arr[0]=curr;
    arr[1]=tail;
    return arr;
}

ListNode *reverseInKGroup(ListNode *head, int k){
    if(k==0){
        return head;
    }
    int len=length(head);
    if(len<k){
        return head;
    };
    ListNode*ans_head=NULL;
    ListNode*ans_tail=NULL;
    while(len>=k){
        len=len-k;
        vector<ListNode*> temp=reverse_k(head,k);
        if(!ans_head){
        ans_head=temp[0];
        ans_tail=temp[1];
        }else{
            ans_tail->next=temp[0];
            ans_tail=temp[1];
        }
        head=temp[2];
        ans_tail->next=head;
    }
    return ans_head;
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
    int k;
    cin >> k;
    h1 = reverseInKGroup(h1, k);
    printList(h1);
    return 0;
}