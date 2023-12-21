//
// Created by sk025162 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_SEVVALKURT_FILEREADER_H
#define GRAPH_PUZZLE_GAME_SEVVALKURT_FILEREADER_H


#include <string>
#include "WordGraph.h"

class FileReader {
private:
    WordGraph& graph;

public:
    FileReader(WordGraph& graph);
    void readFile(const std::string& filename);
};


#endif //GRAPH_PUZZLE_GAME_SEVVALKURT_FILEREADER_H
