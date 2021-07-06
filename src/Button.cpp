#include "../includes/Button.hpp"

Button::Button(Core* core) {

	this->core = core;
}

void Button::SetSprite(sf::Texture* tex){

	this->btnTexs = tex;
	this->btnSpr.setTexture(this->btnTexs[ 0 ]);
}

void Button::AddID(int ID){

	this->id = ID;
}

void Button::Render(sf::RenderWindow& app){

	app.draw(btnSpr);
}

void Button::SetLocation(sf::Vector2f pos){

	this->btnSpr.setPosition(pos);
}

void Button::EventHandle(sf::RenderWindow& app){

	if( this->core->table[ this->id ] != 'E'){

		if( this->core->table[ this->id ] == 'X' ){
			
			this->btnSpr.setTexture(this->btnTexs[ 1 ]);
		}else{

			this->btnSpr.setTexture(this->btnTexs[ 2 ]);
		}
		this->locked = true;
	}else{

		this->locked = false;
		this->btnSpr.setTexture(this->btnTexs[ 0 ]);
	}


	if( sf::Mouse::isButtonPressed(sf::Mouse::Left) ){

		
		if( this->core->playerturn && this->locked == false ){

			// # Check if mouse over here

			if( this->btnSpr.getPosition().x < sf::Mouse::getPosition(app).x 
			&& this->btnSpr.getPosition().y < sf::Mouse::getPosition(app).y 
			&& this->btnSpr.getPosition().x + 120 > sf::Mouse::getPosition(app).x 
			&& this->btnSpr.getPosition().y + 120 > sf::Mouse::getPosition(app).y ){

				this->core->EventHandle(this->id);

				this->locked = true;

			}
		}
	}
}