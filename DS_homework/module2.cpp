#include<iostream>
using namespace std;
 //pass oj test
 //这里先要实现一个堆，堆的一些内部的属性可以看到下面，maxsize最大容量，index就是当前数据的指针（末尾）
 //mode是为了指示最大堆还是最小堆，在类的初始化函数里可以传入参数进行指定
template<class T>
class MinHeap
{
public:
    MinHeap()
    {
        _maxSize = 0;
        _index = -1;
        _minHeap = NULL;
    }
 
    MinHeap(int maxsize,int flag)
    {
        _maxSize = maxsize;
        _index = -1;
        _minHeap = new T[maxsize];
        mode = flag;
 
    }
 
    MinHeap(MinHeap& h)
    {
        _maxSize = h._maxSize;
        _index = h._index;
        for (int i = 0; i < h._index; i++)
            _minHeap[i] = h._minHeap[i];
    }
 
    ~MinHeap()
    {
        delete[] _minHeap;
    }
 //这里就是一些特别基本的函数，基础功能，比较简单
    T* GetMinHeap()
    {
        return _minHeap;
    }
 
    bool IsEmpty()
    {
        return _index == -1;
    }
    bool IsFool()
    {
        return _index == _maxSize;
    }
 
    bool Add(T x)
    {
        if (IsFool())
            return false;
 
        _index++;
        _minHeap[_index] = x;
        return true;
    }
 
    void CreatMinHeap()
    {
        if (IsEmpty())
            return;
 
        for (int i = (_index - 1) / 2; i > -1; i--)
        {
            AdjustDown(i);
        }
    }
 //重点来了，这里的大量的一些关键函数，这里是向下调整函数，大多是用于在删除的时候
 //众所周知，堆在删除的时候是把堆顶不要了，然后把尾部移上了，就会有可能破坏堆的性质，也就是在这个时候调用
 //这个函数至上而下的重新调整，具体的原理其实就是滑动，不和条件的会被滑走，具体的操作还要看是最大堆还是
 //最小堆了，可以看到下面也对mode进行了分类操作
    void AdjustDown(int index)
    {
        if (IsEmpty())
            return;
 
        int temp;
        int flag = 0;
 
        while ((index * 2 + 1) <= _index && flag == 0)
        {
            if (mode)
            {
                if (_minHeap[index] > _minHeap[index * 2 + 1]) 
                    temp = index * 2 + 1;
                else
                    temp = index;
 
                if (index * 2 + 2 <= _index)
                {
                    if (_minHeap[temp] > _minHeap[index * 2 + 2])
                        temp = index * 2 + 2;
                }
 
                if (temp != index)
                {
                    T t = _minHeap[temp];
                    _minHeap[temp] = _minHeap[index];
                    _minHeap[index] = t;
                    index = temp;
 
                }
                else
                    flag = 1;
            }
            else
            {
                if (_minHeap[index] < _minHeap[index * 2 + 1])
                    temp = index * 2 + 1;
                else
                    temp = index;
 
                if (index * 2 + 2 <= _index)
                {
                    if (_minHeap[temp] < _minHeap[index * 2 + 2])
                        temp = index * 2 + 2;
                }
 
                if (temp != index)
                {
                    T t = _minHeap[temp];
                    _minHeap[temp] = _minHeap[index];
                    _minHeap[index] = t;
                    index = temp;
 
                }
                else
                    flag = 1;
            }
 
        }
 
    }
 //这个就和上面的那个是类似的，不过这个是向上调整，大多是用域在插入的时候
 //堆其实是用数组实现的，插入就是直接放在了数组的末尾，然后指针加一
 //当然不可能这么草率的插入了就完事，肯定需要进行一系列的调整
    void AdjustUp(int index)
    {
        if (index < 0 || index == 0)
            return;
 
        int flag = 0;
        while (index != 0 || flag == 0)
        {
            if (mode)
            {
                int i = (index - 1) / 2;
                if (_minHeap[i] > _minHeap[index])
                {
                    T t = _minHeap[i];
                    _minHeap[i] = _minHeap[index];
                    _minHeap[index] = t;
                }
                else
                    flag = 1;
            }
            else
            {
                int i = (index - 1) / 2;
                if (_minHeap[i] < _minHeap[index])
                {
                    T t = _minHeap[i];
                    _minHeap[i] = _minHeap[index];
                    _minHeap[index] = t;
                }
                else
                    flag = 1;
            }
 
            index = (index - 1) / 2;
        }
 
    }
 //这里就是插入函数，可以看到判断了是否超出界限，没有就放在末尾，然后直接调用调整函数就行
    bool InsertNode(const T& v)
    {
        if ((_index + 1) < _maxSize)
        {
            _index++;
            _minHeap[_index] = v;
            AdjustUp(_index);
            return true;
        }
        else
            return false;
    }
    //和上面类似又是相仿的，这个是删除的函数，删除前看看是不是空的，不是的就操作，然后调整
    bool DeleteNode(T& v)
    {
        if (IsEmpty())
            return false;
 
        v = _minHeap[0];
        _minHeap[0] = _minHeap[_index];
        _index--;
 
        AdjustDown(0);
 
    }
 
