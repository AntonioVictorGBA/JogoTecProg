#include "Jogador1.h"

/* CONSTRUTOR/DESTRUTOR */
Jogador1::Jogador1() {/* APLICA OS ATRIBUTOS DO PERSONAGEM */
    this->retangulo.setSize(sf::Vector2f(multiplicador * 101.0f, multiplicador * 74.0f));//dimensões do retângulo

    this->textura.loadFromFile("Animacoes\\personagem1\\personagem1_animacao.png");//carrega a textura (normal)
    this->textura_invertida.loadFromFile("Animacoes\\personagem1\\personagem1_invertido_animacao.png");//carrega a textura (invertida)

    this->retangulo.setTexture(&textura);//aplica a textura (normal) no retângulo
    this->retangulo.setTextureRect(sf::IntRect(2, 2, 101, 74));/*posiciona o pedaço da textura mostrada no retângulo.
                                                                       param. 1 : pixel x
                                                                       param. 2 : pixel y
                                                                       param. 3 : tamanho em x
                                                                       param. 4 : tamanho em y
                                                                 (left, top, width and height)*/
}
Jogador1::~Jogador1() {

}

/* RETORNA O RETÂNGULO */
sf::RectangleShape Jogador1::getRectangleShape() {
	return this->retangulo;
}

/* FUNÇÃO SERVE PARA ANIMAÇÃO DO PERSONAGEM */
void Jogador1::Jogador1_Move() {
    //SE APERTAR 'S'
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        linha = 2 + 4 * 78; //linha 4 do .png é o personagem agachado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            retangulo.setTexture(&textura); //inverte textura (+ precisamente carrega para .png normal)
            //retangulo.move(velocidade_movimento, 0.0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            retangulo.setTexture(&textura_invertida); //inverte textura (+ precisamente troca para .png invertido)
            //retangulo.move(-velocidade_movimento, 0.0);
        }
    }

    //SE APERTAR 'W'
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        linha = 2 + 6 * 78; //linha 6 do .png é o personagem mirando para cima
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            retangulo.setTexture(&textura); //inverte textura (+ precisamente carrega para .png normal)
            linha = 2 + 8 * 78; //linha 8 do .png é o personagem mirando para cima e andando
            retangulo.move(velocidade_movimento, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            retangulo.setTexture(&textura_invertida); //inverte textura (+ precisamente troca para .png invertido)
            linha = 2 + 8 * 78; //linha 8 do .png é o personagem mirando para cima e andando
            retangulo.move(-velocidade_movimento, 0);
        }
    }

    //SE APERTAR 'D'
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        retangulo.setTexture(&textura); //inverte textura (+ precisamente carrega para .png normal)
        retangulo.move(velocidade_movimento, 0);
        linha = 2 + 2 * 78; //linha 2 do .png é o personagem andando
    }

    //SE APERTAR 'A'
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        retangulo.setTexture(&textura_invertida); //inverte textura (+ precisamente troca para .png invertido)
        retangulo.move(-velocidade_movimento, 0);
        linha = 2 + 2 * 78; //linha 2 do .png é o personagem andando
    }

    //SE APERTAR NÃO APERTAR NADA
    else {
        linha = 2 + 0 * 78; //linha 0 do .png é o personagem parado
    }

    //SE APERTAR 'B' (ATIRAR)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
        linha += 78;
    }

    coluna += 106; //atualiza a coluna
    if (coluna >= 2 + 8 * 106) //se a coluna passar de 8 (animação tem 8 frames de 0 a 7)
        coluna = 2;            //coluna volta para a coluna 0 (+ 2 pixels)


    this->retangulo.setTextureRect(sf::IntRect(coluna, linha, 101, 74)); //atualiza a animação do personagem
}
