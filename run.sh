echo "Simple running: "
./bin/strictBF graph.txt
echo "================="

echo "OpenMP running: "
./bin/openmpBF graph.txt
echo "================="

echo "pthreads running: "
./bin/pthreadBF graph.txt
echo "================="
