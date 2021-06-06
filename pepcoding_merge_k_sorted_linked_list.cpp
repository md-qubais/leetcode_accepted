#include <iostream>
#include <vector>
using namespace std;


class ListNode{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val){
        this->val = val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists){
    return nullptr;
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
    return dummy->next
}

int main(){
    int n;
    cin >> n;
    vector<ListNode *> list(n, 0);
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        list[i] = createList(m);
    }
    ListNode *head = mergeKLists(list);
    printList(head);
    return 0;
}