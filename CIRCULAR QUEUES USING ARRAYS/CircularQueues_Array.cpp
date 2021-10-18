#include<iostream>
using namespace std;
class CircularQueue{
public:
    int front;
    int rear;
    int size;
    int queue[];
    CircularQueue(int n)
    {
        front=rear=-1;
        size=n;

    }
    bool IsFull();
    bool IsEmpty();
    void enqueue(int);
    void dequeue();
    void Display();
    void first();
};
bool CircularQueue :: IsFull()
{
    if(front==0&&rear==size-1||front==rear+1)
    {
        return true;
    }
    else{
        return false;
    }
}
bool CircularQueue :: IsEmpty()
{
    if(front==-1)
    {
        return true;
    }
    else{
        return false;
    }
}
void CircularQueue :: enqueue(int ele)
{

        if(IsEmpty()){
            front=rear=0;
            queue[front]=ele;
        }
        else if(rear==size-1){
            rear=0;
            queue[0]=ele;

        }
        else{
            queue[++rear]=ele;

        }


}
void CircularQueue :: dequeue()
{
    int num;
    num=queue[front];
    if(IsEmpty())
    {
        cout<<"The Queue is Already Empty"<<endl;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else if(front==size-1)
    {
        front=0;
    }
    else{
        front++;
    }
    cout<<num<<"is deleted from the queue"<<endl;

}
void CircularQueue :: first()
{
    int num=queue[front];
    cout<<"The First element is "<<num<<endl;
}
void CircularQueue :: Display()
{
    int i=front;

    if(IsEmpty())
    {
        cout<<"The Queue is already empty"<<endl;
    }
    cout<<"The Queue is"<<"\t";
    while(i!=rear)
    {
        cout<<queue[i]<<"\t";
        i=(i+1)%size;
    }
    cout<<queue[rear];


}
int main()
{

    char a;
    int element,n;
    int ans;
    cout<<"Enter the size of queue : ";
    cin>>n;
    CircularQueue obj(n);
    do
    {
        cout<<"*****CIRCULAR QUEUE USING ARRAYS*****"<<endl;
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
                if(obj.IsFull())
               {
                     cout<<"The queue is already full"<<endl;
               }
               else{
                cout<<"Enter the element to be added: ";
                cin>>element;
                cout<<endl;
                obj.enqueue(element);

                }
                break;
              }
        case 2:
            {
                obj.dequeue();

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


