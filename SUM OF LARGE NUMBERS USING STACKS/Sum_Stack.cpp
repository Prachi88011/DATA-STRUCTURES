#include<iostream>
using namespace std;
class Stack
{
    int top;
    int arr[15];
public:
    Stack(){
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
   top++;
   arr[top]=element;
}
int pop()
{
    int item;
    if(IsEmpty())
    {
        cout<<"The Stack is Empty "<<endl;

    }
    else{
        item=arr[top];
        top--;
        }
    return item;

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
        cout<<arr[i];
    }
    cout<<endl;
    }
}

};
int main()
{
    Stack s1,s2,s3,result;
    int num1, num2,q1,q2,n1,n2,sum=0,carry=0,rem=0,first, second;
    cout<<"Enter the first number and number of digits in it : ";
    cin>>first >>n1;
    cout<<endl;
    cout<<"Enter the second number and number of digits in it: ";
    cin>>second>>n2;
    cout<<endl;
    num1=first;
    num2=second;
        int x=1;
        while(n1!=1)
        {
            x=10*x;
            --n1;
        }
        while(x!=0)
        {
         q1=num1/x;
         num1=num1%x;
         x=x/10;
         s1.push(q1);
        }
        int y=1;
        while(n2!=1)
        {
            y=10*y;
            --n2;
        }
        while(y!=0)
        {
         q2=num2/y;
         num2=num2%y;
         y=y/10;
         s2.push(q2);
        }

        if(s1.IsEmpty()!=true&& s2.IsEmpty()!=true)

        {
            while(s1.IsEmpty()!=true&& s2.IsEmpty()!=true)
            {
                sum=s1.pop()+s2.pop()+carry;
                rem=sum%10;
                s3.push(rem);
                carry=sum/10;

            }
           if(s1.IsEmpty()==true&& s2.IsEmpty()==true)
            {

            if(carry!=0)
            {
                s3.push(carry);
            }
            }
        }

        if(s1.IsEmpty()!=true)
        {
            while(s1.IsEmpty()!=true)
            {  sum=0;
               sum=carry+s1.pop() ;
               rem=sum%10;
               s3.push(rem);
               carry=sum/10;

            }
             if(carry!=0)
            {
                s3.push(carry);
            }

        }
        if(s2.IsEmpty()!=true)
        {
            while(s2.IsEmpty()!=true)
            {
               sum=carry+s2.pop() ;
               rem=sum%10;
               s3.push(rem);
               carry=sum/10;

            }
             if(carry!=0)
            {
                s3.push(carry);
            }

        }
        cout<<"The Sum Of Two Large number   "<<first<<" and "<<second<<" using stacks is: ";
        s3.display();

}
