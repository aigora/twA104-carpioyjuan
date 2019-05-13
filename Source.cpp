#include<stdio.h>
#include<windows.h>
#include<malloc.h>
//float temperatura(float);
//float humedad(float);
float sensor(float, float);
int main()
{
	int i=0;
	int motor = 0;
	float temp2=0, hum2=0;
	float *temp;
	float *hum;
	int n;
	printf("cuantas temperaturas y humedades desea calcular: ");
	scanf_s("%d", &n);
	float tempfinal, humfinal;
	temp = (float *)malloc(n * sizeof(float));
	hum= (float *)malloc(n * sizeof(float));
	float sensor1;
	int boton = 0;
	for (i = 0; i < n; i++)
	{
		printf("introduzca temperatura en C:\n");
		scanf_s("%f", &temp[i]);
		printf("introduzca la humedad en % :\n");
		scanf_s("%f", &hum[i]);
		temp2 += temp[i];
		hum2 += hum[i];
	}
	tempfinal = temp2 / n;//media de la temperatura
	humfinal = hum2 / n;//media de la humedad
	
	/*printf("introduzca temperatura en C:\n");
	scanf_s("%f", &temp2);
	printf("introduzca la humedad en %:\n");
	scanf_s("%f", &hum2);*/
	sensor1 = sensor(tempfinal, humfinal);
	
	if (sensor1)
	{
		motor = 1;//se enciende el motor y por consiguiente el ventilador
		printf("el ventilador se ha encendido\n");
		printf("desea apagar el ventilador? pulse 1 si es asi\n");
		scanf_s("%d", &boton);
		if (boton == 1)
		{
			motor = 0;//se apaga
			printf("el ventilador se ha apagado\n");
		}
		else
			printf("el ventilador sigue funcionando\n");
			

	}
			
	else
	{
		motor = 0;//permanece inactivo
		printf("el ventilador permanece inactivo\n");
	}
			
	
	system("pause");
}
float sensor(float tempfinal, float humfinal)
{
	
	if (tempfinal >= 20 && humfinal >= 40)
	{
		return 1;
	}

	else
		return 0;
}
/*float temperatura(float temp2)
{
	if (temp2 > 20)//si la temperatura sobrepasa los 20ºC
		return 1;
	else
		return 0;

}
float humedad(float hum2)
{
	if (hum2 > 50)
		return 1;
	else
		return 0;
}*/