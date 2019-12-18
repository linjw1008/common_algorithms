//计数排序
//适用于在一定范围的数据

#include <iostream>
#include <cstring>

using namespace std;

class CountSort
{
    public:
        void sort_V1(int *array, int n)
        {
            //挑选出数组的最大值
            int max = array[0];
            for (int i = 1; i < n; i++)
            {
                if (max < array[i])
                {
                    max = array[i];
                }
            }
            //挑选出数组的最小值
            int min = array[0];
            for (int i = 1; i < n; i++)
            {
                if (min > array[i])
                {
                    min = array[i];
                }
            }

            int countArrayLen = max - min + 1;
            int *countArray = new int[countArrayLen]();

            //计数
            for (int i = 0; i < n; i++)
            {
                countArray[array[i] - min]++;
            }

            //输出排序结果
            int k = 0;
            for (int i = 0; i < countArrayLen; i++)
            {
                for (int j = 0; j < countArray[i]; j++)
                {
                    array[k++] = i;
                }
            }
        }

        //真正对每个元素进行排序，能够得到每个元素原来的位置
        void sort_V2(int *array, int n)
        {
            //挑选出数组的最大值
            int max = array[0];
            for (int i = 1; i < n; i++)
            {
                if (max < array[i])
                {
                    max = array[i];
                }
            }
            //挑选出数组的最小值
            int min = array[0];
            for (int i = 1; i < n; i++)
            {
                if (min > array[i])
                {
                    min = array[i];
                }
            }
            //计算计数数组长度
            int countArrayLen = max - min + 1;
            int *countArray = new int[countArrayLen]();

            //计数
            for (int i = 0; i < n; i++)
            {
                countArray[array[i] - min]++;
            }

            //关键步骤
            //对计数数组变形，后面元素等于前面元素之和
            //使元素值等于原数组的相应元素最终排序位置
            int sum = 0;
            for (int i = 0; i < countArrayLen; i++)
            {
                sum += countArray[i];
                countArray[i] = sum;
            }
            
            //倒序遍历原始数组，从统计数组找到正确位置，输出到结果数组
            int *res = new int[n];
            for (int i = n - 1; i >= 0; i--)
            {
                res[countArray[array[i] - min] - 1] = array[i];
                countArray[array[i] - min]--;
            }

            for (int i = 0; i < n; i++)
            {
                array[i] = res[i];
            }  
        }
};

int main()
{
    CountSort count_sort;

    int array[] = {5, 7, 9, 4, 1, 3, 5, 11, 66, 44, 52, 98, 19, 67, 24, 0};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    count_sort.sort_V2(array, sizeof(array)/sizeof(int));

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}