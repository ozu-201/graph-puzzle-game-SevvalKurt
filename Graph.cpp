//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Graph.h"
#include "Queue.h"
#include <iostream>


namespace list {

    Graph::Graph(int _vertexCount) : AbstractGraph(_vertexCount){
        vertexToWordArray = new std::string[vertexCount];
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
    }

    void Graph::addEdge(int from, int to) {
        Edge* edge = new Edge(from, to, 1);
        edges[from].insert(edge);

        Edge* edge2 = new Edge(to, from, 1);
        edges[to].insert(edge2);
    }

    Graph::~Graph() {
        delete[] vertexToWordArray;
        delete[] edges;
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        Edge* edge;
        int toNode;
        edge = edges[fromNode].getHead();
        while (edge != nullptr){
            toNode = edge->getTo();
            if (!visited[toNode]){
                visited[toNode] = true;
                depthFirstSearch(visited, toNode);
            }
            edge = edge->getNext();
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        Edge* edge;
        int fromNode, toNode;
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue()->getData();
            edge = edges[fromNode].getHead();
            while (edge != nullptr) {
                toNode = edge->getTo();
                if (!visited[toNode]){
                    visited[toNode] = true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::buildFromWords(const std::vector<std::string>& words) {

        for (int i = 0; i < words.size(); i++) {
            vertexToWordArray[i] = words[i];
            addNode(i, words[i]);
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isOneLetterDiff(words[i], words[j])) {
                    addEdge(i, j);
                }
            }
        }
    }

    bool Graph::isOneLetterDiff(const std::string& word1, const std::string& word2) {
        if (word1.length() != word2.length()) return false;
        int diffCount = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                diffCount++;
                if (diffCount > 1)
                    return false;
            }
        }
        return diffCount == 1;
    }

    void Graph::addNode(int vertex, const std::string& word) {
        if (vertex >= 0 && vertex < vertexCount) {
            vertexToWordArray[vertex] = word;
        } else {
            ;
        }
    }

    void Graph::printGraph() {
        for (int i = 0; i < vertexCount; i++) {
            std::cout << "Node " << i << " (" << vertexToWordArray[i] << "): ";
            for (Edge* edge = edges[i].getHead(); edge != nullptr; edge = edge->getNext()) {
                std::cout << vertexToWordArray[edge->getTo()] << " ";
            }
            std::cout << std::endl;
        }
    }

    Edge* Graph::edgeList(int& edgeCount) {
        edgeCount = edges->size;
        Edge* edgesArray = new Edge[edgeCount];
        return edgesArray;
    }

    bool Graph::containsWord(const std::string& word) {
        for (int i = 0; i < vertexCount; i++) {
            if (vertexToWordArray[i] == word) {
                return true;
            }
        }
        return false;
    }

    std::vector<int> Graph::getAdjacentIndices(int nodeIndex) {
        std::vector<int> adjacentIndices;
        for (Edge* edge = edges[nodeIndex].getHead(); edge != nullptr; edge = edge->getNext()) {
            adjacentIndices.push_back(edge->getTo());
        }
        return adjacentIndices;
    }

    std::vector<std::string> Graph::findShortestPath(const std::string& startWord, const std::string& endWord) {
        int startIndex = -1, endIndex = -1;
        for (int i = 0; i < vertexCount; i++) {
            if (vertexToWordArray[i] == startWord) startIndex = i;
            if (vertexToWordArray[i] == endWord) endIndex = i;
        }

        if (startIndex == -1 || endIndex == -1) return std::vector<std::string>();

        bool* visited = new bool[vertexCount](); // Array to track visited vertices
        int* pred = new int[vertexCount]; // Array to track the path
        std::fill_n(pred, vertexCount, -1);

        Queue queue;
        queue.enqueue(new Node(startIndex));
        visited[startIndex] = true;

        while (!queue.isEmpty()) {
            Node* node = queue.dequeue();
            int current = node->getData();
            delete node;

            if (current == endIndex) {
                std::vector<std::string> path;
                for (int at = endIndex; at != -1; at = pred[at]) {
                    path.insert(path.begin(), vertexToWordArray[at]);
                }
                delete[] visited;
                delete[] pred;
                return path;
            }

            std::vector<int> adjIndices = getAdjacentIndices(current);
            for (int adjIndex : adjIndices) {
                if (!visited[adjIndex]) {
                    queue.enqueue(new Node(adjIndex));
                    visited[adjIndex] = true;
                    pred[adjIndex] = current;
                }
            }
        }

        delete[] visited;
        delete[] pred;

        return std::vector<std::string>();
    }

}