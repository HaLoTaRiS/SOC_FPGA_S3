/*
 *  TP 2 : SOC / FPGA
 *  Jeremy VICENTE & Baptiste FRITOT
 *  tp_seance_3.c
 *
 *  T6 : Mesurer le temps "Tics_par_seconde" & temps de bienvenue
 *  T7 : Mesurer le temps dans le PS pour 10 entier en soft
 *
 */

#include <stdio.h>
#include <stdbool.h>

#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xil_exception.h"
#include "tp_seance_3.h"

bool active_GetTime = false; // Flag

// Fonction pour convertir en ns
u32 calcul_ns (u32 nbr_cycle){
	return nbr_cycle = nbr_cycle*5;
}

// Fonction pour convertir en us
u32 calcul_us (u32 nbr_cycle){
	return nbr_cycle = nbr_cycle*5/1000;
}

/*********** Lance et arret calcul ***********/
void GetTime(void){
	u32 timer_cycle = 0;

	// Lancement du compteur
	if (active_GetTime == false){
		active_GetTime = true;
		init_timer();
	}

	// fin du compteur & r?cup?re la valeur
	else {
		timer_cycle = cycle_timer();
		stop_timer();
		xil_printf("Count timer : %u\r\n",timer_cycle);
		xil_printf("Temps : %u ns | %u us \r\n\r\n",calcul_ns(timer_cycle),calcul_us(timer_cycle));
		active_GetTime = false;
	}
}


int main()
{
	init_platform();
	/*********** CODE TP 2 seance 3 ***********/
	/***** QUESTION T6 : Mesure le temps du message bienvenue *****/
	GetTime(); // d?but comptage
	xil_printf ("=================================\r\n");
	xil_printf ("      Seance 3 - Calcul temps - Timer\r\n");
	xil_printf ("Baptiste FRITOT - Jeremy VICENTE\r\n");
	xil_printf ("=================================\r\n\r\n");
	GetTime(); // fin du comptage

	sleep (2);
	xil_printf ("======\r\n");
	xil_printf ("Calcul de 10 entiers\r\n\r\n");
	/***** QUESTION T7 : comptage 10 entiers  *****/
	int count_T7 = 0;
	GetTime(); // d?but comptage
	for (int i = 0; i<10; i++) {
		count_T7 ++;
	}
	GetTime(); // fin du comptage

	while(1){

	}

	cleanup_platform();
	return 0;
}
