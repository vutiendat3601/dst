#include <iostream>

void quickSort(int nums[], int l, int r)
{
    if (l < r)
    {
        int j = r + 1;
        for (int i = r; i > l; i--)
        {
            if (nums[i] > nums[l])
            {
                j--;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        j--;
        int temp = nums[j];
        nums[j] = nums[l];
        nums[l] = temp;
        quickSort(nums, l, j - 1);
        quickSort(nums, j + 1, r);
    }
}

int main()
{
    int nums[] = {1, 4, 3, 2};
    quickSort(nums, 0, 3);
    for (int i = 0; i < 4; i++)
    {  
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}