#ifndef COMMON_ALGORITHM_UNION_FIND_H_
#define COMMON_ALGORITHM_UNION_FIND_H_

#include <vector>

namespace qeuler {

class UnionFind {
 public:
  explicit UnionFind(const int n) {
    parent_.resize(n);
    rank_.resize(n);
    for (int i = 0; i < n; ++i) {
      parent_[i] = i;
      rank_[i] = 1;
    }
  }
  ~UnionFind() = default;

  int Find(const int x) {
    if (parent_[x] == x) {
      return x;
    }
    const auto root = Find(parent_[parent_[x]]);
    // Path compression.
    parent_[x] = root;
    return root;
  }

  bool Merge(const int x, const int y) {
    const auto root_x = Find(x);
    const auto root_y = Find(y);
    if (root_x == root_y) {
      return false;
    }
    // Merge by rank.
    if (rank_[root_x] <= rank_[root_y]) {
      parent_[root_x] = root_y;
    } else {
      parent_[root_y] = root_x;
    }
    if (rank_[root_x] == rank_[root_y]) {
      ++rank_[root_y];
    }
    return true;
  }

  int SetSize() const {
    int set_size = 0;
    for (int i = 0; i < parent_.size(); ++i) {
      if (i == parent_[i]) {
        ++set_size;
      }
    }
    return set_size;
  }

  bool Connected(const int x, const int y) { return Find(x) == Find(y); }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

}  // namespace qeuler

#endif  // COMMON_ALGORITHM_UNION_FIND_H_