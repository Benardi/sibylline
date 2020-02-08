#include <malloc.h>
#include <limits.h>
#include <math.h>
#include <sort.h>

# define INFINITY INT_MAX

void insertion_sort(int array[], int length)
{
    int j, i, key;

    for (j = 1; j < length; j++)
    {
        key = array[j];
        i = j - 1; /* last element of sorted deck */
        while (i > -1 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}

void merge(int array[], int p, int q, int r)
{
    int* left;
    int* right;
    int n1, n2;
    int i, j, k;

    n1 = q - p + 1;
    n2 = r - q;

    left = malloc((n1 + 1)  * sizeof(int));
    right = malloc((n2 + 1) * sizeof(int));

    /* populate left array */
    for (i = 0; i < n1; i++)
    {
        left[i] = array[p + i];
    }

    /* populate right array */
    for (j = 0; j < n2; j++)
    {
        right[j] = array[q + j + 1];
    }

    left[n1] = INFINITY;
    right[n2] = INFINITY;

    i = j = 0;

    /* transfer values to array in correct order */
    for (k = p; k <= r; k++)
    {
        if (left[i] <= right[j])
        {
            array[k] =  left[i];
            i++;    
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }

    free(left);
    free(right);
}

void merge_sort(int array[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = floor((p + r) / 2);
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }
}

static void shift_right_array(int array[], int start, int end)
{
    int i;
       
    for (i = end; i > start; i--)
    {
        array[i] = array[i-1];
    }
}

void inplace_merge(int array[], int p, int q, int r)
{
    int start1, start2, mid, end, moved;

    start1 = p;
    start2 = q + 1;
    mid = q;
    end = r;

    while (start1 <= mid && start2 <= end)
    {
        if (array[start1] < array[start2])
        {
            start1++;
        }
        else
        {
            moved = array[start2];
            shift_right_array(array, start1, start2);
            array[start1] = moved;
            start2++;
            start1++;
            mid++;
        }
    }
}

void inplace_merge_sort(int array[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = floor((p + r) / 2);
        inplace_merge_sort(array, p, q);
        inplace_merge_sort(array, q + 1, r);
        inplace_merge(array, p, q, r);
    }
}