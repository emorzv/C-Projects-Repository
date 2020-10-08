#ifndef FUNCTIONS
#define FUNCTIONS
#include <time.h>

void errorFunc() {
    int temp = (rand()%20) + 1;
    char tempArr[20];

    if (temp >= 7 && temp <= 17) {
        printf("ERROR %d\n(Type \"continue\" to proceed)\n", temp);
        scanf("%s", tempArr);
        while (strcmp(tempArr, "continue") != 0) {
            system("cls");
            printf("Incorrect input!\nTry again\n");
            scanf("%s", tempArr);
        }
    }
}


void input(int *waterAvailable, int *coffeeAvailable) {
	printf("Amount of available water: ");
	scanf("%d", waterAvailable);
	printf("Amount of available coffee: ");
	scanf("%d", coffeeAvailable);
}


int init(int waterAvailable, int coffeeAvailable, int waterCost, int coffeeCost) {
	if (waterAvailable < waterCost) {
		int temp = waterCost - waterAvailable;
		printf("%d more milliliters of water needed!\n", temp);
		return -1;
	}
	else if (coffeeAvailable < coffeeCost) {
		int temp = coffeeCost - coffeeAvailable;
		printf("%d more grams of coffee needed!\n", temp);
		return -2;
	}
}

void mainFunc(int *waterAvailable, int *coffeeAvailable, int waterCost, int coffeeCost) {
	int i = 0;
	char arr[] = "|       |";
	int len = strlen(arr);
	char holder[len];
	strcpy(holder, arr);
	int counter = 0;
	int counter1 = 0;
	char arr0[] = "\\=====/";
	char arr1[] = " \\===/";
	char arr2[] = "  \\=/";
	srand(time(0));

    errorFunc();

	while (counter != 2) {

		printf("---------------------\n");
		printf("Warming up the water!\n");

		if (arr[i] == ' ') {
			arr[i] = '=';
		}

		printf("     %s\n", arr);
		printf("---------------------");

		Sleep(250);
		system("cls");

		i++;
		if (i == len) {
			i = 0;
			strcpy(arr, holder);
			counter++;
		}
	}

    errorFunc();

	counter = 0;
	while (counter != 2) {

		printf("---------------------\n");
		printf("Grinding the coffee!\n");

		if (arr[i] == ' ') {
			arr[i] = '=';
		}

		printf("     %s\n", arr);
		printf("---------------------");

		Sleep(250);
		system("cls");

		i++;
		if (i == len) {
			i = 0;
			strcpy(arr, holder);
			counter++;
		}
	}

	errorFunc();

	counter = 0;
	while (counter != 4) {
		if (counter1 == 0) {
			printf("---------------------\n");
			printf("Waiting for preparation!\n");
			printf("\n");
			printf("\n");
			printf("       %s\n", arr2);
			printf("---------------------");
			Sleep(350);
			system("cls");
		}
		else if (counter1 == 1) {
			printf("---------------------\n");
			printf("Waiting for preparation!\n");
			printf("\n");
			printf("       %s\n", arr1);
			printf("       %s\n", arr2);
			printf("---------------------");
			Sleep(350);
			system("cls");
		}
		else if (counter1 == 2) {
			printf("---------------------\n");
			printf("Waiting for preparation!\n");
			printf("       %s\n", arr0);
			printf("       %s\n", arr1);
			printf("       %s\n", arr2);
			printf("---------------------");
			Sleep(350);
			system("cls");
		}
		counter1++;
		if (counter1 == 3) {
			counter1 = 0;
			counter++;
		}
	}

	errorFunc();

	printf("---------------------\n");
	printf("Your Coffee Is Ready!\n");
	printf("---------------------");

	*waterAvailable -= waterCost;
	*coffeeAvailable -= coffeeCost;
}

void addWater(int *waterAvailable) {
	printf("Add water: ");
	int temp;
	scanf("%d", &temp);
	*waterAvailable += temp;

}

void addCoffee(int *coffeeAvailable) {
	printf("Add coffee: ");
	int temp;
	scanf("%d", &temp);
	*coffeeAvailable += temp;
}

#endif // FUNCTIONS
