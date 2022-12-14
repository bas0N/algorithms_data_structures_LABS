#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

//https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/

static int distances[4][4] = { {0,10,15,20}, {10,0,35,25}, {15,35,0,30},{20,25,30,0} };


void find_shortest_path(int start,int size) {
    int min_cost = 0;
    vector<int> shortest_path_vertices;



    //loop
    int cost_of_current_travel = 0;
    vector<int> current_path_vertices;
    current_path_vertices.push_back(start);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            vector<int>::iterator it = find(current_path_vertices.begin(), current_path_vertices.end(), cost_of_current_travel);
            //if its starting or it already appeared in the vertex
            if (i==start|| it != current_path_vertices.end()) {
                continue;
            }
            else {

            }

        }
    }



    if (cost_of_current_travel < min_cost) {
        min_cost = cost_of_current_travel;
        //copy vertex
    }
}


void display(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void findSmallestCost(int a[], int size,int start)
{
    int min_cost = -1;
    int shortest_path_vertices[4];

    // Find all possible permutations
    //cout << "Possible permutations are:\n";
    do {
        int cost_of_current_travel = 0;
        int current_path_vertices[4];
        if (a[0]==start) {
            //find all potential paths
           // display(a, size);
            //find the cost
            for (int i = 0; i < 3; i++) {
                cost_of_current_travel = cost_of_current_travel + distances[a[i]][a[i+1]];
            }
            cost_of_current_travel = cost_of_current_travel + distances[a[3]][a[0]];

           // cout<<"current costs:" << cost_of_current_travel << "\n" << endl;
            if (cost_of_current_travel < min_cost||min_cost==-1) {
                min_cost = cost_of_current_travel;
                for (int j = 0; j < size;j++) {
                    shortest_path_vertices[j] = a[j];
                }
            }
        }
    } while (next_permutation(a, a + size));
    cout << "smallest costs:" << min_cost << "\n" << endl;
    cout << "shortest path:" <<"\n" << endl;
    display(shortest_path_vertices, size);


}

int main()
{
    int size = 4;
   
    //insert node to start
    int start;
    cout << "Type a number between 0 and 3 (index of the first house) :\n "; // Type a number and press enter
    cin >> start;

    if (start > 3 || start < 0) {
        cout << "Starting point incorrect\n "; // Type a number and press enter
        cout << "Program exits\n "; // Type a number and press enter
        return 0;
    }

    int a[] = { 0, 1, 2, 3 };

    findSmallestCost(a, 4,start);





}
