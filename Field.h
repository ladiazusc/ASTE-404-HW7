#ifndef _FIELD_H
#define _FIELD_H

#include "Vec.h"
#include <ostream>

// 3D data container
/**
 * @class _Field
 * @brief A 3D data container class that manages a 3D array of type T.
 *
 * @tparam T The data type of the elements stored in the field.
 */
template<typename T>
class _Field {
public:
    /**
     * @brief Constructs a new _Field object.
     *
     * @param nn A 3D vector representing the dimensions of the field.
     */
    _Field(int3 nn) : nn{nn}, ni{nn[0]}, nj{nn[1]}, nk{nn[2]} {
        // Allocate memory
        data = new T**[ni];
        for (int i = 0; i < ni; i++) {
            data[i] = new T*[nj];
            for (int j = 0; j < nj; j++) data[i][j] = new T[nk];
        }
    }

    /**
     * @brief Destroys the _Field object and deallocates memory.
     */
    ~_Field() {
        if (data == nullptr) return;

        // Deallocates memory
        for (int i = 0; i < ni; i++) {
            for (int j = 0; j < nj; j++) delete[] data[i][j];
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }

    /**
     * @brief Accesses the 2D array at the specified index.
     *
     * @param i The index of the first dimension.
     * @return A pointer to the 2D array at index i.
     */
    T** operator[](int i) { return data[i]; }

    /**
     * @brief Accesses the 2D array at the specified index (const version).
     *
     * @param i The index of the first dimension.
     * @return A pointer to the 2D array at index i (const).
     */
    const T** operator[](int i) const { return (const T**)data[i]; }

    /**
     * @brief Outputs the contents of the field to an output stream.
     *
     * @param out The output stream to write to.
     * @param o The _Field object to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream &out, const _Field<T> &o) {
        for (int i = 0; i < o.ni; i++)
            for (int j = 0; j < o.nj; j++)
                for (int k = 0; k < o.nk; k++)
                    out << o[i][j][k] << " ";

        return out;
    }

    const int3 nn;  //!< Dimensions of the field (3D vector)
    const int ni;   //!< Size of the first dimension
    const int nj;   //!< Size of the second dimension
    const int nk;   //!< Size of the third dimension

protected:
    T ***data = nullptr;  //!< 3D array of data
};

// Type alias for _Field with double precision
using Field = _Field<double>;

#endif
