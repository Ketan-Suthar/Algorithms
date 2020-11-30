class Solution
{
	public:
	void shuffleArrayHelper(int *arr, int left, int right)
	{
	    if(right - left <= 1)
	        return;
	    int middle = (left + right) / 2;
	    int left_mid = (left + middle) / 2;
	    int temp = middle+1;
	    for(int i=left_mid+1; i<=middle; i++)
	        swap(arr[i], arr[temp++]);
	    shuffleArrayHelper(arr, left, middle);
	    shuffleArrayHelper(arr, middle+1, right);
	}
	void shuffleArray(int arr[],int n)
	{
	    shuffleArrayHelper(arr, 0, n-1);
	}
		 

};