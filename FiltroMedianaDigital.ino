
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
float x1=0,x2=0,vo,pot,m, X[3], aux, vf, x3;
int i,j;
void loop() {
  pot= analogRead(A0);
  vo = (pot*5)/1023; //Voltaje acondicionado en A0
  vf = vo*0.3/5; //Voltaje Normal
  x3= vf/0.01; //Temperatura
  X[0]=x1;
  X[1]=x2;
  X[2]=x3;
  for(i=1;i<3;i++) //Ordenamiento Burbuja (ordena de menor a mayor los valores)
  {
    for(j=0;j<(3-i);j++)
    {
      if(X[j]>X[j+1])
      {
        aux = X[j];
        X[j]=X[j+1];
        X[j+1]=aux;
      }
    }
  }
  m = X[1]; //Valor central
  Serial.println(m,10);
  x1=x2;
  x2=x3;
  delay(1); //Cada 0.01 segundos
}
