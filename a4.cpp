#include<iostream>
#include<vector>
using namespace std;

class JobSeekerPath {
public:
    int cities, routes, totalDistance = 0;
    int adjacencyMatrix[100][100];
    vector<int> visited, path;

    JobSeekerPath(int c) {
        cities = c;
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
        visited.resize(cities, 0);
    }

    void addRoute(int city1, int city2, int distance) {
        adjacencyMatrix[city1][city2] = distance;
        adjacencyMatrix[city2][city1] = distance;
    }

    void displayRoutes() {
        for(int i = 0; i < cities; i++) {
            for(int j = 0; j < cities; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void findShortestPath() {
        visited[0] = 1; 

        for(int i = 0; i < cities - 1; i++) {
            int minDist = 9999, fromCity = -1, toCity = -1;

            for(int j = 0; j < cities; j++) {
                if(visited[j]) {
                    for(int k = 0; k < cities; k++) {
                        if(adjacencyMatrix[j][k] != 0 && !visited[k] && adjacencyMatrix[j][k] < minDist) {
                            minDist = adjacencyMatrix[j][k];
                            fromCity = j;
                            toCity = k;
                        }
                    }
                }
            }

            if (toCity != -1) {
                visited[toCity] = 1;
                path.push_back(fromCity);
                path.push_back(toCity);
                path.push_back(minDist);
                totalDistance += minDist;
            }
        }

        cout << "Minimum Travel Distance: " << totalDistance << endl;
        cout << "Optimal Travel Path:" << endl;
        for(int i = 0; i < path.size(); i += 3) {
            cout << "City " << path[i] << " -> City " << path[i+1] << " (Distance: " << path[i+2] << ")" << endl;
        }
    }
};

int main() {
    JobSeekerPath jobPath(5);
    jobPath.addRoute(0, 1, 2);
    jobPath.addRoute(0, 2, 4);
    jobPath.addRoute(2, 3, 1);
    jobPath.addRoute(1, 3, 2);
    jobPath.addRoute(1, 4, 3);
    jobPath.addRoute(3, 4, 4);
    
    cout << "Adjacency Matrix of Cities:" << endl;
    jobPath.displayRoutes();
    
    cout << "\nFinding the Shortest Path:\n";
    jobPath.findShortestPath();
    
    return 0;
}
