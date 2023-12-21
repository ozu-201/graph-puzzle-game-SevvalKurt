//
// Created by sk025162 on 12/21/2023.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>

FileReader::FileReader(WordGraph& graph) : graph(graph) {}

void FileReader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;

    if (file.is_open()) {
        while (file >> word) {
            graph.addWord(word);
        }
        file.close();
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    graph.buildGraph();
}