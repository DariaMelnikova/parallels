for (( i=1; i<=50; i++))
	do
		./bin/strictBF graph.txt >> strict.txt
                ./bin/openmpBF graph.txt >> openmp.txt
                ./bin/pthreadBF graph.txt >> pthread.txt
		echo "Number $i"
	done
