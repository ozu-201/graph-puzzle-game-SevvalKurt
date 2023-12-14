//
// Created by sk025162 on 12/14/2023.
//

#include "WordGraph.h"
#include "FileReader.h"

int main() {
    WordGraph graph;
    FileReader fileReader(graph);

    fileReader.readFile("XXX.txt");

    graph.printGraph();

    return 0;
}
