#include<iostream>
using namespace std;

class LinearQueue
{
public:
    int f;
    int rear;
     int size;
    int queue[];
    LinearQueue(int n)
    {
        f=rear=-1;
        size=n;
    }



bool IsEmpty()
{
    if(rear==-1)
    {
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int item)
{

    if(IsEmpty())
    {   rear++;
        queue[++f]=item;

    }
    else if(rear<size-1)
        {
         queue[++rear]=item;
        }
        else
        {
             cout<<"The Queue is Full"<<endl;
        }


}
void dequeue()
{
   if(IsEmpty())
    {
        cout<<"The Queue is already empty"<<endl;
    }
    else
    {
        cout<<queue[f]<<"is deleted"<<endl;
        f++;

    }

}
void first()
{
    cout<<"The First Element is "<<queue[f]<<endl;
}
void Display()
{
    if(IsEmpty())
    {
        cout<<"The Queue is already empty"<<endl;
    }
    for(int i=f;i<=rear;i++)
    {
        cout<<queue[i]<<"\t";
    }

}

};
int main()
{

    char a;
    int element,n;
    int ans;
    cout<<"Enter the size of queue : ";
    cin>>n;
    LinearQueue obj(n);
    do
    {
        cout<<"LINEAR QUEUE USING ARRAYS"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"Enter your choice: ";
        cin>>ans;
        cout<<endl;
        switch(ans)
        {

        case 1:
              {
                cout<<"Enter the element to be added: ";
                cin>>element;
                cout<<endl;
                obj.enqueue(element);
                obj.Display();
                break;
              }
        case 2:
            {
                obj.dequeue();
                obj.Display();
                break;

            }
        case 3:
            {
                obj.first();
                break;

            }
        case 4:
            {
                obj.Display();
                break;

            }
        default :
            {
                cout<<"Wrong choice"<<endl;
                break;
            }
        }
        cout<<endl;
        cout<<"Would You Like To Continue?(y/n)"<<endl;
        cin>>a;

    }while(a=='y'||a=='Y');
}

