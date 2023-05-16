#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>

//dicionario externo para as colunas trabalhadas
//nomes iguais = criar nome

using namespace std;

int main() {

	string originalFileName = "dataset_00_1000_sem_virg.csv";
	string newFileName = "newCsv.csv";

	vector<vector<string>> content;
	vector<string> row;
	vector<int> indices;
	string line, word, column;
	vector<thread> allThreads;
	int count = 0;
	vector<string> columnsName = { "cdtup", "berco", "mes", "portoatracacao", "mes", "tipooperacao", "tiponavegacaoatracacao", "terminal", "origem", "destino", "cdmercadoria", "naturezacarga", "sentido" };

	fstream originalFile(originalFileName, ios::in);
	//if (exists(CSV))) {
		//fstream newFile(newFileName, ios::in);
	//} else {
	ofstream newFile("newCsv.csv");
	//}
	if (originalFile.is_open())
	{
		while (getline(originalFile, line)) {
			stringstream str(line);
			row.clear();

			//Adquiri os indices das colunas a serem categorizadas
			if (count == 0) {
				while (getline(str, column, ',')) {
					if (find(columnsName.begin(), columnsName.end(), column) != columnsName.end()) {
						indices.push_back(count);
					}
				}
			}

			//Grava os valores das colunas a serem categorizadas
			while (getline(str, column, ',')) {
				if (find(indices.begin(), indices.end(), count) != indices.end()) {
					row.push_back(column);
				}
			}

			content.push_back(row);
			count += 1;
		}
	}
	else {
		cout << "Could not open the file\n";
	}

	/*for (int i = 0; i <= count; i++) {
		allThreads[i].join();
	}*/

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

/*for (int i = 0; i <= ) {
			thread thread(eachLine, line, row, word, content);
			allThreads.emplace_back(thread);
		}*/