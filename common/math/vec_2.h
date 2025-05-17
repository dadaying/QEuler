#ifndef COMMON_MATH_VEC_2_H_
#define COMMON_MATH_VEC_2_H_

#include <cmath>
#include <string>

namespace qeuler {

template<class T>
class Vec2 {

public:
    Vec2() = default;
    Vec2(const T x, const T y) : x_(x), y_(y) {}
    ~Vec2() = default;

    static Vec2<T> Zero() {
        return Vec2<T>(0.0, 0.0);
    }

    // Common length compute.
    double Square() const {
        return x_ * x_ + y_ * y_;
    }

    double Norm() const {
        return std::sqrt(Square());
    }

    double Length() const {
        return Norm();
    }

    double DistanceTo(const Vec2<T>& other) const {
        return (*this - other).Length();
    }

    // Operator overloading.
    Vec2<T> operator+(const Vec2<T>& other) const {
        return Vec2<T>(x_ + other.x_, y_ + other.y_);
    }

    Vec2<T> operator-(const Vec2<T>& other) const {
        return Vec2<T>(x_ - other.x_, y_ - other.y_);
    }

    Vec2<T> operator-() const {
        return Vec2<T>(-x_, -y_);
    }

    Vec2<T> operator*(const double factor) const {
        return Vec2<T>(x_ * factor, y_ * factor);
    }

    Vec2<T> operator/(const double factor) const {
        return Vec2<T>(x_ / factor, y_ / factor);
    }

    // Vector compute.
    double Dot(const Vec2<T>& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    double Cross(const Vec2<T>& other) const {
        return x_ * other.y_ - y_ * other.x_;
    }

    double Heading() const {
        return std::atan2(y_, x_);
    }

    double Angle(const Vec2<T>& other) const {
        return std::atan2(Cross(other), Dot(other));
    }

    Vec2<T> Unit() const {
        const auto factor = 1.0 / Length();
        return Vec2<T>(x_ * factor, y_ * factor);
    }

    // Along the direction of the vector, the left side is positive.
    Vec2<T> Normal() const {
        return Vec2<T>(-y_, x_);
    }

    // Counterclockwise rotation is positive.
    //               y
    //         p_1   |     p_0
    //          \    |    /
    //           \   |   /
    //            \  |  /
    //             \ | /  angle=a
    //     -----------------------> x
    //             o |
    //               |
    //               |
    //               |
    //               |
    // o coordinate is the origin.
    // p_0 is the start point, p_1 is the end point.
    // p_0 -> o -> x angle is a
    // p_0 -> o -> p_1 angle is b
    // p_0 o length is r
    // p_1.x = r * cos(a + b) = r * (cosa * cosb - sina * sinb) = p0.x * cosb - p0.y * sinb
    // p_1.y = r * sin(a + b) = r * (sina * cosb + cosa * sinb) = p0.y * cosb + p0.x * sinb
    Vec2<T> Rotate(const double rad_angle) const {
        const double cos_theta = std::cos(rad_angle);
        const double sin_theta = std::sin(rad_angle);
        return Vec2<T>(x_ * cos_theta - y_ * sin_theta, x_ * sin_theta + y_ * cos_theta);
    }

    // Debug functions.
    std::string DebugString() const {
        return "(x, y)=(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    }

    // TODO(liying): Add full precision debug.

    // Data member functions.
    T x() const {
        return x_;
    }

    T& x() {
        return x_;
    }

    T y() const {
        return y_;
    }

    T& y() {
        return y_;
    }

private:
    T x_ = 0.0;
    T y_ = 0.0;
};

using Vec2d = Vec2<double>;
using Vec2f = Vec2<float>;
using Vec2i = Vec2<int>;

}  // namespace qeuler

#endif  // COMMON_MATH_VEC_2_H_