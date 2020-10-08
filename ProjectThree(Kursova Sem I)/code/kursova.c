#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "functions.h"
#include <time.h>

#define COFFEECOST 9 //grams
#define WATERCOST 150 //milliliters

int main() {
	int waterAvailable;
	int coffeeAvailable;
	int temp;
	int answer;


	input(&waterAvailable, &coffeeAvailable);
	printf("\n");
	//printf("%d\n%d\n", waterAvailable, coffeeAvailable);

    while (answer != 2){


        while (waterAvailable < WATERCOST || coffeeAvailable < COFFEECOST) {
            temp = init(waterAvailable, coffeeAvailable, WATERCOST, COFFEECOST);

            if (/*init(waterAvailable, coffeeAvailable, WATERCOST, COFFEECOST)*/ temp == -1) {
                addWater(&waterAvailable);
            }
            else if (/*init(waterAvailable, coffeeAvailable, WATERCOST, COFFEECOST)*/ temp == -2) {
                addCoffee(&coffeeAvailable);
            }
        }

        mainFunc(&waterAvailable, &coffeeAvailable, WATERCOST, COFFEECOST);
        printf("\n%d\n%d\n", waterAvailable, coffeeAvailable);
        printf("\nDo you want another one?\n1.Yes\n2.No\n");
        scanf("%d", &answer);
    }


	return 0;
}
