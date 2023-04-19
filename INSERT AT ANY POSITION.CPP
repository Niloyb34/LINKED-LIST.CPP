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
};
void insertAThead(Node* &head,int d)
{
    Node* temp=new Node(d);///mane head e je nton data ta add korbo tar jnno tou new node lagbe tie create korlam new Node(d) aikane new node take temp point kore
    temp->next=head;
    ///newly added temp ta ager head ke point korbe ba newly added temp er next e head thakbe
    head=temp;///new head hbe newly added temp ta
}
//////////////////////////////////////////////////   INSERT AT TAIL  ////////////////////////////////////////
void insertATtail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;///mane seshe  e add kora temp er address kintu ager tail e thakbe
    tail=temp;///mane nton tail hbe temp ta ba tail take update korlam
}
void insertATposition(Node*&tail,Node* &head,int position,int value)
{
   if(position==1)///mane starting position e amra add korbo tie position ==1 mane jeta asole head e add korar sman
    {
        insertAThead(head,value);///mane amra head e value take patabo
        return;///mane 1 no e dukar por ba jdi 1 no position e add kori tahole erpor return kore dibo insertATposition e
    }
    Node* temp=head;///mane temp namok pointer ta head ke point kore
    int cnt=1;///mane amader pratham node ta starting e bose ase tie cnt initially one
    while(cnt<position-1)///aikane already head consider kora hoice tie
    {
        temp=temp->next;
        cnt++;
    }
    //////////////////////////////////////////////// Tail Updation /////////////////////////////////////////

    //////////////////////////////////////////////////inserting in the last position
    if(temp->next==NULL)///mane temp traverse korte korte last er khali location ta bujabe
    ///muloto linked list er bahirer mane last er pore add korte hole then seta
     {
         insertATtail(tail,value);
         return ;
     }
    ////creating a new node which data in inserted
    Node *nodeToinsert=new Node(value);
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
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
    int i,n,p,v;
    Node* node1=new Node(10);///mane new create kora  node take point korbe node 1 and new node er data aikaner teke 10 pass kori disi
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
    ////////////////////////////       INSERTING AT ANY POSITION     ////////////////////
    cout<<"In which position you want to add and which value you want to add?"<<endl;
    cout<<"Insert the position :"<<endl;
    cin>>p;
    cout<<"Insert the value : "<<endl;
    cin>>v;
    ///p means position and v means value
    insertATposition(tail,head,p,v);///mane holo ami current tail and head ke patalam and 4 tmo position e 22 ke patalam
    print(head);

    cout<<" Head data is:  "<<head->data<<endl;///printing the head value
    cout<<"Tail data is:      "<<tail->data<<endl;///printing the tail value
}

