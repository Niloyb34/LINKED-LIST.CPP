#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;///next akta node typer pointer ja kina arekta node ke point kore
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ////creating a destructor
    ~Node()
    {
        int value=this->data;
        /////////////////////////////////////////   MEMORY FREE  ////////////////////////////////
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
///////////////////////////////////////////////////   INSERT AT HEAD /////////////////////////////////////
void insertAThead(Node* &head,int h)
{
    Node *temp=new Node(h);///mane temp name arekta pointer make korlam ja node ke point korbe aikane nton je value ta patabo take new akta node e dukabo tie new Node(h) use korlam
    /*AKON nton je temp ta add korlam ta jehoto head e add hbe tie nton temp er next hbe ager head ta*/
    temp->next=head;
    head=temp;///mane new head ta hbe newly added temp ta
}
void deleteNode(int position,Node* &head,Node* &tail)///aikane linked list er start teke end prjnto jekono node e delete korte pari
{
    ///deleting first node or start node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;///mane new head ta hbe ager head er porer node ta ja head->next teke pabo

        ////erpor amra memory take free kore dibo mane start node take memory teke free kore dibo

        //memory take amra heap e allocate korcilam tie destructor dara amaderke oi memory take free kore dite hbe
        temp->next=NULL;
        delete temp;
    }
    else
    {
        ///deleting any middle node or last node
        Node* curr =head;///mane current pointer ta initially head ke point kore tie Node* curr=head
        Node* prev=NULL;//naturally initial current ta head hole er age tou kicu thakbe na tie *prev ba previous pointer ta NULL ke point korbe
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
       if(prev->next==NULL)
        {
            tail=prev;
        }
    }
}
void print(Node*&head)///mane head akta node typer pointer
{
    ///akon akta temp namok node typer pointer banie  take traverse krabo and tathe first node er pointer ke reke dilam
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int i,n,p,v,d;
    Node* node1=new Node(22);///mane new create kora  node take point korbe node 1 and new node er data aikaner teke 10 pass kori disi
    Node *head=node1;///mane node 1 take head namok pointer point kore jekhane head ta node typer ba node jatiyo jinish ke point kore
    Node *tail=node1;
    ////mane node 1 take head and tail duitie point kore
    cout<<"Initially linked list is:";
    print(head);
    cout<<"Enter how many numbers you want to add at head= ";
    cin>>n;
    cout<<"Insert the numbers:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>p;
        insertAThead(head,p);
    }
    cout<<"Now the new link list is : "<<endl;
    print(head);
    cout<<"Which element you want to delete: ?";
    cin>>d;
    deleteNode(d,head,tail);///d number position er element ke delete  korbo
    print(head);
    cout<<"Head is :"<<head->data<<endl;
    cout<<"Tail data :"<<tail->data<<endl;
}


