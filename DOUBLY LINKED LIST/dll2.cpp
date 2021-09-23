#include<iostream>
using namespace std;
class node{
    public:
    node*next;
    node*prev;
    int data;
    node(){
    data=0;
    next=NULL;
    prev=NULL;
   }
};
class DLL{
    public:
    node*head;
    node*tail;
    node*temp;
    DLL()
    {
        head=NULL;
        tail=NULL;
        temp=NULL;
    }
bool IsEmpty()
{
    if (head==NULL)
    {
        return true;
    }
    else{
        return false;
    }
}
void Insert_head(int element)
{
    node*temp=new node;
    temp->data=element;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {   head->prev=temp;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
}
void Delete_head()
{
    if(IsEmpty())
    {
        cout<<"The List is already empty"<<endl;
    }
    else{
    node*temp=new node();
   temp=head;
   head=head->next;
   delete temp;
   }

}
void Insert_tail(int element)
{
    node*temp=new node;
    temp->data=element;
    if(tail==NULL)
    {
        head=temp;
        tail=temp;
    }
    tail->next=temp;
    temp->next=NULL;
    temp->prev=tail;
    tail=temp;
}
void Delete_tail()
{
     if(IsEmpty())
    {
        cout<<"The List is already empty"<<endl;
    }
    else{
     node*temp=new node;

        temp=tail;
     tail=tail->prev;
     delete temp;
      tail->next=NULL;

    }
}
void Insert_node(int value, int pos)
{
    int counter=1;
    node*temp=new node;
    node*new_node=new node;
     node*temp1=new node;
    temp=head;
    new_node->data=value;
    new_node->next=NULL;
    while((counter+1)!=pos)
    {
        temp=temp->next;
        counter++;
    }
    temp1=temp->next;
    temp->next=new_node;
    new_node->next=temp1;
    new_node->prev=temp;
    new_node=temp1->prev;

}
void Delete_node( int pos)
{
    if(IsEmpty())
    {
        cout<<"List is Already Empty"<<endl;
    }
    int counter=1;
    node*temp=new node;
    temp=head;
    node*temp1=new node;
    while((counter+1)!=pos)
    {
        temp=temp->next;
        counter++;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;

    delete temp1;
}
bool Check()
{
    int val;
    node*temp=head;
    cout<<"Enter the element to be checked : ";
    cin>>val;
    cout<<endl;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void concatenate(DLL &obj ,DLL &obj2)
{
    node*temp2=new node;
    temp=obj.head;
    temp2=obj2.head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<temp->data<<" <-> ";
    temp->next=temp2;
    temp2->prev=temp;
    while(temp2->next!=NULL)
    {
        cout<<temp2->data<<" <-> ";
        temp2=temp2->next;
    }
    cout<<temp2->data;
    cout<<endl;
    tail=temp2;
}


void display()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<endl;
}
~DLL()
{   node*p=new node;
  while(head!=NULL)
    {
       p=head->next;
       delete head;
       p->prev=NULL;
       head=p;
    }
}
};
int main()
{
    DLL obj,obj2;
    int ans,element;
    char a;

    do
    {
        cout<<"MENU-DOUBLY LINKED LIST"<<endl;
        cout<<"1. Add a node at the head "<<endl;
        cout<<"2. Delete a node from head"<<endl;
        cout<<"3. Add a node at tail "<<endl;
        cout<<"4. Delete a node from tail "<<endl;
        cout<<"5. Check if the element is present or not"<<endl;
        cout<<"6. Insert a node in between the list"<<endl;
		cout<<"7. Delete a node in between the lst"<<endl;
		cout<<"8 .Concatenate another string to The List"<<endl;
		cout<<"9. Display the List"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ans;
        switch(ans)
        {
        case 1:
            {
                cout<<"Enter the element to be added at head : "<<endl;
                cin>>element;
                cout<<endl;
                obj.Insert_head(element);
                obj.display();
                break;
            }
        case 2:
            {
                obj.Delete_head();
                obj.display();
                break;
            }
        case 3:
            {
                cout<<"Enter the element to be added at tail : "<<endl;
                cin>>element;
                cout<<endl;
                obj.Insert_tail(element);
                obj.display();
                break;

            }
        case 4:
            {
                obj.Delete_tail();
                obj.display();
                break;
            }
        case 5:
            {
                if(obj.Check())
                      {
                        cout<<"The Number Entered Is Present"<<endl;
                      }
                     else
                      {
                        cout<<"The Number Entered Is Not Present"<<endl;
                      }
                     obj.display();
                     break;
            }
             case 6:
                    {
                         int element,pos;
                          cout<<"enter the Element to be inserted:  ";
                          cin>>element;
                          cout<<endl;
                          cout<<"Enter the Position where the Element must be Inserted:  ";
                           cin>>pos;
                           cout<<endl;
                           if(pos==1)
                           {
                               obj.Insert_head(element);
                           }
                           obj.Insert_node(element,pos);
                           obj.display();
                           break;
                    }
          case 7:
                    {
                        int pos;
                        cout<<"Enter The Position where node is to be deleted: ";
                        cin>>pos;
                        cout<<endl;
                        if(pos==1)
                        {
                            obj.Delete_head();
                        }
                        obj.Delete_node(pos);
                        obj.display();
                         break;
                    }
            case 8:
            {
                int num;
                cout<<"Enter the second list linked list(Press -1 to stop)"<<endl;
                cin>>num;
                while(num!=-1)
                {
                    obj2.Insert_tail(num);
                    cin>>num;
                }
                obj.concatenate(obj ,obj2);
                break;
            }
          case 9:
            {
                    cout<<"The List contains : ";
                    obj.display();
                    break;
            }
        default:
        {
                cout<<"Wrong choice"<<endl;
                break;
        }

        }
        cout<<"Would you like to continue?(Press 'n' to stop) ";
        cin>>a;



    }while(a!='n');
    return 0;
}


