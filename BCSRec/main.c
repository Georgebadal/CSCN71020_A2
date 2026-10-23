#include <stdio.h>
#include <stdbool.h>

#include "functions.h"

int main(void)
{
	int length = 1;
	int width = 1;
	bool continueProgram = true;
	// showing an infinte loop till user exits
	while (continueProgram) {
		printWelcomeMenu();  // printing menu to select
		printOptions();

		int menuInput;
		menuInput = getIntInput("Enter menu option number:");  //inout an integer

		// selecting options using switch
		switch (menuInput)
		{
			case 1:
			{
				length = setLength(length);
				width = setWidth(width);
				printf("\nThe Rectangle has a length of %i and a width of %i\n\n", length, width);
				break;
			}
			case 2:
			{
				int input = getIntInput("Please enter the length of the rectangle:");
				length=setLength(input);
				printf("Rectangle length is now %i\n\n", length);
				break;
			}
			case 3:
			{
				int input = getIntInput("Please enter the width of the rectangle:");
				width=setWidth(input);
				printf("Rectangle width is now %i\n\n", width);
				break;
			}
			case 4:
			{
				printf("\nThe Rectangle has a perimeter of %i\n\n", getPerimeter(length, width));
				printf("Rectangle perimeter is now %i\n\n", getPerimeter(length, width));
				break;
			}
			case 5:
			{
				printf("\nThe Rectangle has an area of %i\n\n", getArea(length, width));
				printf("Rectangle area is now %i\n\n", getArea(length, width));
				break;
			}
			case 6:
			{
				continueProgram = false;
				break;
			}
			default:
			{
				printf("\nInvalid value entered7.\n\n");
				break;
			}
		}
	}
}
