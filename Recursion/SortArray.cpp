#include <iostream>

using namespace std;

void insertElement(int arr[], int n, int temp)
{
    if(n==0 || arr[n-1] < temp)
    {
        arr[n] = temp; return;
    }
    
    int temp2 = arr[n-1];
    insertElement(arr, n-1, temp);
    arr[n] = temp2;
}

void sortArray(int arr[], int n)
{
    if(n==1)
        return;
    if(n==2 && arr[0] > arr[1])
    {
        arr[0] ^= arr[1] ^= arr[0] ^= arr[1];
        return;
    }

    int temp = arr[n-1];

    sortArray(arr, n-1);

    insertElement(arr, n-1, temp);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    sortArray(arr, n);
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
