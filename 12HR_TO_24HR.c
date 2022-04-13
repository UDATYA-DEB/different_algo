#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char time[11]; // TIME FORMAT 12:12:12AM HH:MM:SSAM/PM
	fgets(time, 11, stdin);
	if (time[8] == 'A')
	{
		char hh[2];
		for (int i = 0; i < 2; i++)
		{
			hh[i] = time[i];
		}
		int hour = atoi(hh);
		if (hour == 12)
		{
			for (int i = 0; i < 2; i++)
			{
				time[i] = '0';
			}
			time[8] = '\0';
			fputs(time, stdout);
		}
		else
		{
			time[8] = '\0';
			fputs(time, stdout);
		}
	}
	else if (time[8] == 'P')
	{
		char hh[2];
		for (int i = 0; i < 2; i++)
		{
			hh[i] = time[i];
		}
		int hour = atoi(hh);
		if (hour == 12)
		{
			time[8] = '\0';
			fputs(time, stdout);
		}
		else
		{
			hour += 12;
			sprintf(hh, "%d", hour);
			for (int i = 0; i < 2; i++)
			{
				time[i] = hh[i];
			}
			time[8] = '\0';
			fputs(time, stdout);
		}	
	}
	else
	{
		printf("Invalid input.");
	}
	return 0;
}
