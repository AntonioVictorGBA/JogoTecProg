#pragma once

#include <SFML/Graphics.hpp>

class HUD {
private:
	sf::Font fonte;
	sf::Text Jogador1_qntBalas;
	char textoTemporario[60] = "";
public:
	HUD();
	~HUD();
	void desenhaHUD(sf::RenderWindow* janela, int balas);
};