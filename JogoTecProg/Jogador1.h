#pragma once

#include <SFML/Graphics.hpp>

class Jogador1 {
private:
    int multiplicador = 4;
    sf::RectangleShape retangulo; //ret�ngulo onde o peda�o da textura ser� exibida
    sf::Texture textura;          //textura (normal)
    sf::Texture textura_invertida;//textura (invertida)

    int coluna = 2, linha = 2;      //coluna e linha do peda�o da textura exibida no ret�ngulo
    float velocidade_movimento = 15;//quantos pixels o personagem ir� andar a cada movimento

public:
    Jogador1();
    ~Jogador1();
    sf::RectangleShape getRectangleShape();
    void Jogador1_Move();
};
