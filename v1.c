#define A 2
#define B 3
#define C 4
#define D 5

#define E 6
#define F 7
#define G 8
#define H 9
 
#define NUMBER_OF_STEPS_PER_REV 512

int i = 0;
int j = 0;

//char FORWARD[] = "FORWARD";
char REVERSE[] = "REVERSE";


void setup(){
Serial.begin(115200);
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);

pinMode(E,OUTPUT);
pinMode(F,OUTPUT);
pinMode(G,OUTPUT);
pinMode(H,OUTPUT);
}

void writeOne(int a,int b,int c,int d){
digitalWrite(A,a);
digitalWrite(B,b);
digitalWrite(C,c);
digitalWrite(D,d);
}

void writeTwo(int e, int f, int g, int h){
digitalWrite(E,e);
digitalWrite(F,f);
digitalWrite(G,g);
digitalWrite(H,h);
}

void stepForwardOne(){
writeOne(1,0,0,0);
delay(5);
writeOne(1,1,0,0);
delay(5);
writeOne(0,1,0,0);
delay(5);
writeOne(0,1,1,0);
delay(5);
writeOne(0,0,1,0);
delay(5);
writeOne(0,0,1,1);
delay(5);
writeOne(0,0,0,1);
delay(5);
writeOne(1,0,0,1);
delay(5);
}

void stepReverseOne(){
writeOne(1,0,0,1);
delay(5);
writeOne(0,0,0,1);
delay(5);
writeOne(0,0,1,1);
delay(5);
writeOne(0,0,1,0);
delay(5);
writeOne(0,1,1,0);
delay(5);
writeOne(0,1,0,0);
delay(5);
writeOne(1,1,0,0);
delay(5);
writeOne(1,0,0,0);
delay(5);
}

void stepForwardTwo(){
writeTwo(1,0,0,0);
delay(5);
writeTwo(1,1,0,0);
delay(5);
writeTwo(0,1,0,0);
delay(5);
writeTwo(0,1,1,0);
delay(5);
writeTwo(0,0,1,0);
delay(5);
writeTwo(0,0,1,1);
delay(5);
writeTwo(0,0,0,1);
delay(5);
writeTwo(1,0,0,1);
delay(5);
}

void stepReverseTwo(){
writeTwo(1,0,0,1);
delay(5);
writeTwo(0,0,0,1);
delay(5);
writeTwo(0,0,1,1);
delay(5);
writeTwo(0,0,1,0);
delay(5);
writeTwo(0,1,1,0);
delay(5);
writeTwo(0,1,0,0);
delay(5);
writeTwo(1,1,0,0);
delay(5);
writeTwo(1,0,0,0);
delay(5);
}

void resetHolders(){
  i = 0;
  j = 0;
}

void revolutions(int multiplier, char wheelDirection[] ){
  //input the amount of revolutions you want a wheel to turn
  Serial.println(wheelDirection);
  if (wheelDirection == "FORWARD"){
    for (i; i < (multiplier * NUMBER_OF_STEPS_PER_REV) + 1; i++){
      stepForwardOne();
      stepForwardTwo();
    }
  }
  else if (wheelDirection == "REVERSE"){
    for (i; i < (multiplier * NUMBER_OF_STEPS_PER_REV) + 1; i++){
      stepReverseOne();
      stepReverseTwo();
    }    
  }

}

void steps(int stepNumber){
  //input the number of steps that you want a wheel to turn
  for (j; j < stepNumber + 1; j++){
    stepForwardOne();
  }
}

void loop(){
  revolutions(1, "FORWARD");
  delay(100);
  resetHolders();
  revolutions(1, "REVERSE");
  delay(100);
  resetHolders();
}
