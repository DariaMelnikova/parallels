# parallels
implement Bellman-Ford's algorithm using openmp

# HOW TO

## Graph generation (Glasgow Haskell Compiler using)

- install ghc

- ghc mkGraph.hs

- ./mkGraph


## Build and execute program:

- g++ -std=c++11 src/main.cpp

- g++ -std=c++11 -fopenmp src/main.cpp

- g++ -std=c++11 -pthread src/pt_main.cpp

- ./a.out graph.txt

## Simplify it!

- run ./build.sh to build exe files: mkGraph, strictBF, openmpBF, pthreadBF and generate graph

(Only if you have ghc installed)

- default settings: vertex count random seed 150

- run ./run.sh to run strictBF, openmpBF and pthreadBF with graph.txt

- enjoy!

# What will you see

$ ./run.sh 

Simple running: 

98 105 124 125 116 40 64 81 68 

Elapsed time: 48635337

=================

OpenMP running: 

98 105 124 125 116 40 64 81 68 

Elapsed time: 5457967

=================

pthreads running: 

0 98 105 124 125 116 40 64 81 68 

Elapsed time: 6905474
