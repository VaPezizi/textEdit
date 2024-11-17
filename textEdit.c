#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

//#define RAYGUI_IMPLEMENTATION
//#include <raygui.h>

#define HEIGHT 600
#define WIDTH 800
#define BUFFERSIZE 500

int addLetter(char * BUFFER, char ToAdd, int * letterCount, int * CurrentIndex){
	
	if(*CurrentIndex == *letterCount){	
		BUFFER[*letterCount] = (char)ToAdd;
		BUFFER[*letterCount + 1] = '\0';
		*letterCount = *letterCount + 1;
		*CurrentIndex = *CurrentIndex + 1;
		return 0;	
	
		if(IsKeyPressed(KEY_ENTER) && (*letterCount < BUFFERSIZE)){
			
			BUFFER[*letterCount] = '\n';
			BUFFER[*letterCount + 1] = '\0';
			*letterCount = *letterCount + 1;
			*CurrentIndex = *CurrentIndex + 1;	
		//BUFFER[*CurrentIndex]
		}	
	}
	else{
		puts("Moro");
	}
	return 0;

}
int removeLetter(char * BUFFER, int * letterCount, int * CurrentIndex){
	if(*CurrentIndex == *letterCount){	
		if(letterCount != 0) letterCount--;
		BUFFER[*letterCount] = '\0';


		return 0;	
	}
	else{
		return 0;
	}
}

int main(){
	//Allocating memory for a Buffer of 500 characters
	

	int letterCount = 0;	
	int frameCount = 0;
	int CurrentIndex = 0;
	
	char * BUFFER = (char*) malloc(sizeof(char) * (BUFFERSIZE + 1));

	if(BUFFER == NULL){
		fprintf(stderr, "Memory allocation error\n");
		return -1;
	}

	BUFFER[BUFFERSIZE + 1] = '\0';
	
	InitWindow(WIDTH, HEIGHT, "Text Edit");
	SetTargetFPS(60);

	Font font = LoadFont("./assets/DejaVuSansCondensed.ttf");


	SetTargetFPS(60);

	//printf("%d\n", '\n');

	while(!WindowShouldClose()){
		
		//SetMouseCursor(MOUSE_CURSOR_IBEAM);
			
		if(CheckCollisionPointRec(GetMousePosition(), (Rectangle) {0, 0, GetScreenWidth(), GetScreenHeight()})){
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
		}	
		
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		int key = GetCharPressed();
		
		//Reading keys till they don't appear anymore
		while(key > 0){
			if((key>= 32) && (key <= 255) && (letterCount < BUFFERSIZE)){
				
				addLetter(BUFFER, (char) key, &letterCount, &CurrentIndex);
						
				//BUFFER[letterCount] = (char)key;
				//BUFFER[letterCount + 1] = '\0';
				//letterCount++;
			}	
			//printf("%d\n", enter);
			key = GetCharPressed();
			//printf("%d\n", key);
		}
		// "Deleting" a letter from the end
		if(IsKeyPressed(KEY_TAB) && letterCount + 3 < BUFFERSIZE){
			for(int i =0;i<5;i++){
				BUFFER[letterCount] = ' ';
				BUFFER[letterCount + 1] = '\0';
				letterCount++;
			}
			//BUFFER[letterCount] = '\t';
			//BUFFER[letterCount+1] = '\0';
			//letterCount++;
			
		}
		if(IsKeyPressed(KEY_BACKSPACE)){
		//	if(letterCount != 0) letterCount--;
		//	BUFFER[letterCount] = '\0';
			removeLetter(BUFFER, &letterCount, &CurrentIndex);
		
		}
		if(IsKeyPressed(KEY_ENTER) && (letterCount < BUFFERSIZE)){
			
			BUFFER[letterCount] = '\n';
			BUFFER[letterCount + 1] = '\0';
			letterCount++;
			puts("Moro");
		}
		
			
		frameCount++;
		/*if(letterCount < BUFFERSIZE){
			if(((frameCount/20)%2) == 0){ continue;}
		}*/
	
		if(letterCount + 1 < BUFFERSIZE){
			if((frameCount/20)%2){
				BUFFER[letterCount] = '_';	
				BUFFER[letterCount + 1] = '\0';
				//DrawTextEx(font,"_", (Vector2){10, 10 * (CURRENTLINE + 1)}, font.baseSize, 2, BLACK);	
			}else{
				BUFFER[letterCount] = '\0';
				//BUFFER[letterCount + 1] = '\0';
			}
		}

		BeginDrawing();
		ClearBackground(WHITE);	
		

		//printf("%d\n", (frameCount/20)%2);	
		

		DrawTextEx(font,BUFFER, (Vector2){10, 10}, font.baseSize, 2, BLACK);	
		EndDrawing();
		//printf("Arvo :%c \n", BUFFER[letterCount - 1]);
	}	
	UnloadFont(font);
	free(BUFFER);
	CloseWindow();
	return 0;
}
