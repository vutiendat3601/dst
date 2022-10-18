#include <iostream>

void merge(int nums[], int l, int mid, int r)
{
    int lLen = mid - l + 1;
    int rLen = r - mid;
    int lA[lLen];
    int rA[rLen];
    int mIndex = l;
    for (int i = 0; i < lLen; i++)
    {
        lA[i] = nums[mIndex++];
    }
    for (int i = 0; i < rLen; i++)
    {
        rA[i] = nums[mIndex++];
    }
    int lIndex = 0;
    int rIndex = 0;
    mIndex = l;
    while (lIndex < lLen && rIndex < rLen)
    {
        if (lA[lIndex] <= rA[rIndex])
        {
            nums[mIndex] = lA[lIndex++];
        }
        else
        {
            nums[mIndex] = rA[rIndex++];
        }
        mIndex++;
    }
    while (lIndex < lLen)
    {
        nums[mIndex++] = lA[lIndex++];
    }
    while (rIndex < rLen)
    {
        nums[mIndex++] = rA[rIndex++];
    }
}

void mergeSort(int nums[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
}

int main()
{
    int nums[] = {1, 4, 3, 2};
    mergeSort(nums, 0, 3);
    for (int i = 0; i < 4; i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}