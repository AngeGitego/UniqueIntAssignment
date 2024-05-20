#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

class UniqueInt {
public:
    static void processFile(std::string inputFilePath, std::string outputFilePath) {
        std::ifstream inputFile(inputFilePath);
        std::ofstream outputFile(outputFilePath);
        if (!inputFile.is_open() || !outputFile.is_open()) {
            std::cerr << "Error opening files!" << std::endl;
            return;
        }

        std::unordered_set<int> uniqueIntegers;
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            int num;
            if (ss >> num) {
                // Check if there are any extra characters after the number
                char extra;
                if (!(ss >> extra)) {
                    uniqueIntegers.insert(num);
                }
            }
        }

        std::vector<int> sortedUniqueIntegers(uniqueIntegers.begin(), uniqueIntegers.end());
        std::sort(sortedUniqueIntegers.begin(), sortedUniqueIntegers.end());

        for (int num : sortedUniqueIntegers) {
            outputFile << num << std::endl;
        }

        inputFile.close();
        outputFile.close();
    }
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path> <output_file_path>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];

    UniqueInt::processFile(inputFilePath, outputFilePath);

    return 0;
}

