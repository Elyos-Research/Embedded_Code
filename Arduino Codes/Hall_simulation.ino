#define HALL_A 12
#define HALL_B 11
#define HALL_C 10

byte currentState = 1;
byte number = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial init");

  // GPIOS
  pinMode(HALL_A, OUTPUT);
  pinMode(HALL_B, OUTPUT);
  pinMode(HALL_C, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    currentState = (currentState >= 6)? 1 : currentState + 1;
    Serial.println(number);
    Serial.read();
  }
  
  switch(currentState){
    case 1:
      digitalWrite(HALL_A, LOW);
      digitalWrite(HALL_B, LOW);
      digitalWrite(HALL_C, HIGH);
      number = 1;
      break;
    case 2:
      digitalWrite(HALL_A, LOW);
      digitalWrite(HALL_B, HIGH);
      digitalWrite(HALL_C, HIGH);
      number = 3;
      break;
    case 3:
      digitalWrite(HALL_A, LOW);
      digitalWrite(HALL_B, HIGH);
      digitalWrite(HALL_C, LOW);
      number = 2;
      break;
    case 4:
      digitalWrite(HALL_A, HIGH);
      digitalWrite(HALL_B, HIGH);
      digitalWrite(HALL_C, LOW);
      number = 6;
      break;
    case 5:
      digitalWrite(HALL_A, HIGH);
      digitalWrite(HALL_B, LOW);
      digitalWrite(HALL_C, LOW);
      number = 4;
      break;
    case 6:
      digitalWrite(HALL_A, HIGH);
      digitalWrite(HALL_B, LOW);
      digitalWrite(HALL_C, HIGH);
      number = 5;
      break;
    default:
      digitalWrite(HALL_A, LOW);
      digitalWrite(HALL_B, LOW);
      digitalWrite(HALL_C, LOW);
      number = 0;
      break;
  }
}
