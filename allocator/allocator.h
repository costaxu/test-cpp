#ifndef __ALLOCATOR_H__
#define __ALLOCATOR_H__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;
namespace Costaxu
{
#define BUFFER_FILE_NAME "/tmp/costaxu_buffer"
#define BUFFER_SIZE      1024*1024*1024

    
    template <class T>
    inline T* _hd_allocate(ptrdiff_t size, T*, char** ppBufferCurrent)
    {
        size_t totalsize=sizeof(T)*size;
        //std::cerr<<"costaxu debug:: _hd_allocate "<<totalsize<<" bytes"<<std::endl;
        T* p = (T*)*ppBufferCurrent;
        *ppBufferCurrent += totalsize;
        //std::cerr<<"end _hd_allocate"<<std::endl;

        return p;
    }

    
    template <class T>
    inline void _hd_deallocate(T* buffer)
    {
        //std::cerr<<"costaxu debug:: _hd_deallocate"<<std::endl;
        //do nothing
    }

    template <class T1, class T2>
    inline void _hd_construct(T1* p, const T2& value, char** pBufferCurrent)
    {
        
        //std::cerr<<"costaxu debug:: _hd_construct"<<std::endl;
        //p = (T1*)*pBufferCurrent;
        //*pBufferCurrent += sizeof(T2);
        //memcpy(p,&value,sizeof(T2));
        //cout<<"costaxu debug:: construct value is:"<<value<<endl;
        new(p) T1(value); 
        //cout<<"costaxu debug:: after construct p is: "<<*p<<endl;
        //std::cerr<<"end _hd_construct"<<std::endl;
        
    }

    template <class T>
    inline void _hd_destroy(T* ptr)
    {
        //std::cerr<<"costaxu debug:: _hd_destroy"<<std::endl;
        ptr->~T();
    }

    template <class T>
    class allocator{
        private:
            static char* m_pBuffer ;
            static char* m_pBufferCurrent;
            int     m_fd;
        public: 

            typedef T value_type;
            typedef T* pointer;
            typedef const T* const_pointer;
            typedef T& reference;
            typedef const T& const_reference;
            typedef size_t   size_type;
            typedef ptrdiff_t difference_type;
        template<class U>
        struct rebind{
            typedef allocator<U> other;
        };
        void init_allocator()
        {
            m_fd = open(BUFFER_FILE_NAME, O_RDWR|O_CREAT|O_TRUNC, 0644);
            if(m_fd< 0 )
            {
                std::cerr<<"costaxu debug:: open "<<BUFFER_FILE_NAME<<"fail" <<std::endl;
                exit(1);
            }
            lseek(m_fd, BUFFER_SIZE, SEEK_SET);
            write(m_fd ,"0",1);
            m_pBuffer = (char*)mmap(0, BUFFER_SIZE, PROT_WRITE,
                    MAP_SHARED, m_fd ,0); 
            m_pBufferCurrent = m_pBuffer;
            //std::cerr<<"mmap "<<m_pBufferCurrent<<std::endl;

        }
        
        allocator()
        {
            if(m_pBuffer ==0)
            {    
                init_allocator();
            }
        }
        
        
        pointer allocate(size_type n, const void* hint=0)
        {
            //cerr<<"costaxu debug:: allocate "<<n<<" structs"<<endl;
            return _hd_allocate((difference_type) n,(pointer)0, &m_pBufferCurrent);
        }

        void deallocate(pointer p,size_type n)
        {
            _hd_deallocate(p);
        }

        void construct(pointer p,const T& value)
        {
            _hd_construct(p,value,&m_pBufferCurrent);
        }

        void destroy(pointer p)
        {
            _hd_destroy(p);
        }

        pointer address(reference x)
        {
            return (pointer)&x;
        }

        const_pointer const_address(const_reference x)
        {
            return (const_pointer)&x;
        }

        size_type max_size() const
        {
            return size_type(UINT_MAX/sizeof(T));
        }
    }  ;
    template<class T>
    char* allocator<T>::m_pBuffer =0;

    template<class T>
    char* allocator<T>::m_pBufferCurrent =0;
};//end of namespace Costaxu
#endif
