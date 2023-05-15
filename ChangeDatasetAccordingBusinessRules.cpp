#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>

using namespace std;

int main() {

    string originalFileName = "dataset_00_1000_sem_virg.csv";
	string newFileName = "newCsv.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;
	vector<std::thread> allThreads;
	int count = 0;

    fstream originalFile(originalFileName, ios::in);
	//if (exists(CSV))) {
		//fstream newFile(newFileName, ios::in);
	//} else {
		ofstream newFile("newCsv.csv");
	//}
	if (originalFile.is_open())
	{
		while (getline(originalFile, line)) {
			count += 1;
			thread eachLine(line, row, word, content);
			allThreads.emplace_back(eachLine);
		}
	} else {
		cout << "Could not open the file\n";
	}

	for (int i = 0; i <= count; i++) {
		allThreads[i].join();
	}

	return 0;
}

void eachLine(string line, vector<string> row, string word, vector<vector<string>> content) {
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ','))
			row.push_back(word);
		content.push_back(row);
	}
}