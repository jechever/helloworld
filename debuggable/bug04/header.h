//Header

//int padding(double *time, double *flux);

typedef struct{
  double *time;
  double *flux;
  int count;
  int pow2;
}Pad;
Pad *padding(Pad *zeros);

typedef struct{
  double *flux;
  int count;
}Bit;
Bit *scramble(Bit *swap);

typedef struct{
  double *flux;
  int count;
  int pow2;
}Loop;
Loop *layers(Loop *onion);
