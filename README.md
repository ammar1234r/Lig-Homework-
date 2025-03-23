# Lig Homework 
Futbol Ligi Simülasyonu

 Giriş
Bu proje, rastgele takımlar seçerek ve maç sonuçlarını kaydederek bir futbol ligi simüle etmeyi amaçlamaktadır. Her takımın performansı takip edilir ve sezon sonunda puan durumu oluşturulur.

Program Nasıl Çalışır?
1. **Takım Verileri Okunur:** `takimlar` adlı dosyadan takım isimleri okunur.
2. **Takımlar Oluşturulur:** Her takım için bir nesne (`clsFootBall_teams`) oluşturulur ve istatistikler (galibiyet, mağlubiyet, atılan goller vb.) saklanır.
3. **Maç Eşleşmeleri Belirlenir:**  
   - `Selecting_Team` fonksiyonu, her hafta rastgele maçları belirler.  
   - Bir takımın aynı rakiple iki kez karşılaşmaması için `vector` kullanılır.  
   - Eğer bir takım aynı sezonda 18 kez ev sahibi olmuşsa veya bir rakiple ikinci kez oynuyorsa, tekrar seçim yapılır.  
4. **Maç Sonuçları Belirlenir:**  
   - `Reffer` (hakem) fonksiyonu rastgele goller belirler.  
   - Kazanan, kaybeden ve puanlar güncellenir.  
5. **Sonuçlar Kaydedilir:**  
   - `SaveResult` fonksiyonu ile her hafta oynanan maçlar kaydedilir.  
   - `SaveResultInFile` fonksiyonu ile sezon sonunda fikstür ve puan durumu dosyaya yazdırılır.  
