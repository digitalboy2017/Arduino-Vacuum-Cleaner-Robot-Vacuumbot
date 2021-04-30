#define echoPin2 46 //Sol ultrasonik sensörün echo pini Arduino'nun 51.pinine
#define trigPin2 47 //Sol ultrasonik sensörün trig pini Arduino'nun 50.pinine
#define echoPin 44 //Ön ultrasonik sensörün echo pini Arduino'nun 44.pinine
#define trigPin 45 //Ön ultrasonik sensörün trig pini Arduino'nun 45.pinine
#define echoPin3 51 //Sağ ultrasonik sensörün echo pini Arduino'nun 46.pinine
#define trigPin3 50 //Sağ ultrasonik sensörün trig pini Arduino'nun 47.pinine
//L298N
#define in1 5
#define in2 6
#define in3 9
#define in4 10

long sure, uzaklik, sure2, uzaklik2, sure3, uzaklik3; //süre ve uzaklık diye iki değişken tanımlıyoruz.

void setup() {
// Ultrasonik sensör Trig pininden ses dalgaları gönderdiği için OUTPUT (Çıkış),
// Bu dalgaları Echo pini ile geri aldığı için INPUT (Giriş) olarak tanımlanır.
pinMode(echoPin2, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin3, OUTPUT);
//Motorlarımızı çıkış olarak tanımlıyoruz.
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW); //Ön ultrasonic sensör pasif hale getirildi
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
uzaklik = sure / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor
digitalWrite(trigPin2, LOW); //Sol ultrasonic sensör pasif hale getirildi
delayMicroseconds(5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
sure2 = pulseIn(echoPin2, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
uzaklik2 = sure2 / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor
digitalWrite(trigPin3, LOW); //Sağ ultrasonic sensör pasif hale getirildi
delayMicroseconds(5);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
sure3 = pulseIn(echoPin3, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
uzaklik3 = sure3 / 29.1 / 2; //ölçülen süre uzaklığa çevriliyor

Serial.print("Sensors FLR:");
Serial.print(uzaklik);
Serial.print("/");
Serial.print(uzaklik2);
Serial.print("/");
Serial.println(uzaklik3);

if (uzaklik < 20 || uzaklik2 && uzaklik3 < 25 || uzaklik && uzaklik2 && uzaklik3 < 25) // Uzaklık 25'den küçük ise,
{
 if (uzaklik2 < uzaklik3){
geri();
delay(150);
sag(); 
delay(700);
}
if (uzaklik3 < uzaklik2){
geri();
delay(150);
sol(); 
delay(700);
}
}
else if (uzaklik3 < 25) // Uzaklık 25'den küçük ise,
{
sol(); // 250 ms sağa dön
delay(250);
}
else if (uzaklik2 < 25) // Uzaklık 25'den küçük ise,
{
sag(); // 250 ms sağa dön
delay(250);
}
else if (uzaklik && uzaklik2 && uzaklik3 > 25) // Uzaklık 15'den küçük ise,
{
ileri();
}
}
void geri(){ // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, HIGH); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, LOW); // Sağ motorun geri hareketi pasif
digitalWrite(in3, HIGH); // Sol motorun ileri hareketi aktif
digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif

}
void sol(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, LOW); // Sağ motorun ileri hareketi aktif
digitalWrite(in2, HIGH); // Sağ motorun geri hareketi pasif
digitalWrite(in3, HIGH); // Sol motorun ileri hareketi aktif
digitalWrite(in4, LOW); // Sol motorun geri hareketi pasif
}

void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

digitalWrite(in1, HIGH); // Sağ motorun ileri hareketi aktif
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
