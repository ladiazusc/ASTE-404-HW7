#ifndef _MAT_H
#define _MAT_H

#include <vector>
#include <stdexcept>
#include "Vec.h"

// vector subtraction c = a - b
/**
 * @brief Implements subtraction of two vectors.
 * 
 * @param a The first vector.
 * @param b The second vector.
 * @return The result of vector subtraction.
 * 
 * \f$ c = a - b = <a_1 - b_1, a_2 - b_2, a_3 - b_3> \f$
 */
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> c(a.size());
    for (size_t i = 0; i < a.size(); i++) c[i] = a[i] - b[i];
    return c;
}

// vector addition c = a + b
/**
 * @brief Implements addition of two vectors.
 * 
 * @param a The first vector.
 * @param b The second vector.
 * @return The result of vector addition.
 * 
 * \f$ c = a + b = <a_1 + b_1, a_2 + b_2, a_3 + b_3> \f$
 */
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> c(a.size());
    for (size_t i = 0; i < a.size(); i++) c[i] = a[i] + b[i];
    return c;
}

// vector scaling c = a * s
/**
 * @brief Implements scaling of a vector by a scalar.
 * 
 * @param a The vector to scale.
 * @param s The scalar value.
 * @return The scaled vector.
 * 
 * \f$ c = a * s = <a_1 * s, a_2 * s, a_3 * s> \f$
 */
std::vector<double> operator*(const std::vector<double>& a, double s) {
    std::vector<double> c(a.size());
    for (size_t i = 0; i < a.size(); i++) c[i] = a[i] * s;
    return c;
}

// matrix base class, specifies the interface to be implemented
/**
 * @class Mat
 * @brief Abstract base class representing a matrix.
 */
class Mat {
public:
    /**
     * @brief Construct a new Mat object.
     * 
     * @param nu The number of rows (unknowns).
     */
    Mat(size_t nu) : nu{ nu } {}

    virtual ~Mat() {}

    /**
     * @brief Accesses an element in the matrix.
     * 
     * @param i Row index.
     * @param j Column index.
     * @return Reference to the element at (i, j).
     */
    virtual double& operator()(int i, int j) = 0;

    /**
     * @brief Accesses an element in the matrix (const version).
     * 
     * @param i Row index.
     * @param j Column index.
     * @return The element at (i, j).
     */
    virtual double operator()(int i, int j) const = 0;

    /**
     * @brief Computes the dot product of a matrix row with a vector.
     * 
     * @param x The vector.
     * @param r The row index.
     * @return The dot product result.
     * 
     * \f$ \text{dot}(x, r) = \sum_{c=0}^{nu-1} A[r][c] \cdot x[c] \f$
     */
    virtual double dot(const std::vector<double>& x, size_t r) const = 0;

    /**
     * @brief Returns the memory size of the matrix in bytes.
     * 
     * @return Size in bytes.
     */
    virtual size_t memsize() = 0;  // matrix size in bytes

    const size_t nu;  //!< Number of rows (unknowns)

    /**
     * @brief Computes the product of a matrix and a vector.
     * 
     * @param A The matrix.
     * @param x The vector.
     * @return The resulting vector from matrix-vector multiplication.
     * 
     * \f$ b = A \cdot x \f$
     */
    friend std::vector<double> operator*(const Mat& A, const std::vector<double>& x) {
        std::vector<double> b(A.nu);
        for (size_t u = 0; u < A.nu; u++)
            b[u] = A.dot(x, u);
        return b;
    }
};

/* Dense matrix, only good for small matrices! */
/**
 * @class DenseMat
 * @brief Dense matrix class that implements the Mat interface.
 */
class DenseMat : public Mat {
public:
    /**
     * @brief Construct a new DenseMat object.
     * 
     * @param nu The number of rows (unknowns).
     */
    DenseMat(size_t nu) : Mat{ nu } {
        // memory for coefficients
        a = new double*[nu];
        for (size_t i = 0; i < nu; i++)
            a[i] = new double[nu];

        // initialize all to zero
        for (size_t i = 0; i < nu; i++)
            for (size_t j = 0; j < nu; j++)
                a[i][j] = 0;
    }

    /**
     * @brief Destroy the DenseMat object.
     */
    ~DenseMat() {
        for (size_t i = 0; i < nu; i++)
            delete[] a[i];
        delete[] a;
    }

    /**
     * @brief Accesses an element in the matrix.
     * 
     * @param i Row index.
     * @param j Column index.
     * @return Reference to the element at (i, j).
     */
    double& operator()(int i, int j) { return a[i][j]; }

