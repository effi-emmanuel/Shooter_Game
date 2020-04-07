#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

/*This is basically a shooting game with 7 levels with which the strength of the CPU's bullets increase on each level*/

bool gameover;
bool enemydead;
int width = 20;
int height = 20;
int shooterX, shooterY, enemyX, enemyY, score, life;
int shooter_ballX, shooter_ballY, enemy_ballX, enemy_ballY;
int nextshooter_ballY, nextshooter_ballX, nextenemy_ballY, nextenemy_ballX;
int nextnextshooter_ballX, nextnextshooter_ballY, nextnextenemy_ballX, nextnextenemy_ballY;
int n_sball;
bool l1, l2, l3, l4, l5, l6, l7;


//This section controls shooting with key 'w'
enum Direction{
	STOP = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

Direction direction;
//end of Direction

//This section controls shooting with key 'q'
enum dir{
	STOP2 = 0,
	UP2,
	DOWN2,
	LEFT2,
	RIGHT2
};

dir direction2;
//end of direction


//This section controls shooting with key 'e'
enum direc{
	STOP3 = 0,
	UP3,
	DOWN3,
	LEFT3,
	RIGHT3
};

direc direction3;
//end of direc

//This is the initial setup of the game 
void setup(){
	l1 = true;
	l2 = false;
	l3 = false;
	l4 = false;
	l5 = false;
	l6 = false;
	l7 = false;
	gameover = false;
	enemydead = false;
	score = 0;
	life = 100;
	shooterX = width/2;
	shooterY = 20;
	enemyX = 0;
	enemyY = 15;
	shooter_ballX = enemyX;
	shooter_ballY = enemyY;
	n_sball = 2;
	nextshooter_ballX = shooter_ballX;
	nextshooter_ballY = shooter_ballY;
	nextnextshooter_ballX = shooter_ballX;
	nextnextshooter_ballY = shooter_ballY;
	enemy_ballX = enemyX;
	enemy_ballY = enemyY;
	nextenemy_ballX = enemy_ballX;
	nextenemy_ballY = enemy_ballY;
	nextnextenemy_ballX = nextenemy_ballX;
	nextnextenemy_ballY = nextenemy_ballY;
}
//end of setup function

//This function controls what appears on the screen
void draw(){
	system("cls");
	system("color F5");
	
	//This loop prints out the first width wall
	for(int i=1; i <= width+2; i++){
		cout<< "#";
	}
	cout<<endl;
	
	//This loop prints out the vertical walls
	for(int i = 1; i <=height; i++){
		for(int j = 1; j<=width+1; j++){
			//The statement takes care of the first wall
			if(j == 1){
				cout<< "#";
			}
			if(i == shooterY && j==shooterX){
				cout<< "O";//This prints out the shooter
			}
			
			if(i == shooter_ballY && j==shooter_ballX){
				cout<< "oo";
			}
			if(i == nextshooter_ballY && j== nextshooter_ballX){
				cout<< "oo";
			}	
			if(i == nextnextshooter_ballY && j== nextnextshooter_ballX){
				cout<< "oo";
			}if(i == enemyY && j == enemyX){
				cout<< "V";//This prints out the enemy
			}if(i == enemy_ballY && j == enemy_ballX){
				cout<< "oo";
				if(l3 == true){
					cout<< "oo";
				}
				else if(l5 == true){
					cout<< "o0o";
				}
				else if(l7 == true){
					cout << "000";
				}
			}if(i == nextenemy_ballY && j == nextenemy_ballX){
				cout<< "oo";
				if(l3 == true){
					cout<< "oo";
				}
				else if(l5 == true){
					cout<< "o0o";
				}
				else if(l7 == true){
					cout << "000";
				}
			}if(i == nextnextenemy_ballY && j == nextnextenemy_ballX){
				cout<< "oo";
				if(l3 == true){
					cout<< "oo";
				}
				else if(l5 == true){
					cout<< "o0o";
				}
				else if(l7 == true){
					cout << "000";
				}
			}else{//This takes care of the space inbetween
				cout<< " ";
			}
			if(j == width){//This statement takes care of the second vertical wall
				cout<< "#";
			}
		}
		cout<< endl;
	}
	
	//This loop prints out the lower width wall
	for(int i=1; i<= width+2; i++){
		cout<< "#";
	}
	cout<<endl;
	cout<< "LIFE: "<<life <<endl;
	cout<< "SCORE: "<< score;
}
//end of draw function

//This function controls the users' kryboard hits and all controls
void input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				shooterX--;
				break;
			case 'd':
				shooterX++;
				break;
			case 'w':
				shooterY--;
				break;
			case 's':
				shooterY++; 
				break;		
			case 'x':
				gameover = true;
				break;
				
			case'j':
				direction = UP;
				shooter_ballX = shooterX;
				shooter_ballY = shooterY;
				enemy_ballX = enemyX;
				enemy_ballY = enemyY;
				break;
			case 'k':
				direction2 = UP2;	
				nextshooter_ballX = shooterX;
				nextshooter_ballY = shooterY;
				nextenemy_ballX = enemyX;
				nextenemy_ballY = enemyY;
				break;
			case 'l':
				direction3 = UP3;	
				nextnextshooter_ballX = shooterX;
				nextnextshooter_ballY = shooterY;
				nextnextenemy_ballX = enemyX;
				nextnextenemy_ballY = enemyY;
				break;
		}
	}
}
//end of input function


