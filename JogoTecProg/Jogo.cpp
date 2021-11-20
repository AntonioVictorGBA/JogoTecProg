#include "Jogo.h"

/* CONSTRUTOR/DESTRUTOR */
Jogo::Jogo() {
	this->janela = new sf::RenderWindow(sf::VideoMode(1280, 720), "Joguinho!");//tamanho e nome da janela
	this->janela->setFramerateLimit(framerate);

	this->jogador_1 = new Jogador1();

	this->hud = new HUD();
}
Jogo::~Jogo() {}

void Jogo::atualiza() {
	while (janela->pollEvent(evento)) {//enquanto ocorrer um evento
		if (evento.type == sf::Event::Closed)//fecha a janela se o evento for de fechar
			janela->close();
	}
	dt = clock.restart().asSeconds();
	this->jogador_1->Jogador1_atualizaTextura(dt, framerate);

	this->renderiza();
}
const bool Jogo::getJanelaIsOpen() {
	return this->janela->isOpen();
}

void Jogo::renderiza() {
	this->janela->clear(sf::Color::Black);              //cor do fundo e limpa a tela (apaga frames anteriores da animação

	hud->desenhaHUD(this->janela, jogador_1->getBalas());

	this->janela->draw(jogador_1->getRectangleShape()); //desenha retângulo (personagem 1) na tela

	this->janela->display();                            //mostra a tela em uma janela
}