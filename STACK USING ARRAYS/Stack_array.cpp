#include<iostream>
using namespace std;

class Stack_Array
{
        int Stack[10];
        int top;
        public:
        Stack_Array()
        {
            top=-1;
        }
bool IsEmpty()
{
    if(top==-1)
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
    if(top==9)
    {
        cout<<"The stack is already full"<<endl;
    }
    else{
   top++;
   Stack[top]=element;
    }
}
void pop()
{
    if(IsEmpty())
    {
        cout<<"The Stack is already empty"<<endl;
    }
    else
    {
        int item;
        item= Stack[top];
        top--;
        cout<<"The element { "<< item << " }has been poped"<<endl;
    }
}
void display()
{
    if(IsEmpty())
    {
        cout<<"The stack is empty"<<endl;
    }
    else{
    int i;
    for( i=top;i>=0;i--)
    {
        cout<<Stack[i]<<"\t";
    }
    cout<<endl;
    }
}

void top_Element()
{
    if(IsEmpty())
       {
           cout<<"The stack is  empty "<<endl;
       }
       else{
        cout<<"The top element is: "<< Stack[top]<<endl;
       }
}
void Size()
{
    int count=0;
    for(int i=0;i<=top;i++)
    {
        count++;
    }
    cout<<"The Size of stack is "<<count<<endl;
}
void Clear()
{
    while(top!=-1)
    {
        pop();
        top--;
    }
}
};
int main()
{
    Stack_Array obj;
    int ans,element;
    char a;

    do
    {
        cout<<"MENU"<<endl;
        cout<<"1.Push an element "<<endl;
        cout<<"2.Pop an element"<<endl;
        cout<<"3.Find Top element "<<endl;
        cout<<"4.Check the Size of stack "<<endl;
        cout<<"5.Clear the stack"<<endl;
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
                obj.display();
                break;
            }
        case 2:
            {
                obj.pop();
                obj.display();
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
            }
        case 5:
            {
                obj.Clear();
                cout<<"The stack is cleared"<<endl;
                break;
            }
        default:
        {
                cout<<"Wrong choice"<<endl;
                break;
        }

        }
        cout<<"WOULD YOU LIKE TO CONTINUE?(Press 'n' to stop) ";
        cin>>a;



    }while(a!='n');
    return 0;
}






