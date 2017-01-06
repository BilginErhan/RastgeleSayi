int buton_durumu;//bouncing probleminin önüne geçmek için
//buton durumunu tutan değişken 
int sayi[6];//rastgele üretilen sayıları tutan dizi
void rastgele_sayi_uret();//fonksiyonların prototipleri belirlenir
void ledleri_yak();
void ledleri_sondur();
void setup() {
  randomSeed(analogRead(A0));//random değeri için çekirdek değeri okunur
  pinMode(A3,INPUT);//buton A3 de input için kullanılması için tanımlanır
  pinMode(8,OUTPUT);//8,9,10,11,12,13 digital pinleri
  pinMode(9,OUTPUT);//output olarak kullanılması için tanımlanır
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
 
 buton_durumu = analogRead(3);//buton durumu okunur
 if (buton_durumu==1023)//eğer 1023 e eşit ise 
 {//ledleri_sondur fonksiyonuna daha sonra
  //rastgele sayı üret fonksiyonuna gider
  ledleri_sondur();
  rastgele_sayi_uret();
 }
 else//eğer 1023 e eşit değilse
 {//rastgele üretettiği sayı var ise ledleri yakar
  //eğer program ilk çalışmaya başladı ise ledlerin 
  //hiçbirini yakmaz
  ledleri_yak();
 }
}
void rastgele_sayi_uret()
{//rastele sayı üret fonksiyonumuz
  for (int i=0;i<6;i++)
  {//for içinde sayi dizisinin
    //i ninci değerine rastgele
    //sayı üretip atama yapar.
    sayi[i]=random(0,2);
  }
}
void ledleri_yak()
{//ledleri yak fonksiyonumuz
  for (int i=0;i<6;i++)
  {//for için de eğer üretilen sayılarımızdan
    //sayi dizisinin i ninci değişkeni
    //1 ise i+8 inci ledi yakar
    //yani [8-13] arasındaki ledleri yakar
    if (sayi[i]==1)
    {
      digitalWrite(i+8,HIGH);
    }
    else//veya söndürür.
    {
      digitalWrite(i+8,LOW);
    }
  }
}
void ledleri_sondur()
{//ledleri söndür fonksiyonumuz
  for (int i=0;i<6;i++)
  {//tüm ledleri butona basıldığı zaman
    //söndürür
    digitalWrite(i+8,LOW);
  }
}

