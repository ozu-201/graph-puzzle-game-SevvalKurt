#include <iostream>
#include "Graph.h"
#include <fstream>
#include <vector>
#include <string>


using namespace list;
using namespace std;

int length(const std::string& str) {
    size_t length = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if ((str[i] & 0xC0) != 0x80) {
            ++length;
        }
    }
    return length;
}

int main() {
    std::ifstream file("../english-dictionary.txt");
    std::vector<std::string> letters3;
    std::vector<std::string> letters4;
    std::vector<std::string> letters5;
    std::string line;
    int vertexCount3 = 0;
    int vertexCount4 = 0;
    int vertexCount5 = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty() && line[line.size() - 1] == '\r') {
                line.erase(line.size() - 1);
            }

            if (length(line) == 3){
                letters3.push_back(line);
                vertexCount3 += 1;
            }else if(length(line) == 4){
                letters4.push_back(line);
                vertexCount4 += 1;
            }else if(length(line) == 5){
                letters5.push_back(line);
                vertexCount5 += 1;
            }

        }
        file.close();
    } else {
        std::cerr << "Unable to open file\n";
    }

    Graph wordGraph(vertexCount3);

    wordGraph.buildFromWords(letters3);
    wordGraph.printGraph();

    while (true) {
        string startWord, targetWord;
        cout << "Enter the starting word (or 'exit' to quit): ";
        cin >> startWord;
        if (startWord == "exit") break;

        cout << "Enter the target word: ";
        cin >> targetWord;

        if (!wordGraph.containsWord(startWord) || !wordGraph.containsWord(targetWord)) {
            cout << "Words not found in the dictionary. Please try again." << endl;
            continue;
        }

        vector<string> path = wordGraph.findShortestPath(startWord, targetWord);
        if (path.empty()) {
            cout << "No path found from " << startWord << " to " << targetWord << "." << endl;
        } else {
            cout << "Path: ";
            for (const string& word : path) {
                cout << word << " -> ";
            }
            cout << "Done" << endl;
        }
    }

    return 0;
}