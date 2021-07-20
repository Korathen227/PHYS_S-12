
const int f3 = 175;
const int cs = 277;
const int d = 294;
const int eb = 311;
const int e = 330;
const int f = 349;
const int fs = 370;
const int g = 391;
const int ab = 415;
const int a = 440;
const int bb = 466;
const int c5 = 523;
const int db5 = 554;
const int d5 = 587;
const int e5 = 659;
const int eb5 = 622;
const int f5 = 698;
const int g5 = 784;
const int a5 = 880;

const int q = 450;
const int h = q*2;
const int w = q*3;

int buzzerPin = 10;

void setup() {

}// not needed 

void loop() {
  buzz(d, q);
  buzz(g, q);
  buzz(bb, q);

  trill(eb);
  trill(g);
  trill(bb);
  buzz(d5, h-150);

  buzz(d5, q);

  trill(d);
  trill(fs);
  trill(a);
  buzz(c5, q+q/2 - 150);
  buzz(bb, q-q/2);
  buzz(a, q);

  trill(d);
  trill(f);
  trill(ab);
  buzz(bb, w-150);

  buzz(g, q);
  buzz(bb, q);
  buzz(d5, q);

  trill(bb);
  trill(d5);
  buzz(g5, h-100);
  buzz(g5, q/2);
  buzz(g5, q/2);

  trill(c5);
  trill(eb5);
  buzz(g5, q-100);
  buzz(a5, q);
  buzz(f5, q/2);
  buzz(eb5, q/2);

  trill(bb);
  trill(d);
  buzz(f5, w-100 + q);

  delay(q/2);

  buzz(a, q/2);
  buzz(d5, q/2);
  buzz(f5, q/2);

  trill(bb);
  trill(d5);
  buzz(a5, h-100);
  buzz(g5, q);

  trill(bb);
  trill(db5);
  buzz(f5, h-100);
  buzz(e5, q);

  trill(f);
  trill(a);
  trill(d5);
  buzz(g5, h - 150);
  buzz(f5, q);

  trill(f3);
  trill(d);
  trill(a);
  buzz(e5, h-150);
  buzz(d5, q);

  trill(d);
  trill(f);
  trill(a);
  buzz(c5, q-150);
  buzz(bb, q);
  buzz(c5, q);
  buzz(d5, q);
  buzz(c5, q);
  buzz(g, q);

  trill(d);
  trill(fs);
  buzz(a, w-100);
  
  delay(w);
}

void buzz(int note, int dur) {
  tone(buzzerPin, note, dur - 50);
  delay(dur);
}

void trill(int note) {
  tone(buzzerPin, note, 50);
  delay(50);
}
