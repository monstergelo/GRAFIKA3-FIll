#include "tabrakan.h"

extern int pesawatterakhir;
extern int peluruterakhir;
extern int pecahanterakhir;

extern objekTabrak pesawat[1];
extern objekTabrak peluru[100];
extern objekTabrak pecahan[10];

void spawnPecahan(titik p);	//memunculkan pecahan pada koordinat p, bisa melihat spawnObjek pada tabrakan.h