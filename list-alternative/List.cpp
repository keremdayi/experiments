#include <iostream>
#include "List.h"

template<typename T>
void List<T>::_reallocate() {
    unsigned int old_cap = _cap;
        if(_cap < _max_double_limit){ // if we did not reach the doubling limit
            _cap <<= 1;
        }else{ // if we reached the doubling limit, then we start linear resizing
            _cap += _max_double_limit;
        }

        T* temp_ptr = (T*) malloc(sizeof(T)*_cap); // reallocate as temporary pointer
        
        for(int i = 0; i < old_cap; i++){ // copy from ptr to temp ptr
            *(temp_ptr+i) = *(_ptr+i);
        }

        free(_ptr); // free old pointer

        _ptr = temp_ptr; // set new pointer
}

template<typename T>
List<T>::List(){
    _size = 0;
    _cap = _initial_list_capacity;
    _ptr = (T*) malloc(sizeof(T)*_cap);
}

template<typename T>
List<T>::List(unsigned int size, T val){
    _cap = _initial_list_capacity;
        _size = size;
        
        while(_cap<size && _cap<_max_double_limit) _cap<<=1; // double cap until it is greater than size
        while(_cap<size) _cap +=_max_double_limit;

        _ptr = (T*) malloc(sizeof(T)*_cap); // initialize the array pointer

        for(unsigned int i = 0; i < _size; i++){ // set all _size elements to val
            *(_ptr+i) = val;
        }
}

template<typename T>
T& List<T>::at(int index){
    if(index >= _size || index < 0){
            throw std::runtime_error("invalid index");
        }
    return *(_ptr+index);
}

template<typename T>
void List<T>::append(T val){
    if(_size == _cap){ 
            _reallocate(); 
        }
        *(_ptr+_size) = val; 
        _size++;
}

template<typename T>
List<T>::~List(){
    free(_ptr); 
}

template<typename T>
unsigned int List<T>::size() {return _size;}


void _do_not_call(){ // this function is only added to resolve the linker errors
    List<int> list;
    list.append(0);
    list.at(0);
    list.size();
}