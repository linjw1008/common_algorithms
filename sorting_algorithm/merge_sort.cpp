//归并排序

#include <iostream>

using namespace std;

class MergeSort
{
    public:
        void sort_V1(int *array, int n)
        {
            mergeSort_V1(array, 0, n - 1);
        }

    private:
        //递归函数
        void mergeSort_V1(int *array, int leftIndex, int rightIndex)
        {
            if (rightIndex <= leftIndex)
                return;
            
            int mid = (leftIndex + rightIndex) / 2;
            mergeSort_V1(array, leftIndex, mid);
            mergeSort_V1(array, mid + 1, rightIndex);
            merge(array, leftIndex, mid, rightIndex);
        }

        //用于将两个小集合合并为1个集合
        void merge(int *array, int start, int mid, int end)
        {
            int *tmp = new int[end - start + 1];
            int ptr1 = start, ptr2 = mid + 1, ptr = 0;

            //将两个小集合元素依照大小关系移到大集合
            while (ptr1 <= mid && ptr2 <= end)
            {
                if (array[ptr1] <= array[ptr2])
                {
                    tmp[ptr++] = array[ptr1++];
                }
                else
                {
                    tmp[ptr++] = array[ptr2++];
                }
            }
            //左边小集合没有放完，继续放到大集合
            while (ptr1 <= mid)
            {
                tmp[ptr++] = array[ptr1++];
            }
            //右边小集合没有放完，继续放到大集合
            while(ptr2 <= end)
            {
                tmp[ptr++] = array[ptr2++];
            }

            //大集合元素放回原数组
            for (int i = 0; i < end - start + 1; i++)
            {
                array[i + start] = tmp[i];
            }

        }

};

int main()
{
    MergeSort mergesort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    mergesort.sort_V1(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}