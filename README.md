patch to make OpenMP-enabled LIBSVM 3.14

tar zxvf libsvm-3.14.tar.gz
cd libsvm-3.14
patch < Makefile.diff
patch < svm_cpp.diff

See the following link for details:
http://www.csie.ntu.edu.tw/~cjlin/libsvm/faq.html#f432
