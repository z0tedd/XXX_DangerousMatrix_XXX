#ifndef DANGEROUSMATRIX
#define DANGEROUSMATRIX


#include <iostream>
#include <random>
#include <vector>
namespace  DM{
  template <typename T >
  class Matrix{
  private:
    std::vector<std::vector<T>> data;
  
  public:
    Matrix(const std::vector<std::vector<T>>& matrixData) : data(matrixData){};
    
    size_t GetRows();
    size_t GetColumns();
    std::vector<T>& operator [] (size_t i);
    const std::vector<T>& operator [] (size_t i) const;
    void drawMatrix() const;
  
    
    using const_iterator = typename std::vector<std::vector<T>>::const_iterator;
 
    // Используем этот псевдоним в объявлении функций
    const_iterator begin() const;
 
    const_iterator end() const;
    
    
    std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix);
 
    
    std::istream& operator >> (std::istream& in, Matrix<T>& matrix);
  };
}





#endif 

