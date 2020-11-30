// arr[]: Input Array
// N : Size of the Array arr[]
#define ll long long
#define lli long long int

lli merge(ll *arr, ll *temp, ll left, ll middle, ll right)
{
    lli leftIndex, rightIndex, result, inversionCount = 0;
    leftIndex = left;
    rightIndex = middle;
    result = left;
    while((leftIndex <= middle-1) && (rightIndex<=right))
    {
        if(arr[leftIndex] <= arr[rightIndex])
            temp[result++] = arr[leftIndex++];
        else
        {
            temp[result++] = arr[rightIndex++];
            inversionCount += (middle-leftIndex);
        }
    }
    while(leftIndex <= middle-1)
        temp[result++] = arr[leftIndex++];
    while(rightIndex <= right)
        temp[result++] = arr[rightIndex++];
    for(leftIndex=left; leftIndex<=right; leftIndex++)
        arr[leftIndex] = temp[leftIndex];
    return inversionCount;
}

lli mergeSort(ll *arr, ll *temp, ll start, ll end)
{
    lli inverstionCount=0;
    if(start < end)
    {
        lli middle = (start + end) / 2;
        inverstionCount += mergeSort(arr, temp, start, middle);
        inverstionCount += mergeSort(arr, temp, middle+1, end);
        inverstionCount += merge(arr, temp, start, middle+1, end);
    }
    return inverstionCount;
}

long long int inversionCount(long long arr[], long long N)
{
    ll *temp = (ll *)malloc(sizeof(ll) * N);
    return mergeSort(arr, temp, 0, N-1);
}