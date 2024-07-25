#ifndef ARRAY_H_
#define ARRAY_H_

struct Array {
  int size;
  int* array;
  Array() : size(0), array(nullptr) {}
  Array(int size) : size(size) { array = new int[size]; }
  Array(int size, int initValue) : size(size) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
      array[i] = initValue;
    }
  }
};

#endif  //! ARRAY_H_