PENDAHULUAN:
Program ini dirancang untuk mengendalikan pemutaran file audio MP3 menggunakan sensor gerak (PIR) dan modul DFPlayer Mini.
Sensor gerak digunakan untuk mendeteksi gerakan, dan DFPlayer Mini bertanggung jawab atas pemutaran file MP3.

1. Library yang Digunakan
Program menggunakan library DFPlayerMini untuk berkomunikasi dengan modul DFPlayer Mini.

2. Pengaturan Pin dan Komunikasi Serial
Sensor PIR terhubung ke pin 5.
Komunikasi serial menggunakan software serial pada pin 16 (RX) dan 17 (TX).

3. Fungsi Setup
Dilakukan inisialisasi awal, termasuk konfigurasi serial, pin, dan komunikasi dengan DFPlayer Mini.
Inisialisasi DFPlayer Mini dilakukan dengan pemeriksaan koneksi dan memulai komunikasi.
Volume pemutaran MP3 diatur pada nilai 30 (dari rentang 0 hingga 30).
Output audio diarahkan ke kartu SD, dan equalizer diatur ke mode normal.
Program dimulai dengan memainkan file MP3 pertama sebagai tanda bahwa alat telah dimulai.

4. Fungsi Loop
Berisi logika utama program yang berjalan secara berulang.
Sensor gerak dibaca, dan jika gerakan terdeteksi, file MP3 pertama diputar.
Program menunggu hingga sensor kembali ke kondisi LOW sebelum melanjutkan.
Pesan debugging ditampilkan di monitor serial Arduino IDE.

5. Pesan Debugging
Serial.println() digunakan untuk memberikan informasi debugging.
Pesan "Gerakan terdeteksi!" akan muncul jika gerakan terdeteksi, dan pesan "....." akan muncul jika tidak ada gerakan.

6. Penundaan (Delay)
Beberapa delay digunakan untuk memberikan waktu tertentu antara aksi tertentu.
Misalnya, terdapat penundaan 5 detik setelah memulai alat dan penundaan 200 milidetik saat tidak ada gerakan.

CATATAN : 
Pastikan telah memasang library DFPlayer Mini pada Arduino IDE sebelum mengunggah program ke perangkat.
Sesuaikan pin dan konfigurasi hardware sesuai dengan kebutuhan proyek.
