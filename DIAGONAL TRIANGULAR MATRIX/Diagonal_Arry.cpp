#include <iostream>
using namespace std;

class Diagonal
{
	int* D;
	int size;
	public:
		Diagonal(int n=10)
		{
			size=n;
			if(size>=0)
				D = new int[size];
			else
				D = 0;
		}
		void store(int row,int col,int data)
		{
			if(row>=0 && row<size && col>=0 && col<size && row==col)
				D[row] = data;
			else
				exit(0);
		}
		int value(int row,int col)
		{
			if(row>=0 && row<size && col>=0 && col<size){
				if(row==col)
					return D[row];
				else
					return 0;
			}
			else{
				cout<<"Wrong Input";
				exit(0);
			}
		}
		void show()
		{
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++)
				{
					if(i==j)
						cout<<D[i]<<" ";
					else
						cout<<"0 ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	int ele,row,col;
	cout<<"Enter the number of numbers of rows and columns: ";
	cin>>row>>col;
	cout<<endl;
	if(row!=col)
    {
        cout<<"invalid"<<endl;
    }
	Diagonal dm = Diagonal(row);
	cout<<"enter the diagonal elements"<<endl;
	for(int i=0,j=0;i<5;i++,j++)
	{
		cin>>ele;
		dm.store(i,j,ele);
	}
	dm.show();
}
