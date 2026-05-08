int minimum(int arr[], int n)
{
    int low = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < low)
        {
            low = arr[i];
        }
    }
    return low;
}

int maximum(int arr[], int n)
{
    int high = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > high)
        {
            high = arr[i];
        }
    }
    return high;
}