int led = 8;

int entre_notas = 50;

int dt = 80; // dois tempos
int ti = 40; // tempo inteiro
int mt = 20; // meio tempo

int Do = 13;
int Re = Do - 1;
int Mi = Re - 1;
int Fa = Mi - 1;
int Sol = Fa - 1;
int La = Sol - 1;
int Si = La - 1;
int Do1 = Si - 1;



void t( int nota, int tempo) { // Toca
 
  tom( nota, tempo);
  delay( entre_notas );
}

void tom( int nota, int tempo ) {
  
  for( int i = tempo; i > 0; i-- ) {
    digitalWrite( led, HIGH );
    delay( nota );
    digitalWrite( led, LOW );
    delay( nota );
  }
}

void melody1(){
 dt = 40; // dois tempos
  ti = 20; // tempo inteiro 
  mt = 10; // meio tempo

  t(Do, mt);  
  t(Do, mt);
  t(Re, ti);
  t(Do, ti);
  t(Fa, ti);
  t(Mi, ti);
  t(Do, mt);  
  t(Do, mt);
  t(Re, ti);
  t(Do, ti);
  t(Sol, ti);
  t(Fa, ti);
  t(Do, mt);
  t(Do, mt);
  t(Do1, dt);
  t(La, ti);
  t(Fa, ti);
  t(Mi, ti);
  t(Re, ti);
  t(Si, mt);
  t(Si, mt);
  t(Si, ti);
  t(Fa, ti);
  t(Sol, ti);
  t(Fa, ti);
  
}

void beep(){
  t(La, 50);  
  delay(150);
  t(La, 50);  
  delay(150);
  t(La, 50);  
  delay(150);
  t(La, 50);  
  delay(150);
  t(La, 50);  
  delay(150);


}
