#include <iostream>         //biblioteca c++
#include <SFML/Graphics.hpp>//biblioteca SFML

#include "Jogador1.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Joguinho!");//tamanho e nome da janela

    Jogador1* jogador_1 = new Jogador1();

    while (window.isOpen()) {//enquanto janela está aberta
        sf::Event event;
        while (window.pollEvent(event)) {//enquanto ocorrer um evento
            if (event.type == sf::Event::Closed)//fecha a janela se o evento for de fechar
                window.close();
            jogador_1->Jogador1_Move();
        }

        window.clear(sf::Color::Black);              //cor do fundo e limpa a tela (apaga frames anteriores da animação
        window.draw(jogador_1->getRectangleShape()); //desenha retângulo (personagem 1) na tela
        window.display();                            //mostra a tela em uma janela
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