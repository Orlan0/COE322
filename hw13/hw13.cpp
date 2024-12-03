//modifiedmatvec
//Name: Orlan Oconer
//TACC username: orlan
//EID: ojo366



#include <iostream>
using std::cout, std::cin;
#include <chrono>
#include <string>
using std::string;

#include <numeric>
using std::accumulate;

#include <Eigen/Dense>
using namespace Eigen;
// ::Matrix, Eigen::Vector;

/*
 * Jacobi Iterative method (Basic)
 */
template<typename MatrixType, typename VectorType>
void JacobiSolve1(MatrixType A, VectorType sol, VectorType rhs) {
  auto tmp{sol};
  int siz = A.rows();
  
  // Set initial guess to identically one
  for (auto& v : sol)
    v = 1.;

  // Perform Jacobi iteration
  for (int it = 0; it < 10; ++it) { // Replacing iota with a standard loop
    for (int i = 0; i < siz; ++i) {
      double sigma = 0.0;
      for (int j = 0; j < siz; ++j) {
        if (i != j) {
          sigma += A(i, j) * sol(j);
        }
      }
      tmp(i) = (rhs(i) - sigma) / A(i, i); // Jacobi update
    }
    sol = tmp; // Update solution
    cout << "it: " << it << '\n' << sol << '\n';
  }
}

/*
 * Jacobi Iterative method (Using Eigen blocks)
 */
template<typename MatrixType, typename VectorType>
void JacobiSolve2(MatrixType A, VectorType sol, VectorType rhs) {
  auto tmp{sol};
  int siz = A.rows();
  
  // Set initial guess to identically one
  for (auto& v : sol)
    v = 1.;

  // Perform Jacobi iteration
  for (int it = 0; it < 10; ++it) { // Replacing iota with a standard loop
    for (int i = 0; i < siz; ++i) {
      // Use Eigen's block() to compute sums
      double sigma = (A.block(i, 0, 1, i) * sol.head(i)).sum() +
                     (A.block(i, i + 1, 1, siz - i - 1) * sol.tail(siz - i - 1)).sum();
      tmp(i) = (rhs(i) - sigma) / A(i, i); // Jacobi update
    }
    sol = tmp; // Update solution
    cout << "it: " << it << '\n' << sol << '\n';
  }
}

int main() {
  const int siz = 5;
  Matrix<double, siz, siz> A;
  Vector<double, siz> sol, rhs, tmp;

  cout << "Matrix size: " << A.rows() << "," << A.cols() << " (" << A.size() << ")\n";

  // Initialize rhs vector and A matrix
  for (auto& v : rhs)
    v = 1.;
  cout << rhs << '\n';

  for (int row = 0; row < siz; ++row) { // Replace iota with standard loop
    sol(row) = static_cast<double>(row); // Exact solution: [0, 1, 2, ...]
    A(row, row) = siz; // Diagonal dominance
    for (int col = 0; col < siz; ++col) { // Replace iota with standard loop
      if (row == col) continue;
      A(row, col) = -1; // Off-diagonal elements
    }
  }

  cout << "sol:\n" << sol << '\n';
  rhs = A * sol;
  cout << "rhs:\n" << rhs << '\n';

  cout << "================ Solve 1\n";
  JacobiSolve1(A, sol, rhs); // Basic implementation

  cout << "================ Solve 2\n";
  JacobiSolve2(A, sol, rhs); // Using block

  Matrix<float, Dynamic, Dynamic> Af(20, 20);
  // or: MatrixXf Af(20,20);

  return 0;
}
