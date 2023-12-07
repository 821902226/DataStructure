#include <iostream>

using namespace std;

void forEach(int * nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int * nums, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(nums[j]>nums[j+1])   //改成小于号实现从大到小的排序
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
        
    } 
}

void selectSort(int *nums, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if(nums[minIndex]>nums[j])  //改成小于号实现从大到小的排序
            {
                minIndex=j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;
    }
    
}

void insertSort(int * nums, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if(nums[j]>nums[j+1])   //改成小于号实现从大到小的排序
            {
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
            else{
                break;
            }
        }
    }
    
}

int main()
{
    int nums[] = {5, 3, 8, 0, 1, 4, 9, 6, 2, 7};

    int size = sizeof(nums)/sizeof(nums[0]);

    //冒泡排序
    cout<<"bubble sort: "<<endl;
    bubbleSort(nums, size);
    forEach(nums, size);

    //选择排序
    cout<<"select sort: "<<endl;
    selectSort(nums, size);
    forEach(nums, size);

    //插入排序
    cout<<"insert sort: "<<endl;
    insertSort(nums, size);
    forEach(nums, size);

    system("pause");
}