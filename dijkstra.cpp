#include <iostream>
//#include
using namespace std;




// method searching for the minimum distance
int findMinimumDistance(int distanceArray[], bool alreadyVisited[])
{
    int minimum = INT_MAX, ind;

    for (int k = 0; k < 6; k++)
    {
        if (alreadyVisited[k] == false && distanceArray[k] <= minimum)
        {
            minimum = distanceArray[k];
            ind = k;
        }
    }
    return ind;
}

void Dij(int graph[6][6], int initialNode) // adjacency matrix 
{
    int distanceArray[6]; // // array to calculate the minimum distance for each node     
    //Array indicating whether we have visited a node or not
    bool alreadyVisited[6];


    for (int k = 0; k < 6; k++)
    {
        distanceArray[k] = INT_MAX;
        alreadyVisited[k] = false;
    }
    // The distance to the initial node has to be zero
    distanceArray[initialNode] = 0;               

    for (int k = 0; k < 6; k++)
    {
        int m = findMinimumDistance(distanceArray, alreadyVisited);
        alreadyVisited[m] = true;
        for (int k = 0; k < 6; k++)
        {
            // updating the distance between adjacent vertices
            if (!alreadyVisited[k] && graph[m][k] && distanceArray[m] != INT_MAX && distanceArray[m] + graph[m][k] < distanceArray[k])
                distanceArray[k] = distanceArray[m] + graph[m][k];
        }
    }
    std::cout << "Vertex\t\tDistance from initial vertex" << endl;
    for (int k = 0; k < 6; k++)
    {
        char str = 65 + k;
        std::cout << str << "\t\t\t" << distanceArray[k] << endl;
    }
}

int main()
{
    //Initialize the graph
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0} };

    std::cout << "The 2d array of distances: " << endl;
    for (int i = 0; i < 6; i++) {
      
        for (int j = 0; j < 6; j++) {
            std::cout <<  graph[i][j];
            std::cout << " ";
        }
        std::cout << "\t" << endl;
    }

    //ask about the number
    int initial;
    std::cout << "Please provide the starting node between 0 and 5: \n" << endl;
    std::cin >> initial;
    std::cout<<"\n" << endl;

    //print the map
    //change the map
    Dij(graph, initial);
    return 0;
}

//I have relied mostly upon the following implementation :https://favtutor.com/blogs/dijkstras-algorithm-cpp
