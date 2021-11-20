#pragma once

#include <SFML/Graphics.hpp>

#define MULTIPLICADOR 4

class Jogador1 {
private:
    sf::RectangleShape retangulo; //retângulo onde o pedaço da textura será exibida
    sf::Texture textura;          //textura (normal)
    sf::Texture textura_invertida;//textura (invertida)

    int coluna = 2, linha = 2;      //coluna e linha do pedaço da textura exibida no retângulo
    int velocidade_movimento = 15;  //quantos pixels o personagem irá andar a cada movimento

    int balas = 15;

    bool atirando = false;

public:
    Jogador1();
    ~Jogador1();
    sf::RectangleShape getRectangleShape();
    int getColuna();
    int getLinha();
    int getBalas();
    void Jogador1_atualizaTextura(float dt, int framerate);
    void Jodador1_moveDireita(float dt, int framerate);
    void Jodador1_moveEsquerda(float dt, int framerate);
};
