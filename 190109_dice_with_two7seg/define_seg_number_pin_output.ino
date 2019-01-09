//you must define a com pin first!!
//com pin define at main page
int a1 = 9;
int b1 = 8;
int c1 = 7;
int d1 = 5;
int e1 = 4;
int f1 = 10;
int g1 = 11;
int a2 = A4;
int b2 = A5;
int c2 = A0;
int d2 = A2;
int e2 = A3;
int f2 = 2;
int g2 = 3;
//以上均為pin腳定義資訊
void segClearAll() {
  //below is 7seg1
  digitalWrite(a1, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(c1, HIGH);
  digitalWrite(d1, HIGH);
  digitalWrite(e1, HIGH);
  digitalWrite(f1, HIGH);
  digitalWrite(g1, HIGH);
  //below is 7seg2
  digitalWrite(a2, HIGH);
  digitalWrite(b2, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
}
void seg1Show0() {
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(e1, LOW);
  digitalWrite(f1, LOW);
}
void seg1Show1() {
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
}
void seg1Show2() {
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(e1, LOW);
  digitalWrite(g1, LOW);
}
void seg1Show3() {
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(g1, LOW);
}
void seg1Show4() {
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(f1, LOW);
  digitalWrite(g1, LOW);
}
void seg1Show5() {
  digitalWrite(a1, LOW);
  digitalWrite(f1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(g1, LOW);
}
void seg1Show6() {
  digitalWrite(a1, LOW);
  digitalWrite(e1, LOW);
  digitalWrite(f1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(g1, LOW);
}
void seg1Show7() {
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(f1, LOW);
}
void seg1Show8() {
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(e1, LOW);
  digitalWrite(f1, LOW);
  digitalWrite(g1, LOW);
}
void seg1Show9() {
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(f1, LOW);
  digitalWrite(g1, LOW);
}

void seg2Show0() {
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
}
void seg2Show1() {
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
}
void seg2Show2() {
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(g2, LOW);
}
void seg2Show3() {
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(g2, LOW);
}
void seg2Show4() {
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
}
void seg2Show5() {
  digitalWrite(a2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(g2, LOW);
}
void seg2Show6() {
  digitalWrite(a2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(g2, LOW);
}
void seg2Show7() {
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(f2, LOW);
}
void seg2Show8() {
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
}
void seg2Show9() {
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
}
