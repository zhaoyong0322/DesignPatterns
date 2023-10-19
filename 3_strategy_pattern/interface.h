#include <iostream>
#include <algorithm>
using namespace std;

class Strategy
{
public:
    Strategy(){}
    virtual ~Strategy(){}
    virtual void doSort(int *arr, int len) = 0;
};

class BubbleSort : public Strategy
{
public:
    void doSort(int *arr, int len)
    {
        sort(arr,arr+len);//core algorithm
        std::cout <<"Bubble Sort"<< endl;
    }
};

class QuickSort: public Strategy
{
public:
    void doSort(int *arr, int len)
    {
        sort(arr,arr+len);
        std::cout <<"Quick Sort" << endl;
    }
};

class MergeSort: public Strategy
{
public:
    void doSort(int *arr, int len)
    {
        sort(arr,arr+len);
        std::cout <<"Merge Sort" << endl;
    }
};


