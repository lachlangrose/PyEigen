#include <pybind11/eigen.h>     //eigen
////#include <pybind11/iostream.h>  //auto conversion b/w stl and python types
//#include <pybind11/pybind11.h>
//#include <pybind11/stl.h>  //auto conversion b/w stl and python types
#include <Eigen/Sparse>
#include <Eigen/SPQRSupport>

//namespace py = pybind11;
////using namespace Eigen;
//class EigenLeastSquaresCG {
//       public:
//	EigenLeastSquaresCG() {}
//	void buildA(int _A) {}
//	//, std::vector<int> _row,
//	//	    std::vector<int> _col, int _c, int _nc) {
//	//	A = Eigen::SparseMatrix<double>(_c, _nc);
//	//	A.reserve(_A.size());
//	//	for (int i = 0; i < _A.size(); i++) {
//	//		A.insert(_row[i], _col[i]) = _A[i];
//	//	}
//	//}
//	void compute() { /*solver.compute(A);*/ }
//	//VectorXd solve(VectorXd B) { return solver.solve(B); }
//
//       private:
//	//LeastSquaresConjugateGradient<SparseMatrix<double> > solver;
//	//Eigen::SparseMatrix<double> A;
//};
//PYBIND11_MODULE(PyEigen, m) {
//	py::class_<EigenLeastSquaresCG>(m, "LeastSquaresConjugateGradient")
//	    .def(py::init<>())
//	    //.def("compute", &EigenLeastSquaresCG::compute)
//	    //.def("solve", &EigenLeastSquaresCG::solve);
//		.def("buildA",(&EigenLeastSquaresCG::buildA);
//};
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
Eigen::VectorXd lsqrcg(Eigen::SparseMatrix<double> A,Eigen::VectorXd B) {
		Eigen::LeastSquaresConjugateGradient<Eigen::SparseMatrix<double> > solver;
		solver.compute(A);
		return solver.solve(B);
}
Eigen::VectorXd lsqrspqr(Eigen::SparseMatrix<double> A,Eigen::VectorXd B) {
		Eigen::SPQR<Eigen::SparseMatrix<double> > spqrsolver(A);
		return spqrsolver.solve(B);
}


PYBIND11_MODULE(eigensparse, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("lsqrcg", &lsqrcg, "Solve Ax=B using Eigen CG sparse iterative solver");
    m.def("lsqspqr", &lsqrspqr, "Solve Ax=B using SPQR sparse iterative solver");

}
