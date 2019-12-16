//冒泡排序

#include <iostream>

using namespace std;

class BubbleSort
{
    public:
        void sort_V1(int *array, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        swap(array, j, j + 1);
                    }
                }  
            }
        }

        //记录下是否完成排序，如果没有再次交换，则完成排序，可以提前退出
        void sort_V2(int *array, int n)
        {
            bool isSorted;
            for (int i = 0; i < n; i++)
            {
                isSorted = true;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        swap(array, j, j + 1);
                        isSorted = false;
                    }
                }  
                if(isSorted) break;
            }
        }

        void sort_V3(int *array, int n)
        {
            bool isSorted;
            int lastExchangeIndex = 0;
            int sortBorder = n - 1;
            for (int i = 0; i < n; i++)
            {
                isSorted = true;

                for (int j = 0; j < sortBorder; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        swap(array, j, j + 1);
                        isSorted = false;
                        lastExchangeIndex = j;
                    } 
                }

                sortBorder = lastExchangeIndex;

                if (isSorted)
                {
                    break;
                }
            }
        }

    private:
        void swap(int *array, int i, int j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
};

int main()
{
    BubbleSort bubblesort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    bubblesort.sort_V3(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}