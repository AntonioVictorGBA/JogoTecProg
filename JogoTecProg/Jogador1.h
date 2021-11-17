#pragma once

#include <SFML/Graphics.hpp>

class Jogador1 {
private:
    int multiplicador = 4;
    sf::RectangleShape retangulo; //retângulo onde o pedaço da textura será exibida
    sf::Texture textura;          //textura (normal)
    sf::Texture textura_invertida;//textura (invertida)

    int coluna = 2, linha = 2;      //coluna e linha do pedaço da textura exibida no retângulo
    float velocidade_movimento = 15;//quantos pixels o personagem irá andar a cada movimento

public:
    Jogador1();
    ~Jogador1();
    sf::RectangleShape getRectangleShape();
    void Jogador1_Move();
};
