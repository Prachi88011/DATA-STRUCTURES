#include<iostream>
using namespace std;
class node{
public:
    node*next;
    int data;
    node()
    {
       data=0;
    }
};
class Stack_sll{
public:
    node*temp;
    node*top;
    Stack_sll()
    {
        top=NULL;

    }
bool IsEmpty()
{
    if(top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void push(int element)
{

   node*temp=new node;
   temp->data=element;
   temp->next=top;
   top=temp;

}
void pop()
{
    if(IsEmpty())
    {
        cout<<"The List is already empty"<<endl;
    }
    else{
    node*temp=new node;
    temp=top;
    top=top->next;
    cout<<temp->data<<" has been deleted"<<endl;
    delete(temp);
    }
}
void top_Element()
{
    if(IsEmpty())
    {
        cout<<"The List is already empty"<<endl;
    }
    else{
        cout<<"The top element is { "<<top->data<<" }";
    }
}
void Size()
{
    int count=0;
    temp=top;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"The size of the stack is "<<count<<endl;

}
void Clear()
{
    temp=top;
    while(top!=NULL)
    {
        pop();
        temp=temp->next;
    }
}
void Display()
{
    temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

};
int main()
{
    Stack_sll obj;
    int ans,element;
    char a;

    do
    {
        cout<<"MENU-STACK USING LINKED LIST"<<endl;
        cout<<"1.Push an element "<<endl;
        cout<<"2.Pop an element"<<endl;
        cout<<"3.Find Top element "<<endl;
        cout<<"4.Check the Size of stack "<<endl;
        cout<<"5.Clear the stack"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ans;
        switch(ans)
        {
        case 1:
            {
                cout<<"Enter the element to be pushed :";
                cin>>element;
                cout<<endl;
                obj.push(element);
                obj.Display();
                break;
            }
        case 2:
            {
                obj.pop();
                obj.Display();
                break;
            }
        case 3:
            {
                obj.top_Element();
                break;

            }
        case 4:
            {
                obj.Size();
                break;
            }
        case 5:
            {
                obj.Clear();
                cout<<"The stack is cleared"<<endl;
                break;
            }
        case 6:
            {
                obj.Display();
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


