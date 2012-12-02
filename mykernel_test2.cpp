#include <iostream>
#include <functional>
#include <memory>
#include <chrono>
#include <cmath>

struct rbf_t{
  inline double operator()(int i, int j) const{
    double tmp = i-j;
    return 1.0;
//    return std::exp(-tmp*tmp);
  }
};
struct kbase_t{
  virtual double operator()(int i, int j) const =0;
};
struct rbf_t2:kbase_t{
  inline double operator()(int i, int j) const{
    double tmp = i-j;
    return 1.0;
//    return std::exp(-tmp*tmp);
  }
};

inline double dyn_rbf(int i, int j) {
  double tmp = i-j;
  return 1.0;
//  return std::exp(-tmp*tmp);
}

template<class K>
void kernelsum(K k, int n, const std::string& str){
  auto time_point_t1 = std::chrono::high_resolution_clock::now();
  double sum = 0.;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      sum += k(i,j);
    }
  }
  auto duration1 = std::chrono::high_resolution_clock::now() - time_point_t1 ;
  std::cout << str << " time: " << duration1.count() << std::endl;
  std::cout << str << " val : " << sum << std::endl; 
  return;
}

void kernelsum2(const kbase_t& k, int n, const std::string& str){
  auto time_point_t1 = std::chrono::high_resolution_clock::now();
  double sum = 0.;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      sum += k(i,j);
    }
  }
  auto duration1 = std::chrono::high_resolution_clock::now() - time_point_t1 ;
  std::cout << str << " time: " << duration1.count() << std::endl;
  std::cout << str << " val : " << sum << std::endl; 
  return;
}


int main(int argc, char* argv[]){
  int N = 100000;
  kernelsum(rbf_t(), N, std::string("static polymorphism "));

  rbf_t2 rbf2;
  kernelsum2(rbf2, N, std::string("dynamic polymorphism "));

  std::function<double ( int, int)> f = &dyn_rbf;
  kernelsum(f, N, std::string("dynamic polymorphism using std::function "));
}