     //这个就是一起写的，排序的，这里没用到
    void HeapSort()
    {
        while (_index > -1)
        {
 
            T temp = _minHeap[0];
            _minHeap[0] = _minHeap[_index];
            _minHeap[_index] = temp;
 
            _index--;
            AdjustDown(0);
 
 
        }
    }
 
 
    T* _minHeap;
    int         _index;
    int         _maxSize;
    int mode;
};
 
int main()
{
    //创建了两个堆，分别是最大堆和最小堆
    MinHeap<int> min_heap(6000, 1);
    MinHeap<int> max_heap(6000, 0);
    min_heap.CreatMinHeap();
    max_heap.CreatMinHeap();
    int num;
    cin >> num;
    //然后开始准备读入数据。进行处理
    for (int i(0); i < num; i++)
    {
        int temp;
        cin >> temp;
        //最小堆空了，那就没得说了，直接放在最小堆里就行了
        if (min_heap._index == -1)
        {
            min_heap.InsertNode(temp);
        }
        else
        {
            //在保证了最小堆已经不是空的化，就拿出堆顶，然后判断大小，堆顶大就放到最大堆
            //反之就放在最小堆，这里简单的说一下原理吧，（具体的说明在实验报告里说的灰常的详细了
            //最大堆里放的是一堆小的数，最小堆反而放了一堆大的数
            //那么最大堆的堆顶就是一堆小的数里的最大的，最小堆的堆顶就是一堆大的数里最小的，
            //那么中位数就必然产生于二者
            int* p = min_heap.GetMinHeap();
            if (p[0] < temp)
            {
                min_heap.InsertNode(temp);
            }
            else
            {
                max_heap.InsertNode(temp);
            }
        }
        //由于一定要保证中位数在堆顶之一，就要保证二者几乎等大
        if (min_heap._index - max_heap._index > 1)
        {
            min_heap.DeleteNode(temp);
            max_heap.InsertNode(temp);
        }
        if (max_heap._index - min_heap._index > 1)
        {
            max_heap.DeleteNode(temp);
            min_heap.InsertNode(temp);
        }
        /*测试用的一些代码
        cout << "check1 ";
        for (int i(0); i < min_heap._index+1; i++)
        {
            int* p = min_heap.GetMinHeap();
            cout << p[i] << " ";
        }
        cout << endl;
        cout << "check2 ";
        for (int i(0); i < max_heap._index+1;i++)
        {
            int* p = max_heap.GetMinHeap();
            cout << p[i] << " ";
        }
        cout << endl;
        */
 //这里就是看看奇偶数，然后对应计算就行，很方便的
        if ((min_heap._index + 1 + max_heap._index + 1) % 2 == 1)
        {
            int* p;
            if(min_heap._index>max_heap._index)
                 p = min_heap.GetMinHeap();
            else
                p = max_heap.GetMinHeap();
            cout  << p[0] << endl;
        }
        else
        {
            int* p1 = min_heap.GetMinHeap();
            int* p2 = max_heap.GetMinHeap();
            cout <<  (p1[0]+p2[0])/2 << endl;
        }
    }
     
 
    return 0;
}
 
