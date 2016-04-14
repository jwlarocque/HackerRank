#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <algorithm>


// WHY IS THIS PROBLEM 1-INDEXED!?
// TODO: also this solution seems a bit shaky to me, should revisit in other languages

std::vector< std::vector<int> > graphFromInput(int numNodes, int numEdges)
{
	std::vector< std::vector<int> > graphOut(numNodes, std::vector<int>(numNodes, -1));
	int tempLeft, tempRight;

	for (int index = 0; index < numEdges; index++) {
		std::cin >> tempLeft >> tempRight;
        tempLeft--;
        tempRight--;
        // undirected, so set both directions (look, it's fine)
		graphOut[tempLeft][tempRight] = 6;
        graphOut[tempRight][tempLeft] = 6;
	}
	return graphOut;
}

std::vector<int> shortestDistances(int startNode, std::vector< std::vector<int> > graph)
{
    std::vector<int> distances(graph.size(), -1);
    distances[startNode] = 0;
    int currentNode;
    std::deque<int> horizon = {startNode};
    while (horizon.size() > 0) {
        currentNode = horizon.front();
        horizon.pop_front();
        for (int toNode = 0; toNode < graph[currentNode].size(); toNode++) {
            if (graph[currentNode][toNode] != -1 && distances[toNode] == -1) {
                distances[toNode] = distances[currentNode] + graph[currentNode][toNode];
                horizon.push_back(toNode);
            }
        }
    }
    return distances;
}

int runFinal()
{
    int cases, numNodes, numEdges, startNode;
    std::vector< std::vector<int> > tempGraph;
    std::vector<int> tempDistances;
    std::cin >> cases;
    
    for (int index = 0; index < cases; index++) {
        std::cin >> numNodes >> numEdges;
        tempGraph = graphFromInput(numNodes, numEdges);
        std::cin >> startNode;
        startNode--;
        tempDistances = shortestDistances(startNode, tempGraph);
        for (int printIndex = 0; printIndex < tempDistances.size(); printIndex++) {
            if (printIndex != startNode) {
                std::cout << tempDistances[printIndex] << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}

int printGraph(std::vector< std::vector<int> > graph)
{
    for (int row = 0; row < graph.size(); row++) {
        std::cout << "[";
        for (int column = 0; column < graph[0].size(); column++) {
            std::cout << graph[row][column] << ", "; // ignores formatting edge case
        }
        std::cout << "]" << std::endl;
    }
    
    return 0;
}

// prints extra stuff
int runTest()
{
    int numNodes, numEdges, startNode;
    std::vector< std::vector<int> > tempGraph;
    std::vector<int> tempDistances;
    
    std::cout << "Enter number of nodes, then number of edges." << std::endl;
    std::cin >> numNodes >> numEdges;
    std::cout << "Enter edges (from node _ to node _ return)." << std::endl;
    tempGraph = graphFromInput(numNodes, numEdges);
    printGraph(tempGraph);
    std::cout << "Created graph from input. Enter starting node." << std::endl;
    std::cin >> startNode;
    startNode--;
    tempDistances = shortestDistances(startNode, tempGraph);
    for (int printIndex = 0; printIndex < numNodes; printIndex++) {
        if (printIndex != startNode) {
            std::cout << tempDistances[printIndex] << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}

int main() {
    runFinal();
    return 0;
}