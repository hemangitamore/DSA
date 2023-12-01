#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor

    ~Node(){
        int val=this->data;
        //memory free

        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }

        cout<<"memory free of node for data ";

    }
};

void insertAtHead(Node*&head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node*&tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;

}

void insertAtPosition(int position,Node*&head,Node*&tail,int d){
    //insert at 1st position
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    
    Node*temp=head;

    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;

        
    }
    
    int cnt=1;
    while(cnt<position-1){
       temp=temp->next;
       cnt++;
    }
    Node*nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}



void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


void deletNode(int position,Node*&head){
    //deleting first node
    if(position==1){
        Node*temp=head;
        head=head->next;

        //memory free start Node

        temp->next=NULL;
        delete temp;
    }
    else{
        //delete node at the middle position or last node
        Node*curr=head;
        Node*prev=head;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;

        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;


    }

    
}
int main(){
    Node*node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
    
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    
    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtPosition(1,head,tail,22);
    print(head);

    cout<<"print tail "<< tail->data<<endl;
    cout<<"print head "<< head->data<<endl;

    deletNode(2,head);
    print(head);

    
    return 0;

}
