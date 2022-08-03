void merge_sort(int *arr, int *temp, int size)
{
    for (int window = 1; window < size; window *= 2)
    {
        for (int left = 0; left + window < size; left += 2 * window)
        {
            int right = left + window;
            int end = right + window;
            if (end > size)
                end = size;

            int k = left;
            int l = left;
            int r = right;
            while (l < right && r < end)
            {
                if (arr[l] > arr[r])
                    temp[k++] = arr[r++];
                else
                    temp[k++] = arr[l++];
            }
            while (l < right)
                temp[k++] = arr[l++];
            while (r < end)
                temp[k++] = arr[r++];
            for (k = left; k < end; ++k)
                arr[k] = temp[k];
        }
    }
}
