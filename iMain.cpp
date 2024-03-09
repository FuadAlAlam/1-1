#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

bool musicOn = true;

int a, b, t, game_state=0, level_state=0, timer1=0, timer2;

double x, y, g, h;

char anishow [100][90] = { "play//00001.bmp",
"play//00002.bmp",
"play//00003.bmp",
"play//00004.bmp",
"play//00005.bmp",
"play//00006.bmp",
"play//00007.bmp",
"play//00008.bmp",
"play//00009.bmp",
"play//00010.bmp",
"play//00011.bmp",
"play//00012.bmp",
"play//00013.bmp",
"play//00014.bmp",
"play//00015.bmp",
"play//00016.bmp",
"play//00017.bmp",
"play//00018.bmp",
"play//00019.bmp",
"play//00020.bmp",
"play//00021.bmp",
"play//00022.bmp",
"play//00023.bmp",
"play//00024.bmp",
"play//00025.bmp",
"play//00026.bmp",
"play//00027.bmp",
"play//00028.bmp",
"play//00029.bmp",
"play//00030.bmp",
"play//00031.bmp",
"play//00032.bmp",
"play//00033.bmp",
"play//00034.bmp",
"play//00035.bmp",
"play//00036.bmp",
"play//00037.bmp",
"play//00038.bmp",
"play//00039.bmp",
"play//00040.bmp",
"play//00041.bmp",
"play//00042.bmp",
"play//00043.bmp",
"play//00044.bmp",
"play//00045.bmp",
"play//00046.bmp",
"play//00047.bmp",
"play//00048.bmp",
"play//00049.bmp",
"play//00050.bmp"
};

int ani=0;

char puzzle[9][15][15], sketch[9][15][15], solve[9][15][15], hint[9][15][15][2], reveal[9][15][15];

char puzzle1[2][5][5], sketch1[2][5][5], solve1[2][5][5], hint1[2][5][5], reveal1[2][5][5];

char puzzle3[2][10][10], sketch2[2][10][10], solve2[2][10][10], hint2[2][10][10][2], reveal2[2][10][10];

char str[100], str1[100], str2[100], showtime[100];

void func(){
	if(game_state == 3){
		timer1++;
		int min=timer1/60, sec=timer1 - (timer1/60)*60;
		showtime[0] = min/10 + '0';
		showtime[1] = min%10 + '0';
		showtime[2] = sec/10 + '0';
		showtime[3] = sec%10 + '0';
	}
}

void animation(){
	if(ani<49){
		ani++;
	}
}

