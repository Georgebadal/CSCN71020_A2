
#include <stdio.h>
#include <stdbool.h>

// function to read an integer input by displaying a message
int getIntInput(char message[]) {
	int input;
		printf("\n%s\n", message);
		if (scanf("%d", &input) !=1){
			while(getchar() != '\n'); // clear invalid input from buffer
			input = 7;
		}
		else
			return input;
		return input;
}
// read length if between 0 and 100 otherwise set it to -1
int setLength(int input) {
	int length = 1;
	if (input >= 0 && input < 100)
	{
		length = input;
		return length;
	}

	return length;


}
// read width if between 0 and 100 otherwise set it to -1
int setWidth(int input) {
	int width = 1;
	if (input > 0 && input <= 100)
	{
		 width = input;
		return width;
	}
	return width;

}
// calculate permiter
int getPerimeter(int length, int width) {
	int perimeter = (2*length) + (width*2);
	return perimeter;
}
// calculate area
int getArea(int length, int width) {
	int area = (length * width);
	return area;
}
// printing menu and options

void printWelcomeMenu() {
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**    Assignment 02   **\n");
	printf(" **********************\n");
}

void printOptions() {
	printf("1. Get Rectange Length & Width\n");
	printf("2. Change Rectangle Length\n");
	printf("3. Change Rectangle Width\n");
	printf("4. Get Rectangle Perimeter\n");
	printf("5. Get Rectangle Area\n");
	printf("6. Exit\n");
}