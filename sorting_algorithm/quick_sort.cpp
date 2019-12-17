//快速排序

#include <iostream>

using namespace std;

class QuickSort
{
    public:
        void sort_V1(int *array, int n)
        {
            quickSort_V1(array, 0, n - 1);
        }

        void sort_V2(int *array, int n)
        {
            quickSort_V2(array, 0, n - 1);
        }

    private:
        //递归函数
        void quickSort_V1(int *array, int leftIndex, int rightIndex)
        {
            if (leftIndex >= rightIndex)
            {
                return;
            }

            int pivotIndex = partition_V1(array, leftIndex, rightIndex);

            //分治法
            quickSort_V1(array, leftIndex, pivotIndex - 1);
            quickSort_V1(array, pivotIndex + 1, rightIndex);
        }

        void quickSort_V2(int *array, int leftIndex, int rightIndex)
        {
            if (leftIndex >= rightIndex)
            {
                return;
            }

            int pivotIndex = partition_V2(array, leftIndex, rightIndex);

            //分治法
            quickSort_V2(array, leftIndex, pivotIndex - 1);
            quickSort_V2(array, pivotIndex + 1, rightIndex);
        }

        //挖坑法
        int partition_V1(int *array, int leftIndex, int rightIndex)
        {
            int pivot = array[leftIndex];
            int lptr = leftIndex;
            int rptr = rightIndex;
            //坑的位置
            int index = leftIndex;

            while (lptr <= rptr)
            {
                //从右向左
                while (lptr <= rptr)
                {
                    if (array[rptr] < pivot)
                    {
                        array[lptr] = array[rptr];
                        index = rptr;
                        lptr++;
                        break;
                    }
                    rptr--;
                }

                //从左向右
                while (rptr >= lptr)
                {
                    if (array[lptr] > pivot)
                    {
                        array[rptr] = array[lptr];
                        index = lptr;
                        rptr--;
                        break;
                    }
                    lptr++;
                }
            }

            array[index] = pivot;

            return index;
        }

        //指针法
        int partition_V2(int *array, int leftIndex, int rightIndex)
        {
            int pivot = array[leftIndex];
            int lptr = leftIndex;
            int rptr = rightIndex;
            
            while (lptr != rptr)
            {
                //从右向左，找到小于基准值的第一个值
                while (lptr < rptr)
                {
                    if (array[rptr] < pivot)
                    {
                        break;
                    }
                    rptr--;
                }

                //从左向右，找到大于基准值的第一个值
                //用大于号，若上方的循环使得lptr = rptr，该循环就不会执行
                while (rptr > lptr)
                {
                    if (array[lptr] > pivot)
                    {
                        break;
                    }
                    lptr++;
                }

                //互相交换这两个值
                swap(array, rptr, lptr);
            }

            //交换pivot和指针重合点
            swap(array, lptr, leftIndex);

            return lptr;
        }

        void swap(int *array, int i, int j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
};

int main()
{
    QuickSort quicksort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    quicksort.sort_V2(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}