#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::string line;
    size_t spaceline{0};
    size_t totalFileLine{0};

    if(!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "can't open the file\n";
    }

    while(std::getline(inputFile, line)) {
        totalFileLine += 1;
        // delete space line in input.txt
        if(line.size() == 0) {
            spaceline += 1;
            continue;
        } else {
            outputFile << line << '\n';
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "operate file: [input.txt], ";
    std::cout << "information are below:\n";
    std::cout << "---------------------------\n";
    std::cout << "totalLines\tspaceLines\t\n";
    std::cout << totalFileLine << "\t\t" << spaceline << '\n';
    // std::cout << "input.txt has " << totalFileLine << " lines\n";
    // std::cout << "has deleted " << spaceline << " spaceLines\n";

    return 0;
}