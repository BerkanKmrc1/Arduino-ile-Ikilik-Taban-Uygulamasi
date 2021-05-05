
const int buttonPin = 2; //Buton pinini 2 olarak ayarladım
int buttonState=0; //buton pininden okuyacağım değeri tanımladım ve 0 atadım  
int diziBoyutu=4;//oluşturacağım dizilerin boyutu
void ikiliktabanacevirme(int,int);//ikiliktabanacevirme fonksiyonununun prototipi
int sayilaritutandizi[4];//rastgele oluşturduğum 1 ila 15 arasındaki 4 sayiyi tuttuğum dizi
int mainicindekiikiligitutandizi[4][4];//tuttuğum rastgele 4 sayiyi ikilige cevirdikten sonra oluşan değerleri içine atacağım dizi
int maks;//maksimum değişkeni
int minn;//minimum değişkeni
int maksminfark;//maksimum ile minimum arasındaki farkı tuttuğum değişken
int minimumubul(int[],int,int&,int&);//minimumubul fonksiyonunun prototipi
int maksimumubul(int[],int,int&,int&);//maksimumunubul fonksiyonunun prototipi
int maksminfarkinitutandizi[1];//maksimum ile minimum farkini bulduktan sonra onu tutacağım dizi
int maksminfarkiniikiliktutandizi[1][4];//maksimum ile minimum farkini ikilik olarak tutacağım dizi



void setup() {//setup tanımı
  randomSeed(analogRead(A0));//Her iterasyonda farklı sayılar üretilmesi için tanımladım.
  pinMode(buttonPin, INPUT); //Buton pinini 2 olarak ayarladım
  Serial.begin(9600);//seri ekranda değerleri görmek için
 //pinmode la giriş çıkış pinlerini ayarladım
    pinMode(3,OUTPUT);
    
    pinMode(4,OUTPUT);
    
    pinMode(5,OUTPUT);
    
    pinMode(6,OUTPUT);

    
    pinMode(7,INPUT);
    
    pinMode(8,INPUT);
    
    pinMode(9,INPUT);
    
    pinMode(10,INPUT);

    pinMode(11,OUTPUT);

    pinMode(12,OUTPUT);
 
}
 
