#include "interface.h"
#include <map>

enum {
    bubbleSort,
    quickSort,
    mergeSort,
};

class Context
{
public:
    Context()
    {
        m_ContexMap.insert({bubbleSort,new BubbleSort()});
        m_ContexMap.insert({quickSort,new QuickSort()});
        m_ContexMap.insert({mergeSort,new MergeSort()});
    }

    void execute(int type, int *arr,int len)
    {
        if (m_ContexMap.count(type)) {
            m_strategy = m_ContexMap[type];
            m_strategy->doSort(arr, len);
        }
    }

private:
    Strategy *m_strategy;
    map<int, Strategy *> m_ContexMap;

};

void print (int *arr,int len) {
    for(int i = 0; i < len; i++) {
        std::cout<< arr[i] << " ";
    }
    std::cout<< std::endl;
}


void  strategy_test() {


    int arr1[] = { 10,99,88,1,5,4,2,66,77,22,11,44};
    int arr2[] = { 10,99,88,1,5,4,2,66,77,22,11,44};
    int arr3[] = { 10,99,88,1,5,4,2,66,77,22,11,44};

    int len = sizeof(arr1)/sizeof(arr1[0]);

    Context *context1 = new Context();
    context1->execute(bubbleSort,arr1, len);
     print(arr1,len);

    context1->execute(quickSort,arr2, len);
     print(arr2,len);

    context1->execute(mergeSort,arr3, len);
    print(arr3,len);

}
