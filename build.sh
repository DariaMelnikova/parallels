ghc mkGraph.hs
./mkGraph 150

mkdir bin
g++ -std=c++11 -o bin/strictBF src/main.cpp
g++ -std=c++11 -fopenmp -o bin/openmpBF src/main.cpp
g++ -std=c++11 -pthread -o bin/pthreadBF src/pt_main.cpp