void loop() {//loop u tanımladım
//oyun başlamadan önce bütün pinleri södürdüm
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  
  buttonState = digitalRead(buttonPin); //buttonpinden değeri okudum 
  delay(200);//butonpininde temassızlık olmaması için delay ekledim
 
  
  if (buttonState == HIGH) //eğer buttonpininden okuduğum değer hıgh ise
  {
    Serial.println("Sayilarin onluk tabanda ki karşılıkları ");//seri ekranda düzenli bir biçimde yazılması için serialprint komutlarıyla düzeltmeler yaptım
      
    for(int i=0;i<=3;i++)//Rastgele sayilari üretmek için bir for döngüsü tanımladım 
     {
       sayilaritutandizi[i]=random(1,16);//0 dan 3 e her oluşturduğum sayiyi sayilaritutandizi adındaki bir dizide sakladım
         
       Serial.print(sayilaritutandizi[i]); //bu dizi elemanlarını seri port ekranında yazdırdım
       Serial.print("---------");//altına kesik çizgiler ekledim düzenli olması açısından
       
     }
      Serial.println("");//seri ekranda düzenleme
      Serial.println(" ");//seri ekranda düzenleme
      minn=minimumubul(sayilaritutandizi,4,minn);//minimumubul adlı fonksiyona rastgele 4 sayıyı tuttuğum diziyi,diziboyutunu ve minn değişkenini gönderdim
      maks=maksimumubul(sayilaritutandizi,4,maks);//maksimumubul adlı fonksiyona rastgele 4 sayıyı tuttuğum diziyi,diziboyutunu ve maks değişkenini gönderdim 
      maksminfark=maks-minn;//Fonksiyonlara gönderdikten sonra bulduğum maks ve min değerlerini birbirinden çıkararak maksminfar adlı değikene atadım
      Serial.print("Maksimum ile minimum farkı = ");//seri ekranda düzenleme
      Serial.println(maksminfark);//maksminfarkını seri ekranda yazdırdım
      Serial.println("");//seri ekranda düzenleme
      Serial.println("Sayilarin ikilik karsiliklari ");//seri ekranda düzenleme
      ikiliktabanacevirme(sayilaritutandizi,mainicindekiikiligitutandizi);//ikiliktabana cevirme fonksiyonuna rastgele sayıları tuttuğum diziyi ve bu sayiların ikilik karşılıklarını tutacağım iki boyutlu diziyi gönderdim
      Serial.println("");//seri ekranda düzenleme
      Serial.println("");//seri ekranda düzenleme
      Serial.println("Farkin ikilik karsiligi ");//seri ekranda düzenleme
      maksminfarkinitutandizi[0]={maksminfark};//maksminfarkını,tuttuğum maksminfarkinitutandizisinin ilk elamanına atadım.
  
      ikiliktabanacevirmemaksminicin(maksminfarkinitutandizi,maksminfarkiniikiliktutandizi);//maks ve min farki için tuttuğum ikiliktabanacevirmemaksmin dizisine maksminfarkinitutandizi ve maksminfarkiniikiliktutandizi değişenlerini gönderdim 
      Serial.println("");//seri ekranda düzenleme

      for(int i=0;i<=3;i++)//iki boyutlu dizimde satırları gezmesi için bir for tanımladım
      {
        for(int j=0;j<=3;j++)//iki boyutlu dizimde sütunları gezmesi için bir for tanımladım
        {
          if(mainicindekiikiligitutandizi[i][j]==1)//gezdiğim satır ve sütünun her bi iterasyonunu kontrol ettim eğer 1 ise
          {
            digitalWrite(j+3,HIGH);//hangi iterasyondaysam 3 fazlasını yani 0 sa 3 numaralı 1 se 4 numaralı ledi yaktım
          }
          else//değilse
            digitalWrite(j+3,LOW);//hangi iterasyondaysam 3 fazlasını yani 0 sa 3 numaralı 1 se  numaralı ledi söndürdüm
        }
        delay(5000);//bu döngü 4 sayı içinde tekrarlanıcak ve her bir kombinasyon 5 saniye yanık kalıcak
      }
        //5 er saniye kombinasyonlardon sonra her bir led sönücek
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW); 
        delay(1000);//bir saniye süresince sönücek ledler
      

    //maksmin farkını ikilik şekilte tutan dizinin 0.satır 0. sütünundan 3.satır 3.sütununa kadar dipswitchden okunan değerler karşılaştırılıcak 
    if(maksminfarkiniikiliktutandizi[0][0]==digitalRead(7) && maksminfarkiniikiliktutandizi[0][1]==digitalRead(8) && maksminfarkiniikiliktutandizi[0][2]==digitalRead(9) && maksminfarkiniikiliktutandizi[0][3]==digitalRead(10))  
      {//eğer şart sağlanırsa
        digitalWrite(11,HIGH);//11 numaralı dijital pine bağlı yeşil led yanıcak
        digitalWrite(12,LOW);//12 numaralı dijital pine bağlı kırmızı led sönücek
        delay(1000);//1 saniye boyunca
      }
    else
      {//eğer şart sağlanmazsa
        digitalWrite(11,LOW);//11 numaralı dijital pine bağlı yeşil led sönücek
        digitalWrite(12,HIGH);//12 numaralı dijital pine bağlı kırmızı led yanıcak
        delay(1000);//1 saniye boyunca
      }
      //en son bu işlemerden sonra her iki led de söndürülecek
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      
         for(int i=0;i<=0;i++)//switchden kullanıcının girdiği değer kontrol etmek için seri ekranda yazdırdığım for döngüsü tek satırlı olduğu için satırı bir kere dolaşıcak
         {
          Serial.println(" ");//seri ekranda düzenleme
          Serial.print("Switchden Girilen Deger -->");//seri ekranda düzenleme
           for(int j=7;j<=10;j++)//sütunda 4 sutunlu olduğu için 7 den 10a 4 kere dolaşıcak
            {
              Serial.print(digitalRead(j));//ve ekrana yazıcak
              Serial.print(" ");//seri ekranda düzenleme
            }
        Serial.print(" ");//seri ekranda düzenleme
         }
      buttonState=LOW;//en son butona tekrar bastığımızda oyunun başlaması için butonu low durumuna getirdim
   }
    
   
  }
