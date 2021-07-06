
#include "../includes/Core.hpp"

Core::Core(){

	this->win  = 0;
	this->lose = 0;
	this->tie  = 0;

	// # Fill array
	for(int i = 0; i < 9; i++){

		this->table[ i ] = 'E';
	}

	// # Insert current playey
	this->currentTurn = 'X';

	// # Load Background images
	for(int i = 0; i < 5; i++ ){

		this->bg_tex[ i ].loadFromFile("./resource/BG_" + std::to_string( i + 1 ) + ".jpg");
	}

	// # Load Screen Images
	this->sc_tex[ 0 ].loadFromFile("./resource/WinScreen.png");
	this->sc_tex[ 1 ].loadFromFile("./resource/LoseScreen.png");
	this->sc_tex[ 2 ].loadFromFile("./resource/TieScreen.png");

	this->screen.setPosition(sf::Vector2f(15, 200));

	// # Hud Screen Image
	this->hud_tex.loadFromFile("./resource/HUD.jpg");
	this->HUD.setTexture(hud_tex);
	this->HUD.setPosition(sf::Vector2f(0, 500));

	this->background.setTexture(this->bg_tex[ 0 ]);

	this->grid_tex.loadFromFile("./resource/Grid.png");
	this->grid.setTexture(grid_tex);
	this->grid.setPosition(sf::Vector2f(0, -50));

	this->font.loadFromFile("./font/SuperMario256.ttf");

	this->h_win.setFont(this->font);
	this->h_win.setCharacterSize(30.f);
	this->h_win.setPosition(sf::Vector2f(115, 528));
	this->h_win.setFillColor(sf::Color(0, 245, 0, 255));

	this->h_lose.setFont(this->font);
	this->h_lose.setCharacterSize(30.f);
	this->h_lose.setPosition(sf::Vector2f(350, 528));
	this->h_lose.setFillColor(sf::Color(135, 45, 45, 255));

	this->h_tie.setFont(this->font);
	this->h_tie.setCharacterSize(30.f);
	this->h_tie.setPosition(sf::Vector2f(530, 528));
	this->h_tie.setFillColor(sf::Color(135, 145, 145, 255));

	this->h_current_player.setFont(this->font);
	this->h_current_player.setCharacterSize(25.f);
	this->h_current_player.setPosition(sf::Vector2f(30, 15));
	this->h_current_player.setFillColor(sf::Color(200, 205, 23, 255));

	// # Sound Load
	this->library[ 0 ].loadFromFile("./sounds/ButtonClick.wav");
	this->library[ 1 ].loadFromFile("./sounds/PlayerLose.wav");
	this->library[ 2 ].loadFromFile("./sounds/PlayerTie.wav");
	this->library[ 3 ].loadFromFile("./sounds/PlayerWin.wav");
	this->library[ 4 ].loadFromFile("./sounds/CardsGiven.wav");
}

void Core::Render(sf::RenderWindow& app){

	if( Timer::Delay(10.f ) ){

		++BG_Section;

		if(this->BG_Section > 4)
			this->BG_Section = 0;

		this->background.setTexture( this->bg_tex[ this->BG_Section ] );

	}

	app.draw(this->HUD);
	app.draw(this->background);
	app.draw(this->grid);

	// # Update and Draw scoreboard

	this->h_win.setString(std::to_string(this->win));
	this->h_lose.setString(std::to_string(this->lose));
	this->h_tie.setString(std::to_string(this->tie));

	if( this->playerturn )
		this->h_current_player.setString("Player is moving...");
	else
		this->h_current_player.setString("CPU is moving...");


	app.draw(this->h_win);
	app.draw(this->h_lose);
	app.draw(this->h_tie);
	app.draw(this->h_current_player);
}

