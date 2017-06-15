int TRIG = 12;
int ECHO = 11;
int distLeft = 0;
int distRight = 0;
int power = 127;
void go();
void forward();
void backward();
void fin();
void turnleft();
void turnright();
int lookLeft();
int lookRight();
int getCM();


void setup(){
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5, OUTPUT);
pinMode(9, OUTPUT);
pinMode(3, OUTPUT);

//pinMode(TRIG, OUTPUT);
//pinMode(ECHO, INPUT);
}



void loop(){
go();
getCM();
if(getCM() <= 25)
{
fin();
delay(1000);
backward();
delay(500);
distLeft = lookLeft();
//delay(200);
distRight = lookRight();

if(distLeft >= distRight){
turnleft();
delay(150);
fin();
delay(1000);
}

else{
turnright();
delay(150);
fin();
delay(1000);
}
}
forward();
//delay(1000);
}


void forward(){
analogWrite(9, power);
analogWrite(3, power);
digitalWrite(8, HIGH);//Left
digitalWrite(7, LOW);//
digitalWrite(6, LOW);//Right
digitalWrite(5, HIGH);//
}
void backward(){
analogWrite(9, 80);
analogWrite(3, 80);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(6, HIGH);
digitalWrite(5, LOW);
}
void fin(){
digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);
}
void turnright(){
analogWrite(9, power);
analogWrite(3, power);
digitalWrite(8, HIGH);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
digitalWrite(5, LOW);
}
void turnleft(){
analogWrite(9, power);
analogWrite(3, power);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(6, LOW);
digitalWrite(5, HIGH);
}

void go(){
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
//TRIG pin must start LOW
digitalWrite(TRIG, LOW);
delay(30);
}

int getCM() {
//Send trig pulse
digitalWrite(TRIG, HIGH);
delayMicroseconds(20);
digitalWrite(TRIG, LOW);
//Wait for echo start
while(digitalRead(ECHO) == LOW);
//Wait for echo end
long startTime = micros();
while(digitalRead(ECHO) == HIGH);
long travelTime = micros() - startTime;
//Get distance in cm
int distance = travelTime / 58;
return distance;
}

int lookLeft(){
turnleft();
delay(150);
fin();
delay(300);
int distance = getCM();
turnright();
delay(150);
return distance;
}

int lookRight(){
turnright();
delay(150);
fin();
delay(300);
int distance = getCM();
turnleft();
delay(150);
return distance;
}
