#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <algorithm>

//dicionario externo para as colunas trabalhadas
//nomes iguais = criar nome

using namespace std;

void printMatriz(vector<vector<string>> content) {
  for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << ",  ";
		}
    
		cout << "\n";
	}
}

void printVector(vector<string> content) {
  for (int i=0;i<content.size();i++)
	{
    cout << content[i] << ", ";
	}
  
  cout << "\n";
}

vector<string> eachLine(string line, vector<string> row, string word, vector<vector<string>> content) {
	{
		row.clear();

		stringstream str(line);

		while (getline(str, word, ','))
			row.push_back(word);
	}
  
  return row;
}

int main() {

	string originalFileName = "dataset_00_1000_sem_virg.csv";
	string newFileName = "newCsv.csv";

	vector<string> vectorTest;
	vector<vector<string>> matrizTeste;

  vectorTest.push_back("T");
  vectorTest.push_back("T");
  vectorTest.push_back("T");
  matrizTeste.push_back(vectorTest);
  matrizTeste.push_back(vectorTest);
  matrizTeste.push_back(vectorTest);
  
	vector<vector<string>> content;
	vector<string> row, headers;
	string line, word;
	vector<string> columnsName = { "cdtup", "berco", "mes", "portoatracacao", "mes", "tipooperacao", "tiponavegacaoatracacao", "terminal", "origem", "destino", "cdmercadoria", "naturezacarga", "sentido" };
  
	ofstream newFile("newCsv.csv");
 
	fstream file (originalFileName, ios::in);
	if(file.is_open())
	{
    // Armazena apenas a primeira linha do CSV
    getline(file, line);
    headers = eachLine(line, row, word, content);

    for ( int i = 0; i < headers.size(); i++ ) {
      cout << headers[i] << " - " << columnsName[i] << "\n";
      if (find(v.begin(), v.end(), "abc") != v.end())
      {
        // Element in vector.
      }
    }

    return 0;
    
    // Armazena o CSV em uma Matriz
    while(getline(file, line))
    {
      row = eachLine(line, row, word, content);
		  content.push_back(row);
    }
	}
	else
		cout<<"Could not open the file\n";
 
	printMatriz(content);
 
	return 0;
}
