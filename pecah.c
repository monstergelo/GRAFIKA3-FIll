#include "pecah.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>


int pesawatterakhir;
int peluruterakhir;
int pecahanterakhir;

objekTabrak pesawat[1];
objekTabrak peluru[100];
objekTabrak pecahan[10];

void spawnPecahan(titik p){

}

int main(){
	//inisialisasi
	init_fb();
	warna c = {255,255,255,255};
	titik pl0 = {0,0};
	titik pl1 = {1000,600};
	titik p0 = {400,550};
	titik p1 = {600,400};
	titik p2 = {300,450};
	titik p3 = {500,450};

	//inisialisasi pesawat
	spawnObjek('a',p0);

	refreshBuffer(pl0,pl1);	//buat background
	gambarObjek();			//siapin gambar pesawat
	spawnObjek('b',p0);	    //gambar peluru
	spawnPecahan(pesawat[0].posisi);  //gambar pecahan
	loadBuffer();			//gambar ke layar

	usleep(2000000);
	int i = 0;
	
	while(i<10000)
	{
		refreshBuffer(pl0,pl1);
		gambarObjek();
		jalanObjek();

		gambarHancur(pesawat[0].posisi);
		pesawat[0].isTabrakan = -1;
		loadBuffer();

		usleep(170);
		i++;
	}


	return 0;
}
