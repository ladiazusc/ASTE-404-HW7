#ifndef _VEC_H
#define _VEC_H

#include <ostream>

/**
 * @brief 3D vector class with template data type.
 * 
 * @tparam T Data type of the vector components.
 */
template<typename T>
struct _vec3 {
  /**
   * @brief Constructs a vector with given components.
   * 
   * @param x The x component.
   * @param y The y component.
   * @param z The z component.
   */
  _vec3(T x, T y, T z) : d{x, y, z} {}

  /**
   * @brief Default constructor that initializes vector components to zero.
   */
  _vec3() : _vec3(0, 0, 0) {}

  /**
   * @brief Implements the addition of two vectors.
   * 
   * This function adds the components of two vectors and modifies the calling vector.
   * 
   * @param o The other vector to add.
   * \f$ \vec{v1} + \vec{v2} = (v1_x + v2_x, v1_y + v2_y, v1_z + v2_z) \f$
   */
  void operator+= (const _vec3<T> &o) { d[0] += o.d[0]; d[1] += o.d[1]; d[2] += o.d[2]; }

  /**
   * @brief Implements the subtraction of two vectors.
   * 
   * This function subtracts the components of another vector from the calling vector.
   * 
   * @param o The other vector to subtract.
   * \f$ \vec{v1} - \vec{v2} = (v1_x - v2_x, v1_y - v2_y, v1_z - v2_z) \f$
   */
  void operator-= (const _vec3<T> &o) { d[0] -= o.d[0]; d[1] -= o.d[1]; d[2] -= o.d[2]; }

  /**
   * @brief Accesses a vector component by index.
   * 
   * @param i The index (0 for x, 1 for y, 2 for z).
   * @return T& Reference to the component.
   */
  T& operator[] (int i) { return d[i]; }

  /**
   * @brief Read-only access to a vector component by index.
   * 
   * @param i The index (0 for x, 1 for y, 2 for z).
   * @return T The component value.
   */
  T operator[] (int i) const { return d[i]; }

  /**
   * @brief Scalar multiplication.
   * 
   * Multiplies the vector by a scalar value.
   * 
   * @param a Vector to scale.
   * @param s Scalar value.
   * @return _vec3<T> The scaled vector.
   * \f$ \vec{v} * s = (v_x * s, v_y * s, v_z * s) \f$
   */
  friend _vec3<T> operator*(const _vec3<T> &a, double s) {
    return _vec3<T>(a.d[0] * s, a.d[1] * s, a.d[2] * s);
  }

  /**
   * @brief Outputs the vector components.
   * 
   * @param out Output stream.
   * @param o Vector to output.
   * @return std::ostream& The output stream.
   */
  friend std::ostream& operator<<(std::ostream &out, const _vec3<T> &o) {
    out << o.d[0] << " " << o.d[1] << " " << o.d[2];
    return out;
  }

protected:
  T d[3]; //!< Vector components (x, y, z).
};

// Define "nicknames" for common types of vectors.
using double3 = _vec3<double>;
using int3 = _vec3<int>;

#endif
