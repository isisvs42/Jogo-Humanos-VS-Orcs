#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "player.hpp"

//void menu();
void ler_nomes(string nomeArquivo, vector<string> &vetorNomes, size_t tamanhoExercito);
void criar_exercito(vector<Player> &raca, const vector<string> &vetorNomes, bool humano);
void imprimir_exercito(vector<Player> &raca, string nomeRaca);
string batalhar(vector<Player> &Humanos, vector<Player> &Orcs);
void a_ultima_esperanca(vector<Player> &Orcs);
void milagre_real(vector<Player> &Humanos);