//ikilik tabana cevirme fonksionu
void ikiliktabanacevirme(int sayilaritutandizi[4],int mainicindekiikiligitutandizi[4][4])//sayilaritutandizi ve mainicindekiikiligitutandizi(ikiboyutlu)olmak üzere iki parametre alcak
{
  for(int i=0;i<=3;i++)//satırları dolaşan for
  {
    for(int j=0;j<=3;j++)//sütunları dolaşan for
    
     {
      mainicindekiikiligitutandizi[i][j]=0;//ilgili iterasyonun satır ve sütununa 0 değerini atıyorum önceden içinde bi değer kalmışsa temizlemek için
     }
  }
     for(int i=0;i<=3;i++)//satirlari dolaşıyorum
     {
      int j=3;//j yi 3 yapıcam çünkü en anlamsız bite yani en sağdaki bite ilk ikiye bölmeden kalanı atmak için
     while(sayilaritutandizi[i]>=1)//rastgele sayilari tek tek kontrol ediyorum 1e eşit veya büyükse gircek döngüye
     {
      mainicindekiikiligitutandizi[i][j]=sayilaritutandizi[i]%2;//o anki rastgele sayinin 2 ye bölümünden kalani sayiların ikiliğini tutan iki boyutlu dizinin o anki satır ve sütununun içine atıcak
      sayilaritutandizi[i]=sayilaritutandizi[i]/2;//ve sayiyi 2 ye bölücek sayı 1 den küçük olana kadar
      j--;//j yi azaltıcak yani bir sonraki iterasyonda en anlamsız bitten en anlamlı bite doğru ikiliği yazmak için
     }
     }
   for(int i=0;i<=3;i++)//Burdaki for da ekrana ikiliği yazmak için satırları dolaştığım for
   {
    for(int j=0;j<=3;j++)//sütunları dolaştığım for
    {
      Serial.print(mainicindekiikiligitutandizi[i][j]);//ekrana ikili yazıcak sırayla her bitini
      Serial.print(" ");//aralarında boşluk bırakıcak
    }
        Serial.print(" ");//ikilik kombinasyonların aralarındada boşluk bırakıcak
   }
      

}
//minimumubul fonksiyonu
int minimumubul(int b[],int dizininBoyutu,int &minimum)//kendisine diziyi,dizininboyutunu ve bir minimum değişkeni(referans) parametre olarak alıcak
{
  minimum=b[0];//dizinin ilk elemanını minimum olarak kabul edicek
  for(int i=1;i<dizininBoyutu;i++)//diziyi dolaşıcak
  {
    if(b[i]<minimum)//minimumdan daha düşük bi değer bulduğunda
    {
      minimum=b[i];//minimumum değerini bu değer ile değiştiricek
    }

  }
  return minimum;//minimumu geriye döndürcek
}
//maksimumubul fonksiyonu
int maksimumubul(int b[],int dizininBoyutu,int &maksimum)//kendisine diziyi,dizininboyutunu ve bir maksimum değişkeni(referans) parametre olarak alıcak
{
  
  maksimum=b[0];//dizinin ilk elamanını maksimum olarak kabul edicek
  for(int i=1;i<dizininBoyutu;i++)//diziyi dolaşıcak
  {
   
    if(b[i]>maksimum)//maksimumdan daha büyük bi eleman varsa
    {
      maksimum=b[i];//o elemanı maksimum değeriyle değiştiricek
    }
  }
  return maksimum;//geriye maksimum değerini döndürcek
}
//maks ile min farkını ikiliğe çevirmek için ayrı bir fonksiyon tanımladım karışmaması için
void ikiliktabanacevirmemaksminicin(int sayilaritutandizi[1],int mainicindekiikiligitutandizi[1][4])//fonksiyonun parametrelerini tanımladım
{
  for(int i=0;i<=0;i++)//1 satırlı olduğu için bir satır dolaşcak sadece
  {
    for(int j=0;j<=3;j++)//3 sütunlu olduğu için 3 sütun dolaşcak
    
     {
      mainicindekiikiligitutandizi[i][j]=0;//her bir sütuna 0 değerini vericek önceden içinde değer kalmışsa sıfırlamak için
     }
  }
     for(int i=0;i<=0;i++)//yine aynı şekilde bir satır dolaşıcak
     {
      int j=3;//j yi üç yapıyorum ki en anlamsız bitine ilk 2 ye bölümden kalanı atsın diye
     while(sayilaritutandizi[i]>=1)//sayı 1e eşit veya daha küçükse
     {
      mainicindekiikiligitutandizi[i][j]=sayilaritutandizi[i]%2;//2 ye bölümünden kalanı ilgili iterasyona at
      sayilaritutandizi[i]=sayilaritutandizi[i]/2;//2 ye bidaha böl sayı 1den küçük olana kadar
      j--;//j yi azaltıyoruz çünkü en anlamsızdan en anlamlıya doğru bit değerlerini oluştursun
     }
     }
   for(int i=0;i<=0;i++)//yine aynı şekilde farkı ekrana yazdırmak için bir for tanımladım 1 satır dolaşıcak sadeece
   {
    for(int j=0;j<=3;j++)//sütunları dolaşıcak toplamda 3 sütun 
    {
      Serial.print(mainicindekiikiligitutandizi[i][j]);//ilgili satır ve sütunu ekrana yazıcak
      Serial.print(" ");//bit değerleri arasına boşluk bırakıcak
    }
        Serial.print(" ");//bit kombinasyonları arasına boşluk bırakıcak
   }
      

}
     
