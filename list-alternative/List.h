#ifndef LIST_H
#define LIST_H

const unsigned int _initial_list_capacity = 1;
const unsigned int _max_double_limit = 100000;

template<typename T> 
class List {
private:
// _ptr is the pointer which will function as our array
    T* _ptr; 

/*
    _size is the number of elements in the array
    while _cap is the total capacity of the current
    dynamic array
*/
    unsigned int _size, _cap;

// reallocate will be called each time the capacity is reached
    void _reallocate();

public:
// the default constructor initializes the list with initial capacity
    List();

/*
    the number and placeholder constructor
    initializes the dynamic array with the placeholder
    val, and size
*/
   List(unsigned int size, T val);

// destructor, frees _ptr
    ~List();

// at returns the element at index
   T& at(int index); 

// append, inserts val to the end of the array
    void append(T val);

// [] operator overloaded to simplify access
    T& operator[] (int index){
        return at(index);
    }

// the size() function returns the number of elements in the array
    unsigned int size();
};
#endif // LIST_H