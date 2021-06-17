#include <iostream>

using namespace std;

int bSearch(int arr[],int item, int beg ,int last)
 {
        int mid;
     while (beg <= last)
    {
     int mid = (beg + last) / 2;
     if (item == arr[mid])
     return mid;
     else if (item < arr[mid])

             bSearch(arr,item , beg, mid - 1);
     else if (item > arr[mid])
               bSearch(arr, item, mid + 1, last);
    }



              return -1;

}
int main()
 {
  int n,arr[30],item;
        cout << "Enter Number of Elements in Array: ";
        cin >> n;
        cout << "Enter Elements of Array: ";
        for (int i = 0; i < n; i++)
        cin >> arr[i];
        cout << "Enter Element to Search: ";
        cin >>item ;
        cout << "RESULT: ";
        int index = bSearch(arr,item,0,n-1);
        if (index == -1)
           cout << item << "  given element was not found in the Array!!";

        else
            cout << item << " found at Index " << index << " Position " << (index + 1) << " in the Arrray.";
            return 0;
}
