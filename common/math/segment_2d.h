#ifndef COMMON_MATH_SEGMENT_2D_H_
#define COMMON_MATH_SEGMENT_2D_H_

#include <cmath>

#include "common/math/vec_2.h"

namespace qeuler {

class Segment2D {
 public:
    Segment2D(const Vec2d& start_point, const Vec2d& end_point)
        : start_point_(start_point), end_point_(end_point) {}
    ~Segment2D() = default;

    double Length() const {
        return (end_point_ - start_point_).Norm();
    }

    double Heading() const {
        return (end_point_ - start_point_).Heading();
    }

    double DistanceTo(const Vec2d& point) const {

    }

    double DistanceTo(const Segment2D& segment) const {
    
    }

    bool IsOverlap(const Segment2D& segment) const {
    
    }

    bool ComputeIntersectionPoint(const Segment2D& segment, Vec2d* intersection_point) const {

    }

    Vec2d ComputeProjectionPoint(const Vec2d& point) const {

    }

    const Vec2d& start() const {
        return start_point_;
    }

    const Vec2d& end() const {
        return end_point_;
    }

 private:
    Vec2d start_point_;
    Vec2d end_point_;
};

}  // namespace qeuler

#endif  // COMMON_MATH_SEGMENT_2D_H_