#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    const double sqrt_5 = std::sqrt(5);
    const double fib = std::pow((1 + sqrt_5) * 0.5, n) / sqrt_5;

    return static_cast<int64_t>(std::round(fib));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // buffer previous fibonacci numbers
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    int64_t fib = 0;

    for (int i = 1; i < n; ++i) {
      fib = fib_prev + fib_curr;
      fib_prev = fib_curr;
      fib_curr = fib;
    }

    return fib;
  }

  int64_t fib_recursive(int n) {

    if (n <= 1) {
      return n;
    }

    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    // memoization
    cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);

    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    const Matrix2x2 res = matrix_power(FibMatrix, n - 1);

    return res[1][1];
  }

}  // namespace assignment
