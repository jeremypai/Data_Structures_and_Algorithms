struct Array {
  int size;
  int *element;
  Array() : size(0), element(nullptr) {}
  Array(int s) : size(s) { element = new int[s]; }
  Array(int s, int initValue) : size(s) {
    element = new int[s];
    for (int i = 0; i < s; ++i) {
      element[i] = initValue;
    }
  }
};