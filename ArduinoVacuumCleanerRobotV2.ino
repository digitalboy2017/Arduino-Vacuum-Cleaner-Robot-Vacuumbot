
#define echoPin 46 //Sol ultrasonik sensörün echo pini Arduino'nun 44.pinine
#define trigPin 47 //Sol ultrasonik sensörün trig pini Arduino'nun 45.pinine
#define echoPin1 44 //Ön ultrasonik sensörün echo pini Arduino'nun 51.pinine
#define trigPin1 45 //Ön ultrasonik sensörün trig pini Arduino'nun 50.pinine
#define echoPin2 51 //Sağ ultrasonik sensörün echo pini Arduino'nun 46.pinine
#define trigPin2 50 //Sağ ultrasonik sensörün trig pini Arduino'nun 47.pinine
//L298N
#define in1 5
#define in2 6
#define in3 7
#define in4 8
#define ena 9
#define enb 10

int maximumRange = 50;
int minimumRange = 20;
int dcs = 255;
int sensor = 0;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
//Motorlarımızı çıkış olarak tanımlıyoruz.
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
Serial.begin(9600);
}

void loop() {
  int olcum = mesafe(maximumRange, minimumRange);
  int olcum1 = mesafe1(maximumRange, minimumRange);
  int olcum2 = mesafe2(maximumRange, minimumRange);

Serial.println("L:");
Serial.print(olcum);
Serial.print("  F:");
Serial.print(olcum1);
Serial.print("  R:");
Serial.print(olcum2); 

  char val = Serial.read() ;//reads the signal
  digitalWrite(ena, dcs);//Sol motor hızını ayarla
  digitalWrite(enb, dcs);//Sağ motor hızını ayarla
   if (val == 'F') { ileri();}
   if (val == 'R'){ sag();}
   if (val == 'L'){ sol();}
   if (val == 'B'){ geri();}
   if (val == 'S'){ dur();}
   if (val == 'T'){ dcs=255;}
   if (val == 'N'){ dcs=150;}
   if (val == 'M'){ dcs=50;}
   if (val == 'A'){ sensor=1;}
    if(sensor>0) {
  if (olcum1 < minimumRange || olcum && olcum2 < minimumRange ){ 
  if (olcum < olcum2){ geri();
   delay(150);
   sag();
   delay(500);}
   if (olcum2 < olcum){ geri();
   delay(150);
   sol();
   delay(500);}
    }
  else if (olcum < minimumRange){ sag();
   delay(250);}
  else if (olcum2 < minimumRange){ sol();
   delay(250);}
  else if (olcum && olcum1 && olcum2 > minimumRange){
    ileri();}

    
  if (val == 'S'){ sensor=0;}
  }
  }


int mesafe(int maxrange, int minrange){
  
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);
  
  return distance;
}

int mesafe1(int maxrange, int minrange){
 
  long duration1, distance1;

  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 / 58.2;
  delay(50);
  
  return distance1;
}

int mesafe2(int maxrange, int minrange){
 
  long duration2, distance2;

  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 / 58.2;
  delay(50);

  return distance2;
}

void dur(){ // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, LOW); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
digitalWrite(in3, LOW); // Sol motorun ileri hareketi aktif
digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif

}
void geri(){ // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, HIGH); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
digitalWrite(in3, HIGH); // Sol motorun ileri hareketi aktif
digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif

}
void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, LOW); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, HIGH); // Sağ motorun geri hareketi pasif
digitalWrite(in3, LOW); // Sol motorun ileri hareketi aktif
digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif
}

void sol(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, LOW); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
digitalWrite(in3, LOW); // Sol motorun ileri hareketi aktif
digitalWrite(in4, HIGH); // Sol motorun geri hareketi pasif
}
void ileri(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, LOW); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, HIGH); // Sağ motorun geri hareketi pasif
digitalWrite(in3, LOW); // Sol motorun ileri hareketi aktif
digitalWrite(in4, HIGH); // Sol motorun geri hareketi pasif
}
