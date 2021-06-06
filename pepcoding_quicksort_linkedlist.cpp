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
    ListNode *next = NULL;

    ListNode(int val){
        this->val = val;
    }
};

void printList(ListNode *node){
    ListNode *curr = node;
    while (curr != NULL){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}



//always use quicksort on mid or random
//using pivot first or last doesnt give us more
//optimized answer than mid or random choosing the
//pivot element
ListNode* quickSort(ListNode*head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    ListNode*curr=head;
    ListNode*small=NULL;
    ListNode*small_start=NULL;
    ListNode*big=NULL;
    ListNode*big_start=NULL;
    ListNode*pivot=head;
    while(curr){
        if(head==curr){
        }else if(curr->val<=pivot->val){
            if(small_start==NULL){
                small_start=curr;
                small=curr;
            }else{
                small->next=curr;
                small=curr;
            }
        }else{
            if(big_start==NULL){
                big_start=curr;
                big=curr;
            }else{
                big->next=curr;
                big=curr;
            }
        }
        curr=curr->next;
    }
    if(big_start){
        big->next=NULL;
    }
    if(small_start){
        small->next=NULL;
    }
    ListNode*left=quickSort(small_start);
    ListNode*right=quickSort(big_start);
    if(left and right){
        ListNode*t=left;
        while(t->next){
            t=t->next;
        }
        t->next=pivot;
        pivot->next=right;
    }else if(left){
        ListNode*t=left;
        while(t->next){
            t=t->next;
        }
        t->next=pivot;
        pivot->next=NULL;
    }
    else if(right){
        left=pivot;
        left->next=right;
    }
    return left;
}

ListNode* createList(int n){
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
    ListNode *head = quickSort(h1);
    printList(head);
    return 0;
}
