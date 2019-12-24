#include<iostream>
using namespace std;
 //pass oj test
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
    bool DeleteNode(T& v)
    {
        if (IsEmpty())
            return false;
 
        v = _minHeap[0];
        _minHeap[0] = _minHeap[_index];
        _index--;
 
        AdjustDown(0);
 
    }
 
     
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
    MinHeap<int> min_heap(6000, 1);
    MinHeap<int> max_heap(6000, 0);
    min_heap.CreatMinHeap();
    max_heap.CreatMinHeap();
    int num;
    cin >> num;
    for (int i(0); i < num; i++)
    {
        int temp;
        cin >> temp;
        if (min_heap._index == -1)
        {
            min_heap.InsertNode(temp);
        }
        else
        {
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
        /*
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
 
