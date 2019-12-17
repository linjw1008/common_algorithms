//希尔排序
//在插入排序的基础上改进

#include <iostream>

using namespace std;

class ShellSort
{
    public:
        void sort_V1(int *array, int n)
        {
            //采用希尔增量
            int step = n;
            while(step > 1)
            {
                //增量减半，直至为1
                step = step / 2;
                //按照增量分组，每组分别进行插入排序
                for (int i = 0; i < step; i++)
                {
                    //开始插入排序
                    for (int j = i + step; j < n; j += step)
                    {
                        int tmp = array[j];
                        int k;
                        for (k = j - step; tmp < array[k] & k >= 0; k -= step)
                        {
                            array[k + step] = array[k];
                        }
                        array[k + step] = tmp;
                    }
                }
            }
        }

        void sort_V2(int *array, int n)
        {
            //采用Hibbard增量
            //1,3,5,7,15
            //2^k - 1
            int step = n;
            while(step > 1)
            {
                //Hibbard增量，直至为1
                step = (step + 1) / 2 - 1;
                //按照增量分组，每组分别进行插入排序
                for (int i = 0; i < step; i++)
                {
                    //开始插入排序
                    for (int j = i + step; j < n; j += step)
                    {
                        int tmp = array[j];
                        int k;
                        for (k = j - step; tmp < array[k] & k >= 0; k -= step)
                        {
                            array[k + step] = array[k];
                        }
                        array[k + step] = tmp;
                    }
                }
            }
        }

    private:

};

int main()
{
    ShellSort shellsort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    shellsort.sort_V2(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}