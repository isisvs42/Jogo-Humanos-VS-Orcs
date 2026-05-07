# ⚔️ Battle Humans vs ORCs

Projeto desenvolvido em C++ para a disciplina de Linguagem de Programação II da UFSC.

## 📖 Sobre o Projeto

O jogo consiste em uma batalha entre dois times:

- Humanos
- ORCs

Cada equipe possui lutadores gerados automaticamente com atributos aleatórios, enquanto os nomes são carregados de arquivos de texto contendo até 500 nomes para cada raça.

A batalha acontece em modo texto, simulando um combate automático até que todos os integrantes de um dos times sejam eliminados.

---

## 🛠️ Tecnologias Utilizadas

- C++
- Programação Orientada a Objetos
- STL (`vector`, `string`, `pair`, `tuple`)
- Manipulação de arquivos (`ifstream`, `ofstream`)
- Randomização de atributos

---

## 📂 Estrutura do Projeto

```bash
📁 projeto/
│
├── main.cpp
├── player.hpp
├── player.cpp
├── functions.hpp
├── functions.cpp
├── humanos.txt
├── orcs.txt
└── README.md
