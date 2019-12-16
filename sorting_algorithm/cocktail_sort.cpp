//鸡尾酒排序

#include <iostream>

using namespace std;

class CockTailSort
{
    public:
        void sort_V1(int *array, int n)
        {
            bool isSorted;

            for (int i = 0; i < n / 2; i++)
            {
                isSorted = true;
                //奇数轮排序。从左向右
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        swap(array, j, j + 1);
                        isSorted = false;
                    }
                }
                //是否完成排序，若完成，提前退出
                if (isSorted)
                {
                    break;
                }
                isSorted = true;
                //偶数轮排序。从右向左
                for (int j = n - i - 1; j > i; j--)
                {
                    if (array[j] < array[j - 1])
                    {
                        swap(array, j, j + 1);
                        isSorted = false;
                    }
                } 
                //是否完成排序，若完成，提前退出
                if (isSorted)
                {
                    break;
                }
            }
        }

        //改进算法，设置边界值，缩小每次遍历的边界
        void sort_V2(int *array, int n)
        {
            bool isSorted;

            int leftBorder = 0;
            int rightBorder = n - 1;
            int leftLastExchangeIndex = 0;
            int rightLastExchangeIndex = 0;

            for (int i = 0; i < n / 2; i++)
            {
                isSorted = true;
                //奇数轮排序。从左向右
                for (int j = leftBorder; j < rightBorder; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        swap(array, j, j + 1);
                        isSorted = false;
                        rightLastExchangeIndex = j;
                    }
                }
                rightBorder = rightLastExchangeIndex;
                //是否完成排序，若完成，提前退出
                if (isSorted)
                {
                    break;
                }
                isSorted = true;
                //偶数轮排序。从右向左
                for (int j = rightBorder; j > leftBorder; j--)
                {
                    if (array[j] < array[j - 1])
                    {
                        swap(array, j, j - 1);
                        isSorted = false;
                        leftLastExchangeIndex = j;
                    }
                } 
                leftBorder = leftLastExchangeIndex;
                //是否完成排序，若完成，提前退出
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
    CockTailSort cocktailsort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    cocktailsort.sort_V2(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}