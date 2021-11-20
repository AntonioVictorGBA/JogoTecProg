#pragma once
#include <SFML/Graphics.hpp>//biblioteca SFML

#include "Jogador1.h"
#include "HUD.h"

//class HUD;

class Jogo {
private:
	//VARIÁVEIS
	sf::RenderWindow* janela;
	sf::Event evento;
	sf::Clock clock;

	float dt = 0; //delta time

	int framerate = 60;

	//OBJETOS
	Jogador1* jogador_1;

	HUD* hud;

public:
	Jogo();
	~Jogo();
	void atualiza();
	const bool getJanelaIsOpen();
	void renderiza();
};