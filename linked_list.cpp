#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node* link;
};

node* head=NULL;

node* pre;
node* next;

node* temp;


void addnode(int value)
{
    
    temp=(node*)(malloc(sizeof(node)));
    temp->data=value;
    temp->link=NULL;
    
    if(head==NULL)
    {
        head=temp;
        
    }
    else
    {
        pre=head;
        while(pre->link!=NULL)
        pre=pre->link;
        pre->link=temp;
    }
    pre=temp;

}

void display()
{
    temp=head;
    cout<<"\nLINKED LIST VALUE IS ";
    while(temp!=NULL)
    {
        cout<<"\nVALUE IS "<<temp->data;
        temp=temp->link;
    }
}

void insert(int value,int position)
{
    int count=1;
    node* save;

    temp=(node*)(malloc(sizeof(node)));
    temp->data=value;
    pre=head;

    while((count+1)!=position)
    {
        pre=pre->link;
        count++;
    }
    save=pre->link;
    pre->link=temp;
    temp->link=save;

}

void insertFirst(int value)
{
    temp=(node*)(malloc(sizeof(node)));
    temp->data=value;

    temp->link=head;
    head=temp;
}

int main()
{
    int n;
    do
    {
    cout<<"\nDo you want to continue ";
    cin>>n;
    if(n==0)
    break;
    switch(n)
    {
        case 1:
        {
            int value;
            cout<<"\nEnter value ";
            cin>>value;
            addnode(value);
            break;
        }

        case 2:
        {
            display();
            break;
        }

        case 3:
        {
            int value,position;
            cout<<"\nEnter the value and position you want to insert other than 1 ";
            cin>>value>>position;
            if(position!=1)
            insert(value,position);
            else
            insertFirst(value);
            break;
        }

        case 4:
        {
            int value;
            cout<<"\nEnter value to be inserted at first ";
            cin>>value;
            insertFirst(value);
            break;
        }
        default:
        {
            cout<<"\nEnter a valid value ";
        }
    }
    }while(1);
}