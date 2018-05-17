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

const int imax  = numeric_limits<int>::max();
vector<edge> gr;
vector<int> d;
vector<int> p;

int v_cnt, e_cnt;


void* thread(void * args) {
  for (int j = 0; j < e_cnt - 1; j++)
    if (d[ gr[j].start ] < imax)
      {
        if (d[ gr[j].end ] > d[ gr[j].start ] + gr[j].weight)
          {
             d[ gr[j].end ] = d[ gr[j].start ] + gr[j].weight;
             p[ gr[j].end ] = gr[j].start;
          }
      }

}

void bf(int start_v, int end_v) {
    d = vector<int> (v_cnt, imax);
    d[ start_v ] = 0;
    p = vector<int>(v_cnt, -1);

    chrono::high_resolution_clock::time_point start_t = std::chrono::high_resolution_clock::now();

    int thread_num = v_cnt - 1;
    int status_addr;

    vector<pthread_t> threads(thread_num);

    for (int i = 0; i < thread_num; i++) 
      {

        if (pthread_create(&threads[i], NULL, thread, 0))
          {
            cout << "Error: create thread " << endl;
            exit(1);
          }
      }

    for (int i = 0; i < thread_num; i++) 
      {

        if (pthread_join(threads[i], (void**)&status_addr))
          {
            cout << "Error: join thread" << endl;
            exit(1);
          }
      }

    chrono::high_resolution_clock::time_point end_t = std::chrono::high_resolution_clock::now();

    if (d[ end_v ] == imax)
      {
        cout << "Imossible to find the path" << endl;
        return;
      }
    else 
      {
        vector<int> result;
        for (int i = end_v; i != -1; i = p[i])
          result.push_back(i);

        for (int i = result.size(); i >= 0; i--)
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

  int start_v, end_v;
  int start, end, weight;

  inp >> v_cnt >> e_cnt >> start_v >> end_v;

  for (int i = 0; i < e_cnt; ++i)
    {
      inp >> start >> end >> weight;
      gr.push_back({start, end, weight});
    }
  inp.close();

  bf(start_v, end_v);

  return 0;
}
