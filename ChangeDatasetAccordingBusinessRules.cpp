#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void printMatriz(vector<vector<string>> content) {
  for (int i = 0; i < content.size(); i++) {
    for (int j = 0; j < content[i].size(); j++) {
      cout << content[i][j] << ",  ";
    }
    cout << "\n";
  }
}

void printVector(vector<string> content) {
  for (int i = 0; i < content.size(); i++) {
    cout << content[i] << ", ";
  }

  cout << "\n";
}

vector<string> eachLine(string line, vector<string> row, string word) {
  row.clear();

  stringstream str(line);

  while (getline(str, word, ',')) {
    row.push_back(word);
  }

  return row;
}

int main() {
  vector<vector<string>> content;
  vector<string> row, headersName, vectorValido;
  vector<int> headersId;
  string line, word;
  int linhas, colunas;
  vector<string> columnsName = {
      "cdtup",         "berco",        "portoatracacao",
      "mes",           "tipooperacao", "tiponavegacaoatracacao",
      "terminal",      "origem",       "destino",
      "naturezacarga", "sentido",      "cdmercadoria"};

  string originalFile = "dataset_00_1000_sem_virg.csv";
  fstream file;
  file.open(originalFile);

  if (file.is_open()) {
    // Armazena o CSV em uma Matriz
    while (getline(file, line)) {
      row = eachLine(line, row, word);
      content.push_back(row);
    }

    linhas = content.size();
    colunas = content[0].size();

    // Armazena apenas a primeira linha do CSV
    for (int coluna = 0; coluna < colunas; coluna++) {
      if (find(columnsName.begin(), columnsName.end(), content[0][coluna]) !=
          columnsName.end()) {
        headersId.push_back(coluna);
      }
    }

  } else {
    cout << "Could not open the file: dataset_00_1000_sem_virg.csv\n";
  }

  file.close();
  fstream fileColumn;

  for (int coluna = 0; coluna < colunas; coluna++) {
    string columnName = "csv/" + content[0][coluna] + ".csv";

    if (find(begin(headersId), end(headersId), coluna) != end(headersId)) {
      // Criacao do arquivo de dicionario
      ofstream{columnName};
      fileColumn.open(columnName);

      if (fileColumn.is_open()) {
        int cont = 1;
        vectorValido.clear();

        for (int linha = 1; linha < linhas; linha++) {
          if (find(vectorValido.begin(), vectorValido.end(),
                   content[linha][coluna]) == vectorValido.end()) {
            vectorValido.push_back(content[linha][coluna]);
            fileColumn << content[linha][coluna] << "," << cont << "\n";
            cont++;
          }
        }

        fileColumn.close();

        // Categorizacao
        map<string, string> columnMap;
        fileColumn.open(columnName);

        while (getline(fileColumn, line)) {
          row.clear();

          stringstream str(line);

          while (getline(str, word, ',')) {
            row.push_back(word);
          }

          columnMap.insert(make_pair(row[0], row[1]));
        }

        for (int linha = 1; linha < linhas; linha++) {
          auto it = columnMap.find(content[linha][coluna]);

          if (it != columnMap.end()) {
            content[linha][coluna] = it->second;
          }
        }

        fileColumn.close();
      } else {
        cout << "Could not open the file: " << columnName << "\n";
      }
    }
  }

  // Armazena a Matriz no CSV
  file.open(originalFile);

  if (file.is_open()) {
    for (int linha = 0; linha < linhas; linha++) {
      file << content[linha][0];
      for (int coluna = 1; coluna < colunas; coluna++) {
        file << "," << content[linha][coluna];
      }
      file << "\n";
    }
  } else {
    cout << "Could not open the file: " << originalFile << "\n";
  }

  return 0;
}
