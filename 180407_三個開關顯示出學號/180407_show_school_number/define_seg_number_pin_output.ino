//you must define a com pin first!!
int a=32,b=30,c=4,d=6,e=7,f=34,g=36;
void segClearAll(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void segShow0(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
}
void segShow1(){
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
}
void segShow2(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(g,LOW);
}
void segShow3(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(g,LOW);
}
void segShow4(){
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void segShow5(){
  digitalWrite(a,LOW);
  digitalWrite(f,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(g,LOW);
}
void segShow6(){
  digitalWrite(a,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(g,LOW);
}
void segShow7(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
}
void segShow8(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void segShow9(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

