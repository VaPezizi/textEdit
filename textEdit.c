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

	int letterCount = 0;
	
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
	

		BeginDrawing();
		ClearBackground(WHITE);	
		
		DrawText(BUFFER, 10, 10, 40, MAROON);	
		
		EndDrawing();
		//printf("Arvo :%c \n", BUFFER[letterCount - 1]);
	}	

	free(BUFFER);
	return 0;
}
