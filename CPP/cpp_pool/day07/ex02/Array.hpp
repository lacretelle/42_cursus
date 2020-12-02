#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template< typename T >
class Array
{
    public:
        Array<T>(void) : _arr(0), _elem(0){}
        Array<T>(unsigned int n) : _elem(n) {
            _arr = new T[n];
            for (unsigned int i = 0; i < n; i++)
                _arr[i] = T();
        }
        Array<T>(Array const & src) : _arr(new T[0]) { *this = src; }
        Array<T> const & operator=(Array const & src){
            if (this != &src)
            {
                if (this->_arr != 0)
                    delete [] this->_arr;
                this->_elem = src.size();
                this->_arr = new T[this->_elem];
                if (src._arr != 0)
                {
                    for (unsigned int i = 0; i < src.size(); i++)
                        this->_arr[i] = src._arr[i];
                }
            }
            return *this;
        }
        T&  operator[](unsigned int index){
            if (index >= this->size())
                throw std::out_of_range("Impossible to do that !");
            return this->_arr[index];
        }
        ~Array<T>(){
            if (_arr)
                delete[] _arr;
        }

        unsigned int    size() const { return this->_elem; }

    private:
        T*              _arr;
        unsigned int    _elem;
};

#endif