    /**
     * @brief Accesses an element in the matrix (const version).
     * 
     * @param i Row index.
     * @param j Column index.
     * @return The element at (i, j).
     */
    double operator()(int i, int j) const { return a[i][j]; }

    /**
     * @brief Computes the dot product of a matrix row with a vector.
     * 
     * @param x The vector.
     * @param r The row index.
     * @return The dot product result.
     * 
     * \f$ \text{dot}(x, r) = \sum_{c=0}^{nu-1} A[r][c] \cdot x[c] \f$
     */
    double dot(const std::vector<double>& x, size_t r) const {
        double sum = 0;
        for (size_t c = 0; c < nu; c++)
            sum += a[r][c] * x[c];
        return sum;
    }

    /**
     * @brief Returns the memory size of the matrix in bytes.
     * 
     * @return Size in bytes.
     */
    size_t memsize() { return nu * nu * sizeof(double); }

protected:
    double** a;  //!< Coefficients, [nu][nu]
};

/* Sparse matrix with up to 7 non-zero values per row */
/**
 * @class SparseMat
 * @brief Sparse matrix class that implements the Mat interface.
 */
class SparseMat : public Mat {
public:
    /**
     * @brief Construct a new SparseMat object.
     * 
     * @param nu The number of rows (unknowns).
     */
    SparseMat(size_t nu) : Mat{ nu } {
        // memory for coefficients
        a = new double*[nu];
        for (size_t i = 0; i < nu; i++)
            a[i] = new double[max_vals];

        // memory for column indexes
        c = new int*[nu];
        for (size_t i = 0; i < nu; i++)
            c[i] = new int[max_vals];

        // clear data, column set to -1 are not set
        for (size_t i = 0; i < nu; i++)
            for (size_t j = 0; j < max_vals; j++) {
                c[i][j] = -1;
                a[i][j] = 0;
            }
    }

    /**
     * @brief Destroy the SparseMat object.
     */
    ~SparseMat() {
        for (size_t i = 0; i < nu; i++)
            delete[] a[i];
        delete[] a;

        for (size_t i = 0; i < nu; i++)
            delete[] c[i];
        delete[] c;
    }

    /**
     * @brief Accesses an element in the matrix.
     * 
     * @param i Row index.
     * @param j Column index.
     * @return Reference to the element at (i, j).
     */
    double& operator()(int i, int j) {
        // search for the sparse column corresponding to full matrix column j
        for (int v = 0; v < max_vals; v++) {
            // did we reach an empty slot? If so, make it correspond to column j
            if (c[i][v] < 0) c[i][v] = j;

            // does this sparse column map to j? If so, return the coeff
            if (c[i][v] == j) return a[i][v];
        }

        // getting here implies that all max_val slots are already occupied by columns other than j
        throw std::runtime_error("Sparse matrix too small!");
        return a[i][0];  // just to avoid a warning
    }

    /**
     * @brief Accesses an element in the matrix (const version).
     * 
     * @param i Row index.
     * @param j Column index.
     * @return The element at (i, j).
     */
    double operator()(int i, int j) const {
        // search for the sparse column corresponding to full matrix column j
        for (size_t v = 0; v < max_vals; v++) {
            // did we reach an empty slot? If so, make it correspond to column j
            if (c[i][v] < 0) c[i][v] = j;

            // does this sparse column map to j? If so, return the coeff
            if (c[i][v] == j) return a[i][v];
        }

        // getting here implies that all max_val slots are already occupied by columns other than j
        return 0;  // If not found, return 0 (assume implicit zero)
    }

    /**
     * @brief Computes the dot product of a matrix row with a vector.
     * 
     * @param x The vector.
     * @param r The row index.
     * @return The dot product result.
     * 
     * \f$ \text{dot}(x, r) = \sum_{v=0}^{\text{max\_vals}-1} a[r][v] \cdot x[c[r][v]] \f$
     */
    double dot(const std::vector<double>& x, size_t r) const {
        double sum = 0;
        // loop up to max_vals time and until c[r][v] becomes negative
        for (size_t v = 0; v < max_vals && c[r][v] >= 0; v++)
            sum += a[r][v] * x[c[r][v]];  // c[v] is effective the "j" in full matrix
        return sum;
    }

    /**
     * @brief Returns the memory size of the matrix in bytes.
     * 
     * @return Size in bytes.
     */
    size_t memsize() { return nu * max_vals * sizeof(double); }

protected:
    static constexpr int max_vals = 7;   //!< Max non-zeros per row
    double** a;  //!< Coefficients, [nu][7]
    int** c;    //!< Columns in full matrix, [nu][7], -1 if not set
};

#endif
