#ifndef FIXED_ARRAY_HH
#define FIXED_ARRAY_HH

#include <algorithm>
#include <cassert>

namespace Itch {

  template <typename T, size_t N>
  struct Fixed_array {
    typedef T *iterator;
    typedef T const *const_iterator;
    
    void assign(iterator i_begin, iterator i_end) {
      assert(std::distance(i_begin, i_end) >= 0 && static_cast<size_t>(std::distance(i_begin, i_end)) <= N);
      std::copy(i_begin, i_end, begin());
    }
    
    Fixed_array<T, N> &operator=(Fixed_array<T, N> const &fbs) {
      std::copy(fbs.begin(), fbs.end(), begin());
      return *this;
    }

    T const &operator[](size_t idx) const {
      assert(idx < N);
      return data_[idx];
    }

    T &operator[](size_t idx) {
      assert(idx < N);
      return data_[idx];
    }

    iterator begin() {
      return &data_[0];
    }
    
    const_iterator begin() const {
      return &data_[0];
    }

    iterator end() {
      return &data_[N];
    }
    
    const_iterator end() const {
      return &data_[N];
    }
    
    T data_[N];
  };

}


#endif
