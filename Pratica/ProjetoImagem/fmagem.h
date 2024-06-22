#ifndef FMAGEM_H
#define FMAGEM_H
typedef int Timagem[1024][1024];
void muda_tom(Timagem img, int lin, int col, int fator);
void negativa(Timagem img, int lin, int col);
void binarizar(Timagem img, int lin, int col, int fator);
void iconizar(Timagem img, int *lin, int *col);
void ruido(Timagem img, int lin, int col);
void suavizar(Timagem img, int lin, int col);



#endif /* FMAGEM_H */

