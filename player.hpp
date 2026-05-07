#pragma once

#include <iostream>

using namespace std;

class Player
{
//atributos
private:
     string m_nome;
     float m_vida, m_ataque, m_defesa;
     bool m_sangueReal;

//métodos
public:
    //construtor
    Player();
    Player(string nome, float vida, float ataque, float defesa, bool sangueReal);

    //métodos de acesso do tipo Get e Set
    string GetNome();
    float GetAtaque();
    float GetDefesa();
    float GetVida();
    void SetVida(float vida);

    bool Atacar(Player &oponente);
    void AuraReal(Player &oponente);
};







