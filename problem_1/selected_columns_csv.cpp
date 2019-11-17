#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cassert>


// Implement csv reader:

// 1. Program should read command line arguments:
//     input_csv file (requires blank line at the end)
//     output_csv file 
//     indices of columns (indexing from 0)
// 2. Program reads csv file, selects columns, 
//    and outputs selected columns to output csv


int main (int argc, char **argv) {
    assert(("There is no input_csv", argc > 1));
    std::ifstream fin(argv[1]);
    assert(("There is no output_csv", argc > 2));
    std::ofstream fout(argv[2]);

    while (!fin.eof() && fin.good()) {
        std::string line;
        std::getline(fin, line);
        if (fin.eof())
            break;

        std::stringstream ss(line);
        std::vector<std::string> tokens;
        while (!ss.eof() && ss.good()) {
            std::string token;
            std::getline(ss, token, ',');
            tokens.push_back(token);
        }
        for (int i = 3; i < argc; ++i) {
            int j = atoi(argv[i]);
            assert(("Number of column is incorrect", 0 <= j && j < tokens.size()));
            fout << tokens[j] << (i + 1 == argc ? "\n" : ",");
        }
    }
    
    fin.close();
    fout.close();

    return 0;
}
