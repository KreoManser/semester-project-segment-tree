#include "segment_tree.hpp"
#include "iostream"

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

  void SegmentTree::push_back_(int vert) {
    if (size_ == 0) { return; }

    if ((modification_[vert] != 0) && (vert * 2 + 2 < 4 * size_)) {
      if (modification_[vert * 2] != 0) { modification_[vert * 2] *= modification_[vert]; }
      else { modification_[vert * 2] = modification_[vert]; }
      if (modification_[vert * 2 + 1] != 0) { modification_[vert * 2 + 1] *= modification_[vert]; }
      else { modification_[vert * 2 + 1] = modification_[vert]; }

      tree_[vert] = tree_[vert] * modification_[vert];
      modification_[vert] = 0;
    }
  }

  int SegmentTree::get_min(int l, int r, int vertex, int lp, int rp) {
    push_back_(vertex);
    if ((l <= lp && rp <= r) && (lp == rp)) { return tree_[lp]; }
    if (rp < l || r < lp) { return INT_MAX; }

    int tm = (lp + rp) / 2;
    return std::min(get_min(l, r, vertex * 2, lp, tm), get_min(l, r, vertex * 2 + 1, tm + 1, rp));
  }

  int SegmentTree::get_max(int l, int r, int vertex, int lp, int rp) {
    push_back_(vertex);
    if ((l <= lp && rp <= r) && (lp == rp)) { return tree_[lp]; }
    if (rp < l || r < lp) { return INT_MIN; }

    int tm = (lp + rp) / 2;
    return std::max(get_max(l, r, vertex * 2, lp, tm), get_max(l, r, vertex * 2 + 1, tm + 1, rp));
  }

  int SegmentTree::get_sum(int vertex, int tl, int tr, int lp, int rp) {
    push_back_(vertex);
    if (lp > rp) { return 0; }
    if (lp == tl || rp == tr) { return tree_[vertex]; }

    int tm = (tl + rp) / 2;
    return get_sum(vertex * 2, tl, tm, lp, (rp < tm) ? rp : tm) +
           get_sum(vertex * 2 + 1,tm + 1, tr, (lp > tm + 1) ? lp : tm + 1, rp);
  }

//  void SegmentTree::update(int vertex, int lp, int rp, int idx, int value) {
//    push_back_(vertex);
//    if (lp == rp) { tree_[vertex] = value; }
//    else {
//      int tm = (lp + rp) / 2;
//      if (index <= tm) { update(vertex * 2, lp, tm, index, value) }
//    }
//  }

  int SegmentTree::size() const {
    return size_;
  }

}  // namespace itis