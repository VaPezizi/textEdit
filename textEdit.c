#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

//#define RAYGUI_IMPLEMENTATION
//#include <raygui.h>

#define HEIGHT 600
#define WIDTH 800
#define BUFFERSIZE 500

int main(){
	//Allocating memory for a Buffer of 500 characters
	
	int CURRENTLINE = 1;
	
	char * BUFFER = (char*) malloc(sizeof(char) * (BUFFERSIZE + 1));
	BUFFER[BUFFERSIZE + 1] = '\0';
	
	InitWindow(WIDTH, HEIGHT, "Text Edit");
	SetTargetFPS(60);

	Font font = LoadFont("./assets/DejaVuSansCondensed.ttf");


	int letterCount = 0;	
	int frameCount = 0;

	SetTargetFPS(60);

	printf("%d\n", '\n');

	while(!WindowShouldClose()){
		
		if(CheckCollisionPointRec(GetMousePosition(), (Rectangle) {0, 0, GetScreenWidth(), GetScreenHeight()})){
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			
			int key = GetCharPressed();
			int enter = GetKeyPressed(); 	

			while(key > 0){
				if((key>= 32) && (key <= 255) && (letterCount < BUFFERSIZE)){
					
					BUFFER[letterCount] = (char)key;
					BUFFER[letterCount + 1] = '\0';
					letterCount++;
				}
				
				enter = GetKeyPressed();
				printf("%d\n", enter);
				key = GetCharPressed();
				printf("%d\n", key);
			}
			if(IsKeyPressed(KEY_BACKSPACE)){
				letterCount--;
				if(letterCount < 0) letterCount = 0;
				BUFFER[letterCount] = '\0';
			}
			if(IsKeyPressed(KEY_ENTER) && (letterCount < BUFFERSIZE)){
				
				BUFFER[letterCount] = '\n';
				BUFFER[letterCount + 1] = '\0';
				letterCount++;
				CURRENTLINE++;
				puts("Moro");
			}
		}
		
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	
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
