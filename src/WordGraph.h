//
// Created by sk025162 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_SEVVALKURT_WORDGRAPH_H
#define GRAPH_PUZZLE_GAME_SEVVALKURT_WORDGRAPH_H

#include <unordered_map>
#include <vector>
#include <string>

class WordGraph {
private:
    std::unordered_map<std::string, std::vector<std::string>> graph;

public:
    WordGraph();
    void addWord(const std::string& word);
    void buildGraph();
    bool differByOne(const std::string& word1, const std::string& word2) const;
    void printGraph() const;
};

#endif //GRAPH_PUZZLE_GAME_SEVVALKURT_WORDGRAPH_H

