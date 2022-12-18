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

void DijWithNormalEdges(int graph[6][6], int initialNode) // adjacency matrix 
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
void DijWithNegativeEdges(int graph[][3], int numOfVectors ,int numOfEdges ,
    int initalNode) {
    
    int distances[6];
    for (int i = 0; i < numOfVectors; i++)
        distances[i] = INT_MAX;

    // initialize distance of source as 0
    distances[initalNode] = 0;

    for (int i = 0; i < numOfVectors - 1; i++) {

        for (int j = 0; j < numOfEdges; j++) {
            if (distances[graph[j][0]] != INT_MAX && distances[graph[j][0]] + graph[j][2] < distances[graph[j][1]])
            {
                distances[graph[j][1]] = distances[graph[j][0]] + graph[j][2];
            }
        }
    }
    

    cout << "Vertex\t\tDistance from initial vertex" << endl;
    for (int i = 0; i < numOfVectors; i++) {
        char str = 65 + i;
        cout << str << "\t\t" << distances[i] << endl;

    }
}

int main()
{
    //Initialize the graph for normal dijkstra 
    int graphNormalDijkstra[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0} };
    //Initialize the graph for negative vertices dijkstra 
    int graphNegativeDijkstraPresentation[6][6] = {
           {0, -1, 2, 0, 0, 0},
           {-1, 0, 0, -5, 1, 0},
           {2, 0, 0, 2, 3, 0},
           {0, -5, 2, 0, 2, -2},
           {0, 1, 3, 2, 0, 1},
           {0, 0, 0, -2, 1, 0} };
    
    std::cout << "The 2d array of distances for regular dijkstra: " << endl;
    for (int i = 0; i < 6; i++) {
      
        for (int j = 0; j < 6; j++) {
            std::cout << graphNormalDijkstra[i][j];
            std::cout << " ";
        }
        std::cout << "\t" << endl;
    }

    //ask about the number
    int initialElemNormalDijkstra;
    std::cout << "Please provide the starting node between 0 and 5 for negative edges dijkstra: \n" << endl;
    std::cin >> initialElemNormalDijkstra;
    std::cout<<"\n" << endl;

    //print the map
    //change the map
    DijWithNormalEdges(graphNormalDijkstra, initialElemNormalDijkstra);
    
    std::cout << "The 2d array of distances for negative dijkstra: " << endl;
    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {
            std::cout << graphNegativeDijkstraPresentation[i][j];
            std::cout << " ";
        }
        std::cout << "\t" << endl;
    }

    //define the relations for negative dijkstra
    //table include edges which goes as follows: {beginningOfEdge, endOfEdge, weight}
    int graphNegativeDijkstra[][3] = { {0,1,-1},{0,2,2},{1,3,-5},{1,4,1},{2,3,2},{2,4,3},{3,4,2},{3,5,-2}, {4,5,1}};
    int initialElemNegativeDijkstra;
    std::cout << "Please provide the starting node between 0 and 5 for negative edges dijkstra: \n" << endl;
    std::cin >> initialElemNegativeDijkstra;
    std::cout << "\n" << endl;
    DijWithNegativeEdges(graphNegativeDijkstra,6,9, initialElemNegativeDijkstra);
    return 0;
}













//I have relied mostly upon the following implementation :https://favtutor.com/blogs/dijkstras-algorithm-cpp
//https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/
