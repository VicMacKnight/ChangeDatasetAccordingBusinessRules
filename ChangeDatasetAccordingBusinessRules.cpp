#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string filename = "dataset_00_1000_sem_virg.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(filename, ios::in);
}