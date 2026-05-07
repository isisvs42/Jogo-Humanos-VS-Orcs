#include "../include/player.hpp"

//construtores
Player::Player()
{
    m_nome = "";
    m_vida = m_ataque = m_defesa = 3;
    m_sangueReal = false;
}

Player::Player(string nome, float vida, float ataque, float defesa, bool sangueReal)
{
    m_nome = nome;
    m_vida = vida;
    m_ataque = ataque;
    m_defesa = defesa;
    m_sangueReal = sangueReal;
}

//destrutor

//métodos de acesso GET e SET
string Player::GetNome()
{
    return m_nome;
}

float Player::GetAtaque()
{
    return m_ataque;
}

float Player::GetDefesa()
{
    return m_defesa;
}

float Player::GetVida()
{
    return m_vida;
}

void Player::SetVida(float vida)
{
    m_vida = vida;
}

bool Player::Atacar(Player &oponente)
{
    //se o atacante tiver valor de ataque superior à defesa do oponente,
    //deve-se decrementar do valor do ataque, a defesa do oponente.
    //A diferença será decrementada da vida do oponente.

    if(m_ataque > oponente.GetDefesa())
    {
        float valorVidaOponente = oponente.GetVida() - m_ataque + oponente.GetDefesa();
        oponente.SetVida(valorVidaOponente);
        return true;
    }
    else
    {
        return false;
    }
}

//outros métodos
void Player::AuraReal(Player &oponente){
    size_t chance = rand()%10 + 1; // de 1 a 10

    if(!m_sangueReal) return;

    if(chance > 2){
        // retira 50% de vida do oponente
        oponente.SetVida(oponente.GetVida()*0.5);
    }
}