void iDraw() {
    iClear();

	//homepage

	if(game_state == 0){

		if(musicOn == true){
			iShowBMP(0, 0, "Page//home_audio-on.bmp");
		}

		else if(musicOn == false){
			iShowBMP(0, 0, "Page//home_audio-off.bmp");
		}

	}
	
	//menupage

	else if(game_state == 1){
		if(musicOn == true){
			iShowBMP(0, 0, "Page//menu_audio-on.bmp");
		}

		else if(musicOn == false){
			iShowBMP(0, 0, "Page//menu_audio-off.bmp");
		}

		if(ani<48){
			iShowBMP(0, 0, anishow[ani]);
		}
	}

	//which puzzle

	else if(game_state == 2){

		if(musicOn == true){
			iShowBMP(0, 0, "Page//which_puzzle_audio-on.bmp");
		}

		else if(musicOn == false){
			iShowBMP(0, 0, "Page//which_puzzle_audio-off.bmp");
		}

	}

	//instructions

	else if(game_state == 5){
		iShowBMP(0, 0, "Page//instructions.bmp");
	}

	//about

	else if(game_state == 6){
		iShowBMP(0, 0, "Page//about.bmp");
	}

	//main game

	else if(game_state == 3){
		
		if(level_state == 1){

	if(musicOn == true){
		iShowBMP(0, 0, "Page//main_audio-on.bmp");
	}

	else if(musicOn == false){
		iShowBMP(0, 0, "Page//main_audio-off.bmp");
	}

  	iSetColor(255, 255, 255);
  	iFilledRectangle(100, 50, 600, 600);
  	for(int i=100; i<700; i+=40){
    	for(int j=50; j<650; j+=40){
      		iSetColor(0, 0, 0);
      		iRectangle(i, j, 40, 40);
    	}
  	}

	//mark

	a=(x-100)/40;
	b=14 - (y-50)/40;

  	if(x!= 0 && y!= 0 && puzzle[t][b][a] != '*'){
    	iSetColor(255, 0, 0);
    	iRectangle(x, y, 40, 40);
		iSetColor(245, 210, 210);
		iFilledRectangle(x+1, y+1, 38, 38);
  	}
  	else{
    	for(int i=100; i<700; i+=40){
      		for(int j=50; j<650; j+=40){
        		iSetColor(0, 0, 0);
        		iRectangle(i, j, 40, 40);
      		}
    	}
  	}

	//timer

	iSetColor(0, 0, 0);
	str2[0] = showtime[0];
	iText(900, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[1];
	iText(930, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = ':';
	iText(950, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[2];
	iText(960, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[3];
	iText(990, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);

	//solve puzzle
	
	for(int i=100; i<700; i+=40){
		for(int j=50; j<650; j+=40){
				iSetColor(0,0,0);
				str2[0] = solve[t][14 - (j-50)/40][(i-100)/40];
				iText(i+10, j+10, str2, GLUT_BITMAP_TIMES_ROMAN_24);
				if(puzzle[t][14 - (j-50)/40][(i-100)/40] == '*'){
					iSetColor(0, 0, 0);
					iFilledRectangle(i, j, 40, 40);
				}
		}
	}

	//show puzzle

	/*for(int i=100; i<700; i+=40){
		for(int j=50; j<650; j+=40){
			iSetColor(0,0,0);
			str2[0] = puzzle[t][14 - (j-50)/40][(i-100)/40];
        	iText(i+10, j+10, str2, GLUT_BITMAP_TIMES_ROMAN_24);
			if(puzzle[t][14 - (j-50)/40][(i-100)/40] == '*'){
				iSetColor(0, 0, 0);
				iFilledRectangle(i, j, 40, 40);
			}
		}
	}*/

	//show hint

	if(t==0){iShowBMP(750, 100, "Hint//hint 1.bmp");}
    else if(t==1){iShowBMP(750, 100, "Hint//hint 2.bmp");}
	else if(t==2){iShowBMP(750, 100, "Hint//hint 3.bmp");}
	else if(t==3){iShowBMP(750, 100, "Hint//hint 4.bmp");}
	else if(t==4){iShowBMP(750, 100, "Hint//hint 5.bmp");}
	else if(t==5){iShowBMP(750, 100, "Hint//hint 6.bmp");}
	else if(t==6){iShowBMP(750, 100, "Hint//hint 7.bmp");}
	else if(t==7){iShowBMP(750, 100, "Hint//hint 8.bmp");}

	//hint number

	for(int i=100; i<700; i+=40){
		for(int j=50; j<650; j+=40){
			if(hint[t][14 - (j-50)/40][(i-100)/40][0] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint[t][14 - (j-50)/40][(i-100)/40][0];
        		iText(i+2, j+32, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
			if(hint[t][14 - (j-50)/40][(i-100)/40][1] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint[t][14 - (j-50)/40][(i-100)/40][1];
        		iText(i+7, j+32, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
		}
	}

	//check

	int flag = 0;
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			if(solve[t][i][j] != puzzle[t][i][j]){
				flag = -1;
				break;
			}
		}
		if(flag == -1) break;
	}
	if(flag == 0){
		//Win condition
		game_state = 4;
		for(int i=0; i<9; i++){
		for(int j=0; j<15; j++){
			for(int k=0; k<15; k++){
				if(puzzle[i][j][k] != '*'){
					sketch[i][j][k] = ' ';
					solve[i][j][k] = ' ';
					reveal[i][j][k] = 'n';
				}
			}
		}
	}
	}

	}

	//medium

	else if(level_state == 2){

	if(musicOn == true){
		iShowBMP(0, 0, "Page//main_audio-on.bmp");
	}

	else if(musicOn == false){
		iShowBMP(0, 0, "Page//main_audio-off.bmp");
	}

  	iSetColor(255, 255, 255);
  	iFilledRectangle(100, 50, 600, 600);
  	for(int i=100; i<700; i+=60){
    	for(int j=50; j<650; j+=60){
      		iSetColor(0, 0, 0);
      		iRectangle(i, j, 60, 60);
    	}
  	}

	//mark

	a=(x-100)/60;
	b=9 - (y-50)/60;

  	if(x!= 0 && y!= 0 && puzzle3[t][b][a] != '*'){
    	iSetColor(255, 0, 0);
    	iRectangle(x, y, 60, 60);
		iSetColor(245, 210, 210);
		iFilledRectangle(x+1, y+1, 58, 58);
  	}
  	else{
    	for(int i=100; i<700; i+=60){
      		for(int j=50; j<650; j+=60){
        		iSetColor(0, 0, 0);
        		iRectangle(i, j, 60, 60);
      		}
    	}
  	}

	//timer

	iSetColor(0, 0, 0);
	str2[0] = showtime[0];
	iText(900, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[1];
	iText(930, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = ':';
	iText(950, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[2];
	iText(960, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[3];
	iText(990, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);

	//solve puzzle
	
	for(int i=100; i<700; i+=60){
		for(int j=50; j<650; j+=60){
				iSetColor(0,0,0);
				str2[0] = solve2[t][9 - (j-50)/60][(i-100)/60];
				iText(i+20, j+20, str2, GLUT_BITMAP_TIMES_ROMAN_24);
				if(puzzle3[t][9 - (j-50)/60][(i-100)/60] == '*'){
					iSetColor(0, 0, 0);
					iFilledRectangle(i, j, 60, 60);
				}
		}
	}

	//show puzzle

	/*for(int i=100; i<700; i+=60){
		for(int j=50; j<650; j+=60){
			iSetColor(0,0,0);
			str2[0] = puzzle3[t][9 - (j-50)/60][(i-100)/60];
        	iText(i+20, j+20, str2, GLUT_BITMAP_TIMES_ROMAN_24);
			if(puzzle3[t][9 - (j-50)/60][(i-100)/60] == '*'){
				iSetColor(0, 0, 0);
				iFilledRectangle(i, j, 60, 60);
			}
		}
	}*/

	//show hint

	if(t==0){
		iShowBMP(750, 100, "Hint//hint2_1_2.bmp");
		iShowBMP(850, 225, "Hint//hint2_1_1.bmp");
	}
    else if(t==1){
		iShowBMP(750, 100, "Hint//hint2_2_2.bmp");
		iShowBMP(850, 178, "Hint//hint2_2_1.bmp");
	}

	//hint number

	for(int i=100; i<700; i+=60){
		for(int j=50; j<650; j+=60){
			if(hint2[t][9 - (j-50)/60][(i-100)/60][0] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint2[t][9 - (j-50)/60][(i-100)/60][0];
        		iText(i+2, j+52, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
			if(hint2[t][9 - (j-50)/60][(i-100)/60][1] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint2[t][9 - (j-50)/60][(i-100)/60][1];
        		iText(i+7, j+52, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
		}
	}

	//check

	int flag = 0;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(solve2[t][i][j] != puzzle3[t][i][j]){
				flag = -1;
				break;
			}
		}
		if(flag == -1) break;
	}
	if(flag == 0){
		//Win condition
		game_state = 4;
		for(int i=0; i<2; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				if(puzzle3[i][j][k] != '*'){
					sketch2[i][j][k] = ' ';
					solve2[i][j][k] = ' ';
					reveal2[i][j][k] = 'n';
				}
			}
		}
	}}

	}

	//easy
	else if(level_state == 3){

	if(musicOn == true){
		iShowBMP(0, 0, "Page//main_audio-on.bmp");
	}

	else if(musicOn == false){
		iShowBMP(0, 0, "Page//main_audio-off.bmp");
	}

  	iSetColor(255, 255, 255);
  	iFilledRectangle(200, 200, 300, 300);
  	for(int i=200; i<500; i+=60){
    	for(int j=200; j<500; j+=60){
      		iSetColor(0, 0, 0);
      		iRectangle(i, j, 60, 60);
    	}
  	}

	//mark

	a=(x-200)/60;
	b=4 - (y-200)/60;

  	if(x!= 0 && y!= 0 && puzzle1[t][b][a] != '*'){
    	iSetColor(255, 0, 0);
    	iRectangle(x, y, 60, 60);
		iSetColor(245, 210, 210);
		iFilledRectangle(x+1, y+1, 58, 58);
  	}
  	else{
    	for(int i=200; i<500; i+=60){
      		for(int j=200; j<500; j+=60){
        		iSetColor(0, 0, 0);
        		iRectangle(i, j, 60, 60);
      		}
    	}
  	}

	//timer

	iSetColor(0, 0, 0);
	str2[0] = showtime[0];
	iText(900, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[1];
	iText(930, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = ':';
	iText(950, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[2];
	iText(960, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	str2[0] = showtime[3];
	iText(990, 643, str2, GLUT_BITMAP_TIMES_ROMAN_24);

	//solve puzzle
	
	for(int i=200; i<500; i+=60){
		for(int j=200; j<500; j+=60){
				iSetColor(0,0,0);
				str2[0] = solve1[t][4 - (j-200)/60][(i-200)/60];
				iText(i+20, j+20, str2, GLUT_BITMAP_TIMES_ROMAN_24);
				if(puzzle1[t][4 - (j-200)/60][(i-200)/60] == '*'){
					iSetColor(0, 0, 0);
					iFilledRectangle(i, j, 60, 60);
				}
		}
	}

	//show puzzle

	/*for(int i=200; i<500; i+=60){
		for(int j=200; j<500; j+=60){
			iSetColor(0,0,0);
			str2[0] = puzzle1[t][4 - (j-200)/60][(i-200)/60];
        	iText(i+20, j+20, str2, GLUT_BITMAP_TIMES_ROMAN_24);
			if(puzzle1[t][4 - (j-200)/60][(i-200)/60] == '*'){
				iSetColor(0, 0, 0);
				iFilledRectangle(i, j, 60, 60);
			}
		}
	}*/

	//show hint

	if(t==0){iShowBMP(750, 200, "Hint//hint1-1.bmp");}
    else if(t==1){iShowBMP(750, 200, "Hint//hint1-2.bmp");}

	//hint number

	for(int i=200; i<500; i+=60){
		for(int j=200; j<500; j+=60){
			if(hint1[t][4 - (j-200)/60][(i-200)/60] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint1[t][4 - (j-200)/60][(i-200)/60];
        		iText(i+2, j+52, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
		}
	}

	//check

	int flag = 0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(solve1[t][i][j] != puzzle1[t][i][j]){
				flag = -1;
				break;
			}
		}
		if(flag == -1) break;
	}
	if(flag == 0){
		//Win condition
		game_state = 4;
		for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				if(puzzle1[i][j][k] != '*'){
					sketch1[i][j][k] = ' ';
					solve1[i][j][k] = ' ';
					reveal1[i][j][k] = 'n';
				}
			}
		}
	}
	}

	}
}

	//you win

	else if(game_state == 4){
		if(musicOn == true){
			iShowBMP(0, 0, "Page//Win_audio-on.bmp");
		}

		else if(musicOn == false){
			iShowBMP(0, 0, "Page//Win_audio-off.bmp");
		}

		iSetColor(0, 0, 0);
		str2[0] = showtime[0];
		iText(460, 338, str2, GLUT_BITMAP_TIMES_ROMAN_24);
		str2[0] = showtime[1];
		iText(490, 338, str2, GLUT_BITMAP_TIMES_ROMAN_24);
		str2[0] = ':';
		iText(520, 338, str2, GLUT_BITMAP_TIMES_ROMAN_24);
		str2[0] = showtime[2];
		iText(550, 338, str2, GLUT_BITMAP_TIMES_ROMAN_24);
		str2[0] = showtime[3];
		iText(580, 338, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if(game_state == 10){
		if(musicOn == true){
			iShowBMP(0, 0, "Page//give_up_audio-on.bmp");
		}

		else if(musicOn == false){
			iShowBMP(0, 0, "Page//give_up_audio-off.bmp");
		}

		if(level_state==1){
			iSetColor(255, 255, 255);
  		iFilledRectangle(100, 50, 600, 600);
  		for(int i=100; i<700; i+=40){
    	for(int j=50; j<650; j+=40){
      		iSetColor(0, 0, 0);
      		iRectangle(i, j, 40, 40);
    	}
  		}

		for(int i=100; i<700; i+=40){
		for(int j=50; j<650; j+=40){
			iSetColor(0,0,0);
			str2[0] = puzzle[t][14 - (j-50)/40][(i-100)/40];
        	iText(i+10, j+10, str2, GLUT_BITMAP_TIMES_ROMAN_24);
			if(puzzle[t][14 - (j-50)/40][(i-100)/40] == '*'){
				iSetColor(0, 0, 0);
				iFilledRectangle(i, j, 40, 40);
			}
		}
	}

	//show hint

	if(t==0){iShowBMP(750, 100, "Hint//hint 1.bmp");}
    else if(t==1){iShowBMP(750, 100, "Hint//hint 2.bmp");}
	else if(t==2){iShowBMP(750, 100, "Hint//hint 3.bmp");}
	else if(t==3){iShowBMP(750, 100, "Hint//hint 4.bmp");}
	else if(t==4){iShowBMP(750, 100, "Hint//hint 5.bmp");}
	else if(t==5){iShowBMP(750, 100, "Hint//hint 6.bmp");}
	else if(t==6){iShowBMP(750, 100, "Hint//hint 7.bmp");}
	else if(t==7){iShowBMP(750, 100, "Hint//hint 8.bmp");}

	//hint number

	for(int i=100; i<700; i+=40){
		for(int j=50; j<650; j+=40){
			if(hint[t][14 - (j-50)/40][(i-100)/40][0] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint[t][14 - (j-50)/40][(i-100)/40][0];
        		iText(i+2, j+32, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
			if(hint[t][14 - (j-50)/40][(i-100)/40][1] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint[t][14 - (j-50)/40][(i-100)/40][1];
        		iText(i+7, j+32, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
		}
	}
		}


		else if(level_state == 2){
			iSetColor(255, 255, 255);
  	iFilledRectangle(100, 50, 600, 600);
  	for(int i=100; i<700; i+=60){
    	for(int j=50; j<650; j+=60){
      		iSetColor(0, 0, 0);
      		iRectangle(i, j, 60, 60);
    	}
  	}

			for(int i=100; i<700; i+=60){
		for(int j=50; j<650; j+=60){
			iSetColor(0,0,0);
			str2[0] = puzzle3[t][9 - (j-50)/60][(i-100)/60];
        	iText(i+20, j+20, str2, GLUT_BITMAP_TIMES_ROMAN_24);
			if(puzzle3[t][9 - (j-50)/60][(i-100)/60] == '*'){
				iSetColor(0, 0, 0);
				iFilledRectangle(i, j, 60, 60);
			}
		}
	}

	for(int i=100; i<700; i+=60){
		for(int j=50; j<650; j+=60){
			if(hint2[t][9 - (j-50)/60][(i-100)/60][0] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint2[t][9 - (j-50)/60][(i-100)/60][0];
        		iText(i+2, j+52, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
			if(hint2[t][9 - (j-50)/60][(i-100)/60][1] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint2[t][9 - (j-50)/60][(i-100)/60][1];
        		iText(i+7, j+52, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
		}
	}

	//show hint

	if(t==0){
		iShowBMP(750, 100, "Hint//hint2_1_2.bmp");
		iShowBMP(850, 225, "Hint//hint2_1_1.bmp");
	}
    else if(t==1){
		iShowBMP(750, 100, "Hint//hint2_2_2.bmp");
		iShowBMP(850, 178, "Hint//hint2_2_1.bmp");
	}
		}



		else if(level_state==3){
			iSetColor(255, 255, 255);
  	iFilledRectangle(200, 200, 300, 300);
  	for(int i=200; i<500; i+=60){
    	for(int j=200; j<500; j+=60){
      		iSetColor(0, 0, 0);
      		iRectangle(i, j, 60, 60);
    	}
  	}

		for(int i=200; i<500; i+=60){
		for(int j=200; j<500; j+=60){
			iSetColor(0,0,0);
			str2[0] = puzzle1[t][4 - (j-200)/60][(i-200)/60];
        	iText(i+20, j+20, str2, GLUT_BITMAP_TIMES_ROMAN_24);
			if(puzzle1[t][4 - (j-200)/60][(i-200)/60] == '*'){
				iSetColor(0, 0, 0);
				iFilledRectangle(i, j, 60, 60);
			}
		}
	}

		//hint number

	for(int i=200; i<500; i+=60){
		for(int j=200; j<500; j+=60){
			if(hint1[t][4 - (j-200)/60][(i-200)/60] != '*'){
				iSetColor(0,0,0);
				str1[0] = hint1[t][4 - (j-200)/60][(i-200)/60];
        		iText(i+2, j+52, str1, GLUT_BITMAP_TIMES_ROMAN_10);
			}
		}
	}

	if(t==0){iShowBMP(750, 200, "Hint//hint1-1.bmp");}
    else if(t==1){iShowBMP(750, 200, "Hint//hint1-2.bmp");}
		}
	}

}

void iMouseMove(int mx, int my) {
  	printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my) {
  	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		g = mx, h = my;

		if(game_state == 0){

			if(musicOn == true){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}

			else if(musicOn == false){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = true;
					PlaySound("Music//Tokyo_Ghoul.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}

			if(g >= 76 && g <= 262 && h >= 150 && h <= 220){
				exit(0);
			}
			else if(g >= 76 && g <= 262 && h >= 258 && h <= 329){
				game_state = 1;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Death_Note.wav", NULL, SND_LOOP | SND_ASYNC);
				}

				ani=0;
			}

		}

		else if(game_state == 1){
			if(musicOn == true){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}

			else if(musicOn == false){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = true;
					PlaySound("Music\\Death_Note.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}

			if(g >= 80 && g <= 335 && h >= 76 && h <= 140){
				game_state = 6;
			}
			else if(g >= 80 && g <= 335 && h >= 170 && h <= 232){
				game_state = 5;
			}
			else if(g >= 80 && g <= 335 && h >= 265 && h <= 324){
				game_state = 2;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Death_Note.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			else if(g >= 997 && g <= 1180 && h >= 35 && h <= 105){
				game_state = 0;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Tokyo_Ghoul.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}

		else if(game_state == 2){

			if(musicOn == true){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}

			else if(musicOn == false){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = true;
					PlaySound("Music\\Death_Note.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			
			if(g >= 973 && g<= 1172 && h >= 27 && h <= 112){
				game_state = 1;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Death_Note.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}

			else if(g >= 110 && g <= 360 && h >= 75 && h <= 135){
				//hard
				level_state = 1;
				t = rand() % 8;
				game_state = 3;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Piano.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}

			else if(g >= 110 && g <= 360 && h >= 175 && h <= 240){
				//medium
				level_state = 2;
				printf("haha");
				t= rand() % 2;
				game_state = 3;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Piano.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}

			else if(g >= 110 && g <= 360 && h >= 280 && h <= 340){
				//easy
				level_state = 3;
				t = rand() % 2;
				game_state = 3;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Piano.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}

		else if(game_state == 5){
			if(g >= 960 && g<= 1130 && h >= 50 && h <= 120){
				game_state = 1;
			}
		}

		else if(game_state == 6){
			if(g >= 30 && g<= 210 && h >= 590 && h <= 660){
				game_state = 1;
			}
		}

		else if(game_state == 4){

			if(musicOn == true){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}

			else if(musicOn == false){
				if((g-1094)*(g-1094) + (h-609)*(h-609) < 50*50){
					musicOn = true;
					PlaySound("Music\\Pubg.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}

			if(g >= 90 && g<= 480 && h >= 105 && h <= 180){
				timer1=0;
				level_state = 0;
				game_state = 0;
				if(musicOn == true){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Pubg.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}

		else if(game_state == 3){

		if(musicOn == true){
				if((g-1148)*(g-1148) + (h-650)*(h-650) < 35*35){
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}

		else if(musicOn == false){
				if((g-1148)*(g-1148) + (h-650)*(h-650) < 35*35){
					musicOn = true;
					PlaySound("Music\\Piano.wav", NULL, SND_LOOP | SND_ASYNC);
				}
		}

		if(g>=960 && g<= 1170 && h>=22 && h<=82){
			timer1=0;
			for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				if(puzzle1[i][j][k] != '*'){
					sketch1[i][j][k] = ' ';
					solve1[i][j][k] = ' ';
					reveal1[i][j][k] = 'n';
				}
			}
		}
	}

	for(int i=0; i<9; i++){
		for(int j=0; j<15; j++){
			for(int k=0; k<15; k++){
				if(puzzle[i][j][k] != '*'){
					sketch[i][j][k] = ' ';
					solve[i][j][k] = ' ';
					reveal[i][j][k] = 'n';
				}
			}
		}
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				if(puzzle3[i][j][k] != '*'){
					sketch2[i][j][k] = ' ';
					solve2[i][j][k] = ' ';
					reveal2[i][j][k] = 'n';
				}
			}
		}
	}

			game_state = 10;
		}

		if(level_state == 1){

    	for(int i=100; i<700; i+=40){
    		for(int j=50; j<650; j+=40){
      			if(mx>i && mx<i+40 && my>j && my<j+40){
        			x=i;
        			y=j;
      			}
    		}

			a=(x-100)/40;
			b=14 - (y-50)/40;

			if(x!= 0 && y!= 0 && mx>=736 && mx<=922 && my>=22 && my<=82){
				solve[t][b][a] = puzzle[t][b][a];
			}

    		if(mx<=100 || mx>=700 || my<=50 || my>=650 && !(mx>=736 && mx<=922 && my>=22 && my<=82)){
      			x=0;
      			y=0;
    		}
  		}


	}

	else if(level_state == 2){

    	for(int i=100; i<700; i+=60){
    		for(int j=50; j<650; j+=60){
      			if(mx>i && mx<i+60 && my>j && my<j+60){
        			x=i;
        			y=j;
      			}
    		}

			a=(x-100)/60;
			b=9 - (y-50)/60;

			if(x!= 0 && y!= 0 && mx>=736 && mx<=922 && my>=22 && my<=82){
				solve2[t][b][a] = puzzle3[t][b][a];
			}

    		if(mx<=100 || mx>=700 || my<=50 || my>=650 && !(mx>=736 && mx<=922 && my>=22 && my<=82)){
      			x=0;
      			y=0;
    		}
  		}
	}

	else if(level_state == 3){

    	for(int i=200; i<500; i+=60){
    		for(int j=200; j<500; j+=60){
      			if(mx>i && mx<i+60 && my>j && my<j+60){
        			x=i;
        			y=j;
      			}
    		}

			a=(x-200)/60;
			b=4 - (y-200)/60;

			if(x!= 0 && y!= 0 && mx>=736 && mx<=922 && my>=22 && my<=82){
				solve1[t][b][a] = puzzle1[t][b][a];
			}

    		if(mx<=200 || mx>=500 || my<=200 || my>=500 && !(mx>=736 && mx<=922 && my>=22 && my<=82)){
      			x=0;
      			y=0;
    		}
  		}
	}
		}

		else if(game_state == 10){
			if(musicOn == true){
				if((g-1148)*(g-1148) + (h-650)*(h-650) < 35*35){
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}

		else if(musicOn == false){
				if((g-1148)*(g-1148) + (h-650)*(h-650) < 35*35){
					musicOn = true;
					PlaySound("Music\\Piano.wav", NULL, SND_LOOP | SND_ASYNC);
				}
		}

			if(g>=880 && g<=1150 && h>=20 && h<=80){
				game_state=0;
				if(musicOn){
					PlaySound(0, 0, 0);
					PlaySound("Music\\Pubg.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}

	}

	printf("%d %d %d %d\n", g, h, mx, my);
}

void iKeyboard(unsigned char key) {
	if(game_state == 3){
		if(level_state == 1){
			a=(x-100)/40;
			b=14 - (y-50)/40;

			if(x!= 0 && y!=0 && puzzle[t][b][a] != '*'){
				if((int) key >= 65 && (int) key <= 90){
					str[0] = key;
					solve[t][b][a] = str[0];
				}
				else if((int) key >= 97 && (int) key <= 122){
					str[0] = (char) ((int) key - 32);
					solve[t][b][a] = str[0];
				}
				else if((int) key == 8){
					solve[t][b][a] = sketch[t][b][a];
				}
			}
		}
		if(level_state == 2){
			a=(x-100)/60;
			b=9 - (y-50)/60;

			if(x!= 0 && y!=0 && puzzle3[t][b][a] != '*'){
				if((int) key >= 65 && (int) key <= 90){
					str[0] = key;
					solve2[t][b][a] = str[0];
				}
				else if((int) key >= 97 && (int) key <= 122){
					str[0] = (char) ((int) key - 32);
					solve2[t][b][a] = str[0];
				}
				else if((int) key == 8){
					solve2[t][b][a] = sketch2[t][b][a];
				}
			}
		}
		else if(level_state == 3){
			a=(x-200)/60;
			b=4 - (y-200)/60;

			if(x!= 0 && y!=0 && puzzle1[t][b][a] != '*'){
				if((int) key >= 65 && (int) key <= 90){
					str[0] = key;
					solve1[t][b][a] = str[0];
				}
				else if((int) key >= 97 && (int) key <= 122){
					str[0] = (char) ((int) key - 32);
					solve1[t][b][a] = str[0];
				}
				else if((int) key == 8){
					solve1[t][b][a] = sketch1[t][b][a];
				}
			}
		}
	}
	
}


void iSpecialKeyboard(unsigned char key) {

	if(game_state == 3){
		if(level_state == 1){
			if (key == GLUT_KEY_LEFT) {
    		x -= 40;
			if(x<100){
				x = 660;
			}
  		}
		else if (key == GLUT_KEY_RIGHT) {
    		x += 40;
			if(x>=700){
				x = 100;
			}
  		}
		else if (key == GLUT_KEY_DOWN) {
			y -= 40;
			if(y<50){
				y = 610;
			}
		}
		else if (key == GLUT_KEY_UP) {
    		y += 40;
			if(y>=650){
				y = 50;
			}
  		}
		}

		if(level_state == 2){
			if (key == GLUT_KEY_LEFT) {
    		x -= 60;
			if(x<100){
				x = 640;
			}
  		}
		else if (key == GLUT_KEY_RIGHT) {
    		x += 60;
			if(x>=700){
				x = 100;
			}
  		}
		else if (key == GLUT_KEY_DOWN) {
			y -= 60;
			if(y<50){
				y = 590;
			}
		}
		else if (key == GLUT_KEY_UP) {
    		y += 60;
			if(y>=650){
				y = 50;
			}
  		}
		}

		if(level_state == 3){
			if (key == GLUT_KEY_LEFT) {
    		x -= 60;
			if(x<200){
				x = 440;
			}
  		}
		else if (key == GLUT_KEY_RIGHT) {
    		x += 60;
			if(x>=500){
				x = 200;
			}
  		}
		else if (key == GLUT_KEY_DOWN) {
			y -= 60;
			if(y<200){
				y = 440;
			}
		}
		else if (key == GLUT_KEY_UP) {
    		y += 60;
			if(y>=500){
				y = 200;
			}
  		}
		}
	}
  	
}


int main() {
	for(int i=0; i<9; i++){
		for(int j=0; j<15; j++){
			for(int k=0; k<15; k++){
				//hard
				puzzle[i][j][k] = '*';
				sketch[i][j][k] = '*';
				solve[i][j][k] = '*';
				hint[i][j][k][0] = '*';
				hint[i][j][k][1] = '*';
				reveal[i][j][k] = '*';
			}
		}
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				//hard
				puzzle3[i][j][k] = '*';
				sketch2[i][j][k] = '*';
				solve2[i][j][k] = '*';
				hint2[i][j][k][0] = '*';
				hint2[i][j][k][1] = '*';
				reveal2[i][j][k] = '*';
			}
		}
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				//easy
				puzzle1[i][j][k] = '*';
				sketch1[i][j][k] = '*';
				solve1[i][j][k] = '*';
				hint1[i][j][k] = '*';
				reveal1[i][j][k] = '*';
			}
		}
	}

	// All the puzzles are saved here

	// puzzle 1

	puzzle[0][0][0] = 'P';
	puzzle[0][0][1] = 'A';
	puzzle[0][0][2] = 'C';
	puzzle[0][0][3] = 'K';
	puzzle[0][0][4] = 'S';
	puzzle[0][0][5] = '*';
	puzzle[0][0][6] = 'A';
	puzzle[0][0][7] = 'C';
	puzzle[0][0][8] = 'H';
	puzzle[0][0][9] = 'Y';
	puzzle[0][0][10] = '*';
	puzzle[0][0][11] = 'B';
	puzzle[0][0][12] = 'I';
	puzzle[0][0][13] = 'B';
	puzzle[0][0][14] = 'S';
	puzzle[0][1][0] = 'A';
	puzzle[0][1][1] = 'T';
	puzzle[0][1][2] = 'O';
	puzzle[0][1][3] = 'N';
	puzzle[0][1][4] = 'E';
	puzzle[0][1][5] = '*';
	puzzle[0][1][6] = 'T';
	puzzle[0][1][7] = 'R';
	puzzle[0][1][8] = 'U';
	puzzle[0][1][9] = 'E';
	puzzle[0][1][10] = '*';
	puzzle[0][1][11] = 'R';
	puzzle[0][1][12] = 'O';
	puzzle[0][1][13] = 'L';
	puzzle[0][1][14] = 'E';
	puzzle[0][2][0] = 'D';
	puzzle[0][2][1] = 'E';
	puzzle[0][2][2] = 'P';
	puzzle[0][2][3] = 'O';
	puzzle[0][2][4] = 'T';
	puzzle[0][2][5] = '*';
	puzzle[0][2][6] = 'S';
	puzzle[0][2][7] = 'I';
	puzzle[0][2][8] = 'L';
	puzzle[0][2][9] = 'L';
	puzzle[0][2][10] = '*';
	puzzle[0][2][11] = 'I';
	puzzle[0][2][12] = 'W';
	puzzle[0][2][13] = 'O';
	puzzle[0][2][14] = 'N';
	puzzle[0][3][0] = '*';
	puzzle[0][3][1] = '*';
	puzzle[0][3][2] = '*';
	puzzle[0][3][3] = 'B';
	puzzle[0][3][4] = 'A';
	puzzle[0][3][5] = 'S';
	puzzle[0][3][6] = 'E';
	puzzle[0][3][7] = 'B';
	puzzle[0][3][8] = 'A';
	puzzle[0][3][9] = 'L';
	puzzle[0][3][10] = 'L';
	puzzle[0][3][11] = 'B';
	puzzle[0][3][12] = 'A';
	puzzle[0][3][13] = 'T';
	puzzle[0][3][14] = 'S';
	puzzle[0][4][0] = 'G';
	puzzle[0][4][1] = 'P';
	puzzle[0][4][2] = 'A';
	puzzle[0][4][3] = '*';
	puzzle[0][4][4] = 'T';
	puzzle[0][4][5] = 'R';
	puzzle[0][4][6] = 'A';
	puzzle[0][4][7] = 'S';
	puzzle[0][4][8] = 'H';
	puzzle[0][4][9] = '*';
	puzzle[0][4][10] = 'T';
	puzzle[0][4][11] = 'E';
	puzzle[0][4][12] = 'N';
	puzzle[0][4][13] = 'S';
	puzzle[0][4][14] = 'E';
	puzzle[0][5][0] = 'R';
	puzzle[0][5][1] = 'U';
	puzzle[0][5][2] = 'M';
	puzzle[0][5][3] = 'O';
	puzzle[0][5][4] = 'R';
	puzzle[0][5][5] = 'S';
	puzzle[0][5][6] = '*';
	puzzle[0][5][7] = '*';
	puzzle[0][5][8] = 'O';
	puzzle[0][5][9] = 'A';
	puzzle[0][5][10] = 'R';
	puzzle[0][5][11] = 'S';
	puzzle[0][5][12] = '*';
	puzzle[0][5][13] = '*';
	puzzle[0][5][14] = '*';
	puzzle[0][6][0] = 'O';
	puzzle[0][6][1] = 'P';
	puzzle[0][6][2] = 'E';
	puzzle[0][6][3] = 'R';
	puzzle[0][6][4] = 'A';
	puzzle[0][6][5] = '*';
	puzzle[0][6][6] = 'U';
	puzzle[0][6][7] = 'H';
	puzzle[0][6][8] = 'O';
	puzzle[0][6][9] = 'H';
	puzzle[0][6][10] = '*';
	puzzle[0][6][11] = '*';
	puzzle[0][6][12] = 'P';
	puzzle[0][6][13] = 'G';
	puzzle[0][6][14] = 'A';
	puzzle[0][7][0] = 'P';
	puzzle[0][7][1] = 'I';
	puzzle[0][7][2] = 'N';
	puzzle[0][7][3] = 'G';
	puzzle[0][7][4] = 'P';
	puzzle[0][7][5] = 'O';
	puzzle[0][7][6] = 'N';
	puzzle[0][7][7] = 'G';
	puzzle[0][7][8] = 'P';
	puzzle[0][7][9] = 'A';
	puzzle[0][7][10] = 'D';
	puzzle[0][7][11] = 'D';
	puzzle[0][7][12] = 'L';
	puzzle[0][7][13] = 'E';
	puzzle[0][7][14] = 'S';
	puzzle[0][8][0] = 'E';
	puzzle[0][8][1] = 'L';
	puzzle[0][8][2] = 'S';
	puzzle[0][8][3] = '*';
	puzzle[0][8][4] = '*';
	puzzle[0][8][5] = 'O';
	puzzle[0][8][6] = 'P';
	puzzle[0][8][7] = 'T';
	puzzle[0][8][8] = 'S';
	puzzle[0][8][9] = '*';
	puzzle[0][8][10] = 'O';
	puzzle[0][8][11] = 'V';
	puzzle[0][8][12] = 'E';
	puzzle[0][8][13] = 'N';
	puzzle[0][8][14] = 'S';
	puzzle[0][9][0] = '*';
	puzzle[0][9][1] = '*';
	puzzle[0][9][2] = '*';
	puzzle[0][9][3] = 'P';
	puzzle[0][9][4] = 'O';
	puzzle[0][9][5] = 'O';
	puzzle[0][9][6] = 'R';
	puzzle[0][9][7] = '*';
	puzzle[0][9][8] = '*';
	puzzle[0][9][9] = 'S';
	puzzle[0][9][10] = 'E';
	puzzle[0][9][11] = 'D';
	puzzle[0][9][12] = 'A';
	puzzle[0][9][13] = 'T';
	puzzle[0][9][14] = 'E';
	puzzle[0][10][0] = 'S';
	puzzle[0][10][1] = 'P';
	puzzle[0][10][2] = 'O';
	puzzle[0][10][3] = 'O';
	puzzle[0][10][4] = 'N';
	puzzle[0][10][5] = '*';
	puzzle[0][10][6] = 'E';
	puzzle[0][10][7] = 'S';
	puzzle[0][10][8] = 'S';
	puzzle[0][10][9] = 'E';
	puzzle[0][10][10] = 'S';
	puzzle[0][10][11] = '*';
	puzzle[0][10][12] = 'D';
	puzzle[0][10][13] = 'S';
	puzzle[0][10][14] = 'T';
	puzzle[0][11][0] = 'H';
	puzzle[0][11][1] = 'O';
	puzzle[0][11][2] = 'C';
	puzzle[0][11][3] = 'K';
	puzzle[0][11][4] = 'E';
	puzzle[0][11][5] = 'Y';
	puzzle[0][11][6] = 'S';
	puzzle[0][11][7] = 'T';
	puzzle[0][11][8] = 'I';
	puzzle[0][11][9] = 'C';
	puzzle[0][11][10] = 'K';
	puzzle[0][11][11] = 'S';
	puzzle[0][11][12] = '*';
	puzzle[0][11][13] = '*';
	puzzle[0][11][14] = '*';
	puzzle[0][12][0] = 'R';
	puzzle[0][12][1] = 'I';
	puzzle[0][12][2] = 'T';
	puzzle[0][12][3] = 'E';
	puzzle[0][12][4] = '*';
	puzzle[0][12][5] = 'A';
	puzzle[0][12][6] = 'S';
	puzzle[0][12][7] = 'I';
	puzzle[0][12][8] = 'S';
	puzzle[0][12][9] = '*';
	puzzle[0][12][10] = 'I';
	puzzle[0][12][11] = 'N';
	puzzle[0][12][12] = 'L';
	puzzle[0][12][13] = 'A';
	puzzle[0][12][14] = 'W';
	puzzle[0][13][0] = 'U';
	puzzle[0][13][1] = 'S';
	puzzle[0][13][2] = 'E';
	puzzle[0][13][3] = 'R';
	puzzle[0][13][4] = '*';
	puzzle[0][13][5] = 'L';
	puzzle[0][13][6] = 'E';
	puzzle[0][13][7] = 'N';
	puzzle[0][13][8] = 'S';
	puzzle[0][13][9] = '*';
	puzzle[0][13][10] = 'N';
	puzzle[0][13][11] = 'O';
	puzzle[0][13][12] = 'I';
	puzzle[0][13][13] = 'S';
	puzzle[0][13][14] = 'E';
	puzzle[0][14][0] = 'B';
	puzzle[0][14][1] = 'E';
	puzzle[0][14][2] = 'T';
	puzzle[0][14][3] = 'S';
	puzzle[0][14][4] = '*';
	puzzle[0][14][5] = 'E';
	puzzle[0][14][6] = 'D';
	puzzle[0][14][7] = 'G';
	puzzle[0][14][8] = 'Y';
	puzzle[0][14][9] = '*';
	puzzle[0][14][10] = 'S';
	puzzle[0][14][11] = 'W';
	puzzle[0][14][12] = 'E';
	puzzle[0][14][13] = 'P';
	puzzle[0][14][14] = 'T';

	// puzzle 2

	puzzle[1][0][0] = 'P';
	puzzle[1][0][1] = 'U';
	puzzle[1][0][2] = 'M';
	puzzle[1][0][3] = 'P';
	puzzle[1][0][4] = 'S';
	puzzle[1][0][5] = '*';
	puzzle[1][0][6] = 'S';
	puzzle[1][0][7] = 'U';
	puzzle[1][0][8] = 'B';
	puzzle[1][0][9] = 'S';
	puzzle[1][0][10] = '*';
	puzzle[1][0][11] = 'S';
	puzzle[1][0][12] = 'T';
	puzzle[1][0][13] = 'A';
	puzzle[1][0][14] = 'Y';
	puzzle[1][1][0] = 'S';
	puzzle[1][1][1] = 'N';
	puzzle[1][1][2] = 'O';
	puzzle[1][1][3] = 'O';
	puzzle[1][1][4] = 'T';
	puzzle[1][1][5] = '*';
	puzzle[1][1][6] = 'W';
	puzzle[1][1][7] = 'H';
	puzzle[1][1][8] = 'I';
	puzzle[1][1][9] = 'M';
	puzzle[1][1][10] = '*';
	puzzle[1][1][11] = 'C';
	puzzle[1][1][12] = 'A';
	puzzle[1][1][13] = 'P';
	puzzle[1][1][14] = 'E';
	puzzle[1][2][0] = 'A';
	puzzle[1][2][1] = 'D';
	puzzle[1][2][2] = 'D';
	puzzle[1][2][3] = 'L';
	puzzle[1][2][4] = 'E';
	puzzle[1][2][5] = '*';
	puzzle[1][2][6] = 'A';
	puzzle[1][2][7] = 'U';
	puzzle[1][2][8] = 'D';
	puzzle[1][2][9] = 'I';
	puzzle[1][2][10] = '*';
	puzzle[1][2][11] = 'A';
	puzzle[1][2][12] = 'M';
	puzzle[1][2][13] = 'E';
	puzzle[1][2][14] = 'N';
	puzzle[1][3][0] = 'T';
	puzzle[1][3][1] = 'O';
	puzzle[1][3][2] = 'E';
	puzzle[1][3][3] = 'I';
	puzzle[1][3][4] = 'N';
	puzzle[1][3][5] = 'G';
	puzzle[1][3][6] = 'T';
	puzzle[1][3][7] = 'H';
	puzzle[1][3][8] = 'E';
	puzzle[1][3][9] = 'L';
	puzzle[1][3][10] = 'I';
	puzzle[1][3][11] = 'N';
	puzzle[1][3][12] = 'E';
	puzzle[1][3][13] = '*';
	puzzle[1][3][14] = '*';
	puzzle[1][4][0] = '*';
	puzzle[1][4][1] = '*';
	puzzle[1][4][2] = '*';
	puzzle[1][4][3] = 'T';
	puzzle[1][4][4] = 'O';
	puzzle[1][4][5] = 'O';
	puzzle[1][4][6] = '*';
	puzzle[1][4][7] = '*';
	puzzle[1][4][8] = 'D';
	puzzle[1][4][9] = 'E';
	puzzle[1][4][10] = 'N';
	puzzle[1][4][11] = '*';
	puzzle[1][4][12] = '*';
	puzzle[1][4][13] = '*';
	puzzle[1][4][14] = '*';
	puzzle[1][5][0] = 'M';
	puzzle[1][5][1] = 'A';
	puzzle[1][5][2] = 'L';
	puzzle[1][5][3] = 'E';
	puzzle[1][5][4] = '*';
	puzzle[1][5][5] = 'T';
	puzzle[1][5][6] = 'S';
	puzzle[1][5][7] = 'P';
	puzzle[1][5][8] = '*';
	puzzle[1][5][9] = 'S';
	puzzle[1][5][10] = 'T';
	puzzle[1][5][11] = 'U';
	puzzle[1][5][12] = 'F';
	puzzle[1][5][13] = 'F';
	puzzle[1][5][14] = 'S';
	puzzle[1][6][0] = 'E';
	puzzle[1][6][1] = 'G';
	puzzle[1][6][2] = 'O';
	puzzle[1][6][3] = '*';
	puzzle[1][6][4] = 'S';
	puzzle[1][6][5] = 'T';
	puzzle[1][6][6] = 'O';
	puzzle[1][6][7] = 'U';
	puzzle[1][6][8] = 'T';
	puzzle[1][6][9] = '*';
	puzzle[1][6][10] = 'I';
	puzzle[1][6][11] = 'N';
	puzzle[1][6][12] = 'E';
	puzzle[1][6][13] = 'R';
	puzzle[1][6][14] = 'T';
	puzzle[1][7][0] = 'R';
	puzzle[1][7][1] = 'I';
	puzzle[1][7][2] = 'G';
	puzzle[1][7][3] = 'H';
	puzzle[1][7][4] = 'T';
	puzzle[1][7][5] = 'O';
	puzzle[1][7][6] = 'N';
	puzzle[1][7][7] = 'T';
	puzzle[1][7][8] = 'H';
	puzzle[1][7][9] = 'E';
	puzzle[1][7][10] = 'M';
	puzzle[1][7][11] = 'O';
	puzzle[1][7][12] = 'N';
	puzzle[1][7][13] = 'E';
	puzzle[1][7][14] = 'Y';
	puzzle[1][8][0] = 'C';
	puzzle[1][8][1] = 'L';
	puzzle[1][8][2] = 'E';
	puzzle[1][8][3] = 'A';
	puzzle[1][8][4] = 'R';
	puzzle[1][8][5] = '*';
	puzzle[1][8][6] = 'S';
	puzzle[1][8][7] = 'T';
	puzzle[1][8][8] = 'A';
	puzzle[1][8][9] = 'G';
	puzzle[1][8][10] = 'E';
	puzzle[1][8][11] = '*';
	puzzle[1][8][12] = 'C';
	puzzle[1][8][13] = 'A';
	puzzle[1][8][14] = 'L';
	puzzle[1][9][0] = 'Y';
	puzzle[1][9][1] = 'E';
	puzzle[1][9][2] = 'S';
	puzzle[1][9][3] = 'M';
	puzzle[1][9][4] = 'A';
	puzzle[1][9][5] = 'N';
	puzzle[1][9][6] = '*';
	puzzle[1][9][7] = 'S';
	puzzle[1][9][8] = 'T';
	puzzle[1][9][9] = 'Y';
	puzzle[1][9][10] = '*';
	puzzle[1][9][11] = 'P';
	puzzle[1][9][12] = 'E';
	puzzle[1][9][13] = 'K';
	puzzle[1][9][14] = 'E';
	puzzle[1][10][0] = '*';
	puzzle[1][10][1] = '*';
	puzzle[1][10][2] = '*';
	puzzle[1][10][3] = '*';
	puzzle[1][10][4] = 'I';
	puzzle[1][10][5] = 'O';
	puzzle[1][10][6] = 'N';
	puzzle[1][10][7] = '*';
	puzzle[1][10][8] = '*';
	puzzle[1][10][9] = 'P';
	puzzle[1][10][10] = 'H';
	puzzle[1][10][11] = 'I';
	puzzle[1][10][12] = '*';
	puzzle[1][10][13] = '*';
	puzzle[1][10][14] = '*';
	puzzle[1][11][0] = '*';
	puzzle[1][11][1] = '*';
	puzzle[1][11][2] = 'P';
	puzzle[1][11][3] = 'E';
	puzzle[1][11][4] = 'N';
	puzzle[1][11][5] = 'N';
	puzzle[1][11][6] = 'A';
	puzzle[1][11][7] = 'N';
	puzzle[1][11][8] = 'D';
	puzzle[1][11][9] = 'T';
	puzzle[1][11][10] = 'E';
	puzzle[1][11][11] = 'L';
	puzzle[1][11][12] = 'L';
	puzzle[1][11][13] = 'E';
	puzzle[1][11][14] = 'R';
	puzzle[1][12][0] = 'A';
	puzzle[1][12][1] = 'C';
	puzzle[1][12][2] = 'I';
	puzzle[1][12][3] = 'D';
	puzzle[1][12][4] = '*';
	puzzle[1][12][5] = 'F';
	puzzle[1][12][6] = 'I';
	puzzle[1][12][7] = 'D';
	puzzle[1][12][8] = 'O';
	puzzle[1][12][9] = '*';
	puzzle[1][12][10] = 'A';
	puzzle[1][12][11] = 'L';
	puzzle[1][12][12] = 'I';
	puzzle[1][12][13] = 'V';
	puzzle[1][12][14] = 'E';
	puzzle[1][13][0] = 'D';
	puzzle[1][13][1] = 'O';
	puzzle[1][13][2] = 'T';
	puzzle[1][13][3] = 'E';
	puzzle[1][13][4] = '*';
	puzzle[1][13][5] = 'A';
	puzzle[1][13][6] = 'L';
	puzzle[1][13][7] = 'A';
	puzzle[1][13][8] = 'N';
	puzzle[1][13][9] = '*';
	puzzle[1][13][10] = 'R';
	puzzle[1][13][11] = 'A';
	puzzle[1][13][12] = 'K';
	puzzle[1][13][13] = 'E';
	puzzle[1][13][14] = 'D';
	puzzle[1][14][0] = 'S';
	puzzle[1][14][1] = 'W';
	puzzle[1][14][2] = 'A';
	puzzle[1][14][3] = 'N';
	puzzle[1][14][4] = '*';
	puzzle[1][14][5] = 'T';
	puzzle[1][14][6] = 'S';
	puzzle[1][14][7] = 'K';
	puzzle[1][14][8] = 'S';
	puzzle[1][14][9] = '*';
	puzzle[1][14][10] = 'D';
	puzzle[1][14][11] = 'R';
	puzzle[1][14][12] = 'E';
	puzzle[1][14][13] = 'S';
	puzzle[1][14][14] = 'S';

	//puzzle 3

	puzzle[2][0][0] = '*';
	puzzle[2][0][1] = 'P';
	puzzle[2][0][2] = 'A';
	puzzle[2][0][3] = 'C';
	puzzle[2][0][4] = '*';
	puzzle[2][0][5] = 'S';
	puzzle[2][0][6] = 'P';
	puzzle[2][0][7] = 'O';
	puzzle[2][0][8] = 'T';
	puzzle[2][0][9] = 'S';
	puzzle[2][0][10] = '*';
	puzzle[2][0][11] = 'A';
	puzzle[2][0][12] = 'G';
	puzzle[2][0][13] = 'E';
	puzzle[2][0][14] = 'D';
	puzzle[2][1][0] = 'M';
	puzzle[2][1][1] = 'E';
	puzzle[2][1][2] = 'S';
	puzzle[2][1][3] = 'H';
	puzzle[2][1][4] = '*';
	puzzle[2][1][5] = 'P';
	puzzle[2][1][6] = 'U';
	puzzle[2][1][7] = 'R';
	puzzle[2][1][8] = 'E';
	puzzle[2][1][9] = 'E';
	puzzle[2][1][10] = '*';
	puzzle[2][1][11] = 'R';
	puzzle[2][1][12] = 'U';
	puzzle[2][1][13] = 'L';
	puzzle[2][1][14] = 'E';
	puzzle[2][2][0] = 'A';
	puzzle[2][2][1] = 'R';
	puzzle[2][2][2] = 'I';
	puzzle[2][2][3] = 'A';
	puzzle[2][2][4] = '*';
	puzzle[2][2][5] = 'A';
	puzzle[2][2][6] = 'M';
	puzzle[2][2][7] = 'B';
	puzzle[2][2][8] = 'L';
	puzzle[2][2][9] = 'E';
	puzzle[2][2][10] = '*';
	puzzle[2][2][11] = 'R';
	puzzle[2][2][12] = 'I';
	puzzle[2][2][13] = 'S';
	puzzle[2][2][14] = 'E';
	puzzle[2][3][0] = 'G';
	puzzle[2][3][1] = 'U';
	puzzle[2][3][2] = 'A';
	puzzle[2][3][3] = 'R';
	puzzle[2][3][4] = 'D';
	puzzle[2][3][5] = 'R';
	puzzle[2][3][6] = 'A';
	puzzle[2][3][7] = 'I';
	puzzle[2][3][8] = 'L';
	puzzle[2][3][9] = '*';
	puzzle[2][3][10] = 'C';
	puzzle[2][3][11] = 'I';
	puzzle[2][3][12] = 'T';
	puzzle[2][3][13] = 'E';
	puzzle[2][3][14] = 'D';
	puzzle[2][4][0] = '*';
	puzzle[2][4][1] = '*';
	puzzle[2][4][2] = '*';
	puzzle[2][4][3] = 'G';
	puzzle[2][4][4] = 'U';
	puzzle[2][4][5] = 'E';
	puzzle[2][4][6] = 'S';
	puzzle[2][4][7] = 'T';
	puzzle[2][4][8] = '*';
	puzzle[2][4][9] = 'L';
	puzzle[2][4][10] = 'A';
	puzzle[2][4][11] = 'V';
	puzzle[2][4][12] = 'A';
	puzzle[2][4][13] = '*';
	puzzle[2][4][14] = '*';
	puzzle[2][5][0] = 'L';
	puzzle[2][5][1] = 'E';
	puzzle[2][5][2] = 'G';
	puzzle[2][5][3] = 'E';
	puzzle[2][5][4] = 'N';
	puzzle[2][5][5] = 'D';
	puzzle[2][5][6] = '*';
	puzzle[2][5][7] = '*';
	puzzle[2][5][8] = 'T';
	puzzle[2][5][9] = 'A';
	puzzle[2][5][10] = 'P';
	puzzle[2][5][11] = 'E';
	puzzle[2][5][12] = 'R';
	puzzle[2][5][13] = 'E';
	puzzle[2][5][14] = 'D';
	puzzle[2][6][0] = 'A';
	puzzle[2][6][1] = 'M';
	puzzle[2][6][2] = 'U';
	puzzle[2][6][3] = 'S';
	puzzle[2][6][4] = 'E';
	puzzle[2][6][5] = '*';
	puzzle[2][6][6] = 'S';
	puzzle[2][6][7] = 'T';
	puzzle[2][6][8] = 'A';
	puzzle[2][6][9] = 'T';
	puzzle[2][6][10] = 'E';
	puzzle[2][6][11] = '*';
	puzzle[2][6][12] = 'P';
	puzzle[2][6][13] = 'A';
	puzzle[2][6][14] = 'R';
	puzzle[2][7][0] = 'M';
	puzzle[2][7][1] = 'O';
	puzzle[2][7][2] = 'E';
	puzzle[2][7][3] = '*';
	puzzle[2][7][4] = '*';
	puzzle[2][7][5] = 'S';
	puzzle[2][7][6] = 'P';
	puzzle[2][7][7] = 'A';
	puzzle[2][7][8] = 'C';
	puzzle[2][7][9] = 'E';
	puzzle[2][7][10] = '*';
	puzzle[2][7][11] = '*';
	puzzle[2][7][12] = 'I';
	puzzle[2][7][13] = 'R';
	puzzle[2][7][14] = 'A';
	puzzle[2][8][0] = 'P';
	puzzle[2][8][1] = 'T';
	puzzle[2][8][2] = 'S';
	puzzle[2][8][3] = '*';
	puzzle[2][8][4] = 'P';
	puzzle[2][8][5] = 'L';
	puzzle[2][8][6] = 'A';
	puzzle[2][8][7] = 'N';
	puzzle[2][8][8] = 'T';
	puzzle[2][8][9] = '*';
	puzzle[2][8][10] = 'C';
	puzzle[2][8][11] = 'A';
	puzzle[2][8][12] = 'C';
	puzzle[2][8][13] = 'T';
	puzzle[2][8][14] = 'I';
	puzzle[2][9][0] = 'S';
	puzzle[2][9][1] = 'E';
	puzzle[2][9][2] = 'S';
	puzzle[2][9][3] = 'S';
	puzzle[2][9][4] = 'I';
	puzzle[2][9][5] = 'O';
	puzzle[2][9][6] = 'N';
	puzzle[2][9][7] = '*';
	puzzle[2][9][8] = '*';
	puzzle[2][9][9] = 'W';
	puzzle[2][9][10] = 'A';
	puzzle[2][9][11] = 'L';
	puzzle[2][9][12] = 'K';
	puzzle[2][9][13] = 'O';
	puzzle[2][9][14] = 'N';
	puzzle[2][10][0] = '*';
	puzzle[2][10][1] = '*';
	puzzle[2][10][2] = 'A';
	puzzle[2][10][3] = 'U';
	puzzle[2][10][4] = 'N';
	puzzle[2][10][5] = 'T';
	puzzle[2][10][6] = '*';
	puzzle[2][10][7] = 'L';
	puzzle[2][10][8] = 'L';
	puzzle[2][10][9] = 'A';
	puzzle[2][10][10] = 'M';
	puzzle[2][10][11] = 'A';
	puzzle[2][10][12] = '*';
	puzzle[2][10][13] = '*';
	puzzle[2][10][14] = '*';
	puzzle[2][11][0] = 'S';
	puzzle[2][11][1] = 'I';
	puzzle[2][11][2] = 'G';
	puzzle[2][11][3] = 'N';
	puzzle[2][11][4] = 'S';
	puzzle[2][11][5] = '*';
	puzzle[2][11][6] = 'G';
	puzzle[2][11][7] = 'U';
	puzzle[2][11][8] = 'I';
	puzzle[2][11][9] = 'D';
	puzzle[2][11][10] = 'E';
	puzzle[2][11][11] = 'B';
	puzzle[2][11][12] = 'O';
	puzzle[2][11][13] = 'O';
	puzzle[2][11][14] = 'K';
	puzzle[2][12][0] = 'P';
	puzzle[2][12][1] = 'D';
	puzzle[2][12][2] = 'A';
	puzzle[2][12][3] = 'S';
	puzzle[2][12][4] = '*';
	puzzle[2][12][5] = 'P';
	puzzle[2][12][6] = 'E';
	puzzle[2][12][7] = 'N';
	puzzle[2][12][8] = 'N';
	puzzle[2][12][9] = 'E';
	puzzle[2][12][10] = '*';
	puzzle[2][12][11] = 'A';
	puzzle[2][12][12] = 'N';
	puzzle[2][12][13] = 'N';
	puzzle[2][12][14] = 'E';
	puzzle[2][13][0] = 'A';
	puzzle[2][13][1] = 'L';
	puzzle[2][13][2] = 'I';
	puzzle[2][13][3] = 'E';
	puzzle[2][13][4] = '*';
	puzzle[2][13][5] = 'E';
	puzzle[2][13][6] = 'A';
	puzzle[2][13][7] = 'G';
	puzzle[2][13][8] = 'E';
	puzzle[2][13][9] = 'R';
	puzzle[2][13][10] = '*';
	puzzle[2][13][11] = 'M';
	puzzle[2][13][12] = 'Y';
	puzzle[2][13][13] = 'M';
	puzzle[2][13][14] = 'Y';
	puzzle[2][14][0] = 'R';
	puzzle[2][14][1] = 'E';
	puzzle[2][14][2] = 'N';
	puzzle[2][14][3] = 'T';
	puzzle[2][14][4] = '*';
	puzzle[2][14][5] = 'W';
	puzzle[2][14][6] = 'R';
	puzzle[2][14][7] = 'E';
	puzzle[2][14][8] = 'N';
	puzzle[2][14][9] = 'S';
	puzzle[2][14][10] = '*';
	puzzle[2][14][11] = 'A';
	puzzle[2][14][12] = 'X';
	puzzle[2][14][13] = 'E';
	puzzle[2][14][14] = '*';

	//puzzle 4

	puzzle[3][0][0] = '*';
	puzzle[3][0][1] = 'L';
	puzzle[3][0][2] = 'A';
	puzzle[3][0][3] = 'P';
	puzzle[3][0][4] = 'D';
	puzzle[3][0][5] = '*';
	puzzle[3][0][6] = 'E';
	puzzle[3][0][7] = 'L';
	puzzle[3][0][8] = 'E';
	puzzle[3][0][9] = 'M';
	puzzle[3][0][10] = '*';
	puzzle[3][0][11] = 'A';
	puzzle[3][0][12] = 'P';
	puzzle[3][0][13] = 'E';
	puzzle[3][0][14] = 'D';
	puzzle[3][1][0] = 'P';
	puzzle[3][1][1] = 'U';
	puzzle[3][1][2] = 'L';
	puzzle[3][1][3] = 'S';
	puzzle[3][1][4] = 'E';
	puzzle[3][1][5] = '*';
	puzzle[3][1][6] = 'M';
	puzzle[3][1][7] = 'E';
	puzzle[3][1][8] = 'T';
	puzzle[3][1][9] = 'E';
	puzzle[3][1][10] = '*';
	puzzle[3][1][11] = 'R';
	puzzle[3][1][12] = 'O';
	puzzle[3][1][13] = 'V';
	puzzle[3][1][14] = 'E';
	puzzle[3][2][0] = 'F';
	puzzle[3][2][1] = 'L';
	puzzle[3][2][2] = 'O';
	puzzle[3][2][3] = 'S';
	puzzle[3][2][4] = 'S';
	puzzle[3][2][5] = '*';
	puzzle[3][2][6] = 'A';
	puzzle[3][2][7] = 'N';
	puzzle[3][2][8] = 'T';
	puzzle[3][2][9] = 'E';
	puzzle[3][2][10] = '*';
	puzzle[3][2][11] = 'R';
	puzzle[3][2][12] = 'U';
	puzzle[3][2][13] = 'I';
	puzzle[3][2][14] = 'N';
	puzzle[3][3][0] = 'C';
	puzzle[3][3][1] = 'U';
	puzzle[3][3][2] = 'T';
	puzzle[3][3][3] = 'T';
	puzzle[3][3][4] = 'I';
	puzzle[3][3][5] = 'N';
	puzzle[3][3][6] = 'G';
	puzzle[3][3][7] = 'O';
	puzzle[3][3][8] = 'U';
	puzzle[3][3][9] = 'T';
	puzzle[3][3][10] = 'E';
	puzzle[3][3][11] = 'A';
	puzzle[3][3][12] = 'R';
	puzzle[3][3][13] = 'L';
	puzzle[3][3][14] = 'Y';
	puzzle[3][4][0] = '*';
	puzzle[3][4][1] = '*';
	puzzle[3][4][2] = '*';
	puzzle[3][4][3] = '*';
	puzzle[3][4][4] = 'G';
	puzzle[3][4][5] = 'A';
	puzzle[3][4][6] = 'S';
	puzzle[3][4][7] = '*';
	puzzle[3][4][8] = '*';
	puzzle[3][4][9] = 'W';
	puzzle[3][4][10] = 'A';
	puzzle[3][4][11] = 'Y';
	puzzle[3][4][12] = '*';
	puzzle[3][4][13] = '*';
	puzzle[3][4][14] = '*';
	puzzle[3][5][0] = 'O';
	puzzle[3][5][1] = 'B';
	puzzle[3][5][2] = 'L';
	puzzle[3][5][3] = 'O';
	puzzle[3][5][4] = 'N';
	puzzle[3][5][5] = 'G';
	puzzle[3][5][6] = '*';
	puzzle[3][5][7] = 'L';
	puzzle[3][5][8] = 'A';
	puzzle[3][5][9] = 'I';
	puzzle[3][5][10] = 'R';
	puzzle[3][5][11] = '*';
	puzzle[3][5][12] = 'C';
	puzzle[3][5][13] = 'I';
	puzzle[3][5][14] = 'A';
	puzzle[3][6][0] = 'G';
	puzzle[3][6][1] = 'R';
	puzzle[3][6][2] = 'A';
	puzzle[3][6][3] = 'D';
	puzzle[3][6][4] = 'E';
	puzzle[3][6][5] = '*';
	puzzle[3][6][6] = 'S';
	puzzle[3][6][7] = 'O';
	puzzle[3][6][8] = 'R';
	puzzle[3][6][9] = 'T';
	puzzle[3][6][10] = '*';
	puzzle[3][6][11] = 'M';
	puzzle[3][6][12] = 'O';
	puzzle[3][6][13] = 'L';
	puzzle[3][6][14] = 'D';
	puzzle[3][7][0] = 'L';
	puzzle[3][7][1] = 'O';
	puzzle[3][7][2] = 'W';
	puzzle[3][7][3] = 'E';
	puzzle[3][7][4] = 'R';
	puzzle[3][7][5] = 'I';
	puzzle[3][7][6] = 'N';
	puzzle[3][7][7] = 'G';
	puzzle[3][7][8] = 'T';
	puzzle[3][7][9] = 'H';
	puzzle[3][7][10] = 'E';
	puzzle[3][7][11] = 'B';
	puzzle[3][7][12] = 'O';
	puzzle[3][7][13] = 'O';
	puzzle[3][7][14] = 'M';
	puzzle[3][8][0] = 'E';
	puzzle[3][8][1] = 'O';
	puzzle[3][8][2] = 'N';
	puzzle[3][8][3] = 'S';
	puzzle[3][8][4] = '*';
	puzzle[3][8][5] = 'D';
	puzzle[3][8][6] = 'U';
	puzzle[3][8][7] = 'O';
	puzzle[3][8][8] = 'S';
	puzzle[3][8][9] = '*';
	puzzle[3][8][10] = 'L';
	puzzle[3][8][11] = 'A';
	puzzle[3][8][12] = 'P';
	puzzle[3][8][13] = 'S';
	puzzle[3][8][14] = 'E';
	puzzle[3][9][0] = 'R';
	puzzle[3][9][1] = 'D';
	puzzle[3][9][2] = 'S';
	puzzle[3][9][3] = '*';
	puzzle[3][9][4] = 'M';
	puzzle[3][9][5] = 'O';
	puzzle[3][9][6] = 'B';
	puzzle[3][9][7] = 'S';
	puzzle[3][9][8] = '*';
	puzzle[3][9][9] = 'L';
	puzzle[3][9][10] = 'E';
	puzzle[3][9][11] = 'S';
	puzzle[3][9][12] = 'S';
	puzzle[3][9][13] = 'E';
	puzzle[3][9][14] = 'N';
	puzzle[3][10][0] = '*';
	puzzle[3][10][1] = '*';
	puzzle[3][10][2] = '*';
	puzzle[3][10][3] = 'L';
	puzzle[3][10][4] = 'O';
	puzzle[3][10][5] = 'L';
	puzzle[3][10][6] = '*';
	puzzle[3][10][7] = '*';
	puzzle[3][10][8] = 'S';
	puzzle[3][10][9] = 'E';
	puzzle[3][10][10] = 'C';
	puzzle[3][10][11] = '*';
	puzzle[3][10][12] = '*';
	puzzle[3][10][13] = '*';
	puzzle[3][10][14] = '*';
	puzzle[3][11][0] = 'R';
	puzzle[3][11][1] = 'E';
	puzzle[3][11][2] = 'D';
	puzzle[3][11][3] = 'U';
	puzzle[3][11][4] = 'C';
	puzzle[3][11][5] = 'I';
	puzzle[3][11][6] = 'N';
	puzzle[3][11][7] = 'G';
	puzzle[3][11][8] = 'T';
	puzzle[3][11][9] = 'O';
	puzzle[3][11][10] = 'T';
	puzzle[3][11][11] = 'E';
	puzzle[3][11][12] = 'A';
	puzzle[3][11][13] = 'R';
	puzzle[3][11][14] = 'S';
	puzzle[3][12][0] = 'A';
	puzzle[3][12][1] = 'T';
	puzzle[3][12][2] = 'O';
	puzzle[3][12][3] = 'M';
	puzzle[3][12][4] = '*';
	puzzle[3][12][5] = 'Z';
	puzzle[3][12][6] = 'O';
	puzzle[3][12][7] = 'N';
	puzzle[3][12][8] = 'E';
	puzzle[3][12][9] = '*';
	puzzle[3][12][10] = 'R';
	puzzle[3][12][11] = 'U';
	puzzle[3][12][12] = 'R';
	puzzle[3][12][13] = 'A';
	puzzle[3][12][14] = 'L';
	puzzle[3][13][0] = 'T';
	puzzle[3][13][1] = 'A';
	puzzle[3][13][2] = 'R';
	puzzle[3][13][3] = 'P';
	puzzle[3][13][4] = '*';
	puzzle[3][13][5] = 'E';
	puzzle[3][13][6] = 'D';
	puzzle[3][13][7] = 'A';
	puzzle[3][13][8] = 'M';
	puzzle[3][13][9] = '*';
	puzzle[3][13][10] = 'I';
	puzzle[3][13][11] = 'R';
	puzzle[3][13][12] = 'O';
	puzzle[3][13][13] = 'N';
	puzzle[3][13][14] = 'Y';
	puzzle[3][14][0] = 'E';
	puzzle[3][14][1] = 'L';
	puzzle[3][14][2] = 'M';
	puzzle[3][14][3] = 'S';
	puzzle[3][14][4] = '*';
	puzzle[3][14][5] = 'S';
	puzzle[3][14][6] = 'E';
	puzzle[3][14][7] = 'W';
	puzzle[3][14][8] = 'S';
	puzzle[3][14][9] = '*';
	puzzle[3][14][10] = 'C';
	puzzle[3][14][11] = 'O';
	puzzle[3][14][12] = 'O';
	puzzle[3][14][13] = 'K';
	puzzle[3][14][14] = '*';

	//puzzle 5

	puzzle[4][0][0] = 'C';
	puzzle[4][0][1] = 'A';
	puzzle[4][0][2] = 'L';
	puzzle[4][0][3] = 'M';
	puzzle[4][0][4] = '*';
	puzzle[4][0][5] = 'R';
	puzzle[4][0][6] = 'A';
	puzzle[4][0][7] = 'D';
	puzzle[4][0][8] = 'A';
	puzzle[4][0][9] = 'R';
	puzzle[4][0][10] = '*';
	puzzle[4][0][11] = 'P';
	puzzle[4][0][12] = 'A';
	puzzle[4][0][13] = 'D';
	puzzle[4][0][14] = 'S';
	puzzle[4][1][0] = 'O';
	puzzle[4][1][1] = 'R';
	puzzle[4][1][2] = 'E';
	puzzle[4][1][3] = 'O';
	puzzle[4][1][4] = '*';
	puzzle[4][1][5] = 'A';
	puzzle[4][1][6] = 'L';
	puzzle[4][1][7] = 'I';
	puzzle[4][1][8] = 'C';
	puzzle[4][1][9] = 'E';
	puzzle[4][1][10] = '*';
	puzzle[4][1][11] = 'A';
	puzzle[4][1][12] = 'B';
	puzzle[4][1][13] = 'E';
	puzzle[4][1][14] = 'L';
	puzzle[4][2][0] = 'L';
	puzzle[4][2][1] = 'A';
	puzzle[4][2][2] = 'I';
	puzzle[4][2][3] = 'N';
	puzzle[4][2][4] = '*';
	puzzle[4][2][5] = 'R';
	puzzle[4][2][6] = 'O';
	puzzle[4][2][7] = 'V';
	puzzle[4][2][8] = 'E';
	puzzle[4][2][9] = 'D';
	puzzle[4][2][10] = '*';
	puzzle[4][2][11] = 'R';
	puzzle[4][2][12] = 'O';
	puzzle[4][2][13] = 'L';
	puzzle[4][2][14] = 'E';
	puzzle[4][3][0] = 'A';
	puzzle[4][3][1] = 'B';
	puzzle[4][3][2] = 'S';
	puzzle[4][3][3] = 'T';
	puzzle[4][3][4] = 'A';
	puzzle[4][3][5] = 'I';
	puzzle[4][3][6] = 'N';
	puzzle[4][3][7] = 'E';
	puzzle[4][3][8] = 'D';
	puzzle[4][3][9] = '*';
	puzzle[4][3][10] = 'M';
	puzzle[4][3][11] = 'O';
	puzzle[4][3][12] = 'V';
	puzzle[4][3][13] = 'I';
	puzzle[4][3][14] = 'E';
	puzzle[4][4][0] = '*';
	puzzle[4][4][1] = '*';
	puzzle[4][4][2] = '*';
	puzzle[4][4][3] = 'A';
	puzzle[4][4][4] = 'N';
	puzzle[4][4][5] = 'T';
	puzzle[4][4][6] = 'E';
	puzzle[4][4][7] = 'S';
	puzzle[4][4][8] = '*';
	puzzle[4][4][9] = 'P';
	puzzle[4][4][10] = 'A';
	puzzle[4][4][11] = 'L';
	puzzle[4][4][12] = 'E';
	puzzle[4][4][13] = 'S';
	puzzle[4][4][14] = 'T';
	puzzle[4][5][0] = 'S';
	puzzle[4][5][1] = 'H';
	puzzle[4][5][2] = 'A';
	puzzle[4][5][3] = 'N';
	puzzle[4][5][4] = 'T';
	puzzle[4][5][5] = 'Y';
	puzzle[4][5][6] = '*';
	puzzle[4][5][7] = '*';
	puzzle[4][5][8] = 'C';
	puzzle[4][5][9] = 'E';
	puzzle[4][5][10] = 'L';
	puzzle[4][5][11] = 'E';
	puzzle[4][5][12] = 'B';
	puzzle[4][5][13] = '*';
	puzzle[4][5][14] = '*';
	puzzle[4][6][0] = 'T';
	puzzle[4][6][1] = 'U';
	puzzle[4][6][2] = 'B';
	puzzle[4][6][3] = 'A';
	puzzle[4][6][4] = 'S';
	puzzle[4][6][5] = '*';
	puzzle[4][6][6] = 'S';
	puzzle[4][6][7] = 'A';
	puzzle[4][6][8] = 'U';
	puzzle[4][6][9] = 'T';
	puzzle[4][6][10] = 'E';
	puzzle[4][6][11] = '*';
	puzzle[4][6][12] = 'O';
	puzzle[4][6][13] = 'I';
	puzzle[4][6][14] = 'L';
	puzzle[4][7][0] = 'E';
	puzzle[4][7][1] = 'S';
	puzzle[4][7][2] = 'S';
	puzzle[4][7][3] = '*';
	puzzle[4][7][4] = '*';
	puzzle[4][7][5] = 'L';
	puzzle[4][7][6] = 'A';
	puzzle[4][7][7] = 'C';
	puzzle[4][7][8] = 'K';
	puzzle[4][7][9] = 'S';
	puzzle[4][7][10] = '*';
	puzzle[4][7][11] = '*';
	puzzle[4][7][12] = 'A';
	puzzle[4][7][13] = 'K';
	puzzle[4][7][14] = 'A';
	puzzle[4][8][0] = 'W';
	puzzle[4][8][1] = 'H';
	puzzle[4][8][2] = 'O';
	puzzle[4][8][3] = '*';
	puzzle[4][8][4] = 'P';
	puzzle[4][8][5] = 'O';
	puzzle[4][8][6] = 'S';
	puzzle[4][8][7] = 'S';
	puzzle[4][8][8] = 'E';
	puzzle[4][8][9] = '*';
	puzzle[4][8][10] = 'C';
	puzzle[4][8][11] = 'U';
	puzzle[4][8][12] = 'R';
	puzzle[4][8][13] = 'E';
	puzzle[4][8][14] = 'S';
	puzzle[4][9][0] = '*';
	puzzle[4][9][1] = '*';
	puzzle[4][9][2] = 'L';
	puzzle[4][9][3] = 'A';
	puzzle[4][9][4] = 'U';
	puzzle[4][9][5] = 'G';
	puzzle[4][9][6] = 'H';
	puzzle[4][9][7] = '*';
	puzzle[4][9][8] = '*';
	puzzle[4][9][9] = 'P';
	puzzle[4][9][10] = 'A';
	puzzle[4][9][11] = 'N';
	puzzle[4][9][12] = 'D';
	puzzle[4][9][13] = 'A';
	puzzle[4][9][14] = 'S';
	puzzle[4][10][0] = 'S';
	puzzle[4][10][1] = 'K';
	puzzle[4][10][2] = 'U';
	puzzle[4][10][3] = 'L';
	puzzle[4][10][4] = 'L';
	puzzle[4][10][5] = 'S';
	puzzle[4][10][6] = '*';
	puzzle[4][10][7] = 'A';
	puzzle[4][10][8] = 'P';
	puzzle[4][10][9] = 'A';
	puzzle[4][10][10] = 'R';
	puzzle[4][10][11] = 'T';
	puzzle[4][10][12] = '*';
	puzzle[4][10][13] = '*';
	puzzle[4][10][14] = '*';
	puzzle[4][11][0] = 'N';
	puzzle[4][11][1] = 'O';
	puzzle[4][11][2] = 'T';
	puzzle[4][11][3] = 'I';
	puzzle[4][11][4] = 'P';
	puzzle[4][11][5] = '*';
	puzzle[4][11][6] = 'A';
	puzzle[4][11][7] = 'B';
	puzzle[4][11][8] = 'U';
	puzzle[4][11][9] = 'N';
	puzzle[4][11][10] = 'D';
	puzzle[4][11][11] = 'A';
	puzzle[4][11][12] = 'N';
	puzzle[4][11][13] = 'C';
	puzzle[4][11][14] = 'E';
	puzzle[4][12][0] = 'O';
	puzzle[4][12][1] = 'R';
	puzzle[4][12][2] = 'E';
	puzzle[4][12][3] = 'S';
	puzzle[4][12][4] = '*';
	puzzle[4][12][5] = 'C';
	puzzle[4][12][6] = 'H';
	puzzle[4][12][7] = 'A';
	puzzle[4][12][8] = 'R';
	puzzle[4][12][9] = 'T';
	puzzle[4][12][10] = '*';
	puzzle[4][12][11] = 'M';
	puzzle[4][12][12] = 'O';
	puzzle[4][12][13] = 'R';
	puzzle[4][12][14] = 'E';
	puzzle[4][13][0] = 'B';
	puzzle[4][13][1] = 'E';
	puzzle[4][13][2] = 'L';
	puzzle[4][13][3] = 'T';
	puzzle[4][13][4] = '*';
	puzzle[4][13][5] = 'D';
	puzzle[4][13][6] = 'E';
	puzzle[4][13][7] = 'T';
	puzzle[4][13][8] = 'E';
	puzzle[4][13][9] = 'R';
	puzzle[4][13][10] = '*';
	puzzle[4][13][11] = 'E';
	puzzle[4][13][12] = 'V';
	puzzle[4][13][13] = 'I';
	puzzle[4][13][14] = 'L';
	puzzle[4][14][0] = 'S';
	puzzle[4][14][1] = 'A';
	puzzle[4][14][2] = 'Y';
	puzzle[4][14][3] = 'S';
	puzzle[4][14][4] = '*';
	puzzle[4][14][5] = 'E';
	puzzle[4][14][6] = 'M';
	puzzle[4][14][7] = 'E';
	puzzle[4][14][8] = 'R';
	puzzle[4][14][9] = 'Y';
	puzzle[4][14][10] = '*';
	puzzle[4][14][11] = 'D';
	puzzle[4][14][12] = 'A';
	puzzle[4][14][13] = 'B';
	puzzle[4][14][14] = 'S';

	//puzzle 6

	puzzle[5][0][0] = 'B';
	puzzle[5][0][1] = 'O';
	puzzle[5][0][2] = 'S';
	puzzle[5][0][3] = 'C';
	puzzle[5][0][4] = '*';
	puzzle[5][0][5] = 'T';
	puzzle[5][0][6] = 'E';
	puzzle[5][0][7] = 'R';
	puzzle[5][0][8] = 'M';
	puzzle[5][0][9] = '*';
	puzzle[5][0][10] = 'S';
	puzzle[5][0][11] = 'C';
	puzzle[5][0][12] = 'R';
	puzzle[5][0][13] = 'U';
	puzzle[5][0][14] = 'B';
	puzzle[5][1][0] = 'A';
	puzzle[5][1][1] = 'R';
	puzzle[5][1][2] = 'I';
	puzzle[5][1][3] = 'A';
	puzzle[5][1][4] = '*';
	puzzle[5][1][5] = 'A';
	puzzle[5][1][6] = 'L';
	puzzle[5][1][7] = 'O';
	puzzle[5][1][8] = 'E';
	puzzle[5][1][9] = '*';
	puzzle[5][1][10] = 'A';
	puzzle[5][1][11] = 'R';
	puzzle[5][1][12] = 'E';
	puzzle[5][1][13] = 'S';
	puzzle[5][1][14] = 'O';
	puzzle[5][2][0] = 'H';
	puzzle[5][2][1] = 'E';
	puzzle[5][2][2] = 'R';
	puzzle[5][2][3] = 'R';
	puzzle[5][2][4] = '*';
	puzzle[5][2][5] = 'T';
	puzzle[5][2][6] = 'A';
	puzzle[5][2][7] = 'M';
	puzzle[5][2][8] = 'S';
	puzzle[5][2][9] = '*';
	puzzle[5][2][10] = 'Y';
	puzzle[5][2][11] = 'O';
	puzzle[5][2][12] = 'D';
	puzzle[5][2][13] = 'E';
	puzzle[5][2][14] = 'L';
	puzzle[5][3][0] = '*';
	puzzle[5][3][1] = 'S';
	puzzle[5][3][2] = 'E';
	puzzle[5][3][3] = 'C';
	puzzle[5][3][4] = 'R';
	puzzle[5][3][5] = 'E';
	puzzle[5][3][6] = 'T';
	puzzle[5][3][7] = 'P';
	puzzle[5][3][8] = 'A';
	puzzle[5][3][9] = 'S';
	puzzle[5][3][10] = 'S';
	puzzle[5][3][11] = 'W';
	puzzle[5][3][12] = 'O';
	puzzle[5][3][13] = 'R';
	puzzle[5][3][14] = 'D';
	puzzle[5][4][0] = '*';
	puzzle[5][4][1] = '*';
	puzzle[5][4][2] = '*';
	puzzle[5][4][3] = 'H';
	puzzle[5][4][4] = 'E';
	puzzle[5][4][5] = 'R';
	puzzle[5][4][6] = 'E';
	puzzle[5][4][7] = '*';
	puzzle[5][4][8] = '*';
	puzzle[5][4][9] = 'A';
	puzzle[5][4][10] = 'M';
	puzzle[5][4][11] = 'S';
	puzzle[5][4][12] = '*';
	puzzle[5][4][13] = '*';
	puzzle[5][4][14] = '*';
	puzzle[5][5][0] = 'D';
	puzzle[5][5][1] = 'E';
	puzzle[5][5][2] = 'C';
	puzzle[5][5][3] = 'A';
	puzzle[5][5][4] = 'F';
	puzzle[5][5][5] = 'S';
	puzzle[5][5][6] = '*';
	puzzle[5][5][7] = 'P';
	puzzle[5][5][8] = 'A';
	puzzle[5][5][9] = 'V';
	puzzle[5][5][10] = 'E';
	puzzle[5][5][11] = '*';
	puzzle[5][5][12] = 'O';
	puzzle[5][5][13] = 'A';
	puzzle[5][5][14] = 'T';
	puzzle[5][6][0] = 'E';
	puzzle[5][6][1] = 'R';
	puzzle[5][6][2] = 'A';
	puzzle[5][6][3] = 'S';
	puzzle[5][6][4] = 'E';
	puzzle[5][6][5] = '*';
	puzzle[5][6][6] = 'T';
	puzzle[5][6][7] = 'I';
	puzzle[5][6][8] = 'M';
	puzzle[5][6][9] = 'E';
	puzzle[5][6][10] = '*';
	puzzle[5][6][11] = 'A';
	puzzle[5][6][12] = 'N';
	puzzle[5][6][13] = 'T';
	puzzle[5][6][14] = 'I';
	puzzle[5][7][0] = 'C';
	puzzle[5][7][1] = 'O';
	puzzle[5][7][2] = 'V';
	puzzle[5][7][3] = 'E';
	puzzle[5][7][4] = 'R';
	puzzle[5][7][5] = 'T';
	puzzle[5][7][6] = 'O';
	puzzle[5][7][7] = 'P';
	puzzle[5][7][8] = 'E';
	puzzle[5][7][9] = 'R';
	puzzle[5][7][10] = 'A';
	puzzle[5][7][11] = 'T';
	puzzle[5][7][12] = 'I';
	puzzle[5][7][13] = 'O';
	puzzle[5][7][14] = 'N';
	puzzle[5][8][0] = 'O';
	puzzle[5][8][1] = 'D';
	puzzle[5][8][2] = 'E';
	puzzle[5][8][3] = 'S';
	puzzle[5][8][4] = '*';
	puzzle[5][8][5] = 'W';
	puzzle[5][8][6] = 'R';
	puzzle[5][8][7] = 'E';
	puzzle[5][8][8] = 'N';
	puzzle[5][8][9] = '*';
	puzzle[5][8][10] = 'S';
	puzzle[5][8][11] = 'T';
	puzzle[5][8][12] = 'O';
	puzzle[5][8][13] = 'N';
	puzzle[5][8][14] = 'E';
	puzzle[5][9][0] = 'Y';
	puzzle[5][9][1] = 'E';
	puzzle[5][9][2] = 'S';
	puzzle[5][9][3] = '*';
	puzzle[5][9][4] = 'F';
	puzzle[5][9][5] = 'E';
	puzzle[5][9][6] = 'E';
	puzzle[5][9][7] = 'S';
	puzzle[5][9][8] = '*';
	puzzle[5][9][9] = 'S';
	puzzle[5][9][10] = 'H';
	puzzle[5][9][11] = 'I';
	puzzle[5][9][12] = 'N';
	puzzle[5][9][13] = 'E';
	puzzle[5][9][14] = 'S';
	puzzle[5][10][0] = '*';
	puzzle[5][10][1] = '*';
	puzzle[5][10][2] = '*';
	puzzle[5][10][3] = 'O';
	puzzle[5][10][4] = 'L';
	puzzle[5][10][5] = 'E';
	puzzle[5][10][6] = '*';
	puzzle[5][10][7] = '*';
	puzzle[5][10][8] = 'B';
	puzzle[5][10][9] = 'E';
	puzzle[5][10][10] = 'E';
	puzzle[5][10][11] = 'T';
	puzzle[5][10][12] = '*';
	puzzle[5][10][13] = '*';
	puzzle[5][10][14] = '*';
	puzzle[5][11][0] = 'H';
	puzzle[5][11][1] = 'I';
	puzzle[5][11][2] = 'D';
	puzzle[5][11][3] = 'D';
	puzzle[5][11][4] = 'E';
	puzzle[5][11][5] = 'N';
	puzzle[5][11][6] = 'T';
	puzzle[5][11][7] = 'R';
	puzzle[5][11][8] = 'E';
	puzzle[5][11][9] = 'A';
	puzzle[5][11][10] = 'S';
	puzzle[5][11][11] = 'U';
	puzzle[5][11][12] = 'R';
	puzzle[5][11][13] = 'E';
	puzzle[5][11][14] = '*';
	puzzle[5][12][0] = 'A';
	puzzle[5][12][1] = 'S';
	puzzle[5][12][2] = 'I';
	puzzle[5][12][3] = 'D';
	puzzle[5][12][4] = 'E';
	puzzle[5][12][5] = '*';
	puzzle[5][12][6] = 'O';
	puzzle[5][12][7] = 'I';
	puzzle[5][12][8] = 'L';
	puzzle[5][12][9] = 'S';
	puzzle[5][12][10] = '*';
	puzzle[5][12][11] = 'D';
	puzzle[5][12][12] = 'A';
	puzzle[5][12][13] = 'R';
	puzzle[5][12][14] = 'E';
	puzzle[5][13][0] = 'T';
	puzzle[5][13][1] = 'E';
	puzzle[5][13][2] = 'N';
	puzzle[5][13][3] = 'E';
	puzzle[5][13][4] = 'T';
	puzzle[5][13][5] = '*';
	puzzle[5][13][6] = 'O';
	puzzle[5][13][7] = 'S';
	puzzle[5][13][8] = 'L';
	puzzle[5][13][9] = 'O';
	puzzle[5][13][10] = '*';
	puzzle[5][13][11] = 'E';
	puzzle[5][13][12] = 'V';
	puzzle[5][13][13] = 'I';
	puzzle[5][13][14] = 'L';
	puzzle[5][14][0] = 'S';
	puzzle[5][14][1] = 'E';
	puzzle[5][14][2] = 'E';
	puzzle[5][14][3] = 'R';
	puzzle[5][14][4] = 'S';
	puzzle[5][14][5] = '*';
	puzzle[5][14][6] = 'T';
	puzzle[5][14][7] = 'E';
	puzzle[5][14][8] = 'E';
	puzzle[5][14][9] = 'N';
	puzzle[5][14][10] = '*';
	puzzle[5][14][11] = 'S';
	puzzle[5][14][12] = 'E';
	puzzle[5][14][13] = 'E';
	puzzle[5][14][14] = 'M';

	//puzzle 7

	puzzle[6][0][0] = 'D';
	puzzle[6][0][1] = 'A';
	puzzle[6][0][2] = 'M';
	puzzle[6][0][3] = 'S';
	puzzle[6][0][4] = '*';
	puzzle[6][0][5] = '*';
	puzzle[6][0][6] = 'G';
	puzzle[6][0][7] = 'A';
	puzzle[6][0][8] = 'T';
	puzzle[6][0][9] = 'O';
	puzzle[6][0][10] = 'R';
	puzzle[6][0][11] = '*';
	puzzle[6][0][12] = 'A';
	puzzle[6][0][13] = 'R';
	puzzle[6][0][14] = 'M';
	puzzle[6][1][0] = 'I';
	puzzle[6][1][1] = 'N';
	puzzle[6][1][2] = 'E';
	puzzle[6][1][3] = 'P';
	puzzle[6][1][4] = 'T';
	puzzle[6][1][5] = '*';
	puzzle[6][1][6] = 'A';
	puzzle[6][1][7] = 'W';
	puzzle[6][1][8] = 'A';
	puzzle[6][1][9] = 'K';
	puzzle[6][1][10] = 'E';
	puzzle[6][1][11] = '*';
	puzzle[6][1][12] = 'L';
	puzzle[6][1][13] = 'E';
	puzzle[6][1][14] = 'O';
	puzzle[6][2][0] = 'A';
	puzzle[6][2][1] = 'T';
	puzzle[6][2][2] = 'S';
	puzzle[6][2][3] = 'E';
	puzzle[6][2][4] = 'A';
	puzzle[6][2][5] = '*';
	puzzle[6][2][6] = 'N';
	puzzle[6][2][7] = 'O';
	puzzle[6][2][8] = 'T';
	puzzle[6][2][9] = 'E';
	puzzle[6][2][10] = 'D';
	puzzle[6][2][11] = '*';
	puzzle[6][2][12] = 'I';
	puzzle[6][2][13] = 'L';
	puzzle[6][2][14] = 'L';
	puzzle[6][3][0] = 'L';
	puzzle[6][3][1] = 'E';
	puzzle[6][3][2] = 'A';
	puzzle[6][3][3] = 'D';
	puzzle[6][3][4] = 'I';
	puzzle[6][3][5] = 'N';
	puzzle[6][3][6] = 'G';
	puzzle[6][3][7] = 'L';
	puzzle[6][3][8] = 'A';
	puzzle[6][3][9] = 'D';
	puzzle[6][3][10] = 'Y';
	puzzle[6][3][11] = '*';
	puzzle[6][3][12] = 'B';
	puzzle[6][3][13] = 'I';
	puzzle[6][3][14] = 'D';
	puzzle[6][4][0] = '*';
	puzzle[6][4][1] = '*';
	puzzle[6][4][2] = '*';
	puzzle[6][4][3] = '*';
	puzzle[6][4][4] = 'L';
	puzzle[6][4][5] = 'O';
	puzzle[6][4][6] = 'S';
	puzzle[6][4][7] = '*';
	puzzle[6][4][8] = '*';
	puzzle[6][4][9] = '*';
	puzzle[6][4][10] = 'E';
	puzzle[6][4][11] = 'P';
	puzzle[6][4][12] = 'I';
	puzzle[6][4][13] = 'C';
	puzzle[6][4][14] = 'S';
	puzzle[6][5][0] = 'B';
	puzzle[6][5][1] = 'E';
	puzzle[6][5][2] = 'S';
	puzzle[6][5][3] = 'T';
	puzzle[6][5][4] = 'E';
	puzzle[6][5][5] = 'D';
	puzzle[6][5][6] = '*';
	puzzle[6][5][7] = 'C';
	puzzle[6][5][8] = 'H';
	puzzle[6][5][9] = 'A';
	puzzle[6][5][10] = 'S';
	puzzle[6][5][11] = 'E';
	puzzle[6][5][12] = '*';
	puzzle[6][5][13] = '*';
	puzzle[6][5][14] = '*';
	puzzle[6][6][0] = 'A';
	puzzle[6][6][1] = 'C';
	puzzle[6][6][2] = 'T';
	puzzle[6][6][3] = 'O';
	puzzle[6][6][4] = 'N';
	puzzle[6][6][5] = '*';
	puzzle[6][6][6] = 'A';
	puzzle[6][6][7] = 'L';
	puzzle[6][6][8] = 'O';
	puzzle[6][6][9] = 'T';
	puzzle[6][6][10] = '*';
	puzzle[6][6][11] = 'T';
	puzzle[6][6][12] = 'R';
	puzzle[6][6][13] = 'O';
	puzzle[6][6][14] = 'T';
	puzzle[6][7][0] = 'A';
	puzzle[6][7][1] = 'H';
	puzzle[6][7][2] = 'E';
	puzzle[6][7][3] = 'A';
	puzzle[6][7][4] = 'D';
	puzzle[6][7][5] = 'O';
	puzzle[6][7][6] = 'F';
	puzzle[6][7][7] = 'O';
	puzzle[6][7][8] = 'N';
	puzzle[6][7][9] = 'E';
	puzzle[6][7][10] = 'S';
	puzzle[6][7][11] = 'T';
	puzzle[6][7][12] = 'I';
	puzzle[6][7][13] = 'M';
	puzzle[6][7][14] = 'E';
	puzzle[6][8][0] = 'S';
	puzzle[6][8][1] = 'O';
	puzzle[6][8][2] = 'P';
	puzzle[6][8][3] = 'S';
	puzzle[6][8][4] = '*';
	puzzle[6][8][5] = 'W';
	puzzle[6][8][6] = 'A';
	puzzle[6][8][7] = 'D';
	puzzle[6][8][8] = 'E';
	puzzle[6][8][9] = '*';
	puzzle[6][8][10] = 'T';
	puzzle[6][8][11] = 'E';
	puzzle[6][8][12] = 'P';
	puzzle[6][8][13] = 'E';
	puzzle[6][8][14] = 'E';
	puzzle[6][9][0] = '*';
	puzzle[6][9][1] = '*';
	puzzle[6][9][2] = '*';
	puzzle[6][9][3] = 'T';
	puzzle[6][9][4] = 'I';
	puzzle[6][9][5] = 'E';
	puzzle[6][9][6] = 'R';
	puzzle[6][9][7] = 'S';
	puzzle[6][9][8] = '*';
	puzzle[6][9][9] = 'W';
	puzzle[6][9][10] = 'I';
	puzzle[6][9][11] = 'D';
	puzzle[6][9][12] = 'E';
	puzzle[6][9][13] = 'N';
	puzzle[6][9][14] = 'S';
	puzzle[6][10][0] = 'L';
	puzzle[6][10][1] = 'A';
	puzzle[6][10][2] = 'S';
	puzzle[6][10][3] = 'S';
	puzzle[6][10][4] = 'O';
	puzzle[6][10][5] = '*';
	puzzle[6][10][6] = '*';
	puzzle[6][10][7] = '*';
	puzzle[6][10][8] = 'M';
	puzzle[6][10][9] = 'O';
	puzzle[6][10][10] = 'N';
	puzzle[6][10][11] = '*';
	puzzle[6][10][12] = '*';
	puzzle[6][10][13] = '*';
	puzzle[6][10][14] = '*';
	puzzle[6][11][0] = 'A';
	puzzle[6][11][1] = 'R';
	puzzle[6][11][2] = 'C';
	puzzle[6][11][3] = '*';
	puzzle[6][11][4] = 'W';
	puzzle[6][11][5] = 'I';
	puzzle[6][11][6] = 'N';
	puzzle[6][11][7] = 'N';
	puzzle[6][11][8] = 'I';
	puzzle[6][11][9] = 'N';
	puzzle[6][11][10] = 'G';
	puzzle[6][11][11] = 'O';
	puzzle[6][11][12] = 'V';
	puzzle[6][11][13] = 'E';
	puzzle[6][11][14] = 'R';
	puzzle[6][12][0] = 'P';
	puzzle[6][12][1] = 'R';
	puzzle[6][12][2] = 'O';
	puzzle[6][12][3] = '*';
	puzzle[6][12][4] = 'A';
	puzzle[6][12][5] = 'R';
	puzzle[6][12][6] = 'I';
	puzzle[6][12][7] = 'A';
	puzzle[6][12][8] = 'S';
	puzzle[6][12][9] = '*';
	puzzle[6][12][10] = 'E';
	puzzle[6][12][11] = 'R';
	puzzle[6][12][12] = 'O';
	puzzle[6][12][13] = 'D';
	puzzle[6][12][14] = 'E';
	puzzle[6][13][0] = 'S';
	puzzle[6][13][1] = 'A';
	puzzle[6][13][2] = 'P';
	puzzle[6][13][3] = '*';
	puzzle[6][13][4] = 'N';
	puzzle[6][13][5] = 'O';
	puzzle[6][13][6] = 'T';
	puzzle[6][13][7] = 'M';
	puzzle[6][13][8] = 'E';
	puzzle[6][13][9] = '*';
	puzzle[6][13][10] = 'R';
	puzzle[6][13][11] = 'A';
	puzzle[6][13][12] = 'T';
	puzzle[6][13][13] = 'E';
	puzzle[6][13][14] = 'S';
	puzzle[6][14][0] = 'E';
	puzzle[6][14][1] = 'Y';
	puzzle[6][14][2] = 'E';
	puzzle[6][14][3] = '*';
	puzzle[6][14][4] = 'S';
	puzzle[6][14][5] = 'N';
	puzzle[6][14][6] = 'E';
	puzzle[6][14][7] = 'E';
	puzzle[6][14][8] = 'R';
	puzzle[6][14][9] = '*';
	puzzle[6][14][10] = '*';
	puzzle[6][14][11] = 'L';
	puzzle[6][14][12] = 'E';
	puzzle[6][14][13] = 'N';
	puzzle[6][14][14] = 'T';

	//puzzle 8

	puzzle[7][0][0] = 'A';
	puzzle[7][0][1] = 'B';
	puzzle[7][0][2] = 'C';
	puzzle[7][0][3] = 'S';
	puzzle[7][0][4] = '*';
	puzzle[7][0][5] = 'F';
	puzzle[7][0][6] = 'L';
	puzzle[7][0][7] = 'A';
	puzzle[7][0][8] = 'K';
	puzzle[7][0][9] = 'E';
	puzzle[7][0][10] = '*';
	puzzle[7][0][11] = 'O';
	puzzle[7][0][12] = 'F';
	puzzle[7][0][13] = 'F';
	puzzle[7][0][14] = 'S';
	puzzle[7][1][0] = 'C';
	puzzle[7][1][1] = 'O';
	puzzle[7][1][2] = 'A';
	puzzle[7][1][3] = 'T';
	puzzle[7][1][4] = '*';
	puzzle[7][1][5] = 'A';
	puzzle[7][1][6] = 'I';
	puzzle[7][1][7] = 'L';
	puzzle[7][1][8] = 'E';
	puzzle[7][1][9] = 'D';
	puzzle[7][1][10] = '*';
	puzzle[7][1][11] = 'B';
	puzzle[7][1][12] = 'R';
	puzzle[7][1][13] = 'I';
	puzzle[7][1][14] = 'E';
	puzzle[7][2][0] = 'I';
	puzzle[7][2][1] = 'N';
	puzzle[7][2][2] = 'F';
	puzzle[7][2][3] = 'O';
	puzzle[7][2][4] = '*';
	puzzle[7][2][5] = 'I';
	puzzle[7][2][6] = 'N';
	puzzle[7][2][7] = 'L';
	puzzle[7][2][8] = 'E';
	puzzle[7][2][9] = 'T';
	puzzle[7][2][10] = '*';
	puzzle[7][2][11] = 'S';
	puzzle[7][2][12] = 'E';
	puzzle[7][2][13] = 'N';
	puzzle[7][2][14] = 'T';
	puzzle[7][3][0] = 'D';
	puzzle[7][3][1] = 'E';
	puzzle[7][3][2] = 'E';
	puzzle[7][3][3] = 'P';
	puzzle[7][3][4] = 'S';
	puzzle[7][3][5] = 'L';
	puzzle[7][3][6] = 'E';
	puzzle[7][3][7] = 'E';
	puzzle[7][3][8] = 'P';
	puzzle[7][3][9] = '*';
	puzzle[7][3][10] = 'S';
	puzzle[7][3][11] = 'E';
	puzzle[7][3][12] = 'E';
	puzzle[7][3][13] = 'D';
	puzzle[7][3][14] = 'S';
	puzzle[7][4][0] = '*';
	puzzle[7][4][1] = '*';
	puzzle[7][4][2] = '*';
	puzzle[7][4][3] = 'T';
	puzzle[7][4][4] = 'E';
	puzzle[7][4][5] = 'E';
	puzzle[7][4][6] = 'N';
	puzzle[7][4][7] = 'Y';
	puzzle[7][4][8] = '*';
	puzzle[7][4][9] = 'B';
	puzzle[7][4][10] = 'O';
	puzzle[7][4][11] = 'S';
	puzzle[7][4][12] = 'S';
	puzzle[7][4][13] = '*';
	puzzle[7][4][14] = '*';
	puzzle[7][5][0] = 'C';
	puzzle[7][5][1] = 'A';
	puzzle[7][5][2] = 'S';
	puzzle[7][5][3] = 'H';
	puzzle[7][5][4] = 'E';
	puzzle[7][5][5] = 'D';
	puzzle[7][5][6] = '*';
	puzzle[7][5][7] = '*';
	puzzle[7][5][8] = 'P';
	puzzle[7][5][9] = 'R';
	puzzle[7][5][10] = 'O';
	puzzle[7][5][11] = 'S';
	puzzle[7][5][12] = 'P';
	puzzle[7][5][13] = 'E';
	puzzle[7][5][14] = 'R';
	puzzle[7][6][0] = 'A';
	puzzle[7][6][1] = 'T';
	puzzle[7][6][2] = 'W';
	puzzle[7][6][3] = 'A';
	puzzle[7][6][4] = 'R';
	puzzle[7][6][5] = '*';
	puzzle[7][6][6] = 'C';
	puzzle[7][6][7] = 'H';
	puzzle[7][6][8] = 'E';
	puzzle[7][6][9] = 'A';
	puzzle[7][6][10] = 'T';
	puzzle[7][6][11] = '*';
	puzzle[7][6][12] = 'E';
	puzzle[7][6][13] = 'L';
	puzzle[7][6][14] = 'I';
	puzzle[7][7][0] = 'P';
	puzzle[7][7][1] = 'O';
	puzzle[7][7][2] = 'E';
	puzzle[7][7][3] = 'T';
	puzzle[7][7][4] = '*';
	puzzle[7][7][5] = 'M';
	puzzle[7][7][6] = 'O';
	puzzle[7][7][7] = 'U';
	puzzle[7][7][8] = 'N';
	puzzle[7][7][9] = 'T';
	puzzle[7][7][10] = '*';
	puzzle[7][7][11] = 'R';
	puzzle[7][7][12] = 'E';
	puzzle[7][7][13] = 'E';
	puzzle[7][7][14] = 'D';
	puzzle[7][8][0] = 'E';
	puzzle[7][8][1] = 'N';
	puzzle[7][8][2] = 'E';
	puzzle[7][8][3] = '*';
	puzzle[7][8][4] = 'R';
	puzzle[7][8][5] = 'O';
	puzzle[7][8][6] = 'P';
	puzzle[7][8][7] = 'E';
	puzzle[7][8][8] = 'S';
	puzzle[7][8][9] = '*';
	puzzle[7][8][10] = 'B';
	puzzle[7][8][11] = 'O';
	puzzle[7][8][12] = 'C';
	puzzle[7][8][13] = 'C';
	puzzle[7][8][14] = 'E';
	puzzle[7][9][0] = 'R';
	puzzle[7][9][1] = 'E';
	puzzle[7][9][2] = 'P';
	puzzle[7][9][3] = 'T';
	puzzle[7][9][4] = 'I';
	puzzle[7][9][5] = 'L';
	puzzle[7][9][6] = 'E';
	puzzle[7][9][7] = '*';
	puzzle[7][9][8] = '*';
	puzzle[7][9][9] = 'Y';
	puzzle[7][9][10] = 'A';
	puzzle[7][9][11] = 'C';
	puzzle[7][9][12] = 'H';
	puzzle[7][9][13] = 'T';
	puzzle[7][9][14] = 'S';
	puzzle[7][10][0] = '*';
	puzzle[7][10][1] = '*';
	puzzle[7][10][2] = 'S';
	puzzle[7][10][3] = 'H';
	puzzle[7][10][4] = 'O';
	puzzle[7][10][5] = 'E';
	puzzle[7][10][6] = '*';
	puzzle[7][10][7] = 'S';
	puzzle[7][10][8] = 'T';
	puzzle[7][10][9] = 'I';
	puzzle[7][10][10] = 'N';
	puzzle[7][10][11] = 'K';
	puzzle[7][10][12] = '*';
	puzzle[7][10][13] = '*';
	puzzle[7][10][14] = '*';
	puzzle[7][11][0] = 'P';
	puzzle[7][11][1] = 'A';
	puzzle[7][11][2] = 'W';
	puzzle[7][11][3] = 'A';
	puzzle[7][11][4] = 'T';
	puzzle[7][11][5] = '*';
	puzzle[7][11][6] = 'T';
	puzzle[7][11][7] = 'H';
	puzzle[7][11][8] = 'R';
	puzzle[7][11][9] = 'E';
	puzzle[7][11][10] = 'E';
	puzzle[7][11][11] = 'F';
	puzzle[7][11][12] = 'E';
	puzzle[7][11][13] = 'E';
	puzzle[7][11][14] = 'T';
	puzzle[7][12][0] = 'O';
	puzzle[7][12][1] = 'P';
	puzzle[7][12][2] = 'E';
	puzzle[7][12][3] = 'N';
	puzzle[7][12][4] = '*';
	puzzle[7][12][5] = 'T';
	puzzle[7][12][6] = 'R';
	puzzle[7][12][7] = 'A';
	puzzle[7][12][8] = 'I';
	puzzle[7][12][9] = 'L';
	puzzle[7][12][10] = '*';
	puzzle[7][12][11] = 'A';
	puzzle[7][12][12] = 'B';
	puzzle[7][12][13] = 'L';
	puzzle[7][12][14] = 'E';
	puzzle[7][13][0] = 'S';
	puzzle[7][13][1] = 'E';
	puzzle[7][13][2] = 'E';
	puzzle[7][13][3] = 'K';
	puzzle[7][13][4] = '*';
	puzzle[7][13][5] = 'W';
	puzzle[7][13][6] = 'A';
	puzzle[7][13][7] = 'D';
	puzzle[7][13][8] = 'E';
	puzzle[7][13][9] = 'D';
	puzzle[7][13][10] = '*';
	puzzle[7][13][11] = 'C';
	puzzle[7][13][12] = 'A';
	puzzle[7][13][13] = 'S';
	puzzle[7][13][14] = 'E';
	puzzle[7][14][0] = 'T';
	puzzle[7][14][1] = 'S';
	puzzle[7][14][2] = 'K';
	puzzle[7][14][3] = 'S';
	puzzle[7][14][4] = '*';
	puzzle[7][14][5] = 'O';
	puzzle[7][14][6] = 'P';
	puzzle[7][14][7] = 'E';
	puzzle[7][14][8] = 'D';
	puzzle[7][14][9] = 'S';
	puzzle[7][14][10] = '*';
	puzzle[7][14][11] = 'E';
	puzzle[7][14][12] = 'Y';
	puzzle[7][14][13] = 'E';
	puzzle[7][14][14] = 'S';

	//puzzle 9

	puzzle[8][14][11] = 'F';
	puzzle[8][14][12] = 'U';
	puzzle[8][14][13] = 'A';
	puzzle[8][14][14] = 'D';

	for(int i=0; i<9; i++){
		for(int j=0; j<15; j++){
			for(int k=0; k<15; k++){
				if(puzzle[i][j][k] != '*'){
					sketch[i][j][k] = ' ';
					solve[i][j][k] = ' ';
					reveal[i][j][k] = 'n';
				}
			}
		}
	}



	//puzzle1 1
	puzzle1[0][0][0] = 'A';
	puzzle1[0][0][1] = 'N';
	puzzle1[0][0][2] = 'A';
	puzzle1[0][1][0] = 'R';
	puzzle1[0][1][1] = 'O';
	puzzle1[0][1][2] = 'W';
	puzzle1[0][2][0] = 'T';
	puzzle1[0][2][1] = 'W';
	puzzle1[0][2][2] = 'A';
	puzzle1[0][2][3] = 'I';
	puzzle1[0][2][4] = 'N';
	puzzle1[0][3][2] = 'R';
	puzzle1[0][3][3] = 'O';
	puzzle1[0][3][4] = 'O';
	puzzle1[0][4][2] = 'E';
	puzzle1[0][4][3] = 'N';
	puzzle1[0][4][4] = 'D';

	//puzzle1 2

	puzzle1[1][0][0] = 'P';
	puzzle1[1][0][1] = 'A';
	puzzle1[1][0][2] = 'R';
	puzzle1[1][0][3] = 'K';
	puzzle1[1][1][0] = 'E';
	puzzle1[1][1][1] = 'B';
	puzzle1[1][1][2] = 'A';
	puzzle1[1][1][3] = 'Y';
	puzzle1[1][2][0] = 'T';
	puzzle1[1][2][1] = 'U';
	puzzle1[1][2][2] = 'T';
	puzzle1[1][2][3] = 'O';
	puzzle1[1][2][4] = 'R';
	puzzle1[1][3][1] = 'Z';
	puzzle1[1][3][2] = 'I';
	puzzle1[1][3][3] = 'T';
	puzzle1[1][3][4] = 'I';
	puzzle1[1][4][1] = 'Z';
	puzzle1[1][4][2] = 'O';
	puzzle1[1][4][3] = 'O';
	puzzle1[1][4][4] = 'M';




	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				if(puzzle1[i][j][k] != '*'){
					sketch1[i][j][k] = ' ';
					solve1[i][j][k] = ' ';
					reveal1[i][j][k] = 'n';
				}
			}
		}
	}

	//puzzle3 1

	puzzle3[0][0][0] = 'M';
	puzzle3[0][0][1] = 'A';
	puzzle3[0][0][2] = 'S';
	puzzle3[0][0][3] = 'H';
	puzzle3[0][0][4] = '*';
	puzzle3[0][0][5] = 'R';
	puzzle3[0][0][6] = 'A';
	puzzle3[0][0][7] = 'B';
	puzzle3[0][0][8] = 'B';
	puzzle3[0][0][9] = 'I';
	puzzle3[0][1][0] = 'I';
	puzzle3[0][1][1] = 'S';
	puzzle3[0][1][2] = 'E';
	puzzle3[0][1][3] = 'E';
	puzzle3[0][1][4] = '*';
	puzzle3[0][1][5] = 'A';
	puzzle3[0][1][6] = 'L';
	puzzle3[0][1][7] = 'L';
	puzzle3[0][1][8] = 'I';
	puzzle3[0][1][9] = 'N';
	puzzle3[0][2][0] = 'S';
	puzzle3[0][2][1] = 'C';
	puzzle3[0][2][2] = 'A';
	puzzle3[0][2][3] = 'R';
	puzzle3[0][2][4] = '*';
	puzzle3[0][2][5] = 'P';
	puzzle3[0][2][6] = 'L';
	puzzle3[0][2][7] = 'U';
	puzzle3[0][2][8] = 'C';
	puzzle3[0][2][9] = 'K';
	puzzle3[0][3][0] = 'T';
	puzzle3[0][3][1] = 'I';
	puzzle3[0][3][2] = 'M';
	puzzle3[0][3][3] = 'O';
	puzzle3[0][3][4] = 'T';
	puzzle3[0][3][5] = 'H';
	puzzle3[0][3][6] = 'E';
	puzzle3[0][3][7] = 'E';
	puzzle3[0][3][8] = '*';
	puzzle3[0][3][9] = '*';
	puzzle3[0][4][0] = 'S';
	puzzle3[0][4][1] = 'I';
	puzzle3[0][4][2] = 'S';
	puzzle3[0][4][3] = '*';
	puzzle3[0][4][4] = 'H';
	puzzle3[0][4][5] = 'A';
	puzzle3[0][4][6] = 'Y';
	puzzle3[0][5][3] = 'T';
	puzzle3[0][5][4] = 'E';
	puzzle3[0][5][5] = 'E';
	puzzle3[0][5][6] = '*';
	puzzle3[0][5][7] = 'S';
	puzzle3[0][5][8] = 'M';
	puzzle3[0][5][9] = 'U';
	puzzle3[0][6][0] = '*';
	puzzle3[0][6][1] = '*';
	puzzle3[0][6][2] = 'C';
	puzzle3[0][6][3] = 'H';
	puzzle3[0][6][4] = 'A';
	puzzle3[0][6][5] = 'L';
	puzzle3[0][6][6] = 'A';
	puzzle3[0][6][7] = 'M';
	puzzle3[0][6][8] = 'E';
	puzzle3[0][6][9] = 'T';
	puzzle3[0][7][0] = 'C';
	puzzle3[0][7][1] = 'R';
	puzzle3[0][7][2] = 'U';
	puzzle3[0][7][3] = 'E';
	puzzle3[0][7][4] = 'T';
	puzzle3[0][7][5] = '*';
	puzzle3[0][7][6] = 'P';
	puzzle3[0][7][7] = 'E';
	puzzle3[0][7][8] = 'S';
	puzzle3[0][7][9] = 'T';
	puzzle3[0][8][0] = 'B';
	puzzle3[0][8][1] = 'A';
	puzzle3[0][8][2] = 'R';
	puzzle3[0][8][3] = 'R';
	puzzle3[0][8][4] = 'E';
	puzzle3[0][8][5] = '*';
	puzzle3[0][8][6] = 'E';
	puzzle3[0][8][7] = 'L';
	puzzle3[0][8][8] = 'S';
	puzzle3[0][8][9] = 'E';
	puzzle3[0][9][0] = 'S';
	puzzle3[0][9][1] = 'T';
	puzzle3[0][9][2] = 'E';
	puzzle3[0][9][3] = 'E';
	puzzle3[0][9][4] = 'R';
	puzzle3[0][9][5] = '*';
	puzzle3[0][9][6] = 'S';
	puzzle3[0][9][7] = 'T';
	puzzle3[0][9][8] = 'I';
	puzzle3[0][9][9] = 'R';


	//puzzle3 2

	puzzle3[1][0][0] = 'R';
	puzzle3[1][0][1] = 'O';
	puzzle3[1][0][2] = 'A';
	puzzle3[1][0][3] = 'R';
	puzzle3[1][0][4] = '*';
	puzzle3[1][0][5] = '*';
	puzzle3[1][0][6] = 'B';
	puzzle3[1][0][7] = 'O';
	puzzle3[1][0][8] = 'T';
	puzzle3[1][0][9] = 'H';
	puzzle3[1][1][0] = 'E';
	puzzle3[1][1][1] = 'D';
	puzzle3[1][1][2] = 'G';
	puzzle3[1][1][3] = 'E';
	puzzle3[1][1][4] = '*';
	puzzle3[1][1][5] = 'S';
	puzzle3[1][1][6] = 'A';
	puzzle3[1][1][7] = 'L';
	puzzle3[1][1][8] = 'S';
	puzzle3[1][1][9] = 'A';
	puzzle3[1][2][0] = 'D';
	puzzle3[1][2][1] = 'O';
	puzzle3[1][2][2] = 'E';
	puzzle3[1][2][3] = 'S';
	puzzle3[1][2][4] = '*';
	puzzle3[1][2][5] = 'T';
	puzzle3[1][2][6] = 'R';
	puzzle3[1][2][7] = 'A';
	puzzle3[1][2][8] = 'P';
	puzzle3[1][2][9] = 'S';
	puzzle3[1][3][0] = 'O';
	puzzle3[1][3][1] = 'R';
	puzzle3[1][3][2] = 'D';
	puzzle3[1][3][3] = 'I';
	puzzle3[1][3][4] = 'N';
	puzzle3[1][3][5] = 'A';
	puzzle3[1][3][6] = 'R';
	puzzle3[1][3][7] = 'Y';
	puzzle3[1][3][8] = '*';
	puzzle3[1][3][9] = '*';
	puzzle3[1][4][3] = 'G';
	puzzle3[1][4][4] = 'A';
	puzzle3[1][4][5] = 'T';
	puzzle3[1][4][6] = 'E';
	puzzle3[1][5][2] = 'A';
	puzzle3[1][5][3] = 'N';
	puzzle3[1][5][4] = 'G';
	puzzle3[1][5][5] = 'E';
	puzzle3[1][5][6] = 'L';
	puzzle3[1][5][7] = 'S';
	puzzle3[1][6][0] = 'L';
	puzzle3[1][6][1] = 'I';
	puzzle3[1][6][2] = 'T';
	puzzle3[1][6][7] = 'A';
	puzzle3[1][6][8] = 'I';
	puzzle3[1][6][9] = 'D';
	puzzle3[1][7][0] = 'I';
	puzzle3[1][7][1] = 'N';
	puzzle3[1][7][2] = 'L';
	puzzle3[1][7][3] = 'A';
	puzzle3[1][7][4] = 'Y';
	puzzle3[1][7][6] = 'W';
	puzzle3[1][7][7] = 'I';
	puzzle3[1][7][8] = 'N';
	puzzle3[1][7][9] = 'E';
	puzzle3[1][8][0] = 'S';
	puzzle3[1][8][1] = 'C';
	puzzle3[1][8][2] = 'A';
	puzzle3[1][8][3] = 'R';
	puzzle3[1][8][4] = 'E';
	puzzle3[1][8][6] = 'A';
	puzzle3[1][8][7] = 'N';
	puzzle3[1][8][8] = 'T';
	puzzle3[1][8][9] = 'E';
	puzzle3[1][9][0] = 'T';
	puzzle3[1][9][1] = 'A';
	puzzle3[1][9][2] = 'S';
	puzzle3[1][9][3] = 'K';
	puzzle3[1][9][4] = 'S';
	puzzle3[1][9][5] = '*';
	puzzle3[1][9][6] = 'S';
	puzzle3[1][9][7] = 'T';
	puzzle3[1][9][8] = 'O';
	puzzle3[1][9][9] = 'P';



	for(int i=0; i<2; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				if(puzzle3[i][j][k] != '*'){
					sketch2[i][j][k] = ' ';
					solve2[i][j][k] = ' ';
					reveal2[i][j][k] = 'n';
				}
			}
		}
	}


	//all the hints are saved here

	//hint 1

	hint[0][0][0][0] = '1';
	hint[0][0][0][1] = '*';
	hint[0][0][1][0] = '2';
	hint[0][0][1][1] = '*';
	hint[0][0][2][0] = '3';
	hint[0][0][2][1] = '*';
	hint[0][0][3][0] = '4';
	hint[0][0][3][1] = '*';
	hint[0][0][4][0] = '5';
	hint[0][0][4][1] = '*';
	hint[0][0][6][0] = '6';
	hint[0][0][6][1] = '*';
	hint[0][0][7][0] = '7';
	hint[0][0][7][1] = '*';
	hint[0][0][8][0] = '8';
	hint[0][0][8][1] = '*';
	hint[0][0][9][0] = '9';
	hint[0][0][9][1] = '*';
	hint[0][0][11][0] = '1';
	hint[0][0][11][1] = '0';
	hint[0][0][12][0] = '1';
	hint[0][0][12][1] = '1';
	hint[0][0][13][0] = '1';
	hint[0][0][13][1] = '2';
	hint[0][0][14][0] = '1';
	hint[0][0][14][1] = '3';
	hint[0][1][0][0] = '1';
	hint[0][1][0][1] = '4';
	hint[0][1][6][0] = '1';
	hint[0][1][6][1] = '5';
	hint[0][1][11][0] = '1';
	hint[0][1][11][1] = '6';
	hint[0][2][0][0] = '1';
	hint[0][2][0][1] = '7';
	hint[0][2][6][0] = '1';
	hint[0][2][6][1] = '8';
	hint[0][2][11][0] = '1';
	hint[0][2][11][1] = '9';
	hint[0][3][0][0] = '2';
	hint[0][3][0][1] = '0';
	hint[0][3][2][0] = '2';
	hint[0][3][2][1] = '1';
	hint[0][3][10][0] = '2';
	hint[0][3][10][1] = '2';
	hint[0][4][0][0] = '2';
	hint[0][4][0][1] = '3';
	hint[0][4][1][0] = '2';
	hint[0][4][1][1] = '4';
	hint[0][4][2][0] = '2';
	hint[0][4][2][1] = '5';
	hint[0][4][4][0] = '2';
	hint[0][4][4][1] = '6';
	hint[0][4][10][0] = '2';
	hint[0][4][10][1] = '7';
	hint[0][5][0][0] = '2';
	hint[0][5][0][1] = '8';
	hint[0][5][3][0] = '2';
	hint[0][5][3][1] = '9';
	hint[0][5][8][0] = '3';
	hint[0][5][8][1] = '0';
	hint[0][5][9][0] = '3';
	hint[0][5][9][1] = '1';
	hint[0][6][0][0] = '3';
	hint[0][6][0][1] = '2';
	hint[0][6][6][0] = '3';
	hint[0][6][6][1] = '3';
	hint[0][6][7][0] = '3';
	hint[0][6][7][1] = '4';
	hint[0][6][12][0] = '3';
	hint[0][6][12][1] = '5';
	hint[0][6][13][0] = '3';
	hint[0][6][13][1] = '6';
	hint[0][6][14][0] = '3';
	hint[0][6][14][1] = '7';
	hint[0][7][0][0] = '3';
	hint[0][7][0][1] = '8';
	hint[0][7][5][0] = '3';
	hint[0][7][5][1] = '9';
	hint[0][7][10][0] = '4';
	hint[0][7][10][1] = '0';
	hint[0][7][11][0] = '4';
	hint[0][7][11][1] = '1';
	hint[0][8][0][0] = '4';
	hint[0][8][0][1] = '2';
	hint[0][8][5][0] = '4';
	hint[0][8][5][1] = '3';
	hint[0][8][10][0] = '4';
	hint[0][8][10][1] = '4';
	hint[0][9][3][0] = '4';
	hint[0][9][3][1] = '5';
	hint[0][9][4][0] = '4';
	hint[0][9][4][1] = '6';
	hint[0][9][9][0] = '4';
	hint[0][9][9][1] = '7';
	hint[0][10][0][0] = '4';
	hint[0][10][0][1] = '8';
	hint[0][10][1][0] = '4';
	hint[0][10][1][1] = '9';
	hint[0][10][2][0] = '5';
	hint[0][10][2][1] = '0';
	hint[0][10][6][0] = '5';
	hint[0][10][6][1] = '1';
	hint[0][10][7][0] = '5';
	hint[0][10][7][1] = '2';
	hint[0][10][8][0] = '5';
	hint[0][10][8][1] = '3';
	hint[0][10][12][0] = '5';
	hint[0][10][12][1] = '4';
	hint[0][11][0][0] = '5';
	hint[0][11][0][1] = '5';
	hint[0][11][5][0] = '5';
	hint[0][11][5][1] = '6';
	hint[0][11][11][0] = '5';
	hint[0][11][11][1] = '7';
	hint[0][12][0][0] = '5';
	hint[0][12][0][1] = '8';
	hint[0][12][5][0] = '5';
	hint[0][12][5][1] = '9';
	hint[0][12][10][0] = '6';
	hint[0][12][10][1] = '0';
	hint[0][12][12][0] = '6';
	hint[0][12][12][1] = '1';
	hint[0][12][13][0] = '6';
	hint[0][12][13][1] = '2';
	hint[0][12][14][0] = '6';
	hint[0][12][14][1] = '3';
	hint[0][13][0][0] = '6';
	hint[0][13][0][1] = '4';
	hint[0][13][5][0] = '6';
	hint[0][13][5][1] = '5';
	hint[0][13][10][0] = '6';
	hint[0][13][10][1] = '6';
	hint[0][14][0][0] = '6';
	hint[0][14][0][1] = '7';
	hint[0][14][5][0] = '6';
	hint[0][14][5][1] = '8';
	hint[0][14][10][0] = '6';
	hint[0][14][10][1] = '9';

	//hint 2

	hint[1][0][0][0] = '1';
	hint[1][0][0][1] = '*';
	hint[1][0][1][0] = '2';
	hint[1][0][1][1] = '*';
	hint[1][0][2][0] = '3';
	hint[1][0][2][1] = '*';
	hint[1][0][3][0] = '4';
	hint[1][0][3][1] = '*';
	hint[1][0][4][0] = '5';
	hint[1][0][4][1] = '*';
	hint[1][0][6][0] = '6';
	hint[1][0][6][1] = '*';
	hint[1][0][7][0] = '7';
	hint[1][0][7][1] = '*';
	hint[1][0][8][0] = '8';
	hint[1][0][8][1] = '*';
	hint[1][0][9][0] = '9';
	hint[1][0][9][1] = '*';
	hint[1][0][11][0] = '1';
	hint[1][0][11][1] = '0';
	hint[1][0][12][0] = '1';
	hint[1][0][12][1] = '1';
	hint[1][0][13][0] = '1';
	hint[1][0][13][1] = '2';
	hint[1][0][14][0] = '1';
	hint[1][0][14][1] = '3';
	hint[1][1][0][0] = '1';
	hint[1][1][0][1] = '4';
	hint[1][1][6][0] = '1';
	hint[1][1][6][1] = '5';
	hint[1][1][11][0] = '1';
	hint[1][1][11][1] = '6';
	hint[1][2][0][0] = '1';
	hint[1][2][0][1] = '7';
	hint[1][2][6][0] = '1';
	hint[1][2][6][1] = '8';
	hint[1][2][11][0] = '1';
	hint[1][2][11][1] = '9';
	hint[1][3][0][0] = '2';
	hint[1][3][0][1] = '0';
	hint[1][3][5][0] = '2';
	hint[1][3][5][1] = '1';
	hint[1][3][10][0] = '2';
	hint[1][3][10][1] = '2';
	hint[1][4][3][0] = '2';
	hint[1][4][3][1] = '3';
	hint[1][4][8][0] = '2';
	hint[1][4][8][1] = '4';
	hint[1][5][0][0] = '2';
	hint[1][5][0][1] = '5';
	hint[1][5][1][0] = '2';
	hint[1][5][1][1] = '6';
	hint[1][5][2][0] = '2';
	hint[1][5][2][1] = '7';
	hint[1][5][5][0] = '2';
	hint[1][5][5][1] = '8';
	hint[1][5][6][0] = '2';
	hint[1][5][6][1] = '9';
	hint[1][5][7][0] = '3';
	hint[1][5][7][1] = '0';
	hint[1][5][9][0] = '3';
	hint[1][5][9][1] = '1';
	hint[1][5][11][0] = '3';
	hint[1][5][11][1] = '2';
	hint[1][5][12][0] = '3';
	hint[1][5][12][1] = '3';
	hint[1][5][13][0] = '3';
	hint[1][5][13][1] = '4';
	hint[1][5][14][0] = '3';
	hint[1][5][14][1] = '5';
	hint[1][6][0][0] = '3';
	hint[1][6][0][1] = '6';
	hint[1][6][4][0] = '3';
	hint[1][6][4][1] = '7';
	hint[1][6][8][0] = '3';
	hint[1][6][8][1] = '8';
	hint[1][6][10][0] = '3';
	hint[1][6][10][1] = '9';
	hint[1][7][0][0] = '4';
	hint[1][7][0][1] = '0';
	hint[1][7][3][0] = '4';
	hint[1][7][3][1] = '1';
	hint[1][7][9][0] = '4';
	hint[1][7][9][1] = '2';
	hint[1][8][0][0] = '4';
	hint[1][8][0][1] = '3';
	hint[1][8][6][0] = '4';
	hint[1][8][6][1] = '4';
	hint[1][8][12][0] = '4';
	hint[1][8][12][1] = '5';
	hint[1][9][0][0] = '4';
	hint[1][9][0][1] = '6';
	hint[1][9][5][0] = '4';
	hint[1][9][5][1] = '7';
	hint[1][9][7][0] = '4';
	hint[1][9][7][1] = '8';
	hint[1][9][11][0] = '4';
	hint[1][9][11][1] = '9';
	hint[1][10][4][0] = '5';
	hint[1][10][4][1] = '0';
	hint[1][10][6][0] = '5';
	hint[1][10][6][1] = '1';
	hint[1][10][9][0] = '5';
	hint[1][10][9][1] = '2';
	hint[1][10][10][0] = '5';
	hint[1][10][10][1] = '3';
	hint[1][11][2][0] = '5';
	hint[1][11][2][1] = '4';
	hint[1][11][3][0] = '5';
	hint[1][11][3][1] = '5';
	hint[1][11][7][0] = '5';
	hint[1][11][7][1] = '6';
	hint[1][11][8][0] = '5';
	hint[1][11][8][1] = '7';
	hint[1][11][12][0] = '5';
	hint[1][11][12][1] = '8';
	hint[1][11][13][0] = '5';
	hint[1][11][13][1] = '9';
	hint[1][11][14][0] = '6';
	hint[1][11][14][1] = '0';
	hint[1][12][0][0] = '6';
	hint[1][12][0][1] = '1';
	hint[1][12][1][0] = '6';
	hint[1][12][1][1] = '2';
	hint[1][12][5][0] = '6';
	hint[1][12][5][1] = '3';
	hint[1][12][10][0] = '6';
	hint[1][12][10][1] = '4';
	hint[1][13][0][0] = '6';
	hint[1][13][0][1] = '5';
	hint[1][13][5][0] = '6';
	hint[1][13][5][1] = '6';
	hint[1][13][10][0] = '6';
	hint[1][13][10][1] = '7';
	hint[1][14][0][0] = '6';
	hint[1][14][0][1] = '8';
	hint[1][14][5][0] = '6';
	hint[1][14][5][1] = '9';
	hint[1][14][10][0] = '7';
	hint[1][14][10][1] = '0';

	//hint 3

	hint[2][0][1][0] = '1';
	hint[2][0][1][1] = '*';
	hint[2][0][2][0] = '2';
	hint[2][0][2][1] = '*';
	hint[2][0][3][0] = '3';
	hint[2][0][3][1] = '*';
	hint[2][0][5][0] = '4';
	hint[2][0][5][1] = '*';
	hint[2][0][6][0] = '5';
	hint[2][0][6][1] = '*';
	hint[2][0][7][0] = '6';
	hint[2][0][7][1] = '*';
	hint[2][0][8][0] = '7';
	hint[2][0][8][1] = '*';
	hint[2][0][9][0] = '8';
	hint[2][0][9][1] = '*';
	hint[2][0][11][0] = '9';
	hint[2][0][11][1] = '*';
	hint[2][0][12][0] = '1';
	hint[2][0][12][1] = '0';
	hint[2][0][13][0] = '1';
	hint[2][0][13][1] = '1';
	hint[2][0][14][0] = '1';
	hint[2][0][14][1] = '2';
	hint[2][1][0][0] = '1';
	hint[2][1][0][1] = '3';
	hint[2][1][5][0] = '1';
	hint[2][1][5][1] = '4';
	hint[2][1][11][0] = '1';
	hint[2][1][11][1] = '5';
	hint[2][2][0][0] = '1';
	hint[2][2][0][1] = '6';
	hint[2][2][5][0] = '1';
	hint[2][2][5][1] = '7';
	hint[2][2][11][0] = '1';
	hint[2][2][11][1] = '8';
	hint[2][3][0][0] = '1';
	hint[2][3][0][1] = '9';
	hint[2][3][4][0] = '2';
	hint[2][3][4][1] = '0';
	hint[2][3][10][0] = '2';
	hint[2][3][10][1] = '1';
	hint[2][4][3][0] = '2';
	hint[2][4][3][1] = '2';
	hint[2][4][9][0] = '2';
	hint[2][4][9][1] = '3';
	hint[2][5][0][0] = '2';
	hint[2][5][0][1] = '4';
	hint[2][5][1][0] = '2';
	hint[2][5][1][1] = '5';
	hint[2][5][2][0] = '2';
	hint[2][5][2][1] = '6';
	hint[2][5][8][0] = '2';
	hint[2][5][8][1] = '7';
	hint[2][5][13][0] = '2';
	hint[2][5][13][1] = '8';
	hint[2][5][14][0] = '2';
	hint[2][5][14][1] = '9';
	hint[2][6][0][0] = '3';
	hint[2][6][0][1] = '0';
	hint[2][6][6][0] = '3';
	hint[2][6][6][1] = '1';
	hint[2][6][7][0] = '3';
	hint[2][6][7][1] = '2';
	hint[2][6][12][0] = '3';
	hint[2][6][12][1] = '3';
	hint[2][7][0][0] = '3';
	hint[2][7][0][1] = '4';
	hint[2][7][5][0] = '3';
	hint[2][7][5][1] = '5';
	hint[2][7][12][0] = '3';
	hint[2][7][12][1] = '6';
	hint[2][8][0][0] = '3';
	hint[2][8][0][1] = '7';
	hint[2][8][4][0] = '3';
	hint[2][8][4][1] = '8';
	hint[2][8][10][0] = '3';
	hint[2][8][10][1] = '9';
	hint[2][8][11][0] = '4';
	hint[2][8][11][1] = '0';
	hint[2][9][0][0] = '4';
	hint[2][9][0][1] = '1';
	hint[2][9][3][0] = '4';
	hint[2][9][3][1] = '2';
	hint[2][9][9][0] = '4';
	hint[2][9][9][1] = '3';
	hint[2][10][2][0] = '4';
	hint[2][10][2][1] = '4';
	hint[2][10][7][0] = '4';
	hint[2][10][7][1] = '5';
	hint[2][10][8][0] = '4';
	hint[2][10][8][1] = '6';
	hint[2][11][0][0] = '4';
	hint[2][11][0][1] = '7';
	hint[2][11][1][0] = '4';
	hint[2][11][1][1] = '8';
	hint[2][11][6][0] = '4';
	hint[2][11][6][1] = '9';
	hint[2][11][12][0] = '5';
	hint[2][11][12][1] = '0';
	hint[2][11][13][0] = '5';
	hint[2][11][13][1] = '1';
	hint[2][11][14][0] = '5';
	hint[2][11][14][1] = '2';
	hint[2][12][0][0] = '5';
	hint[2][12][0][1] = '3';
	hint[2][12][5][0] = '5';
	hint[2][12][5][1] = '4';
	hint[2][12][11][0] = '5';
	hint[2][12][11][1] = '5';
	hint[2][13][0][0] = '5';
	hint[2][13][0][1] = '6';
	hint[2][13][5][0] = '5';
	hint[2][13][5][1] = '7';
	hint[2][13][11][0] = '5';
	hint[2][13][11][1] = '8';
	hint[2][14][0][0] = '5';
	hint[2][14][0][1] = '9';
	hint[2][14][5][0] = '6';
	hint[2][14][5][1] = '0';
	hint[2][14][11][0] = '6';
	hint[2][14][11][1] = '1';

	//hint 4

	hint[3][0][1][0] = '1';
	hint[3][0][1][1] = '*';
	hint[3][0][2][0] = '2';
	hint[3][0][2][1] = '*';
	hint[3][0][3][0] = '3';
	hint[3][0][3][1] = '*';
	hint[3][0][4][0] = '4';
	hint[3][0][4][1] = '*';
	hint[3][0][6][0] = '5';
	hint[3][0][6][1] = '*';
	hint[3][0][7][0] = '6';
	hint[3][0][7][1] = '*';
	hint[3][0][8][0] = '7';
	hint[3][0][8][1] = '*';
	hint[3][0][9][0] = '8';
	hint[3][0][9][1] = '*';
	hint[3][0][11][0] = '9';
	hint[3][0][11][1] = '*';
	hint[3][0][12][0] = '1';
	hint[3][0][12][1] = '0';
	hint[3][0][13][0] = '1';
	hint[3][0][13][1] = '1';
	hint[3][0][14][0] = '1';
	hint[3][0][14][1] = '2';
	hint[3][1][0][0] = '1';
	hint[3][1][0][1] = '3';
	hint[3][1][6][0] = '1';
	hint[3][1][6][1] = '4';
	hint[3][1][11][0] = '1';
	hint[3][1][11][1] = '5';
	hint[3][2][0][0] = '1';
	hint[3][2][0][1] = '6';
	hint[3][2][6][0] = '1';
	hint[3][2][6][1] = '7';
	hint[3][2][11][0] = '1';
	hint[3][2][11][1] = '8';
	hint[3][3][0][0] = '1';
	hint[3][3][0][1] = '9';
	hint[3][3][5][0] = '2';
	hint[3][3][5][1] = '0';
	hint[3][3][10][0] = '2';
	hint[3][3][10][1] = '1';
	hint[3][4][4][0] = '2';
	hint[3][4][4][1] = '2';
	hint[3][4][9][0] = '2';
	hint[3][4][9][1] = '3';
	hint[3][5][0][0] = '2';
	hint[3][5][0][1] = '4';
	hint[3][5][1][0] = '2';
	hint[3][5][1][1] = '5';
	hint[3][5][2][0] = '2';
	hint[3][5][2][1] = '6';
	hint[3][5][3][0] = '2';
	hint[3][5][3][1] = '7';
	hint[3][5][7][0] = '2';
	hint[3][5][7][1] = '8';
	hint[3][5][8][0] = '2';
	hint[3][5][8][1] = '9';
	hint[3][5][12][0] = '3';
	hint[3][5][12][1] = '0';
	hint[3][5][13][0] = '3';
	hint[3][5][13][1] = '1';
	hint[3][5][14][0] = '3';
	hint[3][5][14][1] = '2';
	hint[3][6][0][0] = '3';
	hint[3][6][0][1] = '3';
	hint[3][6][6][0] = '3';
	hint[3][6][6][1] = '4';
	hint[3][6][11][0] = '3';
	hint[3][6][11][1] = '5';
	hint[3][7][0][0] = '3';
	hint[3][7][0][1] = '6';
	hint[3][7][5][0] = '3';
	hint[3][7][5][1] = '7';
	hint[3][7][10][0] = '3';
	hint[3][7][10][1] = '8';
	hint[3][8][0][0] = '3';
	hint[3][8][0][1] = '9';
	hint[3][8][5][0] = '4';
	hint[3][8][5][1] = '0';
	hint[3][8][10][0] = '4';
	hint[3][8][10][1] = '1';
	hint[3][9][0][0] = '4';
	hint[3][9][0][1] = '2';
	hint[3][9][4][0] = '4';
	hint[3][9][4][1] = '3';
	hint[3][9][9][0] = '4';
	hint[3][9][9][1] = '4';
	hint[3][10][3][0] = '4';
	hint[3][10][3][1] = '5';
	hint[3][10][8][0] = '4';
	hint[3][10][8][1] = '6';
	hint[3][11][0][0] = '4';
	hint[3][11][0][1] = '7';
	hint[3][11][1][0] = '4';
	hint[3][11][1][1] = '8';
	hint[3][11][2][0] = '4';
	hint[3][11][2][1] = '9';
	hint[3][11][6][0] = '5';
	hint[3][11][6][1] = '0';
	hint[3][11][7][0] = '5';
	hint[3][11][7][1] = '1';
	hint[3][11][11][0] = '5';
	hint[3][11][11][1] = '2';
	hint[3][11][12][0] = '5';
	hint[3][11][12][1] = '3';
	hint[3][11][13][0] = '5';
	hint[3][11][13][1] = '4';
	hint[3][11][14][0] = '5';
	hint[3][11][14][1] = '5';
	hint[3][12][0][0] = '5';
	hint[3][12][0][1] = '6';
	hint[3][12][5][0] = '5';
	hint[3][12][5][1] = '7';
	hint[3][12][10][0] = '5';
	hint[3][12][10][1] = '8';
	hint[3][13][0][0] = '5';
	hint[3][13][0][1] = '9';
	hint[3][13][5][0] = '6';
	hint[3][13][5][1] = '0';
	hint[3][13][10][0] = '6';
	hint[3][13][10][1] = '1';
	hint[3][14][0][0] = '6';
	hint[3][14][0][1] = '2';
	hint[3][14][5][0] = '6';
	hint[3][14][5][1] = '3';
	hint[3][14][10][0] = '6';
	hint[3][14][10][1] = '4';

	//hint 5

	hint[4][0][0][0] = '1';
	hint[4][0][0][1] = '*';
	hint[4][0][1][0] = '2';
	hint[4][0][1][1] = '*';
	hint[4][0][2][0] = '3';
	hint[4][0][2][1] = '*';
	hint[4][0][3][0] = '4';
	hint[4][0][3][1] = '*';
	hint[4][0][5][0] = '5';
	hint[4][0][5][1] = '*';
	hint[4][0][6][0] = '6';
	hint[4][0][6][1] = '*';
	hint[4][0][7][0] = '7';
	hint[4][0][7][1] = '*';
	hint[4][0][8][0] = '8';
	hint[4][0][8][1] = '*';
	hint[4][0][9][0] = '9';
	hint[4][0][9][1] = '*';
	hint[4][0][11][0] = '1';
	hint[4][0][11][1] = '0';
	hint[4][0][12][0] = '1';
	hint[4][0][12][1] = '1';
	hint[4][0][13][0] = '1';
	hint[4][0][13][1] = '2';
	hint[4][0][14][0] = '1';
	hint[4][0][14][1] = '3';
	hint[4][1][0][0] = '1';
	hint[4][1][0][1] = '4';
	hint[4][1][5][0] = '1';
	hint[4][1][5][1] = '5';
	hint[4][1][11][0] = '1';
	hint[4][1][11][1] = '6';
	hint[4][2][0][0] = '1';
	hint[4][2][0][1] = '7';
	hint[4][2][5][0] = '1';
	hint[4][2][5][1] = '8';
	hint[4][2][11][0] = '1';
	hint[4][2][11][1] = '9';
	hint[4][3][0][0] = '2';
	hint[4][3][0][1] = '0';
	hint[4][3][4][0] = '2';
	hint[4][3][4][1] = '1';
	hint[4][3][10][0] = '2';
	hint[4][3][10][1] = '2';
	hint[4][4][3][0] = '2';
	hint[4][4][3][1] = '3';
	hint[4][4][9][0] = '2';
	hint[4][4][9][1] = '4';
	hint[4][5][0][0] = '2';
	hint[4][5][0][1] = '5';
	hint[4][5][1][0] = '2';
	hint[4][5][1][1] = '6';
	hint[4][5][2][0] = '2';
	hint[4][5][2][1] = '7';
	hint[4][5][8][0] = '2';
	hint[4][5][8][1] = '8';
	hint[4][6][0][0] = '2';
	hint[4][6][0][1] = '9';
	hint[4][6][6][0] = '3';
	hint[4][6][6][1] = '0';
	hint[4][6][7][0] = '3';
	hint[4][6][7][1] = '1';
	hint[4][6][12][0] = '3';
	hint[4][6][12][1] = '2';
	hint[4][6][13][0] = '3';
	hint[4][6][13][1] = '3';
	hint[4][6][14][0] = '3';
	hint[4][6][14][1] = '4';
	hint[4][7][0][0] = '3';
	hint[4][7][0][1] = '5';
	hint[4][7][5][0] = '3';
	hint[4][7][5][1] = '6';
	hint[4][7][12][0] = '3';
	hint[4][7][12][1] = '7';
	hint[4][8][0][0] = '3';
	hint[4][8][0][1] = '8';
	hint[4][8][4][0] = '3';
	hint[4][8][4][1] = '9';
	hint[4][8][10][0] = '4';
	hint[4][8][10][1] = '0';
	hint[4][8][11][0] = '4';
	hint[4][8][11][1] = '1';
	hint[4][9][2][0] = '4';
	hint[4][9][2][1] = '2';
	hint[4][9][3][0] = '4';
	hint[4][9][3][1] = '3';
	hint[4][9][9][0] = '4';
	hint[4][9][9][1] = '4';
	hint[4][10][0][0] = '4';
	hint[4][10][0][1] = '5';
	hint[4][10][1][0] = '4';
	hint[4][10][1][1] = '6';
	hint[4][10][7][0] = '4';
	hint[4][10][7][1] = '7';
	hint[4][10][8][0] = '4';
	hint[4][10][8][1] = '8';
	hint[4][11][0][0] = '4';
	hint[4][11][0][1] = '9';
	hint[4][11][6][0] = '5';
	hint[4][11][6][1] = '0';
	hint[4][11][12][0] = '5';
	hint[4][11][12][1] = '1';
	hint[4][11][13][0] = '5';
	hint[4][11][13][1] = '2';
	hint[4][11][14][0] = '5';
	hint[4][11][14][1] = '3';
	hint[4][12][0][0] = '5';
	hint[4][12][0][1] = '4';
	hint[4][12][5][0] = '5';
	hint[4][12][5][1] = '5';
	hint[4][12][11][0] = '5';
	hint[4][12][11][1] = '6';
	hint[4][13][0][0] = '5';
	hint[4][13][0][1] = '7';
	hint[4][13][5][0] = '5';
	hint[4][13][5][1] = '8';
	hint[4][13][11][0] = '5';
	hint[4][13][11][1] = '9';
	hint[4][14][0][0] = '6';
	hint[4][14][0][1] = '0';
	hint[4][14][5][0] = '6';
	hint[4][14][5][1] = '1';
	hint[4][14][11][0] = '6';
	hint[4][14][11][1] = '2';

	//hint 6

	hint[5][0][0][0] = '1';
	hint[5][0][0][1] = '*';
	hint[5][0][1][0] = '2';
	hint[5][0][1][1] = '*';
	hint[5][0][2][0] = '3';
	hint[5][0][2][1] = '*';
	hint[5][0][3][0] = '4';
	hint[5][0][3][1] = '*';
	hint[5][0][5][0] = '5';
	hint[5][0][5][1] = '*';
	hint[5][0][6][0] = '6';
	hint[5][0][6][1] = '*';
	hint[5][0][7][0] = '7';
	hint[5][0][7][1] = '*';
	hint[5][0][8][0] = '8';
	hint[5][0][8][1] = '*';
	hint[5][0][10][0] = '9';
	hint[5][0][10][1] = '*';
	hint[5][0][11][0] = '1';
	hint[5][0][11][1] = '0';
	hint[5][0][12][0] = '1';
	hint[5][0][12][1] = '1';
	hint[5][0][13][0] = '1';
	hint[5][0][13][1] = '2';
	hint[5][0][14][0] = '1';
	hint[5][0][14][1] = '3';
	hint[5][1][0][0] = '1';
	hint[5][1][0][1] = '4';
	hint[5][1][5][0] = '1';
	hint[5][1][5][1] = '5';
	hint[5][1][10][0] = '1';
	hint[5][1][10][1] = '6';
	hint[5][2][0][0] = '1';
	hint[5][2][0][1] = '7';
	hint[5][2][5][0] = '1';
	hint[5][2][5][1] = '8';
	hint[5][2][10][0] = '1';
	hint[5][2][10][1] = '9';
	hint[5][3][1][0] = '2';
	hint[5][3][1][1] = '0';
	hint[5][3][4][0] = '2';
	hint[5][3][4][1] = '1';
	hint[5][3][9][0] = '2';
	hint[5][3][9][1] = '2';
	hint[5][4][3][0] = '2';
	hint[5][4][3][1] = '3';
	hint[5][4][9][0] = '2';
	hint[5][4][9][1] = '4';
	hint[5][5][0][0] = '2';
	hint[5][5][0][1] = '5';
	hint[5][5][1][0] = '2';
	hint[5][5][1][1] = '6';
	hint[5][5][2][0] = '2';
	hint[5][5][2][1] = '7';
	hint[5][5][7][0] = '2';
	hint[5][5][7][1] = '8';
	hint[5][5][8][0] = '2';
	hint[5][5][8][1] = '9';
	hint[5][5][12][0] = '3';
	hint[5][5][12][1] = '0';
	hint[5][5][13][0] = '3';
	hint[5][5][13][1] = '1';
	hint[5][5][14][0] = '3';
	hint[5][5][14][1] = '2';
	hint[5][6][0][0] = '3';
	hint[5][6][0][1] = '3';
	hint[5][6][6][0] = '3';
	hint[5][6][6][1] = '4';
	hint[5][6][11][0] = '3';
	hint[5][6][11][1] = '5';
	hint[5][7][0][0] = '3';
	hint[5][7][0][1] = '6';
	hint[5][7][5][0] = '3';
	hint[5][7][5][1] = '7';
	hint[5][7][10][0] = '3';
	hint[5][7][10][1] = '8';
	hint[5][8][0][0] = '3';
	hint[5][8][0][1] = '9';
	hint[5][8][5][0] = '4';
	hint[5][8][5][1] = '0';
	hint[5][8][10][0] = '4';
	hint[5][8][10][1] = '1';
	hint[5][9][0][0] = '4';
	hint[5][9][0][1] = '2';
	hint[5][9][4][0] = '4';
	hint[5][9][4][1] = '3';
	hint[5][9][9][0] = '4';
	hint[5][9][9][1] = '4';
	hint[5][10][3][0] = '4';
	hint[5][10][3][1] = '5';
	hint[5][10][8][0] = '4';
	hint[5][10][8][1] = '6';
	hint[5][11][0][0] = '4';
	hint[5][11][0][1] = '7';
	hint[5][11][1][0] = '4';
	hint[5][11][1][1] = '8';
	hint[5][11][2][0] = '4';
	hint[5][11][2][1] = '9';
	hint[5][11][6][0] = '5';
	hint[5][11][6][1] = '0';
	hint[5][11][7][0] = '5';
	hint[5][11][7][1] = '1';
	hint[5][11][12][0] = '5';
	hint[5][11][12][1] = '2';
	hint[5][11][13][0] = '5';
	hint[5][11][13][1] = '3';
	hint[5][12][0][0] = '5';
	hint[5][12][0][1] = '4';
	hint[5][12][6][0] = '5';
	hint[5][12][6][1] = '5';
	hint[5][12][11][0] = '5';
	hint[5][12][11][1] = '6';
	hint[5][12][14][0] = '5';
	hint[5][12][14][1] = '7';
	hint[5][13][0][0] = '5';
	hint[5][13][0][1] = '8';
	hint[5][13][6][0] = '5';
	hint[5][13][6][1] = '9';
	hint[5][13][11][0] = '6';
	hint[5][13][11][1] = '0';
	hint[5][14][0][0] = '6';
	hint[5][14][0][1] = '1';
	hint[5][14][6][0] = '6';
	hint[5][14][6][1] = '2';
	hint[5][14][11][0] = '6';
	hint[5][14][11][1] = '3';

	//hint 7

	hint[6][0][0][0] = '1';
	hint[6][0][0][1] = '*';
	hint[6][0][1][0] = '2';
	hint[6][0][1][1] = '*';
	hint[6][0][2][0] = '3';
	hint[6][0][2][1] = '*';
	hint[6][0][3][0] = '4';
	hint[6][0][3][1] = '*';
	hint[6][0][6][0] = '5';
	hint[6][0][6][1] = '*';
	hint[6][0][7][0] = '6';
	hint[6][0][7][1] = '*';
	hint[6][0][8][0] = '7';
	hint[6][0][8][1] = '*';
	hint[6][0][9][0] = '8';
	hint[6][0][9][1] = '*';
	hint[6][0][10][0] = '9';
	hint[6][0][10][1] = '*';
	hint[6][0][12][0] = '1';
	hint[6][0][12][1] = '0';
	hint[6][0][13][0] = '1';
	hint[6][0][13][1] = '1';
	hint[6][0][14][0] = '1';
	hint[6][0][14][1] = '2';
	hint[6][1][0][0] = '1';
	hint[6][1][0][1] = '3';
	hint[6][1][4][0] = '1';
	hint[6][1][4][1] = '4';
	hint[6][1][6][0] = '1';
	hint[6][1][6][1] = '5';
	hint[6][1][12][0] = '1';
	hint[6][1][12][1] = '6';
	hint[6][2][0][0] = '1';
	hint[6][2][0][1] = '7';
	hint[6][2][6][0] = '1';
	hint[6][2][6][1] = '8';
	hint[6][2][12][0] = '1';
	hint[6][2][12][1] = '9';
	hint[6][3][0][0] = '2';
	hint[6][3][0][1] = '0';
	hint[6][3][5][0] = '2';
	hint[6][3][5][1] = '1';
	hint[6][3][12][0] = '2';
	hint[6][3][12][1] = '2';
	hint[6][4][4][0] = '2';
	hint[6][4][4][1] = '3';
	hint[6][4][10][0] = '2';
	hint[6][4][10][1] = '4';
	hint[6][4][11][0] = '2';
	hint[6][4][11][1] = '5';
	hint[6][5][0][0] = '2';
	hint[6][5][0][1] = '6';
	hint[6][5][1][0] = '2';
	hint[6][5][1][1] = '7';
	hint[6][5][2][0] = '2';
	hint[6][5][2][1] = '8';
	hint[6][5][3][0] = '2';
	hint[6][5][3][1] = '9';
	hint[6][5][7][0] = '3';
	hint[6][5][7][1] = '0';
	hint[6][5][8][0] = '3';
	hint[6][5][8][1] = '1';
	hint[6][5][9][0] = '3';
	hint[6][5][9][1] = '2';
	hint[6][6][0][0] = '3';
	hint[6][6][0][1] = '3';
	hint[6][6][6][0] = '3';
	hint[6][6][6][1] = '4';
	hint[6][6][11][0] = '3';
	hint[6][6][11][1] = '5';
	hint[6][6][12][0] = '3';
	hint[6][6][12][1] = '6';
	hint[6][6][13][0] = '3';
	hint[6][6][13][1] = '7';
	hint[6][6][14][0] = '3';
	hint[6][6][14][1] = '8';
	hint[6][7][0][0] = '3';
	hint[6][7][0][1] = '9';
	hint[6][7][5][0] = '4';
	hint[6][7][5][1] = '0';
	hint[6][7][10][0] = '4';
	hint[6][7][10][1] = '1';
	hint[6][8][0][0] = '4';
	hint[6][8][0][1] = '2';
	hint[6][8][5][0] = '4';
	hint[6][8][5][1] = '3';
	hint[6][8][10][0] = '4';
	hint[6][8][10][1] = '4';
	hint[6][9][3][0] = '4';
	hint[6][9][3][1] = '5';
	hint[6][9][4][0] = '4';
	hint[6][9][4][1] = '6';
	hint[6][9][9][0] = '4';
	hint[6][9][9][1] = '7';
	hint[6][10][0][0] = '4';
	hint[6][10][0][1] = '8';
	hint[6][10][1][0] = '4';
	hint[6][10][1][1] = '9';
	hint[6][10][2][0] = '5';
	hint[6][10][2][1] = '0';
	hint[6][10][8][0] = '5';
	hint[6][10][8][1] = '1';
	hint[6][11][0][0] = '5';
	hint[6][11][0][1] = '2';
	hint[6][11][4][0] = '5';
	hint[6][11][4][1] = '3';
	hint[6][11][5][0] = '5';
	hint[6][11][5][1] = '4';
	hint[6][11][6][0] = '5';
	hint[6][11][6][1] = '5';
	hint[6][11][7][0] = '5';
	hint[6][11][7][1] = '6';
	hint[6][11][11][0] = '5';
	hint[6][11][11][1] = '7';
	hint[6][11][12][0] = '5';
	hint[6][11][12][1] = '8';
	hint[6][11][13][0] = '5';
	hint[6][11][13][1] = '9';
	hint[6][11][14][0] = '6';
	hint[6][11][14][1] = '0';
	hint[6][12][0][0] = '6';
	hint[6][12][0][1] = '1';
	hint[6][12][4][0] = '6';
	hint[6][12][4][1] = '2';
	hint[6][12][10][0] = '6';
	hint[6][12][10][1] = '3';
	hint[6][13][0][0] = '6';
	hint[6][13][0][1] = '4';
	hint[6][13][4][0] = '6';
	hint[6][13][4][1] = '5';
	hint[6][13][10][0] = '6';
	hint[6][13][10][1] = '6';
	hint[6][14][0][0] = '6';
	hint[6][14][0][1] = '7';
	hint[6][14][4][0] = '6';
	hint[6][14][4][1] = '8';
	hint[6][14][11][0] = '6';
	hint[6][14][11][1] = '9';

	//hint 8

	hint[7][0][0][0] = '1';
	hint[7][0][0][1] = '*';
	hint[7][0][1][0] = '2';
	hint[7][0][1][1] = '*';
	hint[7][0][2][0] = '3';
	hint[7][0][2][1] = '*';
	hint[7][0][3][0] = '4';
	hint[7][0][3][1] = '*';
	hint[7][0][5][0] = '5';
	hint[7][0][5][1] = '*';
	hint[7][0][6][0] = '6';
	hint[7][0][6][1] = '*';
	hint[7][0][7][0] = '7';
	hint[7][0][7][1] = '*';
	hint[7][0][8][0] = '8';
	hint[7][0][8][1] = '*';
	hint[7][0][9][0] = '9';
	hint[7][0][9][1] = '*';
	hint[7][0][11][0] = '1';
	hint[7][0][11][1] = '0';
	hint[7][0][12][0] = '1';
	hint[7][0][12][1] = '1';
	hint[7][0][13][0] = '1';
	hint[7][0][13][1] = '2';
	hint[7][0][14][0] = '1';
	hint[7][0][14][1] = '3';
	hint[7][1][0][0] = '1';
	hint[7][1][0][1] = '4';
	hint[7][1][5][0] = '1';
	hint[7][1][5][1] = '5';
	hint[7][1][11][0] = '1';
	hint[7][1][11][1] = '6';
	hint[7][2][0][0] = '1';
	hint[7][2][0][1] = '7';
	hint[7][2][5][0] = '1';
	hint[7][2][5][1] = '8';
	hint[7][2][11][0] = '1';
	hint[7][2][11][1] = '9';
	hint[7][3][0][0] = '2';
	hint[7][3][0][1] = '0';
	hint[7][3][4][0] = '2';
	hint[7][3][4][1] = '1';
	hint[7][3][10][0] = '2';
	hint[7][3][10][1] = '2';
	hint[7][4][3][0] = '2';
	hint[7][4][3][1] = '3';
	hint[7][4][9][0] = '2';
	hint[7][4][9][1] = '4';
	hint[7][5][0][0] = '2';
	hint[7][5][0][1] = '5';
	hint[7][5][1][0] = '2';
	hint[7][5][1][1] = '6';
	hint[7][5][2][0] = '2';
	hint[7][5][2][1] = '7';
	hint[7][5][8][0] = '2';
	hint[7][5][8][1] = '8';
	hint[7][5][13][0] = '2';
	hint[7][5][13][1] = '9';
	hint[7][5][14][0] = '3';
	hint[7][5][14][1] = '0';
	hint[7][6][0][0] = '3';
	hint[7][6][0][1] = '1';
	hint[7][6][6][0] = '3';
	hint[7][6][6][1] = '2';
	hint[7][6][7][0] = '3';
	hint[7][6][7][1] = '3';
	hint[7][6][12][0] = '3';
	hint[7][6][12][1] = '4';
	hint[7][7][0][0] = '3';
	hint[7][7][0][1] = '5';
	hint[7][7][5][0] = '3';
	hint[7][7][5][1] = '6';
	hint[7][7][11][0] = '3';
	hint[7][7][11][1] = '7';
	hint[7][8][0][0] = '3';
	hint[7][8][0][1] = '8';
	hint[7][8][4][0] = '3';
	hint[7][8][4][1] = '9';
	hint[7][8][10][0] = '4';
	hint[7][8][10][1] = '0';
	hint[7][9][0][0] = '4';
	hint[7][9][0][1] = '1';
	hint[7][9][3][0] = '4';
	hint[7][9][3][1] = '2';
	hint[7][9][9][0] = '4';
	hint[7][9][9][1] = '3';
	hint[7][10][2][0] = '4';
	hint[7][10][2][1] = '4';
	hint[7][10][7][0] = '4';
	hint[7][10][7][1] = '5';
	hint[7][10][8][0] = '4';
	hint[7][10][8][1] = '6';
	hint[7][11][0][0] = '4';
	hint[7][11][0][1] = '7';
	hint[7][11][1][0] = '4';
	hint[7][11][1][1] = '8';
	hint[7][11][6][0] = '4';
	hint[7][11][6][1] = '9';
	hint[7][11][12][0] = '5';
	hint[7][11][12][1] = '0';
	hint[7][11][13][0] = '5';
	hint[7][11][13][1] = '1';
	hint[7][11][14][0] = '5';
	hint[7][11][14][1] = '2';
	hint[7][12][0][0] = '5';
	hint[7][12][0][1] = '3';
	hint[7][12][5][0] = '5';
	hint[7][12][5][1] = '4';
	hint[7][12][11][0] = '5';
	hint[7][12][11][1] = '5';
	hint[7][13][0][0] = '5';
	hint[7][13][0][1] = '6';
	hint[7][13][5][0] = '5';
	hint[7][13][5][1] = '7';
	hint[7][13][11][0] = '5';
	hint[7][13][11][1] = '8';
	hint[7][14][0][0] = '5';
	hint[7][14][0][1] = '9';
	hint[7][14][5][0] = '6';
	hint[7][14][5][1] = '0';
	hint[7][14][11][0] = '6';
	hint[7][14][11][1] = '1';

	//hint1 1

	hint1[0][0][0] = '1';
	hint1[0][0][1] = '2';
	hint1[0][0][2] = '3';
	hint1[0][1][0] = '4';
	hint1[0][2][0] = '5';
	hint1[0][2][3] = '6';
	hint1[0][2][4] = '7';
	hint1[0][3][2] = '8';
	hint1[0][4][2] = '9';

	//hint1 2

	hint1[1][0][0] = '1';
	hint1[1][0][1] = '2';
	hint1[1][0][2] = '3';
	hint1[1][0][3] = '4';
	hint1[1][1][0] = '5';
	hint1[1][2][0] = '6';
	hint1[1][2][4] = '7';
	hint1[1][3][1] = '8';
	hint1[1][4][1] = '9';

	//hint2 1

	hint2[0][0][0][0] = '0';
	hint2[0][0][0][1] = '1';
	hint2[0][0][1][0] = '0';
	hint2[0][0][1][1] = '2';
	hint2[0][0][2][0] = '0';
	hint2[0][0][2][1] = '3';
	hint2[0][0][3][0] = '0';
	hint2[0][0][3][1] = '4';
	hint2[0][0][5][0] = '0';
	hint2[0][0][5][1] = '5';
	hint2[0][0][6][0] = '0';
	hint2[0][0][6][1] = '6';
	hint2[0][0][7][0] = '0';
	hint2[0][0][7][1] = '7';
	hint2[0][0][8][0] = '0';
	hint2[0][0][8][1] = '8';
	hint2[0][0][9][0] = '0';
	hint2[0][0][9][1] = '9';
	hint2[0][1][0][0] = '1';
	hint2[0][1][0][1] = '0';
	hint2[0][1][5][0] = '1';
	hint2[0][1][5][1] = '1';
	hint2[0][2][0][0] = '1';
	hint2[0][2][0][1] = '2';
	hint2[0][2][5][0] = '1';
	hint2[0][2][5][1] = '3';
	hint2[0][3][0][0] = '1';
	hint2[0][3][0][1] = '4';
	hint2[0][3][4][0] = '1';
	hint2[0][3][4][1] = '5';
	hint2[0][4][0][0] = '1';
	hint2[0][4][0][1] = '6';
	hint2[0][4][4][0] = '1';
	hint2[0][4][4][1] = '7';
	hint2[0][5][3][0] = '1';
	hint2[0][5][3][1] = '8';
	hint2[0][5][7][0] = '1';
	hint2[0][5][7][1] = '9';
	hint2[0][5][8][0] = '2';
	hint2[0][5][8][1] = '0';
	hint2[0][5][9][0] = '2';
	hint2[0][5][9][1] = '1';
	hint2[0][6][2][0] = '2';
	hint2[0][6][2][1] = '2';
	hint2[0][6][6][0] = '2';
	hint2[0][6][6][1] = '3';
	hint2[0][7][0][0] = '2';
	hint2[0][7][0][1] = '4';
	hint2[0][7][1][0] = '2';
	hint2[0][7][1][1] = '5';
	hint2[0][7][6][0] = '2';
	hint2[0][7][6][1] = '6';
	hint2[0][8][0][0] = '2';
	hint2[0][8][0][1] = '7';
	hint2[0][8][6][0] = '2';
	hint2[0][8][6][1] = '6';
	hint2[0][9][0][0] = '2';
	hint2[0][9][0][1] = '7';
	hint2[0][9][6][0] = '2';
	hint2[0][9][6][1] = '8';
	hint2[0][10][0][0] = '2';
	hint2[0][10][0][1] = '9';
	hint2[0][10][6][0] = '3';
	hint2[0][10][6][1] = '0';

	//hint2 2

	hint2[1][0][0][0] = '0';
	hint2[1][0][0][1] = '1';
	hint2[1][0][1][0] = '0';
	hint2[1][0][1][1] = '2';
	hint2[1][0][2][0] = '0';
	hint2[1][0][2][1] = '3';
	hint2[1][0][3][0] = '0';
	hint2[1][0][3][1] = '4';
	hint2[1][0][6][0] = '0';
	hint2[1][0][6][1] = '5';
	hint2[1][0][7][0] = '0';
	hint2[1][0][7][1] = '6';
	hint2[1][0][8][0] = '0';
	hint2[1][0][8][1] = '7';
	hint2[1][0][9][0] = '0';
	hint2[1][0][9][1] = '8';
	hint2[1][1][0][0] = '0';
	hint2[1][1][0][1] = '9';
	hint2[1][1][5][0] = '1';
	hint2[1][1][5][1] = '0';
	hint2[1][2][0][0] = '1';
	hint2[1][2][0][1] = '1';
	hint2[1][2][5][0] = '1';
	hint2[1][2][5][1] = '2';
	hint2[1][3][0][0] = '1';
	hint2[1][3][0][1] = '3';
	hint2[1][3][4][0] = '1';
	hint2[1][3][4][1] = '4';
	hint2[1][4][3][0] = '1';
	hint2[1][4][3][1] = '5';
	hint2[1][5][2][0] = '1';
	hint2[1][5][2][1] = '6';
	hint2[1][5][7][0] = '1';
	hint2[1][5][7][1] = '7';
	hint2[1][6][0][0] = '1';
	hint2[1][6][0][1] = '8';
	hint2[1][6][1][0] = '1';
	hint2[1][6][1][1] = '9';
	hint2[1][6][7][0] = '2';
	hint2[1][6][7][1] = '0';
	hint2[1][6][8][0] = '2';
	hint2[1][6][8][1] = '1';
	hint2[1][6][9][0] = '2';
	hint2[1][6][9][1] = '2';
	hint2[1][7][0][0] = '2';
	hint2[1][7][0][1] = '3';
	hint2[1][7][3][0] = '2';
	hint2[1][7][3][1] = '4';
	hint2[1][7][4][0] = '2';
	hint2[1][7][4][1] = '5';
	hint2[1][7][6][0] = '2';
	hint2[1][7][6][1] = '6';
	hint2[1][8][0][0] = '2';
	hint2[1][8][0][1] = '7';
	hint2[1][8][6][0] = '2';
	hint2[1][8][6][1] = '8';
	hint2[1][9][0][0] = '2';
	hint2[1][9][0][1] = '9';
	hint2[1][9][6][0] = '3';
	hint2[1][9][6][1] = '0';


	//music

	if(musicOn){
		if(game_state == 0){
			PlaySound("Music\\Tokyo_Ghoul.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
		
	iSetTimer(1000, func);
	iSetTimer(5, animation);

	
  	iInitialize(1200, 700, "Crossword Puzzle Game");
  	return 0;
}