uint16_t Core::CheckWins(){

	// # 0 = Win
	// # 1 = Tie
	// # 2 = Continue Game

	// # Player Check Wins #
	
	// # check first line horizontal
	if( table[ 0 ] == currentTurn && table[ 1 ] == currentTurn && table[ 2 ] == currentTurn )
		return 0;
	// # check second line horizontal
	if( table[ 3 ] == currentTurn && table[ 4 ] == currentTurn && table[ 5 ] == currentTurn )
		return 0;
	// # check third line horizontal
	if( table[ 6 ] == currentTurn && table[ 7 ] == currentTurn && table[ 8 ] == currentTurn )
		return 0;

	// # check first line vertical
	if( table[ 0 ] == currentTurn && table[ 3 ] == currentTurn && table[ 6 ] == currentTurn )
		return 0;
	// # check second line vertical
	if( table[ 1 ] == currentTurn && table[ 4 ] == currentTurn && table[ 7 ] == currentTurn )
		return 0;
	// # check third line vertical
	if( table[ 2 ] == currentTurn && table[ 5 ] == currentTurn && table[ 8 ] == currentTurn )
		return 0;

	// # check first line diagonal
	if( table[ 0 ] == currentTurn && table[ 4 ] == currentTurn && table[ 8 ] == currentTurn )
		return 0;
	// # check second line horizontal
	if( table[ 2 ] == currentTurn && table[ 4 ] == currentTurn && table[ 6 ] == currentTurn )
		return 0;
	
	size_t count;

	for(int i = 0; i < 9; i++){

		if( this->table[ i ] == 'E' )
			count++;
	}

	if( count > 0 ){

		return 2;
	}

	return 1;
}

void Core::EventHandle(int id){

	this->table[ id ] = this->currentTurn;

	this->play.setBuffer(this->library[ 0 ]);
	this->play.play();

	switch( CheckWins() ){

		case 0:

			if( playerturn ){

				this->win++;
				screen.setTexture(sc_tex[ 0 ]);
				this->play.setBuffer(this->library[ 3 ]);
				this->play.play();
				this->endMatch = true;
			}else{

				this->lose++;
				screen.setTexture(sc_tex[ 1 ]);

				if( ( rand() % 2 ) == 1 ){
					
					this->play.setBuffer(this->library[ 1 ]);
					this->play.play();
				}else{
					
					this->play.setBuffer(this->library[ 2 ]);
					this->play.play();
				}

				this->endMatch = true;
			}

			break;
		case 1:

			this->tie++;
			screen.setTexture(sc_tex[ 2 ]);
			this->play.setBuffer(this->library[ 2 ]);
			this->play.play();
			this->endMatch = true;
			break;

		default:
			

			if( currentTurn == 'X' ){
				
				currentTurn = 'O';
				playerturn = false;
			}else{

				currentTurn = 'X';
				playerturn = true;
			}

			break;
	}
}

void Core::RestartMatch(){

	this->play.setBuffer(this->library[ 4 ]);
	this->play.play();

	this->endMatch = false;
	this->playerturn  = true;
	this->currentTurn = 'X';
	this->countSpace = 0;

	for( int i = 0; i < 9; i++ ){

		this->table[ i ] = 'E';
	}
}

void Core::AIBrain(){

	if( !this->playerturn && endMatch == false ){


		if( Timer::Delay( 2.5f ) ){

			this->countSpace = 0;

			// # Check if end game
			for(int i = 0; i < 9; i++){
				
				if( table[ i ] == 'E' ){
					this->countSpace++; 
				}
			}

			if( this->countSpace <= 0 ){

				this->tie++;
				screen.setTexture(sc_tex[ 2 ]);
				this->play.setBuffer(this->library[ 2 ]);
				this->play.play();
				this->endMatch = true;
				
			}else if(this->countSpace == 1){

				for(int i = 0; i < 9; i++){
				
					if( table[ i ] == 'E' ){
						EventHandle( i ); 
					}
				}
			}else{

				this->chooseButton = true;

				while( this->chooseButton ){
				
					this->buttonID = rand() % 9;

					for(int i = 0; i < 9; i++){
				
						if( table[ buttonID ] == 'E' ){
							this->EventHandle( buttonID );
							this->chooseButton = false;
							break;
						}
					}
				}

			}

			// #---------------------------
		}
	}
}