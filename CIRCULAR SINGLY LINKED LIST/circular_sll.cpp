#include<iostream>
using namespace std;
class node
{
public:
    node*next;
    int data;
    node()
    {
        data=0;
    }
};
class csll
{
public:
    node*temp;
    node*head;
    node*tail;
    csll()
    {
       head=NULL;
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
void Insert_head(int element )
{
    node*temp=new node;
    temp->data=element;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp->next=head;
    }
    else{
        temp->next=head;
        head=temp;
        tail->next=head;


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
        tail->next=head;
    }
    tail->next=temp;
    tail=temp;
    temp->next=head;


}
void Delete_head()
{
    node*temp;
    if(Is_Empty(head))
    {
        cout<<"The List is Empty"<<endl;
    }
    else{
        temp=head;
        head=head->next;
        delete temp;
        tail->next=head;

    }
}
void Delete_tail()
{
    node*temp;
    if(Is_Empty(head))
    {
        cout<<"The List is Empty"<<endl;
    }
    else{
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        tail=temp;
        temp=temp->next;
        delete temp;
        tail->next=head;

    }

}
bool Check()
{
    int val;
    node*temp=head;
    cout<<"Enter the element to be checked : ";
    cin>>val;
    cout<<endl;
    while(temp!=tail)
    {
        if(temp->data==val)
        {
            return true;
        }
        temp=temp->next;
    }
    if(tail->data==val)
    {
        return true;
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
void Reverse()
{
    node*temp1=head;
    node*temp2=NULL;
    node*temp3=NULL;
    while(temp1!=tail)
    {
        temp3=temp2;
        temp2=temp1;
        temp1=temp1->next;
        temp2->next=temp3;
    }
    temp1->next=temp2;
    temp2=temp1;
    tail=head;
    head=temp2;
    tail->next=head;
}
void Display()
{
     node*temp=new node;
    if(Is_Empty(head))
    {
        cout<<"The List is Empty"<<endl;
    }
    else{
        temp=head;
        while(temp!=tail)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->";
    }
}
~ csll()
{
    node*p=new node;
    while(head!=tail)
    {
        p=head->next;
        delete head;
        head=p;
    }
    delete tail;
}
};
int main()
{
    csll obj;
    int a;
    char ans;
do
{
		cout<<"MENU-CIRCULAR SINGLE LINKED LIST"<<endl;
		cout<<"1. Add a node to head"<<endl;
		cout<<"2. Add a node to tail"<<endl;
		cout<<"3. Delete a node from head"<<endl;
		cout<<"4. Delete a node from tail"<<endl;
		cout<<"5. Check if element is present or not"<<endl;
		cout<<"6. Insert a Node"<<endl;
		cout<<"7. Delete a node"<<endl;
		cout<<"8. Reverese the circular linked list"<<endl;
		cout<<"9. Display"<<endl;
		cout<<"ENTER CHOICE :";
		cin>>a;
		switch(a)
		{
		  case 1: {
                    int element;
                    cout<<"Enter data: ";
                    cin>>element;
                    cout<<endl;
                    obj.Insert_head(element);
		            obj.Display();
		        	break;
		          }
		  case 2: {
		      int element;
                    cout<<"Enter data: ";
                    cin>>element;
                    cout<<endl;
                    obj.Insert_tail(element);
                    obj.Display();
		        	break;
		          }
            case 3: { obj.Delete_head();
                        obj.Display();
                        break;
		          }
	      case 4:  {  obj.Delete_tail();
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
                            obj.Delete_head();
                        }
                        obj.Delete_node(pos);
                        obj.Display();
                         break;
                    }
            case 8:
                    {
                        obj.Reverse();
                        obj.Display();
                        break;
                    }
            case 9:{
                        obj.Display();
                        }

		  default: {cout<<"INVALID CHOICE!"<<endl;
		            break;}

        }   cout<<endl;
			cout<<"WOULD YOU LIKE TO CONTINUE?(Y/N)"<<endl;
			cin>>ans;
} while(ans!='n');
}


