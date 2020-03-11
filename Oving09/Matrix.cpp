#include "Matrix.h"
#include <utility>

double Matrix::get(int row, int col) const{
    return totMatr[row][col];
}

void Matrix::set(int row, int col, double value){ // Ment for brukere for øyeblikket, derfor minus 1.
    if (row > rows || col > columns || row < 1 || col < 1) throw Invalid_req();
    totMatr[row - 1][col - 1] = value;
    return;
}

int Matrix::getRows() const{
    return rows;
}

int Matrix::getColumns() const{
    return columns;
}

bool Matrix::isValid() const{
    return legal;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    if (mat.legal){
        for (int i {0}; i < mat.rows; ++i){
            for (int j {0}; j < mat.columns; ++j){
                os << mat.totMatr[i][j] << " ";
            }
            os << std::endl;
        }
    }
    return os;
}

Matrix Matrix::operator+=(const Matrix& mat2){
    if (rows == mat2.rows && columns == mat2.columns && legal && mat2.legal){
        for (int i {0}; i < rows; ++i){
            for (int j {0}; j < columns; ++j){
                totMatr[i][j] += mat2.totMatr[i][j];
            }
        }
    }
    else{
        legal = false;
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& mat1){
    Matrix mat2 = *this;
    mat2 += mat1;
    return mat2;
}

Matrix& Matrix::operator=(Matrix rhs){
        std::swap(totMatr, rhs.totMatr);
        rows = rhs.getRows();
        columns = rhs.getColumns();
        legal = rhs.isValid();
        return *this;
    }