# Automat-Banknote

EN AZ SAYIDA BANKNOT PARA VERME PROBLEMI

Bu readme.txt dosyası, En Az Sayıda Banknot Para Problemi projesine aittir.
Bu paket, kaynak kodu ile aynı dizin içerisinde bulunacaktır.


ORTAM:
-------------------
Tiva-C-Series-TM4C123G çalıştırılabilecek ortam. 
Energia kullanıldı.
https://energia.nu
-------------------

PROJEYİ ÇALIŞTIRMA:
-------------------
Proje paket içeriğini yukarıda görebilirsiniz.

Bu kod, kurulu energia üzerinden çalıştırıldı.

Kart ve devreniz hazırlanıp bilgisayara bağlandıktan sonnra bilgisayarınızda kurulu energia üzerinden kodu Kopyala-Yapıştır yaparsanız hatasız bir şekilde çalışacaktır.

Kod, herhangi bir hata vermeksizin, daha önceden
belirlenen kriterlere uygun çalıştı.
-------------------
KODU DERLEME:
------------------
Bilgisayarımızda kurulu olan energia ile kodu kolayca derleyebiliriz.

Projeyi geliştirim kartında çalıştırmak için kodu daha önceden oluşturulmuş Tiva C
projesinde yer alan "main.c"ye yapıştırıp build butonuna tıkladıktan sonra debug 
butonuna tıklamanız yeterli.

Kart ile işlem yapmadan önce açılı olan energia ekranından Araçlar\Kart\Launchpad Tiva C w/tm4c123 seçimi yapmalısınız.
------------------

PARAMETRELER
---------------------------
Kodun çalışması <LiquidCrystal.h> kütüphanesinin energia.exe de ekli olması gerekiyor.
---------------------------

PROGRAMIN KULLANIMI
-----------------------------
En Az Sayıda Banknot Para Problemi projesi, program içersinde ürün ile ilgili olan ad bilgisi, stok sayısı ve fiyat bilgisi tanımlanmıştır.
Daha sonra butonlar yardımı ile 5 TL, 10 TL, 20 TL, 50 TL, 100 TL para miktarı girdisi alınır, bitiş butonuna basılınca para girme işlemi bitirilir.
Para girme işleminden sonra hizmet seçim işlemi yapılacaktır butonlara gore hangi hizmetin seçileceği belirlenecektir. 
Kullanıcı yanlış seçim yaptığında Reset butonuna basabilir. Aksi taktirde otomat, kasada bulunan banknotlardan en azını kullanarak kullanıcıya banknot para üstü
verecektir.Kasada yeterli para olmaması durumunda LCD ekranda "Kasada yeterli para yoktur" uyarısı görünecektir.

Tüm bu işlemlerden sonra 1-4 (1 ve 4 dahil) arasında random sayı üretilecektir. Eğer  random sayı 2 olursa para sıkışma durumu olacaktır. Para sıkışma işleminde kırmızı led 
yanacaktır, aksi durumda (random üretilen sayı 2 ye eşit değilse) problem olmadığını 
belirten yeşil led yanacaktır. Para sıkışma durumunda kullanıcıya para iadesi yapılacak ve 
tuşlanan hizmetler kalan hizmet miktarından düşmeyecektir. Tüm bu kontrollerden sonra 
Reset butonuna basılacaktır.
