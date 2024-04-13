#include "DangerousMatrix.h"
#include <iostream>
#include <random>
template <typename T>

namespace  DM{
  
    
  Matrix::Matrix(const std::vector<std::vector<T>>& matrixData) : Matrix::data(matrixData) {}
    
    size_t Matrix::GetRows(){
        return data.size();
    }
    size_t Matrix::GetColumns(){
        return data.empty()?0:data[0].size();
    }
    std::vector<T>& Matrix::operator [] (size_t i){
        return data[i];
    }

    const std::vector<T>& Matrix::operator [] (size_t i) const{
        return data[i];
    }

    void Matrix::drawMatrix() const {
            for (const auto& row : Matrix::data) {
                for (const auto& element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            } 
    }
    using const_iterator = typename std::vector<std::vector<T>>::const_iterator;
 
    // Используем этот псевдоним в объявлении функций
    const_iterator Matrix::begin() const {
        return data.cbegin();
    }
 
    const_iterator Matrix::end() const {
        return data.cend();
    }
    
    
    std::ostream& Matrix::operator << (std::ostream& out, const Matrix<T>& matrix) {
    const size_t rows = matrix.GetRows();
    const size_t columns = matrix.GetColumns();
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            if (j > 0) {
                out << "\t";
            }
            out << matrix[i][j];
        }
        out << "\n";
    }
    return out;
    }
 
    
    std::istream& Matrix::operator >> (std::istream& in, Matrix<T>& matrix) {
    const size_t rows = matrix.GetRows();
    const size_t columns = matrix.GetColumns();
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            in >> matrix(i, j);
        }
    }
    return in;
    }
  }

