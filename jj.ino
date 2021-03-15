
#define r1 10 //set pin10 for red
#define y1 6 //set pin6 for yellow
#define g1 2 //set pin2 for green
#define r2 11 //set pin11 for red
#define y2 7 //set pin7 for yellow
#define g2 3 //set pin3 for green
#define r3 12 //set pin12 for red
#define y3 8 //set pin8 for yellow
#define g3 4 //set pin4 for green
#define r4 13 //set pin13 for red
#define y4 9 //set pin9 for yellow
#define g4 5 //set pin5 for green
#define ldrPin A0 //ldr analog

int matrix[18][2][4]={
  //{green red red red} {on on on on}
  {{g1, r2, r3, r4 },{HIGH, HIGH, HIGH, HIGH}}, //0
  {{g1, r2, r3, r4 },{LOW, LOW, LOW, LOW}},     //1
  {{y1, r2, r3, r4 },{HIGH, HIGH, HIGH, HIGH}}, //2
  {{y1, r2, r3, r4 },{LOW, LOW, LOW, LOW}},     //3
  {{g2, r1, r3, r4},{HIGH, HIGH, HIGH, HIGH}},  //4
  {{g2, r1, r3, r4},{LOW, LOW, LOW, LOW}},      //5
  {{y2, r1, r3, r4},{HIGH, HIGH, HIGH, HIGH}},  //6
  {{y2, r1, r3, r4},{LOW, LOW, LOW, LOW}},      //7
  {{g3, r1, r2, r4},{HIGH, HIGH, HIGH, HIGH}},  //8
  {{g3, r1, r2, r4},{LOW, LOW, LOW, LOW}},      //9
  {{y3, r1, r2, r4},{HIGH, HIGH, HIGH, HIGH}},  //10
  {{y3, r1, r2, r4},{LOW, LOW, LOW, LOW}},      //11
  {{g4, r1, r2, r3},{HIGH, HIGH, HIGH, HIGH}},  //12
  {{g4, r1, r2, r3},{LOW, LOW, LOW, LOW}},      //13
  {{y4, r1, r2, r3},{HIGH, HIGH, HIGH, HIGH}},  //14
  {{y4, r1, r2, r3},{LOW, LOW, LOW, LOW}},      //15
  {{y1, y2, y3, y4},{HIGH, HIGH, HIGH, HIGH}},  //16
  {{y1, y2, y3, y4},{LOW, LOW, LOW, LOW}}       //17
};

void setup() {
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
  int i;
  for(i=2;i<14;i++){
    pinMode(i,OUTPUT);
  }
  
}
void trafficOn(int trf){
  int i;
  int ldrStatus = analogRead(A0);
  if (ldrStatus >= 200){
  for(i=0;i<4;i++){
  digitalWrite(matrix[trf][0][i],matrix[trf][1][i]);
  Serial.print("Its Bright, Traffic are working : ");}
  }
  else{
    for(i=0;i<4;i++)
      digitalWrite(matrix[trf][0][i],LOW);
  yellow();
  }
}
void trafficYOn(int trf){
  int i;
  int ldrStatus = analogRead(A0);
  for(i=0;i<4;i++){
  digitalWrite(matrix[trf][0][i],matrix[trf][1][i]);
 }
}
void loop() {
      trafficOn(0);
      delay(12000);
      trafficOn(1);
      delay(10);
      trafficOn(2);
      delay(3000);
      trafficOn(3);
      trafficOn(4);
      delay(12000);
      trafficOn(5);
      delay(10);
      trafficOn(6);
      delay(3000);
      trafficOn(7);
      delay(10);
      delay(10);
      trafficOn(8);
      delay(12000);
      trafficOn(9);
      delay(10);
      trafficOn(10);
      delay(3000);
      trafficOn(11);
      delay(10);
      trafficOn(12);
      delay(12000);
      trafficOn(13);
      delay(10);
      trafficOn(14);
      delay(3000);
      trafficOn(15);
      delay(10);
      
      
 
    //Serial.println(ldrStatus);
}
void yellow(){
      trafficYOn(16);
      delay(1000);
      trafficYOn(17);
      delay(1000);
      Serial.print("Its DARK, Traffic has problem : ");
}
