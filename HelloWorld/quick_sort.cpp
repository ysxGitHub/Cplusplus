#include "quick_sort.h"

int partition(int *li, int left, int right)
{
    int tmp = li[left];
    while (left < right)
    {
        while (left < right && li[right] >= tmp)
        {
            right -= 1;
        }
        li[left] = li[right];
        while (left < right && li[left] <= tmp)
        {
            left += 1;
        }
        li[right] = li[left];
    }
    li[left] = tmp;
    return left;
}



void quick_sort(int *lis, int left, int right)
{
    if (left < right)
    {
        int mid = partition(lis, left, right);
        quick_sort(lis, left, mid - 1);
        quick_sort(lis, mid + 1, right);
    }  
    return;
}



