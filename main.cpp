/*
Ísis Valois Sampaio 25203994
Guilherme Paiva Peres 25203350
*/


#include "include/functions.hpp"
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

int main()
{
    size_t n_orcs = 0;
    size_t n_humanos = 0;

    // inserção da quantidade de orcs com validação
    while (n_orcs < 1 || n_orcs > 500){
        cout << "Digite o número de orcs: ";
        cin >> n_orcs;
        cin.ignore();
    }

    // inserção da quantidade de humanos com validação
    while (n_humanos < 1 || n_humanos > 500){
        cout << "Digite o número de humanos: ";
        cin >> n_humanos;
        cin.ignore();
    }

    vector<string> nomesHumanos;
    vector<string> nomesOrcs;
    ler_nomes("./DataBase/humanos.txt", nomesHumanos, n_humanos);
    ler_nomes("./DataBase/orcs.txt", nomesOrcs, n_orcs);

    //gerador de numeros randomicos
    srand(time(NULL));

    //criando exércitos
    vector<Player> Humanos; // ou <tuple<Player, bool>>
    vector<Player> Orcs;
    criar_exercito(Humanos, nomesHumanos, true);
    criar_exercito(Orcs, nomesOrcs, false);

    //imprimindo lista de lutadores
    imprimir_exercito(Humanos, "HUMANOS");
    imprimir_exercito(Orcs, "ORCS");
    cout << "----------------------------------------" << endl;

    //lutando até restar exterminar o inimigo
    string resultado = batalhar(Humanos, Orcs);

    //winner
    cout << "----------------------------------------" << endl;
    cout << resultado << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}
