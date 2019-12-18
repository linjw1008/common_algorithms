//堆排序
//利用大顶堆

#include <iostream>

using namespace std;

class HeapSort
{
    public:
        void sort_V1(int *array, int n)
        {
            buildHeap(array, n);
            for (int i = n - 1; i > 0; i--)
            {
                int tmp = array[i];
                array[i] = array[0];
                array[0] = tmp;
                downAdjust(array, 0, i);
            }
        }

    private:
        //构建堆
        void buildHeap(int *array, int len)
        {
            for (int i = len / 2; i >= 0; i--)
            {
                downAdjust(array, i, len);
            }
        }

        void downAdjust(int *array, int index, int len)
        {
            int tmp = array[index];
            int parentIndex = index;
            int childIndex = 2 * parentIndex + 1;
            while (childIndex < len)
            {
                if (childIndex + 1 < len && array[childIndex + 1] > array[childIndex])
                {
                    childIndex++;
                }
                if (tmp < array[childIndex])
                {
                    array[parentIndex] = array[childIndex];
                    parentIndex = childIndex;
                    childIndex = parentIndex * 2 + 1;
                }
                else
                {
                    break;
                }
            }
            array[parentIndex] = tmp;            
        }
};

int main()
{
    HeapSort heap_sort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    heap_sort.sort_V1(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}