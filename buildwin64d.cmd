setlocal
mkdir build
cd build
mkdir win
cd win

cmake ../.. -G"Visual Studio 14 2015 Win64" -DBUILD_TIAN=TRUE
