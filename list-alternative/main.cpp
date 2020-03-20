#include <iostream>
#include <string>
using namespace std;

const unsigned int _initial_list_capacity = 1;
const unsigned int _max_double_limit = 100000;

template<typename T>
class List {
private:
    T* _ptr;
    unsigned int _size, _cap;

    void _reallocate(){
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

public:
    List(){ // default constructor
        _size = 0;
        _cap = _initial_list_capacity;
        _ptr = (T*) malloc(sizeof(T)*_cap);
    }

    List(unsigned int size, T val){ // constructor that constructs a list with size elements, which are equal to val
        _cap = _initial_list_capacity;
        _size = size;
        
        while(_cap<size && _cap<_max_double_limit) _cap<<=1; // double cap until it is greater than size
        while(_cap<size) _cap +=_max_double_limit;

        _ptr = (T*) malloc(sizeof(T)*_cap); // initialize the array pointer

        for(unsigned int i = 0; i < _size; i++){ // set all _size elements to val
            *(_ptr+i) = val;
        }
    }

    T& at(int index) { // function to access element at index: index
        if(index >= _size || index < 0){
            throw std::runtime_error("invalid index");
        }
        return *(_ptr+index);
    } 
    
    void append(T val){ // appending val to the end of the list
        if(_size == _cap){ // if capacity is reached, reallocate
            _reallocate(); 
        }
        *(_ptr+_size) = val; 
        _size++;
    }

    ~List(){
        free(_ptr); 
    }

    T& operator[] (unsigned int index){
        return at(index);
    }

    unsigned int size() {return _size;}
};

int main(){

    List<int> myList;


    myList.append(4);
    myList.append(3);
    myList.append(5);
    myList.append(1);
    myList.append(6);

    myList[1] = 0;

    cout<<myList.size()<<endl;


    for(int i = 0; i < myList.size(); i++) cout<<myList[i]<<" ";


}