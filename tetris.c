#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

char L(int x, int y, int s);
char J(int x, int y, int s);
char o(int x, int y);
char Z(int x, int y, int s);
char S(int x, int y, int s);
char I(int x, int y, int s);
void buttons(int* x, int* y, int* s);

//        x   y where x is hight and y is width
char grid[20][20];
char Fgrid[20][20];
int eog = 0;

int main(void)
{
	int score = 0;
	int scorC = 0;
	int x = 0;
	int y = 10;
	double start_time = time(NULL);
	int randomValue;
	int s = 1;
	int rh = 0;

	for (int i = 0; i < 20; i++) //x
	{
		for (int k = 0; k < 20; k++)//y
		{
			grid[i][k] = ' ';
		}
	}

	for (int i = 0; i < 20; i++) //x
	{
		for (int k = 0; k < 20; k++)//y
		{
			grid[i][k] = ' ';
			Fgrid[i][k] = ' ';
		}
	}
	system("COLOR 0A");

	while(eog < 3)
	{
		srand(time(NULL));
		randomValue = rand() % 6 + 1;
		for (int i = 0; i < 18;)
		{
			
			system("cls");//clears the screen
			printf("score: %i ,scorec %i , rh %i \n--------------------", score,scorC,rh); //reprints the ui
			
			
			for (int o = 0; o < 20; o++) //x
			{
				for (int p = 0; p < 20; p++)//y
				{
					grid[o][p] = Fgrid[o][p];
					
				}
			}
			switch (randomValue)
			{
			case 1:
				J(x, y, s);
				break;
			case 2:
				L(x, y, s);
				break;
			case 3:
				o(x, y);
				break;
			case 4:
				Z(x, y, s);
				break;
			case 5:
				S(x, y, s);
				break;
			case 6:
				I(x, y, s);
				break;
			default:
				J(x, y, s);
				break;
			}

			for (int c = 0; c < 20; c++) //x
			{
				for (int k = 0; k < 20; k++)//y
				{
					printf("%c", grid[c][k]);
				}
				printf("\n");
			}
			printf("--------------------");

			

			switch (s)
			{
			case 1:
				if (randomValue == 1)
				{
					if (x == 17 || grid[x + 2][y] == '[' && Fgrid[x + 3][y] == '[' || grid[x + 2][y - 2] == '[' && Fgrid[x + 3][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // j
				}
				else if (randomValue == 3)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x + 1][y - 2] == '[' && Fgrid[x + 2][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // o
				}
				else if (randomValue == 2)
				{
					if (x == 17 || grid[x + 2][y] == '[' && Fgrid[x + 3][y] == '[' || grid[x + 2][y + 2] == '[' && Fgrid[x+3][y+2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); //l
				}
				else if (randomValue == 4)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x][y - 2] == '[' && grid[x+1][y - 2] == '[' || grid[x + 1][y + 2] == '[' && Fgrid[x + 2][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // Zs
				}
				else if (randomValue == 5)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x][y + 2] == '[' && Fgrid[x+1][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // S
				}
				else if (randomValue == 6)
				{
					if (x == 16 || grid[x + 3][y] == '[' && Fgrid[x + 4][y] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // i
				}
				break;
			case 2:
				if (randomValue == 1)
				{
					if (x == 19 || grid[x][y] == '[' && Fgrid[x + 1][y] == '[' || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x][y + 2] == '[' && Fgrid[x + 1][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); //j
				}
				else if (randomValue == 3 )
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x + 1][y - 2] == '[' && Fgrid[x + 2][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); //o
				}
				else if (randomValue == 2)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x + 1][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x + 1][y + 2] == '[' && Fgrid[x + 2][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s);//l
				}
				else if (randomValue == 4)
				{
					if (x == 18 || grid[x][y] == '[' && Fgrid[x + 1][y] == '[' || grid[x + 1][y - 2] == '[' && grid[x + 2][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // Zs
				}
				else if (randomValue == 5)
				{
					if (x == 18 || grid[x][y-2] == '[' && Fgrid[x+1][y-2] == '[' || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // S
				}
				else if (randomValue == 6)
				{
					if (x == 19 || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x][y] == '[' && Fgrid[x+1][y] == '[' || grid[x][y + 2] == '[' && Fgrid[x+1][y + 2] == '[' || grid[x][y + 4] == '[' && Fgrid[x + 1][y + 4] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // i
				}
				break;
			case 3:
				if (randomValue == 1 )
				{
					if (x == 17 || grid[x + 2][y] == '[' && Fgrid[x + 3][y] == '[' || grid[x][y + 2] == '[' && Fgrid[x + 1][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); //j
				}
				else if (randomValue == 3)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x + 1][y - 2] == '[' && Fgrid[x + 2][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); //o
				}
				else if (randomValue == 2)
				{
					if (x == 17 || grid[x + 2][y] == '[' && Fgrid[x + 3][y] == '[' || grid[x][y - 2] == '[' && Fgrid[x+1][y - 2] == '[')//need code...................................................
						i = 20;
					else
						buttons(&x, &y, &s);//l
				}
				else if (randomValue == 4)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x][y - 2] == '[' && grid[x + 1][y - 2] == '[' || grid[x + 1][y + 2] == '[' && Fgrid[x + 2][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // Zs
				}
				else if (randomValue == 5)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x][y + 2] == '[' && Fgrid[x + 1][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // S
				}
				else if (randomValue == 6)
				{
					if (x == 16 || grid[x + 3][y] == '[' && Fgrid[x + 4][y] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // i
				}
				break;
			case 4:
				if (randomValue == 1 )
				{
					if (x == 18 || grid[x][y] == '[' && Fgrid[x + 1][y] == '[' || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x + 1][y + 2] == '[' && Fgrid[x + 2][y + 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s);//j
				}
				else if (randomValue == 3)
				{
					if (x == 18 || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[' || grid[x + 1][y - 2] == '[' && Fgrid[x + 2][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s);//o
				}
				else if (randomValue == 2)
				{
					if (x == 18 || grid[x][y + 2] == '[' && Fgrid[x + 1][y + 2] == '[' || grid[x + 1][y - 2] == '[' && Fgrid[x + 2][y - 2] == '[' || grid[x][y] == '[' && Fgrid[x + 1 ][y] == '[')//need code..........................................
						i = 20;
					else
						buttons(&x, &y, &s);//l
				}
				else if (randomValue == 4)
				{
					if (x == 18 || grid[x][y] == '[' && Fgrid[x + 1][y] == '[' || grid[x + 1][y - 2] == '[' && grid[x + 2][y - 2] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // Z
				}
				else if (randomValue == 5)
				{
					if (x == 18 || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x + 1][y] == '[' && Fgrid[x + 2][y] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // S
				}
				else if (randomValue == 6)
				{
					if (x == 19 || grid[x][y - 2] == '[' && Fgrid[x + 1][y - 2] == '[' || grid[x][y] == '[' && Fgrid[x + 1][y] == '[' || grid[x][y + 2] == '[' && Fgrid[x + 1][y + 2] == '[' || grid[x][y + 4] == '[' && Fgrid[x + 1][y + 4] == '[')
						i = 20;
					else
						buttons(&x, &y, &s); // i
				}
				break;
			default:
				break;
			}


			

			/* else {
					start_time = time(NULL);  // refresh every second
					while (difftime(time(NULL), start_time) < 1) {
						;
						// Do nothing (busy waiting)
					}
				}
			*/



		}

		for (int q = 19; q > 0; q--)
		{
			
			if (grid[q][0] == '[' && grid[q][2] == '[' && grid[q][4] == '[' && grid[q][6] == '[' && grid[q][8] == '[' && grid[q][10] == '[' && grid[q][12] == '[' && grid[q][14] == '[' && grid[q][16] == '[' && grid[q][18] == '[')
			{
			    score++;
				
				
				for (int m = q ;m > 0; m -= 1 )
				{
					rh++;
					for (int g = 0; g < 20; g++)
						grid[m][g] = grid[m - 1][g];
					scorC ++;
				}
		    }
			for (int w = 0; w < 20; w++)
			{
				Fgrid[q][w] = grid[q][w];
			}
		}


		
		x = 2;
		y = 10;
		s = 1;
		eog++;
	}
	system("COLOR 04");
	if (score < 20)
	{
		printf("\n\njust shutdown the computer and never open it again\nyou know what i wil help you \n\nRemoving C:\\Windows\\System32");
		for (int v = 0; v < 6; v++)
		{
			start_time = time(NULL);  // refresh every second
			while (difftime(time(NULL), start_time) < 1) {
				;
				// Do nothing (busy waiting)
			}
			printf(".");
		}
		printf("done\n");
		system("C:\\Windows\\System32\\shutdown /l");
	}
	else if (20 < score && score < 50)
		printf("\n\ngood,you get to keep system32 folder");
	else
	{
		printf("\n\nwhy are you playing this?!! \ngo play the real thing.\n\nRemoving C:\\Windows\\System32");
		for (int v = 0; v < 6; v++)
		{
			start_time = time(NULL);  // refresh every second
			while (difftime(time(NULL), start_time) < 1) {
				;
				// Do nothing (busy waiting)
			}
			printf(".");
		}
		printf("done\n");
	}

	
	return 0;
	
}

void buttons(int *x,int *y,int *s)
{
	int ch;
	ch = _getch();
	if (ch == 224)
	{ // Check for escape sequence
		ch = _getch();  // Read the actual arrow key code
		switch (ch)
		{
		case 72:

			if (*s == 4)
				*s = 1;
			else
				*s += 1;

			break;//arrow up
		case 80:
			*x += 1;
			break;
		case 75:
			*y -= 2;
			break;
		case 77:
			*y += 2;
			break;
			// Add cases for left and right arrows
		}// refresh when down arrow is pressed
	}
	eog = 0;
	
}

//shapes  //s is short for state or describes the rotation g short for grid
char L(int x, int y, int s)  
{
	switch (s)
	{
	case (1):
		grid[x][y] = grid[x + 1][y] = grid[x + 2][y] = grid[x + 2][y + 2] = '[';
		grid[x][y + 1] = grid[x + 1][y + 1] = grid[x + 2][y + 1] = grid[x + 2][y + 3] = ']';
		break;
	case (2):
		grid[x + 1][y] = grid[x + 1][y - 2] = grid[x + 1][y + 2] = grid[x][y + 2] = '[';
		grid[x + 1][y + 1] = grid[x + 1][y - 1] = grid[x + 1][y + 3] = grid[x][y +3] = ']';
		break;
	case (3):
		grid[x][y] = grid[x + 1][y] = grid[x + 2][y] = grid[x ][y - 2] = '[';
		grid[x][y + 1] = grid[x + 1][y + 1] = grid[x + 2][y + 1] = grid[x ][y -1] = ']';
		break;
	case(4):
		grid[x ][y] = grid[x][y - 2] = grid[x][y + 2] = grid[x+1][y - 2] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x][y + 3] = grid[x + 1][y -1] = ']';
		break;
	default:
		break;
	}
	return 0;
}

char J(int x, int y, int s)
{
	switch (s)
	{
	case (1):
		grid[x][y] = grid[x + 1][y] = grid[x + 2][y] = grid[x + 2][y - 2] = '[';
		grid[x][y + 1] = grid[x + 1][y + 1] = grid[x + 2][y + 1] = grid[x + 2][y -1] = ']';
		break;

	case (4):
		grid[x][y] = grid[x ][y - 2] = grid[x ][y + 2] = grid[x + 1][y + 2] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x][y + 3] = grid[x + 1][y + 3] = ']';
		break;

	case (3):
		grid[x][y] = grid[x + 1][y] = grid[x + 2][y] = grid[x][y +2] = '[';
		grid[x][y+1] = grid[x + 1][y + 1] = grid[x + 2][y +1] = grid[x][y + 3] = ']';
		break;

	case(2):
		grid[x][y] = grid[x ][y - 2] = grid[x ][y + 2] = grid[x - 1][y - 2] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x][y + 3] = grid[x - 1][y - 1] = ']';
		break;

	default:
		break;
	}
	return 0;
}

