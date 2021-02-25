#include <eigen3/Eigen/Sparse>
#include <eigen3/Eigen/SparseLU>
#include <vector>
#include <iostream>

using namespace std;
typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> T;


void forward(double *out, const double *u, const double *f, const double *kappa, 
            double dt, double dx, int m, int n){
    vector<T> triplets;
    Eigen::VectorXd rhs((m+1)*(n+1)); 
    for(int i=0;i<(m+1)*(n+1);i++) rhs[i] = u[i] + f[i];
    for(int i=0;i<m+1;i++)
      for(int j=0;j<n+1;j++){
        if (i==0 || i==m || j==0 || j==n){
          triplets.push_back(T(j*(m+1)+i, j*(m+1)+i, 1.0));
          rhs[j*(m+1)+i] = 0.0;
          continue;
        }
        int idx = j*(m+1)+i;
        double lam = kappa[idx]*dt/dx/dx;
        triplets.push_back(T(idx, idx, 1+4*lam));
        if (i<m-1)
          triplets.push_back(T(idx, j*(m+1)+(i+1), -lam));
        if (i>1)
          triplets.push_back(T(idx, j*(m+1)+(i-1), -lam));
        if (j>1)
          triplets.push_back(T(idx, (j-1)*(m+1)+i, -lam));
        if (j<n-1)
          triplets.push_back(T(idx, (j+1)*(m+1)+i, -lam));
      }

      SpMat A((m+1)*(n+1), (m+1)*(n+1));
      A.setFromTriplets(triplets.begin(), triplets.end());
    

      Eigen::SparseLU<SpMat> solver;
      solver.analyzePattern(A);
      solver.factorize(A);
      Eigen::VectorXd x = solver.solve(rhs);

      for(int i=0;i<(m+1)*(n+1);i++) out[i] = x[i];
}

void backward(
  double *grad_u, double *grad_f, double *grad_kappa, 
  const double * grad_out, 
  const double *out, const double *u, const double *f, const double *kappa, 
  double dt, double dx, int m, int n
){
    vector<T> triplets;
    Eigen::VectorXd rhs((m+1)*(n+1)); 
    for(int i=0;i<(m+1)*(n+1);i++) rhs[i] = grad_out[i];

    for(int i=0;i<m+1;i++)
      for(int j=0;j<n+1;j++){
        if (i==0 || i==m || j==0 || j==n){
          triplets.push_back(T(j*(m+1)+i, j*(m+1)+i, 1.0));
          continue;
        }
        int idx = j*(m+1)+i;
        double lam = kappa[idx]*dt/dx/dx;
        triplets.push_back(T(idx, idx, 1+4*lam));
        if (i<m-1)
          triplets.push_back(T(idx, j*(m+1)+(i+1), -lam));
        if (i>1)
          triplets.push_back(T(idx, j*(m+1)+(i-1), -lam));
        if (j>1)
          triplets.push_back(T(idx, (j-1)*(m+1)+i, -lam));
        if (j<n-1)
          triplets.push_back(T(idx, (j+1)*(m+1)+i, -lam));
      }

      SpMat A((m+1)*(n+1), (m+1)*(n+1));
      A.setFromTriplets(triplets.begin(), triplets.end());
      auto At = A.transpose();
    

      Eigen::SparseLU<SpMat> solver;
      solver.analyzePattern(At);
      solver.factorize(At);
      Eigen::VectorXd g = -solver.solve(rhs);

      for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++){
          int idx = j*(m+1)+i;
          grad_kappa[idx] = 0.0;
          if (i==0 || i==m || j==0 || j==n){
            grad_f[idx] = 0.0;
            grad_u[idx] = 0.0;
          }
          else{
            grad_f[idx] = -g[idx];
            grad_u[idx] = -g[idx];
          }
            
        }
      

      for(int i=0;i<m+1;i++)
      for(int j=0;j<n+1;j++){
        if (i==0 || i==m || j==0 || j==n){
          continue;
        }
        int idx = j*(m+1)+i;
        double lam = kappa[idx]*dt/dx/dx;
        grad_kappa[idx] += 4*out[idx]*dt/dx/dx*g[idx];;
        if (i<m-1){
          grad_kappa[idx] += -out[j*(m+1)+(i+1)]*dt/dx/dx*g[idx];;
        }
        if (i>1){
          grad_kappa[idx] += -out[j*(m+1)+(i-1)]*dt/dx/dx * g[idx];
        }
        if (j>1){
          grad_kappa[idx] += -out[(j-1)*(m+1)+i]*dt/dx/dx * g[idx];
        }
        if (j<n-1){
          grad_kappa[idx] += -out[(j+1)*(m+1)+i]*dt/dx/dx * g[idx];
        }
      }
}