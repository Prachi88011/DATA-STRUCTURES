#include <iostream>
using namespace std;
class Upper_Trianglr
{
	int* D;
	int size;
	public:
		Upper_Trianglr(int n=10)
		{
			size=n;
			if(size>=0)
				D = new int[size*((size+1)/2)];
			else
				D = 0;
		}
		~Upper_Trianglr()
		{
			delete [] D;
		}
		void store(int row,int col,int data)
		{
			if(row>=0 && row<size && col>=0 && col<size && row<=col)
			{
				int pos=((col * (col - 1)) / 2) + row - 1;
				D[pos] = data;
			}
		}
		int value(int row,int col)
		{
			row=row-1;
			col=col-1;
			if(row>=0 && row<size && col>=0 && col<size){
				if(row<=col){
					int pos=((col * (col - 1)) / 2) + row - 1;
					return D[pos];
				}
				else
					return 0;
			}
			else{
				cout<<"Wrong Input";
			}
		}
		void show()
		{
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++)
				{
					if(i<=j)
					{
						int pos=((j * (j - 1)) / 2) + i - 1;
						cout<<D[pos]<<" ";

					}else
						cout<<"0 ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	int ele;
	Upper_Trianglr obj = Upper_Trianglr(5);

	for (int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			ele=i+j+2;
			obj.store(i,j,ele);
		}
	}
	obj.show();
	cout<<endl<<"Printing element at index[2,1] : "<<obj.value(2,1);
	cout<<endl<<"Printing element at index[2,2] : "<<obj.value(2,2);
	cout<<endl<<"Printing element at index[2,3] : "<<obj.value(2,3);
	cout<<endl<<"Printing element at index[2,4] : "<<obj.value(2,4);
	cout<<endl<<"Printing element at index[2,5] : "<<obj.value(2,5);
}