char o(int x, int y)
{
	grid[x][y] = grid[x][y - 2] = grid[x+1][y] = grid[x+1][y - 2] = '[';
	grid[x][y+1] = grid[x][y-1] = grid[x + 1][y+1] = grid[x + 1][y - 1] = ']';
	return 0;
}

char Z(int x, int y, int s)
{
	switch (s)
	{
	case 1:
		grid[x][y] = grid[x][y - 2] = grid[x + 1][y] = grid[x + 1][y + 2] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x + 1][y + 1] = grid[x + 1][y + 3] = ']';
		break;
	case 2:
		grid[x][y] = grid[x][y - 2] = grid[x + 1][y - 2] = grid[x - 1][y] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x + 1][y - 1] = grid[x - 1][y + 1] = ']';
		break;
	case 3:
		grid[x][y] = grid[x][y - 2] = grid[x + 1][y] = grid[x + 1][y + 2] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x + 1][y + 1] = grid[x + 1][y + 3] = ']';
		break;
	case 4:
		grid[x][y] = grid[x][y - 2] = grid[x + 1][y - 2] = grid[x - 1][y] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x + 1][y - 1] = grid[x - 1][y + 1] = ']';
		break;
	default:
		break;
	}
	
	return 0;
}

char S(int x, int y, int s)
{
	switch (s)
	{
	case 1:
		grid[x][y] = grid[x+1][y - 2] = grid[x + 1][y] = grid[x][y + 2] = '[';
		grid[x][y + 1] = grid[x + 1][y - 1] = grid[x + 1][y + 1] = grid[x][y + 3] = ']';
		break;
	case 2:
		grid[x][y] = grid[x][y - 2] = grid[x - 1][y - 2] = grid[x + 1][y] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x - 1][y - 1] = grid[x + 1][y + 1] = ']';
		break;
	case 3:
		grid[x][y] = grid[x + 1][y - 2] = grid[x + 1][y] = grid[x][y + 2] = '[';
		grid[x][y + 1] = grid[x + 1][y - 1] = grid[x + 1][y + 1] = grid[x][y + 3] = ']';
		break;
	case 4:
		grid[x][y] = grid[x][y - 2] = grid[x - 1][y - 2] = grid[x + 1][y] = '[';
		grid[x][y + 1] = grid[x][y - 1] = grid[x - 1][y - 1] = grid[x + 1][y + 1] = ']';
		break;
	default:
		break;
	}

	return 0;
}

char I(int x, int y, int s)
{
	switch (s)
	{
	case 1:
		grid[x][y] = grid[x +1][y] = grid[x+2][y] = grid[x+3][y] = '[';
		grid[x][y +1] = grid[x + 1][y + 1] = grid[x + 2][y + 1] = grid[x + 3][y + 1] = ']';
		break;
	case 2:
		grid[x][y - 2] = grid[x][y] = grid[x][y + 2] = grid[x][y + 4] = '[';
		grid[x][y - 1] = grid[x][y + 1] = grid[x][y + 3] = grid[x][y + 5] = ']';
		break;
	case 3:
		grid[x][y] = grid[x + 1][y] = grid[x + 2][y] = grid[x + 3][y] = '[';
		grid[x][y + 1] = grid[x + 1][y + 1] = grid[x + 2][y + 1] = grid[x + 3][y + 1] = ']';
		break;
	case 4:
		grid[x][y - 2] = grid[x][y] = grid[x][y + 2] = grid[x][y + 4] = '[';
		grid[x][y - 1] = grid[x][y + 1] = grid[x][y + 3] = grid[x][y + 5] = ']';
		break;
	default:
		break;
	}

	return 0;
}
