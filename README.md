# ⚔️ Battle Humans vs ORCs

Projeto desenvolvido em C++ para a disciplina **Linguagem de Programação II (DEC7532)** da UFSC – Campus Araranguá.

Simulação em modo texto (teleespectador) de uma batalha épica entre dois exércitos: **Humanos** e **ORCs**. Cada lutador possui nome próprio, atributos aleatórios e participa de uma luta automática até que um dos times seja completamente exterminado.

---

## 📖 Sobre o Projeto

A batalha é gerada proceduralmente: o usuário define quantos lutadores cada exército terá (de 1 a 500), os nomes são lidos de arquivos de texto pré-existentes e os atributos (vida, ataque, defesa) são sorteados dentro de faixas específicas para cada raça.

A cada rodada, um humano e um orc são sorteados para se enfrentar. A ordem do ataque também é aleatória, e eventos especiais podem alterar o rumo da guerra quando uma das condições de virada for atingida.

---

## ⚙️ Mecânicas de Combate

### Atributos por raça

| Raça    | Vida      | Ataque    | Defesa  |
|---------|-----------|-----------|---------|
| Humano  | 100 – 200 | 100 – 150 | 1 – 75  |
| Orc     | 200 – 300 | 75 – 150  | 5 – 80  |

### Regra de ataque

Um ataque só causa dano se o atributo de **ataque do agressor for maior que a defesa do alvo**. Quando isso ocorre, o dano aplicado é `ataque - defesa` e é descontado da vida do oponente. Caso contrário, o golpe falha.

### Eventos especiais

- 👑 **Milagre Real** — quando o exército humano é reduzido a 50% do tamanho inicial, o Rei entra em campo. Ele possui sangue real e pode invocar a *Aura Real*.
- ✨ **Aura Real** — habilidade exclusiva do Rei. A cada rodada em que ele luta, há 80% de chance de a aura cortar 50% da vida do orc oponente antes do combate corpo a corpo.
- 🙏 **A Última Esperança** — quando restam apenas 30% dos humanos, eles se unem em um cântico sagrado e desferem um ataque coletivo que tira 30% da vida de **todos** os orcs ao mesmo tempo.
- 🎲 **Iniciativa aleatória** — em cada rodada, o jogo sorteia quem desfere o primeiro golpe (humano ou orc), garantindo que o combate não favoreça sempre o mesmo lado.

---

## 🛠️ Tecnologias e Conceitos

- **C++** com Programação Orientada a Objetos (classe `Player`)
- **STL**: `vector`, `string`
- **Manipulação de arquivos**: `ifstream` para leitura dos nomes
- **Randomização** com `rand()` e `srand(time(NULL))`
- **Códigos ANSI** para colorir os eventos especiais no terminal
- **Compilação modular** via Makefile

---

## 📂 Estrutura do Projeto

```
Jogo-Humanos-VS-Orcs/
│
├── main.cpp                  # Ponto de entrada do programa
├── Makefile                  # Compilação automatizada
├── README.md
│
├── include/                  # Cabeçalhos
│   ├── player.hpp
│   └── functions.hpp
│
├── src/                      # Implementações
│   ├── player.cpp
│   └── functions.cpp
│
├── DataBase/                 # Arquivos de nomes
│   ├── humanos.txt           # 500 nomes de guerreiros humanos
│   └── orcs.txt              # 500 nomes de guerreiros orcs
│
└── objs/                     # Objetos compilados (gerado pelo make)
```

---

## 🚀 Como Compilar e Executar

### Pré-requisitos

- Compilador `g++` (suporte a C++11 ou superior)
- `make` instalado
- Terminal com suporte a códigos ANSI (qualquer terminal moderno em Linux, macOS ou WSL no Windows)

### Compilação

Antes de rodar o `make` pela primeira vez, garanta que a pasta `objs/` exista:

```bash
mkdir -p objs
make
```

### Execução

```bash
./Battle_Game
```

O programa pedirá a quantidade de orcs e humanos (entre 1 e 500), imprimirá os exércitos formados e iniciará a batalha. Pressione **Enter** para avançar entre os turnos.

### Limpeza dos arquivos gerados

```bash
make clear
```

---

## 🎮 Como Jogar

O modo de jogo é **teleespectador**: o usuário não controla os lutadores, apenas acompanha a batalha que se desenrola sozinha. A cada turno, pressionando Enter, é possível ver:

- Quem atacou quem
- Se o golpe acertou ou foi defendido
- Mortes em campo
- A entrada do Rei
- O cântico da Última Esperança

Ao final, o time vencedor é anunciado.

---

## 👥 Autores

- **Ísis Valois Sampaio** 
- **Guilherme Paiva Peres** 

Desenvolvido como atividade prática **T1** da disciplina DEC7532 — Linguagem de Programação II — UFSC.
