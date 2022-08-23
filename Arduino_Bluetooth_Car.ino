int t=0;

int speed1 ;
int enA = 12;
int in1 = 2;
int in2 = 6;
// Motor B connections
int enB = 13;
int in3 = 9;
int in4 = 4;

           
void setup() 
{
  
  Serial.begin(38400);  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  speed1 =120;
      
}
void loop() {
 
if(Serial.available()){
  t = Serial.read();
  if(t>9){
    speed1=t;
    }
  Serial.println(t);
}
if(t == 1){            
  forward();
}
 
 
else if(t== 2){      
  reverse();
}
else if(t == 0){      
  offmotor();
} 
else if(t == 3){      
  left();
} 
else if(t == 4){      
  right();
}    
  delay(1); 
 t='off'; 
speed1=150;
}
 

void reverse(){
    
      Serial.println(speed1);  
      Serial.println("reverse");  
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      for (int i = 0; i < speed1; i++) {
      analogWrite(enA, i);
      analogWrite(enB, i);
      }
 }
void forward(){
      Serial.println("forward"); 
      Serial.println(speed1);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); 
      for (int i = 0; i < speed1; i++) {
      analogWrite(enA, i);
      analogWrite(enB, i);
      }   
  }
  void offmotor(){
     Serial.println("Motoroff");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    for (int i = speed1; i >= 0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    
   } 
    
 }
  void right(){
    Serial.println("right");
    analogWrite(enA, 150);
    analogWrite(enB, 150);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
 }
  void left(){
    Serial.println("left");
     analogWrite(enA, 150);
    analogWrite(enB, 150);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
 }
