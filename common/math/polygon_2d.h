#ifndef COMMON_MATH_POLYGON_2D_H_
#define COMMON_MATH_POLYGON_2D_H_

#include <vector>

#include "common/math/vec_2.h"
#include "common/math/segment_2d.h"

namespace qeuler {

class Polygon2D {
 public:
  explicit Polygon2D(std::vector<Vec2d> points) : points_(std::move(points)) {

  }
  ~Polygon2D() {}

  bool IsConvex() const {
    return is_convex_;
  }

  double Area() const {

  }

  double DistanceTo(const Vec2d& point) const {

  }

  double DistanceTo(const Segment2D& segment) const {

  }

  double DistanceTo(const Polygon2D& polygon) const {

  }

  const std::vector<Vec2d>& points() const {
    return points_;
  }

  private:
  bool is_convex_ = false;
  std::vector<Vec2d> points_;
};

}  // namespace qeuler

#endif  // COMMON_MATH_POLYGON_2D_H_