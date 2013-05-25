typedef struct complex *Complex;
/* A implementaçã usando ponteiros, desta maneira,
 * é diferente de quando o implementamos normal-
 * mente. Esses ponteiros são HANDLES. 
 */
Complex COMPLEXinit (float,float);
/* typedef struct { float Re; float Im; } Complex; 
 * Retiramos esta linha e abstraímos a implementa-
 * ção em relação ao struct. Isso tem uma grande 
 * vantagem, pois agora não é possível manipular 
 * diretamente a struct. Primeiro, ele é um pon-
 * teiro, e em segundo lugar, não nos foi defini-
 * do a maneira pela qual são feitas as coisas.
 */
float Re(Complex);
float Im(Complex);
Complex COMPLEXmult (Complex, Complex);

/* Este .h fornece para o cliente uma possibilidade de mexer
 * com a implementação (estamos acessando o tipo). */
