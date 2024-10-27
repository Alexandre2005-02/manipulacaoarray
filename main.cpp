/*
Título: Atividade: Manipulando Array
Autor: Alexandre Aleixo
Data: 2024.10.27
*/



#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Função para aguardar que o usuário pressione Enter
void esperarEnter() {
    cout << "\nPressione Enter para continuar...";
    cin.get();
}

// Função para limpar o buffer e resetar o estado do `cin`
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função genérica para exibir mensagens de erro
void exibirMensagemErro(const string &mensagem) {
    cout << mensagem << endl;
}

// Função para ler uma string válida
string lerEntradaValida(const string &mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);
    return entrada;
}

// Função para zerar o array de nomes
void zerarArray(string array[], int tamanho) {
    fill(array, array + tamanho, "");
    cout << "Array de nomes zerado!";
    esperarEnter();
}

// Função para mostrar o array de nomes
void mostrarArray(string array[], int tamanho) {
    cout << "Conteúdo do array de nomes:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Posição [" << i << "]: " << array[i] << endl;
    }
    esperarEnter();
}

// Função para preencher o array de nomes com entradas do usuário
void preencherArray(string array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = lerEntradaValida("Digite um nome para a posição [" + to_string(i) + "]: ");
    }
    cout << "Array de nomes preenchido manualmente!";
    esperarEnter();
}

// Função para editar um nome em uma posição específica do array
void editarArray(string array[], int tamanho) {
    int posicao = stoi(lerEntradaValida("Digite a posição que deseja editar (0 a " + to_string(tamanho - 1) + "): "));
    while (posicao < 0 || posicao >= tamanho) {
        exibirMensagemErro("Posição inválida! Tente novamente.");
        posicao = stoi(lerEntradaValida("Digite uma posição válida: "));
    }
    string nome = lerEntradaValida("Digite o novo nome para a posição [" + to_string(posicao) + "]: ");
    array[posicao] = nome;
    cout << "Nome alterado com sucesso!";
    esperarEnter();
}

// Função para verificar se um nome está presente no array
void verificarNome(string array[], int tamanho) {
    string nome = lerEntradaValida("Digite o nome que deseja verificar: ");
    bool encontrado = false;
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == nome) {
            cout << "Nome '" << nome << "' encontrado na posição [" << i << "]" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Nome '" << nome << "' não encontrado no array." << endl;
    }
    esperarEnter();
}

// Função para ordenar o array de nomes em ordem alfabética
void ordenarArray(string array[], int tamanho) {
    sort(array, array + tamanho);
    cout << "Array de nomes ordenado com sucesso!";
    esperarEnter();
}

// Função para contar posições preenchidas e vazias
void contarPreenchidosEVazios(string array[], int tamanho) {
    int preenchidos = 0, vazios = 0;
    for (int i = 0; i < tamanho; i++) {
        if (array[i].empty()) vazios++;
        else preenchidos++;
    }
    cout << "Posições preenchidas: " << preenchidos << "\nPosições vazias: " << vazios << endl;
    esperarEnter();
}

// Função para contar ocorrências de um nome no array
void contarOcorrencias(string array[], int tamanho) {
    string nome = lerEntradaValida("Digite o nome que deseja contar: ");
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == nome) contador++;
    }
    cout << "O nome '" << nome << "' aparece " << contador << " vezes no array." << endl;
    esperarEnter();
}

// Função para encontrar e exibir o nome mais curto e o mais longo
void encontrarMaisCurtoMaisLongo(string array[], int tamanho) {
    string maisCurto = "", maisLongo = "";
    for (int i = 0; i < tamanho; i++) {
        if (!array[i].empty()) {
            if (maisCurto.empty() || array[i].size() < maisCurto.size()) maisCurto = array[i];
            if (array[i].size() > maisLongo.size()) maisLongo = array[i];
        }
    }
    cout << "Nome mais curto: " << maisCurto << "\nNome mais longo: " << maisLongo << endl;
    esperarEnter();
}

// Função criativa: inverte os caracteres de todos os nomes no array
void inverterNomes(string array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        reverse(array[i].begin(), array[i].end());
    }
    cout << "Todos os nomes foram invertidos!" << endl;
    esperarEnter();
}

// Função que exibe o menu e retorna a escolha do usuário
int menu() {
    cout << "\nEscolha uma opção:\n";
    cout << "1 - Mostrar array de nomes\n";
    cout << "2 - Zerar array de nomes\n";
    cout << "3 - Preencher array de nomes\n";
    cout << "4 - Editar nome no array\n";
    cout << "5 - Verificar se o nome está no array\n";
    cout << "6 - Ordenar array de nomes\n";
    cout << "7 - Contar preenchidos e vazios\n";
    cout << "8 - Contar ocorrências de um nome\n";
    cout << "9 - Exibir nome mais curto e mais longo\n";
    cout << "10 - Inverter todos os nomes\n";
    cout << "0 - Sair\n";
    return stoi(lerEntradaValida("Opção: "));
}

int main() {
    const int TAMANHO = 3;
    string array[TAMANHO];
    int opcao;
    do {
        opcao = menu();
        switch (opcao) {
            case 1: mostrarArray(array, TAMANHO); break;
            case 2: zerarArray(array, TAMANHO); break;
            case 3: preencherArray(array, TAMANHO); break;
            case 4: editarArray(array, TAMANHO); break;
            case 5: verificarNome(array, TAMANHO); break;
            case 6: ordenarArray(array, TAMANHO); break;
            case 7: contarPreenchidosEVazios(array, TAMANHO); break;
            case 8: contarOcorrencias(array, TAMANHO); break;
            case 9: encontrarMaisCurtoMaisLongo(array, TAMANHO); break;
            case 10: inverterNomes(array, TAMANHO); break;
            case 0: cout << "Saindo do programa..." << endl; break;
            default: exibirMensagemErro("Opção inválida! Escolha uma opção válida."); break;
        }
    } while (opcao != 0);
    return 0;
}