#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <chrono>

using namespace std;

struct edge {
  int start;
  int end;
  int weight;
};

const int imax = std::numeric_limits<int>::max();


void bf(int v_cnt, int e_cnt, int start_v, int end_v, vector<edge> gr) {

    vector<int> d(v_cnt, imax);
    vector<int> p(v_cnt, -1);
    
    d[start_v] = 0;

    chrono::high_resolution_clock::time_point start_t = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < v_cnt - 1; i++) 
      {
        #pragma omp parallel for
        for (int j = 0; j < e_cnt; j++)
            if (d[ gr[j].start ] < imax) 
              {
                if (d[ gr[j].end ] > d[ gr[j].start ] + gr[j].weight) 
                  {
                    d[ gr[j].end ] = d[ gr[j].start ] + gr[j].weight;
                    p[ gr[j].end ] = gr[j].start;
                  }
              }
      }
 
  chrono::high_resolution_clock::time_point end_t = std::chrono::high_resolution_clock::now();

  if (d[ end_v ] == imax)
    {
      cout << "Imossible to find the path" << endl;
    }
  else 
    {
      vector<int> result;
      for (int i = end_v; i != -1; i = p[i]) 
        result.push_back(i);

      for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
      cout << endl;
    }

  cout << "Elapsed time: " << (end_t - start_t).count() << endl; 

}

main(int argc, char* argv[]) {
  if (argc < 2)
    cout << "Specify input file" << endl;

  ifstream inp;
  inp.open(argv[1], ios::out);

  int v_cnt, e_cnt, start_v, end_v;
  int start, end, weight;

  inp >> v_cnt >> e_cnt >> start_v >> end_v;

  vector<edge> gr;

  for (int i = 0; i < e_cnt; ++i)
    {
      inp >> start >> end >> weight;
      gr.push_back({start, end, weight});
    }
  inp.close();


  bf(v_cnt, e_cnt, start_v, end_v, gr);

  return 0;
}
