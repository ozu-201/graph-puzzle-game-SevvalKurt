//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "EdgeList.h"
#include "AbstractGraph.h"
#include <vector>
#include <string>

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
    public:
        std::string* vertexToWordArray;
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void buildFromWords(const std::vector<std::string>& words);
        bool isOneLetterDiff(const std::string& word1, const std::string& word2);
        void addNode(int vertex, const std::string& word);
        void printGraph();
        bool containsWord(const std::string& word);
        std::vector<int> getAdjacentIndices(int nodeIndex);
        std::vector<std::string> findShortestPath(const std::string& startWord, const std::string& endWord);

    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
        Edge* edgeList(int& edgeCount) override;
    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H