/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   fmatriz.h
 * Author: 2024.1.08.022
 *
 * Created on 17 de junho de 2024, 09:24
 */

#ifndef FMATRIZ_H
#define FMATRIZ_H
typedef int matriz[100][100];
void mostrar(matriz m, int l, int c);

void transp(matriz m1, int l1, int c1,
            matriz m2, int *l2, int *c2);

int soma(matriz m1, int l1, int c1,
        matriz m2, int l2, int c2,
        matriz m3, int *l3, int *c3);

int multpl(matriz m1, int l1, int c1,
        matriz m2, int l2, int c2,
        matriz m3, int *l3, int *c3);

void media(matriz m, int l, int c, float *med);



#endif /* FMATRIZ_H */

