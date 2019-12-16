//选择排序

#include <iostream>

using namespace std;

class SelectionSort
{
    public:
        void sort_V1(int *array, int n)
        {
            int minIndex;
            for (int i = 0; i < n - 1; i++)
            {
                minIndex = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (array[minIndex] >= array[j])
                    {
                        minIndex = j;
                    }
                }
                swap(array, i, minIndex);
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
    SelectionSort selectionsort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    selectionsort.sort_V1(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}