//
//  SimpleArray.hpp

#ifndef SimpleArray_hpp
#define SimpleArray_hpp

#include <stdexcept>

template <typename T>
class SimpleArray {
    
    int size;
    T* storage;
    
public:
    
    // Constructor: Create an array of a specific size to store
    //              values of the type specified by the user.
    // Precondition: size > 0
    SimpleArray(int size);
    
    // Destructor: Free the memory allocted for the array.
    ~ SimpleArray();
    
    // Getter for the size of the array
    int getSize();
    
    // Operator [] overload
    T &operator[](int i);
    
};


template <typename T>
SimpleArray<T>::SimpleArray(int s){
    if (s <= 0) throw std::invalid_argument("Invalid size for the array.");
    size = s;
    storage = new T[size];  // Exception will be thrown automatically if memory allocation failed
}

template <typename T>
SimpleArray<T>::~ SimpleArray(){
    if (storage) delete [] storage;
}

template <typename T>
int SimpleArray<T>::getSize(){
    return size;
}

template <typename T>
T &SimpleArray<T>::operator[](int i){
    if(i >= 0 && i < size) return *(storage + i);
    throw std::invalid_argument("Invalid index for the array.");
}


#endif /* SimpleArray_hpp */
