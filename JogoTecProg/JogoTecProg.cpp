#include <iostream>         //biblioteca c++
#include <SFML/Graphics.hpp>//biblioteca SFML

#include "Jogador1.h"
#include "Jogo.h"

int main(){

    //Jogador1* jogador_1 = new Jogador1();
    Jogo* jogo = new Jogo();

    while (jogo->getJanelaIsOpen()) {//enquanto janela está aberta
        jogo->atualiza();
    }

    return 0;
}

































    //jogador_1.setFillColor(sf::Color::Magenta);
    //jogador_1.setFillColor(sf::Color::Green);

    // Animacao animacao(&textura_jogador_1, sf::Vector2u(8,1), 0.3f);
    //float deltaTime = 0.0f;
    //sf::Clock clock;
    /*Jogador1* jogador1 = new Jogador1("Animacoes\\personagem1\\parado\\parado-01.png", 101.0, 73.0);*/

    //deltaTime = clock.restart().asSeconds();

    //animacao.Atualiza(0,deltaTime);
    //jogador_1.setTextureRect(animacao.uvRect);