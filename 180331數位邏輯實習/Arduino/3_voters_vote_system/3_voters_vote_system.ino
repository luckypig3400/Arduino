int voter1=12,voter2=11,voter3=10;
int votepass=9;
void setup() {
  pinMode(voter1,INPUT);
  pinMode(voter1,INPUT);
  pinMode(voter1,INPUT);
  pinMode(votepass,OUTPUT);
}
int read1=digitalRead(voter1);
int read2=digitalRead(voter2);
int read3=digitalRead(voter3);
void loop() {
  read1=digitalRead(voter1);
  read2=digitalRead(voter2);
  read3=digitalRead(voter3);
  if(read1==HIGH && read2==HIGH)digitalWrite(votepass,HIGH);
  else if(read2==HIGH && read3==HIGH)digitalWrite(votepass,HIGH);
  else if(read1==HIGH && read3==HIGH)digitalWrite(votepass,HIGH);
  else if(read1==HIGH && read2==HIGH && read3==HIGH)
    digitalWrite(votepass,HIGH);
  else digitalWrite(votepass,LOW);
}
