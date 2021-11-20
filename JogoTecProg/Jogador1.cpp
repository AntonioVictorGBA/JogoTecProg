#include "Jogador1.h"

/* CONSTRUTOR/DESTRUTOR */
Jogador1::Jogador1() {/* APLICA OS ATRIBUTOS DO PERSONAGEM */
    this->retangulo.setSize(sf::Vector2f(MULTIPLICADOR * 101.0f, MULTIPLICADOR * 74.0f));//dimens�es do ret�ngulo

    this->textura.loadFromFile("Animacoes\\personagem1\\personagem1_animacao.png");//carrega a textura (normal)
    this->textura_invertida.loadFromFile("Animacoes\\personagem1\\personagem1_invertido_animacao.png");//carrega a textura (invertida)

    this->retangulo.setTexture(&textura);//aplica a textura (normal) no ret�ngulo
    this->retangulo.setTextureRect(sf::IntRect(2, 2, 101, 74));/*posiciona o peda�o da textura mostrada no ret�ngulo.
                                                                       param. 1 : pixel x
                                                                       param. 2 : pixel y
                                                                       param. 3 : tamanho em x
                                                                       param. 4 : tamanho em y
                                                                 (left, top, width and height)*/
}
Jogador1::~Jogador1() {

}

/* FUN��O SERVE PARA ANIMA��O DO PERSONAGEM */
void Jogador1::Jogador1_atualizaTextura(float dt, int framerate) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        Jodador1_moveDireita(dt, framerate);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        Jodador1_moveEsquerda(dt, framerate);

    this->retangulo.setTextureRect(sf::IntRect(getColuna(), getLinha(), 101, 74)); //atualiza a anima��o do personagem
}
int Jogador1::getColuna() {
    coluna += 106; //atualiza a coluna
    if (coluna >= 2 + 8 * 106) //se a coluna passar de 8 (anima��o tem 8 frames de 0 a 7)
        coluna = 2;            //coluna volta para a coluna 0 (+ 2 pixels)
    this->retangulo.setTextureRect(sf::IntRect(coluna, linha, 101, 74)); //atualiza a anima��o do personagem
    return coluna;
}
int Jogador1::getLinha() {
    //SE APERTAR 'S'
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        linha = 2 + 4 * 78; //linha 4 do .png � o personagem agachado

    //SE APERTAR 'W'
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        linha = 2 + 6 * 78; //linha 6 do .png � o personagem mirando para cima
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            linha = 2 + 8 * 78; //linha 8 do .png � o personagem mirando para cima e andando
    }

    //SE APERTAR 'D'
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        linha = 2 + 2 * 78; //linha 2 do .png � o personagem andando

    //SE APERTAR 'A'
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        linha = 2 + 2 * 78; //linha 2 do .png � o personagem andando

    //SE N�O APERTAR NADA
    else
        linha = 2 + 0 * 78; //linha 0 do .png � o personagem parado

    //SE N�O APERTAR 'B'
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B))
        atirando = false;

    //SE APERTAR 'B' (ATIRAR)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B) && balas > 0 && atirando == false) {
        atirando = true;
        linha += 78;
        balas--;
    }

    return linha;
}

void Jogador1::Jodador1_moveDireita(float dt, int framerate) {
    this->retangulo.setTexture(&textura); //inverte textura (+ precisamente carrega para .png normal)
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        retangulo.move(velocidade_movimento * dt * framerate, 0);
}
void Jogador1::Jodador1_moveEsquerda(float dt, int framerate) {
    this->retangulo.setTexture(&textura_invertida); //inverte textura (+ precisamente carrega para .png normal)
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        retangulo.move(-velocidade_movimento * dt * framerate, 0);
}

/* RETORNA O RET�NGULO */
sf::RectangleShape Jogador1::getRectangleShape() {
    return this->retangulo;
}

/* RETORNA A QUANTIDADE DE BALAS */
int Jogador1::getBalas() {
    return balas;
}