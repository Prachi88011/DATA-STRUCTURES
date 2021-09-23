#include<iostream>
using namespace std;

class node
{
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
void Insert_head(int element)
{

    node*temp=new node;

    temp->data=element;
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
void Insert_tail(int element)
{

    node*temp=new node;
    temp->data=element;
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
    node*temp=new node;
    temp=head;
    while(temp!= NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
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
}
void concatenate(Single_LinkedList &obj ,Single_LinkedList &obj2)
{
    node*temp2=new node;
    temp=obj.head;
    temp2=obj2.head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data<<" -> ";
    temp->next=temp2;
    while(temp2->next!=NULL)
    {
        cout<<temp2->data<<" -> ";
        temp2=temp2->next;
    }
    cout<<temp2->data;
    cout<<endl;
    tail=temp2;
}
void Reverse()
{
    node*temp1=head;
    node*temp2=NULL;
    node*temp3=NULL;
    while(temp1!=NULL)
    {
        temp3=temp2;
        temp2=temp1;
        temp1=temp1->next;
        temp2->next=temp3;
    }
    tail=head;
    head=temp2;
}

~ Single_LinkedList()
{
    node*p=new node;
    while(head!=NULL)
    {
        p=head->next;
        delete head;
        head=p;
    }

}
};
int main()
{
    Single_LinkedList obj,obj2;
    int a,info;
    char ans;
do
{
		cout<<"MENU-SINGLY LINKED LIST"<<endl;
		cout<<"1. Add a node to head"<<endl;
		cout<<"2. Add a node to tail"<<endl;
		cout<<"3. Delete a node from head"<<endl;
		cout<<"4. Delete a node from tail"<<endl;
		cout<<"5. Linear Search"<<endl;
		cout<<"6. Insert a Node"<<endl;
		cout<<"7. Delete a node"<<endl;
		cout<<"8. Concatenate single linked list"<<endl;
		cout<<"9. Reverse the linked list"<<endl;
		cout<<"ENTER CHOICE :";
		cin>>a;
		switch(a)
		{
		  case 1: {
                    cout<<"Enter the data: ";
                    cin>>info;
                    obj.Insert_head(info);
		            obj.Display();
		        	break;
		          }
		  case 2: {

                    cout<<"Enter the data: ";
                    cin>>info;
                    obj.Insert_tail(info);
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
                               obj.Insert_head(value);
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
                        obj.Reverse();
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




