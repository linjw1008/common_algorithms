//桶排序

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class BucketSort
{
    public:
        void sort_V1(double *array, int n)
        {
            //得到数列min 和 max
            double max = array[0];
            double min = array[0];
            for (int i = 1; i < n; i++)
            {
                if (max < array[i])
                {
                    max = array[i];
                }
                if (min > array[i])
                {
                    min = array[i];
                }
            }
            double step = max - min;

            //初始化桶
            vector<vector<double>> bucketList;
            bucketList.reserve(n); 
            for (int i = 0; i < n; i++)
            {
                vector<double> tmp;
                bucketList.push_back(tmp);
            }

            //将元素入桶
            for (int i = 0; i < n; i++)
            {
                int index = (int) ((array[i] - min) * (n - 1) / step);
                bucketList[index].push_back(array[i]);
            }
            
            //对每个桶的元素进行排序
            for (int i = 0; i < n; i++)
            {
                sort(bucketList[i].begin(), bucketList[i].end());
            }
            
            //输出全部元素
            int index = 0;
            for (int i = 0; i < n; i++)
            {
                for (auto iter : bucketList[i])
                {
                    array[index] = iter;
                    index++;
                }
            }
        }


    private:

};

int main()
{
    BucketSort bucketsort;

    double array[] = {4.12, 6.421, 0.0023, 3.0, 2.123, 8.122, 4.12, 10.09};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    bucketsort.sort_V1(array, sizeof(array)/sizeof(array[0]));

    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        cout << array[i] << " " << endl;
    }
    
    return 0;
}