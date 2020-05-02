/**
 * Implementação de Lista Sequencial utilizando vector de forma estruturada.
 *
 */

//Declaração de bibliotecas
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Declaração dos métodos
int leitura();
int procurarPosicao(vector<int> lista, int k);
int procurarValor(vector<int> lista, int valor);
string listar(vector<int> lista);

/**
 * Realiza a leitura dos dados dos nós.
 *
 * @return O valor lido.
 */
int leitura() {
    cout << "\nDigite um valor: ";
    int valor = 0;
    cin >> valor;
    return valor;
}

/**
 * Retorna o dado de uma posição na lista.
 *
 * @param lista Lista dos Nós.
 * @param k Posição do nó a ser consultado na lista.
 * @return A posição de valor na lsita.
 */

int procurarPosicao(vector<int> lista, int k) {
    if (lista.size() != 0) {
        //Verifica se a posição esta dentro do intervalo da lista.
        if ((k >= 0) && (k < lista.size())) {
            return lista[k];
        } else {
            cout << "Procurar posição - Posição inválida." << endl;
            return -1;
        }
    } else {
        cout << "Procurar posição - Lista vazia." << endl;
        return -1;
    }
}

/**
 * Retorna a posição de um Nó na lista.
 *
 * @param lista Lista dos Nós.
 * @param valor Valor a ser procurado na lista.
 * @return A posição de valor na lsita.
 */

int procurarValor(vector<int> lista, int valor) {
    if (lista.size() != 0) {
        int i = 0;
        //Procura a posição do Nó na lista.
        //Compara o valor na lista ou até chegar no final da lista.
        while ((i < lista.size()) && (valor != lista[i])) {
            i = i + 1;
        }
        //Verifica se a posição esta dentro do intervalo da lista.
        if (i < lista.size()) {
            return i;
        } else {
            return -1;
        }
    } else {
        cout << "Procurar valor - Lista vazia." << endl;
        return -1;
    }
}

/**
 * Lista os dados da lista.
 *
 * @param lista Lista dos Nós. 
 * @return Uma String com os dados da lista.
 */
string listar(vector<int> lista) {
    //String de retorno
    string temp = "";
    for (int i = 0; i < lista.size(); i++) {
        temp = temp + to_string(i) + "-" + to_string(lista[i]) + "\n";
    }
    return temp;
}

/**
 * Programa principal.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char** argv) {
    /**
     * Declaração da lista
     */
    vector<int> lista;
    // Controla o menu da lista
    int opcao = -1;

    //Laço do menu de opções
    while (opcao != 99) {
        //Monta o menu de opções        
        cout << "\n\t### Lista Sequencial ###\n"
                << "Selecione a opção desejada:\n"
                << " 1- Listar Nós\n"
                << " 2- Inserir Nó no início\n"
                << " 3- Inserir Nó em uma posição especifica\n"
                << " 4- Inserir Nó no fim\n"
                << " 5- Inserir Nó ordenado\n"
                << " 6- Remover Nó do início\n"
                << " 7- Remover Nó de uma posição específica\n"
                << " 8- Remover Nó do fim\n"
                << " 9- Remover Nó pelo valor\n"
                << "10- Procurar o dado de uma posição específica\n"
                << "11- Procurar a posição de um dado\n"
                << "12- Mostrar a quantidade de Nós\n"
                << "13- Está cheia?\n"
                << "14- Está vazia?\n"
                << "99- Sair\n"
                << " Opcao:";
        cin >> opcao;
        //Verifica a opção
        switch (opcao) {
            case 1:
            {
                if (lista.empty()) {
                    cout << "\nLista vazia!" << endl;
                } else {
                    cout << "\nListagem \n" << listar(lista) << endl;
                }
                break;
            }
            case 2:
            {
                //Preenche o valor do dado
                int dado = leitura();
                lista.insert(lista.begin(), dado);
                cout << "\nNó inserido no início com Sucesso!" << endl;
                break;
            }
            case 3:
            {
                int k;
                cout << "\nDigite a posição a ser inserido:";
                cin >> k;
                //Preenche o valor do dado
                int dado = leitura();

                lista.insert(lista.begin() + k, dado);
                cout << "\nNó inserido na posição " << k << " com Sucesso!" << endl;
                break;
            }
            case 4:
            {
                //Preenche o valor do dado
                int dado = leitura();

                lista.insert(lista.end(), dado);
                cout << "\nNó inserido no fim com Sucesso!" << endl;

                break;
            }

            case 5:
            {
                //Preenche o valor do dado
                int dado = leitura();
                int posicao = 0;
                //Procura a posição
                while ((posicao < lista.size()) && (dado > lista[posicao])) {
                    posicao = posicao + 1;
                }
                lista.insert(lista.begin() + posicao, dado);
                cout << "\nNó inserido ordenado com Sucesso!" << endl;
                break;
            }
            case 6:
            {
                if (!lista.empty()) {
                    lista.erase(lista.begin());
                    cout << "\nO Nó do início foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nLista vazia!" << endl;
                }
                break;
            }
            case 7:
            {
                if (!lista.empty()) {
                    int k;
                    cout << "\nDigite a posição a ser excluída:";
                    cin >> k;
                    lista.erase(lista.begin() + k);
                    cout << "\nO valor da posição " << k << " foi excluído com Sucesso!" << endl;

                } else {
                    cout << "\nLista vazia!" << endl;
                }
                break;
            }
            case 8:
            {
                if (!lista.empty()) {
                    lista.erase(lista.end() - 1);
                    cout << "\nO Nó da fim foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nLista vazia!" << endl;
                }
                break;
            }
            case 9:
            {
                //Preenche o valor do dado                 
                if (!lista.empty()) {
                    int dado;
                    cout << "\nDigite o valor do dado a ser excluído:";
                    cin >> dado;
                    int posicao = procurarValor(lista, dado);
                    lista.erase(lista.begin() + posicao);
                    cout << "\nO valor " << dado << " foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nLista vazia!" << endl;
                }
                break;
            }
            case 10:
            {
                int k;
                cout << "\nDigite a posição do dado a ser procurada:";
                cin >> k;
                int dado = procurarPosicao(lista, k);
                if (dado != -1) {
                    cout << "\nO valor da posição " << k << "  possui o dado = " << dado << endl;
                } else {
                    cout << "\nA posição " << k << " não está preenchida" << endl;
                }
                break;
            }
            case 11:
            {
                int chave;
                cout << "\nDigite o valor do dado a ser procurado:";
                cin >> chave;
                int posicao = procurarValor(lista, chave);
                cout << "\nO valor " << chave << " esta na posição " << posicao << endl;
                break;
            }
            case 12:
            {
                cout << "\nQuantidade de Nós na lista : " << lista.size() << endl;
                break;
            }
            case 13:
            {
                cout << "\nLista está cheia : " << (lista.size() < lista.max_size()) << endl;
                break;
            }
            case 14:
            {
                cout << "\nLista está vazia : " << lista.empty() << endl;
                break;
            }
                //Opção de saída do programa
            case 99:
            {
                cout << "\nSaindo do programa!";
                break;
            }
                //Opção inválida do menu
            default:
            {
                cout << "\nOpção inválida!";
                break;
            }
        }//Fim switch
    }//Fim while
    return 0;
}//Fim main