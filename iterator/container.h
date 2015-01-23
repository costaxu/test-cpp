#include <new>
#include <iterator>

template<typename T>
struct ContainerIterator :
    public std::iterator<std::forward_iterator_tag,T>
{
    T* data;
    ContainerIterator(T* data =0)
    :data(data)
    {
        
    }

    T& operator*() const 
    {
        return *data;
    }

    T* operator->()const 
    {
        return data;
    }
    
    //pre increament 
    //++i
    ContainerIterator& operator++()
    {
        data++;
        return *this;
    }

    //post increment
    //i++
    ContainerIterator& operator++(int)
    {
        ContainerIterator tmp= *this;
        ++*this;
        return tmp;
    }

    bool operator==(const ContainerIterator& i) const
    {
        return i.data == data;
    }

    bool operator!=(const ContainerIterator& i)const
    {
        return i.data != data;
    }
};

template <typename T>
class Container
{

public:
    typedef ContainerIterator<T> iterator;

    T* __array;
    int iBegin;
    int iEnd;
    Container()
    {
        __array = new T[100];
        iBegin =0;
        iEnd   =0;
    }

    ~Container()
    {
        delete [] __array;
    }
    
    iterator begin()
    {
        return iterator(__array + iBegin);
    }

    iterator end()
    {
        return iterator(__array + iEnd );
    }
    void insert(T t)
    {
        if (iEnd < 99)
            new((T*)__array + (iEnd++)) T(t) ;
    }

    void insert(T& t)
    {
        if (iEnd < 99)
            new((T*)__array + (iEnd++)) T(t) ;
    }

};


