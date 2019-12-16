//插入排序

#include <iostream>

using namespace std;

class InsertSort
{
    public:
        void sort_V1(int *array, int n)
        {
            for (int i = 1; i < n; i++)
            {
                int insertValue = array[i];
                int j;
                for (j = i - 1; j >= 0 && insertValue < array[j]; j--)
                {
                    array[j + 1] = array[j];
                }

                array[j + 1] = insertValue;
            }
        }
};

int main()
{
    InsertSort insertsort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    insertsort.sort_V1(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}