#include "HUD.h"

/* CONSTRUTOR/DESTRUTOR */
HUD::HUD() {
	//this->textura.loadFromFile("Animacoes\\personagem1\\personagem1_animacao.png");//carrega a textura (normal)
	fonte.loadFromFile("Fontes\\montserrat\\MontserratAlternates-Black.otf");
	Jogador1_qntBalas.setFont(fonte);
	Jogador1_qntBalas.setFillColor(sf::Color::White);
	Jogador1_qntBalas.setOutlineThickness(2);
	Jogador1_qntBalas.setOutlineColor(sf::Color::Black);
	Jogador1_qntBalas.setPosition(40, 40);
}
HUD::~HUD() {

}

void HUD::desenhaHUD(sf::RenderWindow* janela, int balas) {
	sprintf_s(textoTemporario, "Balas: %d\n", balas);
	Jogador1_qntBalas.setString(textoTemporario);
	janela->draw(Jogador1_qntBalas);
}