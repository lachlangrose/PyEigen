#ifndef SPARSE_WRAPPER_H
#define SPARSE_WRAPPER_H
#include <Eigen/Sparse>
namespace PyEigen {
using namespace Eigen;
class LeastSquaresCG {
       public:
	LeastSquaresCG();
	 void compute(SparseMatrix<double> A);
	 VectorXd solve(VectorXd); 
}
#endif  // SPARSE_WRAPPER_H
