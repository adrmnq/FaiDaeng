
#define r1 2   //set pin2 for red
#define y1 3   //set pin3 for yellow
#define g1 4   //set pin4 for green
#define r2 5   //set pin5 for red
#define y2 6   //set pin6 for yellow
#define g2 7   //set pin7 for green
#define r3 8   //set pin8 for red
#define y3 9   //set pin9 for yellow
#define g3 10  //set pin10 for green
#define r4 11  //set pin11 for red
#define y4 12  //set pin12 for yellow
#define g4 13  //set pin13 for green
#define ldrPin A0 //ldr analog
#define INTERVAL_MESSAGE 4100 // 4.05 s
unsigned long time = 0;

//--------------------------------------//
void setOn(int a){
  if (a==0){        //Set 1 lighton
    trafficOn(0);
    delay(3000);
    trafficOn(1);
    delay(10);
    trafficOn(2);
    delay(1000);
    trafficOn(3);
    delay(10);
  }
  if (a==1){
    trafficOn(4);
    delay(3000);
    trafficOn(5);
    delay(10);
    trafficOn(6);
    delay(1000);
    trafficOn(7);
    delay(10);
  }
  if (a==2){
    trafficOn(8);
    delay(3000);
    trafficOn(9);
    delay(10);
    trafficOn(10);
    delay(1000);
    trafficOn(11);
    delay(10);
  }
  if (a==3){
    trafficOn(12);
    delay(3000);
    trafficOn(13);
    delay(10);
    trafficOn(14);
    delay(1000);
    trafficOn(15);
    delay(10);
  }
};

//--------------------------------------//

int matrix[18][2][4]={
  //{green red red red} {on on on on}
  {{g1, r2, r3, r4 },{HIGH, HIGH, HIGH, HIGH}}, //0
  {{g1, r2, r3, r4 },{LOW, LOW, LOW, LOW}},     //1
  {{y1, r2, r3, r4 },{HIGH, HIGH, HIGH, HIGH}}, //2
  {{y1, r2, r3, r4 },{LOW, LOW, LOW, LOW}},     //3
  {{g3, r1, r2, r4 },{HIGH, HIGH, HIGH, HIGH}},  //4
  {{g3, r1, r2, r4 },{LOW, LOW, LOW, LOW}},      //5
  {{y3, r1, r2, r4 },{HIGH, HIGH, HIGH, HIGH}},  //6
  {{y3, r1, r2, r4 },{LOW, LOW, LOW, LOW}},      //7
  {{g2, r1, r3, r4 },{HIGH, HIGH, HIGH, HIGH}},  //8
  {{g2, r1, r3, r4 },{LOW, LOW, LOW, LOW}},      //9
  {{y2, r1, r3, r4 },{HIGH, HIGH, HIGH, HIGH}},  //10
  {{y2, r1, r3, r4 },{LOW, LOW, LOW, LOW}},      //11
  {{g4, r1, r2, r3 },{HIGH, HIGH, HIGH, HIGH}},  //12
  {{g4, r1, r2, r3 },{LOW, LOW, LOW, LOW}},      //13
  {{y4, r1, r2, r3 },{HIGH, HIGH, HIGH, HIGH}},  //14
  {{y4, r1, r2, r3 },{LOW, LOW, LOW, LOW}},      //15
  {{y1, y2, y3, y4 },{HIGH, HIGH, HIGH, HIGH}},  //16
  {{y1, y2, y3, y4 },{LOW, LOW, LOW, LOW}}       //17
};

void setup() {
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(g4, OUTPUT);
  
}
void trafficOn(int trf){
  digitalWrite(matrix[trf][0][0],matrix[trf][1][0]);
  digitalWrite(matrix[trf][0][1],matrix[trf][1][1]);
  digitalWrite(matrix[trf][0][2],matrix[trf][1][2]);
  digitalWrite(matrix[trf][0][3],matrix[trf][1][3]);
};
void loop() {
    int ldrStatus = analogRead(A0);
    if (ldrStatus >= 200){
      if(millis()-time >= INTERVAL_MESSAGE){
        time = millis();
        int A = millis()/INTERVAL_MESSAGE;
        int C = A%4;
        setOn(C);
      }
      Serial.print("Its Bright, Traffic are working : ");
    } 
    else {
      trafficOn(16);
      delay(1000);
      trafficOn(17);
      delay(1000);
      Serial.print("Its DARK, Traffic has problem : ");
    }
    Serial.println(ldrStatus);
}
/*เสร็จเรียบร้อย SUPERSOKAI*/