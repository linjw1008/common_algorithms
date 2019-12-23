//基数排序

#include <iostream>
#include <cstring>

using namespace std;

class RadixSort
{
    public:
        void sort_V1(string *array, int n)
        {
            string* sortedArray = new string[n];
            //获取字符串数组的最长字符串的长度
            int maxLen = 0;
            for (int i = 0; i < n; i++)
            {
                if (maxLen < array[i].size())
                {
                    maxLen = array[i].size();
                }
            }
            //从低位开始，对每一位进行稳定版本的计数排序
            for (int i = maxLen - 1; i >= 0; i--)
            {
                //把待排序的字符按照ASCII码存入统计数组
				int count[128] = { 0 };
                for (int j = 0; j < n; j++)
                {
                    count[getCharAscii(array[j], i)]++;
                }
                //对统计数组变形，后面的元素等于前面元素之和
                for (int j = 1; j < sizeof(count) / sizeof(count[0]); j++)
                {
                    count[j] = count[j] + count[j - 1];
                }
                //倒序遍历原始数组，根据统计数组找到正确位置
                for (int j = n - 1; j >= 0; j--)
                {
                    int index = getCharAscii(array[j], i);
                    sortedArray[count[index] - 1] = array[j];
                    count[index]--;
                }
                //复制数组
                for (int i = 0; i < n; i++)
                {
                    array[i] = sortedArray[i];
                }
            }
        }
    private:
        int getCharAscii(string str, int k)
        {
            if (str.size() <= k)
            {
                return 0;
            }
            return str[k];
        }
};

int main()
{
    RadixSort radix_sort;

    string array[] = {"lin", "jia", "wei", "li", "lii", "ljw", "jw", "www"};
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    
    radix_sort.sort_V1(array, sizeof(array) / sizeof(array[0]));

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        puts(array[i].c_str());
    }
    
    return 0;
}