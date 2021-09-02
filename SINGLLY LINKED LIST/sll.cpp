#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node()
    {data=0;
    }
};
class Single_LinkedList
{
public:
        node*head;
        node*tail;
        node*temp;
        Single_LinkedList()
        {   head=NULL;
            tail=NULL;
            temp=NULL;
        }
bool Is_Empty(node*head)
{
    if(head==NULL)
    { return  true;
    }
    else{
        return false;}
}
void Insert_head()
{
    int info;
    node*temp=new node;
    cout<<"Enter the data: ";
    cin>>info;
    cout<<endl;
    temp->data=info;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {temp->next=head;
    head=temp;}
}
void Insert_tail()
{
    int info;
    node*temp=new node;
    cout<<"Enter the data: ";
    cout<<endl;
    cin>>info;
    temp->data=info;
    temp->next=NULL;
    if(tail==NULL)
    {
        head=temp;
        tail=temp;
    }
        tail->next=temp;
    	tail=temp;
}
void Remove_head()
{
    if(Is_Empty(head))
    {
        cout<<"List is Already Empty "<<endl;
    }
    node*temp=new node;
    temp=head;
    head=head->next;
    delete temp;
}
void Display()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void Remove_tail()
{
    if(Is_Empty(head))
    {
        cout<<"List is Already Empty"<<endl;
    }
    node*temp=new node;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    tail=temp;
    delete temp->next;
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
}
void Delete_node( int pos)
{
    if(Is_Empty(head))
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
    delete temp1;
}};
int main()
{
    Single_LinkedList obj;
    int a;
    char ans;
do
{
		cout<<"MENU"<<endl;
		cout<<"1. Add a node to head"<<endl;
		cout<<"2. Add a node to tail"<<endl;
		cout<<"3. Delete a node from head"<<endl;
		cout<<"4. Delete a node from tail"<<endl;
		cout<<"5. Check if element is present or not"<<endl;
		cout<<"6. Insert a Node"<<endl;
		cout<<"7. Delete a node"<<endl;
		cout<<"ENTER CHOICE :";
		cin>>a;
		switch(a)
		{
		  case 1: { obj.Insert_head();
		            obj.Display();
		        	break;
		          }
		  case 2: {
                    obj.Insert_tail();
                    obj.Display();
		        	break;
		          }
            case 3: { obj.Remove_head();
                        obj.Display();
                        break;
		          }
	      case 4:  {  obj.Remove_tail();
                     obj.Display();
                     break;
		           }
          case 5:  {  if(obj.Check())
                      {
                        cout<<"The Number Entered Is Present"<<endl;
                      }
                     else
                      {
                        cout<<"The Number Entered Is Not Present"<<endl;
                      }
                     obj.Display();
                     break;
                  }
          case 6:
                    {
                         int value,pos;
                          cout<<"enter the Element to be inserted:  ";
                          cin>>value;
                          cout<<endl;
                          cout<<"Enter the Position where the Element must be Inserted:  ";
                           cin>>pos;
                           cout<<endl;
                           if(pos==1)
                           {
                               obj.Insert_head();
                           }
                           obj.Insert_node(value,pos);
                           obj.Display();
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
                            obj.Remove_head();
                        }
                        obj.Delete_node(pos);
                        obj.Display();
                         break;
                    }
		  default: {cout<<"INVALID CHOICE!"<<endl;
		            break;}

        }   cout<<endl;
			cout<<"WOULD YOU LIKE TO CONTINUE?(Y/N)"<<endl;
			cin>>ans;
} while(ans!='n');
}




