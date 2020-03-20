#pragma once

#include <stdlib.h>
#include <iostream>

namespace krm {

// max 60000 size
#define max_list_subsize 16 

template <typename Type>
class List {
private:
    unsigned long int _size; // size is up to 2^10
    unsigned long int _idx_size;

    Type *_ptr[max_list_subsize];

public:
    List(){ // empty list
        _size = 0;
        _idx_size = 0;
    } 

    List(unsigned long int size, Type val){ // assign val to every element
        if(size == 0){
            throw "Size cannot be 0";
        }
        _size = size;

        int p = 1;
        int idx = 0;
        while(p<size){
            if(idx > max_list_subsize){
                throw "List max size reached!";
            }
            _ptr[idx] = new Type[p];
            for(unsigned int i = 0; i < p; i++){
                _ptr[idx][i] = val;
            }

            size-=p; // note that size is not the same as _size
            p*=2;
            idx++;
        }

        if(size!=0){
            if(idx > max_list_subsize){
                throw std::runtime_error("Max list size reached!");
            }
            _ptr[idx] = new Type[p];
            for(unsigned int i = 0; i < p; i++){
                _ptr[idx][i] = val;
            }
            idx++;
        }
        _idx_size = idx;
    }

    ~List(){
        for(int i = 0; i < _idx_size; i++){
            delete _ptr[i];
        }
    }

    Type& at(unsigned long int index) {
        if(index >= _size){
            throw std::runtime_error("List index out of range");
        }
        int c = 0;
        int i = 0;
        int p = 1;
        while(index >= c+p){
            c+=p;
            p*=2;
            i++;
        }
        int rel = index - c;
        return _ptr[i][rel];
    }

    void append(Type val){
        int index = _size;
        int c = 0;
        int i = 0;
        int p = 1;
        while(index >= c+p){ // log(index complexity)
            c+=p;
            p*=2;
            i++;
        }
        int rel = index - c;
        if(rel==0){
            _ptr[_idx_size] = new Type[p];
            _idx_size++;
        }
        _ptr[i][rel] = val;
        _size++;
    }

    Type& operator[] (int index) {
        return at(index);
    }

    unsigned int size() {
        return _size;
    }
};

}