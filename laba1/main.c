#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
ÇÀÄÀÍÈÅ 1
	Îáúÿâèòü âåùåñòâåííûå ïåðåìåííûå a, b è ñ è çàäàòü èõ çíà÷åíèÿ. Ïðåäïîëàãàÿ, ÷òî a, b, c åñòü êîýôôèöèåíòû êâàäðàòíîãî óðàâíåíèÿ âûâåñòè íà êîíñîëü çíà÷åíèÿ èõ êîðíåé õ1, õ2. Ñëåäóåò ïîäîáðàòü òàêèå çíà÷åíèÿ êîýôôèöèåíòîâ, ïðè êîòîðûõ êîðíè áóäóò ñóùåñòâîâàòü.
	Ïðèìå÷àíèå. Äëÿ âûïîëíåíèÿ çàäàíèÿ ïîòðåáóåòñÿ ôóíêöèè âû÷èñëåíèÿ êâàä-ðàòíîãî êîðíÿ (âîçâåäåíèå â ñòåïåíü), à òàê æå âûâîä äàííûõ íà êîíñîëü.
	Âîçâåäåíèå â ñòåïåíü - ïîäêëþ÷àåì çàãîëîâî÷íûé ôàéë	 math.h è èñïîëüçóåì ôóíêöèþ pow, ïåðâûì ïàðàìåòðîì êîòîðîãî äîëæåí áûòü âîçâîäèìîå çíà÷åíèå, à âòîðûì - ñòåïåíü, òèï äàííûõ double.
	Âûâîä äàííûõ - çàãîëîâî÷íûé ôàéë stdio.h, ôóíêöèÿ printf, ïåðâûì ïàðàìåòðîì ÿâëÿåòñÿ ôîðìàòíàÿ ñòðîêà, à ïîñëåäóþùèå - ïåðåìåííûå, çíà÷åíèÿ êîòîðûõ íåîáõî-äèìî âûâåñòè.


 run this program using the console pauser or add your own getch, system("pause") or input loop */


float calcRoot(float D, float a, float b);

int main(int argc, char *argv[]) {
		
	printf("vvedite a, b, c\n");
		
	float a, b, c;
	
	scanf("%f", &a);
	scanf("%f", &b);	
	scanf("%f", &c);
	
	float x1, x2, d;
	d = b*b - 4*a*c;
	
	printf("d = %1f\n", d);
	
	if(d < 0)
	{
		printf("korney net\n");
	}
	else if(d == 0)
	{
		printf("koren odin\n");
		x1 = calcRoot(d, a, b);
		printf("x1 = %1f\n", x1);		
	}
	else
	{
		printf("korenia dva\n");
		x1 = calcRoot(d, a, b);
		x2 = calcRoot(d, a, -b);
		printf("x1 = %1f\n", x1);
		printf("x2 = %1f\n", x2);		
	}
		
	return 0;
}

float calcRoot(float D, float a, float b)
{
	return (float)((-b + sqrt(D)) / (2 * a));
}

