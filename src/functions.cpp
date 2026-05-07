#include "../include/functions.hpp"

void ler_nomes(string nomeArquivo, vector<string> &vetorNomes, size_t tamanhoExercito){
    ifstream arquivo(nomeArquivo);  // abre o arquivo

    if (arquivo.is_open()) {          // sempre verificar se abriu
        string linha;
        while (getline(arquivo, linha)) {  // lê uma linha por vez
            vetorNomes.push_back(linha);
            tamanhoExercito--;
            
            if(tamanhoExercito == 0) break;
        }
        arquivo.close();              // fecha quando terminar
    } else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}

void criar_exercito(vector<Player> &raca, const vector<string> &vetorNomes, bool humano){

    if (humano){
        for(size_t i=0; i<vetorNomes.size(); i++)
        {
            float vida = rand()% 101 + 100; // vida de 100 a 200
            float ataque = rand()%51 + 100; // ataque de 100 a 150 
            float defesa = rand()%75 + 1; // defesa de 1 a 75
            Player novoPlayer(vetorNomes.at(i), vida, ataque, defesa, false);

            raca.push_back(novoPlayer);
        }
    } else {
        for(size_t i=0; i<vetorNomes.size(); i++)
        {
            float vida = rand()% 101 + 200; // vida de 200 a 300
            float ataque = rand()%76 + 75; // ataque de 75 a 150
            float defesa = rand()%76 + 5; // defesa de 5 a 80
            Player novoPlayer(vetorNomes.at(i), vida, ataque, defesa, false);

            raca.push_back(novoPlayer);
        }
    }
}

void imprimir_exercito(vector<Player> &raca, string nomeRaca){
    cout << "--------------" << nomeRaca << "--------------" << endl;
    for(size_t i=0; i<raca.size(); i++)
    {
        cout << "nome: " << raca.at(i).GetNome() << "  vida: " << raca.at(i).GetVida() << endl;
    }
}

void batalha_1v1(Player &individuo, Player &oponente, vector<Player> &time_oponente, string FirstRace, string SecondRace, size_t indice)
{
    if(individuo.Atacar(oponente) == true)
    {
        cout << "O " << FirstRace << " " <<  individuo.GetNome() << " atacou o " << SecondRace << " " << oponente.GetNome();
        if(oponente.GetVida() <= 0){
            cout << " e o matou!" << endl;
            time_oponente.erase(time_oponente.begin()+indice);
            return;
        }
    }
    else cout << "O " << FirstRace << " " << individuo.GetNome() << " falhou no ataque ao " << SecondRace << " " << oponente.GetNome() << endl;
    cin.ignore();
}


string batalhar(vector<Player> &Humanos, vector<Player> &Orcs) {
    size_t TotalHumanosInicial = Humanos.size();
    bool flag_rei = true;
    bool flag_esperanca = true;
    while(true)
    {
        if(!Humanos.size())
            return "Os Orcs venceram";

        if(!Orcs.size())
            return "Os Humanos venceram";

        if(Humanos.size() <= TotalHumanosInicial*0.5 && flag_rei){
            flag_rei = false;
            milagre_real(Humanos);
            cout << "\033[1m\033[31m" << "O REI ENTROU EM CAMPO" << "\033[0m" << endl;
            cin.ignore();
        }

        if(Humanos.size() <= TotalHumanosInicial*0.3 && flag_esperanca){
            a_ultima_esperanca(Orcs);
            flag_esperanca = false;
        }

        size_t i = rand()%Humanos.size();
        size_t j = rand()%Orcs.size();

        //player.at(i).Atacar(player.at(j));
        Player &humano = Humanos.at(i);
        Player &orc = Orcs.at(j);

        humano.AuraReal(orc);

        //Define quem ataca primeiro
        if(rand()%2){
            batalha_1v1(humano, orc, Orcs, "humano", "orc", j);
            batalha_1v1(orc, humano, Humanos, "orc", "humano", i);
        }

        else{
            batalha_1v1(orc, humano, Humanos, "orc", "humano", i);
            batalha_1v1(humano, orc, Orcs, "humano", "orc", j);
        }

        //cout << "   " << Humanos.size() << endl;
    }
}

// Quando sobra 30% do exército humano, os humanos sentem uma motivação final e quase religiosa, 
// que os fazem tirar 30% da vida de cada orc: eles se juntam para um ataque coletivo
void a_ultima_esperanca(vector<Player> &Orcs){
    for(int i = 0; i < Orcs.size(); i++)
        Orcs.at(i).SetVida(Orcs.at(i).GetVida() * 0.7);

    // Códigos ANSI
    const string AMARELO  = "\033[33m";
    const string DOURADO  = "\033[93m";  // amarelo brilhante
    const string RESET    = "\033[0m";
    const string NEGRITO  = "\033[1m";

    cout << NEGRITO << DOURADO;
    cout << "Quando restam apenas 30% dos humanos, algo ancestral desperta neles — não coragem, mas fé." << endl;
    cout << AMARELO;
    cout << "Como mártires que abraçam o fim, eles unem suas vozes em um cântico de guerra sagrado e " << endl;
    cout << "desferem um ataque coletivo abençoado, arrancando 30% da vida de cada orc." << endl;
    cout << RESET;  // sempre resetar no final!

    cin.ignore();
}

//O rei entra em campo quando 50% dos soldados morrerem
void milagre_real(vector<Player> &Humanos){
    string nome = "Pedro de Alcântara João Carlos Leopoldo Salvador Bibiano Francisco Xavier de Paula Leocádio Miguel Gabriel Rafael Gonzaga";
    float vida = rand()% 101 + 100; // vida de 100 a 200
    float ataque = rand()%51 + 100; // ataque de 50 a 100 
    float defesa = rand()%75 + 1; // defesa de 1 a 75
    Player Rei(nome, vida, ataque, defesa, true);

    Humanos.push_back(Rei);
}
