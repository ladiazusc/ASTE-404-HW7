#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
#include <gtest/gtest.h>

#include "Vec.h"
#include "Mat.h"

using namespace std;

struct World {
  double3 x0;	// origin
  double3 dh;   // cell spacing
  int3 nn;  	// number of nodes
  int U(int i, int j, int k) {return k*nn[1]*nn[0]+j*nn[0]+i;}
};

//prototypes
void saveVTI(const World &world, const vector<double> &field);
void solveGS(const Mat &mat, vector<double>&x, const vector<double>&b,
		     int max_it = 10000, double tol = 1e-4);



int runTests(int argc, char **args) {
	testing::InitGoogleTest(&argc, args);
	return RUN_ALL_TESTS();
}


/**
 * @brief Main function to initialize world parameters and solve a linear system.
 * 
 * Initializes a 3D world, sets up a sparse matrix, solves a linear system using the 
 * Gauss-Seidel method, and saves the results in VTI format.
 * 
 * @param argc Number of command line arguments.
 * @param args Array of command line arguments.
 * @return int Returns 0 upon successful completion.
 */
int main(int argc, char **args) {
    runTests(argc, args);
    
    World world;
    world.x0 = {0, 0, 0};  //!< Initialize mesh origin
    world.dh = {0.1, 0.1, 0.1}; //!< Cell spacing
    world.nn = {21, 21, 21}; //!< Number of nodes in i, j, k

    int ni = world.nn[0];
    int nj = world.nn[1];
    int nk = world.nn[2];
    int nu = ni * nj * nk;

    SparseMat A(nu); //!< Coefficient matrix
    vector<double> T(nu);
    vector<double> b(nu);

    // Set matrix coefficients
    for (int i = 0; i < ni; i++)
        for (int j = 0; j < nj; j++)
            for (int k = 0; k < nk; k++) {
                int u = world.U(i, j, k);
                if (i == 0 || i == ni - 1 || j == 0 || j == nj - 1 || k == 0 || k == nk - 1) {
                    A(u, u) = 1.0;  //!< Set 1 on the diagonal
                    b[u] = 0;
                    if (i == 0 || j == 0) b[u] = 10;
                } else {
                    //!< Standard 7-point stencil
                    double dx = world.dh[0];
                    double dy = world.dh[1];
                    double dz = world.dh[2];
                    A(u, u - ni * nj) = 1 / (dz * dz);
                    A(u, u - ni) = 1 / (dy * dy);
                    A(u, u - 1) = 1 / (dx * dx);
                    A(u, u) = -2 * (1 / (dx * dx) + 1 / (dy * dy) + 1 / (dz * dz));
                    A(u, u + 1) = 1 / (dx * dx);
                    A(u, u + ni) = 1 / (dy * dy);
                    A(u, u + ni * nj) = 1 / (dz * dz);
                }
            }

    auto t1 = chrono::high_resolution_clock::now();
    solveGS(A, T, b, 10000, 1e-5);
    auto t2 = chrono::high_resolution_clock::now();

    saveVTI(world, T);
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "Done in " << time_span.count() << " seconds using " << A.memsize() / (1024.0 * 1024) << " Mb of RAM" << endl;
    return 0;
}


/**
 * @brief Solves A*x=b using the Gauss-Seidel Successive Over-Relaxation (SOR) method.
 * 
 * This function implements the Gauss-Seidel solver for the linear system:
 * \f[
 * \textbf{A} \vec{x} = \vec{b}
 * \f]
 * 
 * @param A Coefficient matrix.
 * @param x Vector to hold the solution (output).
 * @param b Right-hand-side vector.
 * @param max_it Maximum number of solver iterations (default: 10000).
 * @param tol Solver tolerance (default: 1e-4).
 */
void solveGS(const Mat &A, vector<double>&x, const vector<double>&b, int max_it, double tol) {
	cout<<"In solveGS"<<endl;
	for (int n=0;n<max_it;n++) {
		for (size_t r=0;r<A.nu;r++) {
			double dot = A.dot(x,r);  // A[r] times x dot product
			double g = (b[r] - (dot - A(r,r)*x[r]))/A(r,r);
			x[r] = x[r] + 1.4*(g-x[r]);		// SOR
		}

		if (n%25==0) {
			double sum = 0;
			for (size_t u=0;u<A.nu;u++) {
				double r = b[u]-A.dot(x,u);
				sum+=r*r;
			}
			double norm = sqrt(sum/A.nu);
			if (n%500==0) cout<<"n: "<<n<<", L2: "<<norm<<endl;
			if (norm<tol) {cout<<"Converged in "<<n<<" iterations"<<endl;break;}
		}
	}
}

// writes out temperature field
void saveVTI(const World &world, const vector<double> &field)  {
	// output data
	ofstream out("field.vti");            //open output file
	out<<"<?xml version=\"1.0\"?>\n";
	out<<"<VTKFile type=\"ImageData\">\n";
	out<<"<ImageData WholeExtent=\"0 "<<world.nn[0]-1<<" 0 "<<world.nn[1]-1<<" 0 "<<world.nn[2]-1<<"\" "
	   <<"Origin=\""<<world.x0<<"\" Spacing=\""<<world.dh<<"\">\n";
	out<<"<Piece Extent=\"0 "<<world.nn[0]-1<<" 0 "<<world.nn[1]-1<<" 0 "<<world.nn[2]-1<<"\">\n";

	out<<"<PointData>\n";
	
	out<<"<DataArray Name=\"T (K)\" NumberOfComponents=\"1\" type=\"Float64\" format=\"ascii\">\n";
	for (const double &val:field) out<<val<<" ";
	out<<"</DataArray>\n";

	out<<"</PointData>\n";

	out<<"</Piece>\n";
	out<<"</ImageData>\n";
	out<<"</VTKFile>\n";
}
