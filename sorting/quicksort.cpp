//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {

    bool firstbigger(Node*head1 , Node*head2){
        int cnt1 = 0;
        int cnt2 = 0;
        Node* temp1 = head1;Node* temp2 = head2;
        
        vector<int>head1array;vector<int>head2array;
        while(temp1!=nullptr){
            cnt1++;
            head1array.push_back(temp1->data);
            temp1 = temp1->next;
        }
        while(temp2!=nullptr){
            cnt2++;
            head2array.push_back(temp2->data);
            temp2 = temp2->next;
        }
        if(cnt1==cnt2){
            for(int i = 0;i<cnt1;i++){
                if(head1array[i] > head2array[i]){
                    return true;
                }else if(head1array[i] < head2array[i]){
                    return false;
                }
            }
        }
        return cnt1>cnt2;
    }
    
    
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        while(curr!=nullptr){
            Node*temp = curr->next;
            Node*temp2 = curr;
            curr->next = prev;
            prev = temp2;
            curr = temp;
        }
        return prev;
    }
    
    void print(Node * head){
        while(head!=nullptr){
            cout<<head->data<<" ";
            head = head->next;
        }cout<<endl;
    }
    
    Node* subtract(Node* head1 , Node* head2){
        Node* bigger = reverse(head1);
        Node* smaller = reverse(head2);
        Node* curr = new Node(0);
        Node* result  = curr;
        while(smaller!=nullptr){
             
        }
        Node* ans = reverse(result->next);
        return ans;
    }    
    
    
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // So , what are steps that i have to make . 
        // Firstly , I have to know head1 , head2 , which is bigger. 
        // subtract bigger - smaller.
        while(head1!=nullptr && head1->data==0){
            head1 = head1->next;
        }
        while(head2!=nullptr && head2->data==0){
            head2 = head2->next;
        }
        
        bool check = firstbigger(head1 , head2);
        
        // head1 is greater than head2 , so this function returns 1 if our 
        // observation , is true. else return 0;
        if(check){
            Node*ans = subtract(head1 , head2);
            return ans;
        }else{
            Node* ans = subtract(head2 , head1 );
            return ans;
        }
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends