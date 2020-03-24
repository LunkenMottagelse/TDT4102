#pragma once
#include <array>
#include <iostream>
#include <utility>

class Matrix{
private:
    int rows;
    int columns;
    double** totMatr;
    bool legal;

public:
    class Invalid_req{};
    Matrix() : legal {false}, rows{0}, columns{0} {}
    Matrix(int nRows, int nColumns) : legal {true}, rows{nRows}, columns{nColumns} {
        totMatr = new double*[rows];

        for (int i {0}; i < rows; ++i){
            totMatr[i] = new double[columns];
            for (int j {0}; j < columns; ++j){
                totMatr[i][j] = 0;
            }
        }
    }
    explicit Matrix(int nRows) : Matrix{nRows, nRows} {
        for (int i {0}; i < nRows; ++i){
            totMatr[i][i] = 1;
        }
    }
    Matrix(const Matrix& rhs){
        rows = rhs.getRows();
        columns = rhs.getColumns();
        legal = rhs.isValid();
        totMatr = new double*[rows];

        for (int i {0}; i < rows; ++i){
            totMatr[i] = new double[columns];
            for (int j {0}; j < columns; ++j){
                totMatr[i][j] = rhs.get(i, j);
            }
        }
    }
    Matrix& operator=(Matrix rhs);

    Matrix operator+=(const Matrix& mat2);

    Matrix operator+(const Matrix& mat1);

    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const;
    int getColumns() const;
    bool isValid() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
    
    ~Matrix(){
        delete[] totMatr;
    }
};
