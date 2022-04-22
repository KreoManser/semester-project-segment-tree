#include "segment_tree.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  SegmentTree::SegmentTree(int size, int *array) {
    if (size > 0) {
      size_ = size;
      array_ = array;
      tree_ = new int [4 * size_] {};
      modification_ = new int [4 * size_] {};
      SegmentTree::build_tree_(1, 0, size_ - 1);
    }
  }

  void SegmentTree::build_tree_(int vert, int lp, int rp) {
    if (lp == rp) {
      tree_[vert] = array_[lp];
    } else {
      int tm = (lp + rp) / 2;
      SegmentTree::build_tree_(vert * 2, lp, tm);
      SegmentTree::build_tree_(vert * 2 + 1, tm + 1, rp);
      tree_[vert] = tree_[vert * 2] + tree_[vert * 2 + 1];
    }
  }

  SegmentTree::~SegmentTree() {
    if (size_ > 0) {
      delete[] array_;
      delete[] tree_;
      delete[] modification_;
      array_ = nullptr;
      tree_ = nullptr;
      modification_ = nullptr;
      size_ = 0;
    }
  }

  int SegmentTree::size() const {
    return size_;
  }

}  // namespace itis