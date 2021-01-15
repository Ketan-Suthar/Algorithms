/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
   int left=0, right=n-1;
   while(left<=right)
   {
       int middle=left+(right-left)/2;
       if((middle==0||arr[middle-1]<=arr[middle]) &&
        (middle==n-1||arr[middle+1]<=arr[middle]))
            return middle;
        if(middle>0 && arr[middle-1]>arr[middle])
            right=middle;
        else
            left=middle+1;
   }
   // will never reach this line
   return -1;
}