//All the game's real background codes go here
void logic(){
	
	//This for loop controls the position of the enemy
	for(int a=0; a<width; a++){
		enemyX = rand() % width;
		enemy_ballX = enemyX;
		if(a<width){
			enemyX++;
		}
		if(a == width){
			enemyX--;
		}
	}
	//This switch statement handles shooting with the key 'w'
	switch(direction){
		case UP:
			shooter_ballY--;
			enemy_ballY++;
			break;	
	}
	
	//This switch statement handles shooting with the key 'q'
	switch(direction2){
		case UP2:
			nextshooter_ballY--;
			nextenemy_ballY++;
			break;
	}
	
	//This switch statement handles shooting with the key 'e'
	switch(direction3){
		case UP3:
			nextnextshooter_ballY--;
			nextnextenemy_ballY++;
			break;
	}
	
	if(enemy_ballY == shooterY && enemy_ballX == shooterX){
		life-=5;
	}
	if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
		life-=5;
	}
	if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
		life-=5;
	}
	
	//This section checks for hits on the enemy
	if(shooter_ballY == enemyY && shooter_ballX == enemyX){
		score +=10;
	}
	if(nextshooter_ballY == enemyY && nextshooter_ballX == enemyX){
		score +=10;
	}
	if(nextnextshooter_ballY == enemyY && nextnextshooter_ballX == enemyX){
		score +=10;
	}
	
	
	//LEVEL 2
	if(score == 20){
		enemydead == true;
		cout<< endl << endl << "LEVEL 1 PASSED" << endl;
		cout<< "LEVEL 2" << endl;
		l2 = true;
		enemyY = 13;
		if(enemy_ballY == shooterY && enemy_ballX == shooterX){
			life-=10;
		}
		if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
			life-=10;
		}
		if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
			life-=10;
		}
		for(int a=0; a<width; a++){
			enemyX = rand() % width;
			if(a<width){
				enemyX++;	
			}
			if(a == width){
				enemyX--;
			}
		}
	}
	
	//LEVEL 3
	if(score == 30){
		enemydead == true;
		cout<< endl << endl << "LEVEL 2 PASSED" << endl;
		cout<< "LEVEL 3" << endl;
		l3 = true;
		enemyY = 10;
		if(enemy_ballY == shooterY && enemy_ballX == shooterX){
			life-=15;
		}
		if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
			life-=15;
		}
		if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
			life-=15;
		}
		for(int a=0; a<width; a++){
			enemyX = rand() % width;
			if(a<width){
				enemyX++;	
			}
			if(a == width){
				enemyX--;
			}
		}
	}
	
	//LEVEL 4
	if(score == 40){
		enemydead == true;
		cout<< endl << endl << "LEVEL 3 PASSED" << endl;
		cout<< "LEVEL 4" << endl;
		l4 = true;
		enemyY = 8;
		if(enemy_ballY == shooterY && enemy_ballX == shooterX){
			life-=20;
		}
		if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
			life-=20;
		}
		if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
			life-=20;
		}
		for(int a=0; a<width; a++){
			enemyX = rand() % width;
			if(a<width){
				enemyX++;	
			}
			if(a == width){
				enemyX--;
			}
		}
	}
	
	//LEVEL 5
	if(score == 50){
		enemydead == true;
		cout<< endl << endl << "LEVEL 4 PASSED" << endl;
		cout<< "LEVEL 5" << endl;
		l5 = true;
		enemyY = 5;
		if(enemy_ballY == shooterY && enemy_ballX == shooterX){
			life-=25;
		}
		if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
			life-=25;
		}
		if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
			life-=25;
		}
		for(int a=0; a<width; a++){
			enemyX = rand() % width;
			if(a<width){
				enemyX++;	
			}
			if(a == width){
				enemyX--;
			}
		}
	}
	
	//LEVEL 6
	if(score == 60){
		enemydead == true;
		cout<< endl << endl << "LEVEL 5 PASSED" << endl;
		cout<< "LEVEL 6" << endl;
		l6 = true;
		enemyY = 3;
		if(enemy_ballY == shooterY && enemy_ballX == shooterX){
			life-=30;
		}
		if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
			life-=30;
		}
		if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
			life-=30;
		}
		for(int a=0; a<width; a++){
			enemyX = rand() % width;
			if(a<width){
				enemyX++;	
			}
			if(a == width){
				enemyX--;
			}
		}
	}
	
	//LEVEL 7
	if(score == 70){
		enemydead == true;
		cout<< endl << endl << "LEVEL 6 PASSED" << endl;
		cout<< "BOSS LEVEL" << endl;
		l7 = true;
		enemyY = 1;
		if(enemy_ballY == shooterY && enemy_ballX == shooterX){
			life-=40;
		}
		if(nextenemy_ballY == shooterY && nextenemy_ballX == shooterX){
			life-=40;
		}
		if(nextnextenemy_ballY == shooterY && nextnextenemy_ballX == shooterX){
			life-=40;
		}
		for(int a=0; a<width; a++){
			enemyX = rand() % width;
			if(a<width){
				enemyX++;	
			}
			if(a == width){
				enemyX--;
			}
		}
	}
	
	//end credits
	if(score >= 100){
		cout<< endl<< endl<< "You defeated the final boss!" << endl;
		cout<< "Gun shooter. Copyright Gethsemane\'s Trademark 2019";
		gameover = true;
		getch();
	}
	
	if(life <= 0){
		cout<< "GAMEOVER";
		gameover = true;
		getch();
	}
	//end of statement
}
//end of logic function


//Main Function
int main() {
	
	setup();
	
	while(!gameover){
		draw();
		input();
		logic();
		Sleep(150);
	}
	return 0;
}
