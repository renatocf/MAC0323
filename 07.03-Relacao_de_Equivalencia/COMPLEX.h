typedef struct { float Re; float Im; } Complex;
float Re(Complex);
float Im(Complex);
Complex COMPLEXmult (Complex, Complex);

/* Este .h fornece para o cliente uma possibilidade de mexer
 * com a implementação (estamos acessando o tipo). */
