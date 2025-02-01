#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

};
Node* convertarr2ll(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
    
}
int lengthLL(Node* head){
    int c=0;
    Node* temp=head;
    while(temp){
        c++;
        temp=temp->next;
    }
    return c;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* deletehead(Node* head) {
    if (head == NULL) { // Check if the head is NULL initially
        return NULL;
    }

    Node* temp = head; // Store the current head
    head = head->next; // Move head to the next node
    delete temp; // Delete the old head
    return head; // Return the new head
}
Node* deleteTail(Node* head){
    if (head==NULL||head->next==NULL){return NULL;}
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
void deleteKth(Node* &head,int k){
    if (head==NULL)
    {
       return;
    }
    if (k==1)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    int cnt=0;Node* temp=head;
    Node* prev=NULL;
    while (temp!=NULL)
    {
       cnt++;
       if(cnt==k){ 
        prev->next=prev->next->next;
        free(temp);
        return;
       }
       prev=temp;
       temp=temp->next;
    }
 
    
}
void insertatHead(Node* &head,Node* &tail,int data){
   if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
   }
    Node* newNode=new Node(data);

    newNode->next=head;

    head=newNode;
     
}
void insertatTail(Node* &head,Node* &tail,int data){ 
    if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
   }

    Node* newNode=new Node(data);
    tail->next=newNode; 
    tail=newNode;     
}
void insertatPosition(Node* &head,int pos,int data){
    if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    return;
   }
   if (pos==0)
   {
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
    return;
   }
   
   int cnt=0;
   Node* temp=head;
   Node* prev=NULL;
   while(temp!=NULL){
    if(cnt==pos){
    Node* newNode=new Node(data); 
    prev->next=newNode;
    newNode->next=temp;
    return;
    }
    prev=temp;
    temp=temp->next;
    cnt++;
   }
   
   if(cnt==pos){
    Node* newNode=new Node(data);
    prev->next=newNode;
    newNode->next=temp;
    return;
   }

}
Node* reverseList(Node* head) {
        if(head==NULL){
            return head;
        }

        Node* temp=head;
        
        Node* previ=NULL;
        while(temp!=NULL){
            ListNode* x=temp->next;
            temp->next=previ;
            previ=temp;
            temp=x;
        }
        return previ;
}

DOUBLEY LINKEDLIST
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    
};

void print(Node* &head){
    Node* temp=head;

    while (temp!=NULL)
    {
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    
}
int getlenth(Node* &head){
    Node* temp=head;
    int c=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        c++;
    }

    return c;
    
}

void insertatk(Node* &head,int data,int k){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        return;
    }
    if(k==0){
        Node* newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    int cnt=1;
    Node* temp=head;
    Node* previ=NULL;
    while (temp!=NULL)
    {
        if (cnt==k)
        {
           Node* newNode=new Node(data);
           previ->next=newNode;
           newNode->prev=previ;
           newNode->next=temp;
           temp->prev=newNode;
           return;
        }
        previ=temp;
        temp=temp->next;
        cnt++;
        
    }
    if(cnt==k){
           Node* newNode=new Node(data);
           previ->next=newNode;
           newNode->prev=previ;
           return;
    }

}

void deleteatk(Node* &head,int k){
    if(head==NULL){
        return;
    }
    if(k==1){
     Node* temp=head;
     head=head->next;
     delete temp;
     return;
    }
    int cnt=1;
    Node* temp=head;
    Node* previ=NULL;
    while (temp!=NULL)
    {
        if (cnt==k)
        {
            
            previ->next=previ->next->next;
            previ->next->prev=previ;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
            return;
        }
        previ=temp;
        temp=temp->next;
        cnt++;
        
    }
    if (cnt==k)
    {
        Node* temp=previ;
        previ=previ->prev;
        temp->prev=NULL;
        previ->next=NULL;
        delete temp;
        return;
    }
    
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    // Node* y = Node(arr[0]);
    // cout << "Node data: " << y->data << endl;
    // cout << "Node address: " << &y << endl;
    Node* head=convertarr2ll(arr);
    cout<<head->data;
    cout<<endl;
   print(head);
    cout<<lengthLL(head)<<endl;
   head=deletehead(head);
   print(head);
   head=deleteTail(head);
   print(head);
   head=deleteKth(head,2);

   Node* head=NULL; 
   Node* tail=NULL; 
   insertatTail(head,tail,20);
   insertatTail(head,tail,30);
   insertatTail(head,tail,40);
   insertatTail(head,tail,50);
   insertatTail(head,tail,60);
   insertatPosition(head,0,90);
   deleteKth(head,1);
   print(head); 

DOUBLEY LINKEDLIST
Node* first=new Node(10);
Node* first1=new Node(20);
Node* first2=new Node(30);
Node* first3=new Node(40);
//first->prev=NULL;
first->next=first1;
first1->prev=first;
first1->next=first2;
first2->prev=first1;
first2->next=first3;
first3->prev=first2;
//first3->next=NULL;

insertatk(first,33,5);

deleteatk(first,4);
print(first);

CIRCULAR LINKEDIST
CIRCULAR DOUBLEY LINKEDLIST


Reverse LINKEDLIST



}
