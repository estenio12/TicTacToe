// ###########################
// #
// # @ Author: Estenio Garcia
// #
// # @ License: MIT
// #
// ###########################

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "./includes/Core.hpp"
#include "./includes/Button.hpp"
#include "./includes/Timer.hpp"

int main(){

	srand(time(NULL));

	sf::RenderWindow app(sf::VideoMode(626, 600), "Tic-Tac-Toe - by Estenio Garcia", sf::Style::Close);
	app.setFramerateLimit(60.f);
	sf::Event event;

	// # Load Content
	sf::Texture btnImage[3];
	btnImage[ 0 ].loadFromFile("./resource/btn_1.png");
	btnImage[ 1 ].loadFromFile("./resource/btn_2.png");
	btnImage[ 2 ].loadFromFile("./resource/btn_3.png");

	// # Instances
	Core* core = new Core();

	Button* btn1 = new Button(core);
	Button* btn2 = new Button(core);
	Button* btn3 = new Button(core);
	Button* btn4 = new Button(core);
	Button* btn5 = new Button(core);
	Button* btn6 = new Button(core);
	Button* btn7 = new Button(core);
	Button* btn8 = new Button(core);
	Button* btn9 = new Button(core);

	// # Settup attributes
	btn1->AddID(0);
	btn1->SetSprite(btnImage);
	btn1->SetLocation(sf::Vector2f(110, 55));
	// ______________________________________
	btn2->AddID(1);
	btn2->SetSprite(btnImage);
	btn2->SetLocation(sf::Vector2f(255, 55));
	// ______________________________________
	btn3->AddID(2);
	btn3->SetSprite(btnImage);
	btn3->SetLocation(sf::Vector2f(402, 55));
	// ______________________________________
	btn4->AddID(3);
	btn4->SetSprite(btnImage);
	btn4->SetLocation(sf::Vector2f(110, 200));
	// ______________________________________
	btn5->AddID(4);
	btn5->SetSprite(btnImage);
	btn5->SetLocation(sf::Vector2f(255, 200));
	// ______________________________________
	btn6->AddID(5);
	btn6->SetSprite(btnImage);
	btn6->SetLocation(sf::Vector2f(402, 200));
	// ______________________________________
	btn7->AddID(6);
	btn7->SetSprite(btnImage);
	btn7->SetLocation(sf::Vector2f(110, 348));
	// ______________________________________
	btn8->AddID(7);
	btn8->SetSprite(btnImage);
	btn8->SetLocation(sf::Vector2f(255, 348));
	// ______________________________________
	btn9->AddID(8);
	btn9->SetSprite(btnImage);
	btn9->SetLocation(sf::Vector2f(402, 348));


	while(app.isOpen()){

		while(app.pollEvent(event)){

			if(event.type == sf::Event::Closed)
				app.close();
		}

		core->AIBrain();

		btn1->EventHandle(app);
		btn2->EventHandle(app);
		btn3->EventHandle(app);
		btn4->EventHandle(app);
		btn5->EventHandle(app);
		btn6->EventHandle(app);
		btn7->EventHandle(app);
		btn8->EventHandle(app);
		btn9->EventHandle(app);

		app.clear();

		core->Render(app);
		btn1->Render(app);
		btn2->Render(app);
		btn3->Render(app);
		btn4->Render(app);
		btn5->Render(app);
		btn6->Render(app);
		btn7->Render(app);
		btn8->Render(app);
		btn9->Render(app);

		if( core->endMatch ){

			app.draw(core->screen);

			if( Timer::Delay(5.f) ){

				core->RestartMatch();
			}
		}

		app.display();
	}


	return 0;
}