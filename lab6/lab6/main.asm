setup:
	LDI R16, 0X00 //0000 0000 daki Register'� R16'ya y�kledim.
	OUT DDRD, R16 //R16 i�indeki de�eri (0) PortD'ye atad�m.
	LDI R16, 0xFF //1111 1111 deki Register'� R16'ya y�kledim.
	OUT DDRB, R16 //R16 i�indeki de�eri (1) PortB'ye atad�m.
LOOP:
	LDI R16, 0x00 //Register'�n ilk de�erini (0) yapt�m. (kapal�)
	OUT PORTB, R16 //PortB'nin de ilk de�erini (0) yapt�m.
	LDI R21, 0x00 //R21'i de 0000 0000 yapt�m.
	IN R23, PIND // D pinini giri� pini olarak ayarlad�m.
	MOV R24, R23 //R23 i�inde tutulan de�eri R24'e atad�m.
	ANDI R24, 0x80 //R21'den input de�eri okuyup, R23 ve R24'e atad�m.
				//R24 ile 1000 0000 (pin 7) say�s�n� ve i�lemine soktum.
	BREQ LOOP //Elde edilen sonu� 0 ise ba�a d�nmesini sa�lad�m.
	
	LDI R16, 0x08 //1 ise 1000 0000 de�erini R16'ya y�kledim.
	AND R16, R23 // R16 ile R23'� aralar�nda ve i�lemine soktum.
	OR R21, R16 // R21 ile R16'y� aralar�nda veya i�lemine soktum.
	
	LDI R17, 0x10 // 0001 0000 de�erini R17'ye y�kledim.
	AND R17, R23 // R17 ile R23'� aralar�nda ve i�lemine soktum.
	OR R21, R17 // R21 ile R17'yi aralar�nda veya i�lemine soktum.

	LDI R18,0x20 // 0010 0000 de�erini R18'e y�kledim.
	AND R18, R23 // R18 ile R23'� aralar�nda ve i�lemine soktum.
	OR R21, R18 // R21 ile R18'i aralar�nda veya i�lemine soktum.

	LDI R19, 0x40 // 0100 0000 de�erini R19'a y�kledim.
	AND R19, R23 // R19 ile R23'� aralar�nda ve i�lemine soktum.
	OR R21, R19 // R21 ile R19'u aralar�nda veya i�lemine soktum.
//Burada yapt���m i�lem: 7 numaral� pin 1 ise �imdiki de�eri bir
//�ncekine atama i�lemi.
	RCALL to_Gray //to_Gray adl� alt fonksiyonu �a��rd�m.
	RJMP LOOP //Sonsuz d�ng�
to_Gray: // to_Gray isimli alt fonksiyon.
	MOV R22, R21 //R21 i�inde tutulan de�eri R22'ye atad�m.

	LSR R21 //R21 i�indeki de�eri 3 kere sa�a kayd�rarak
	LSR R21 //3 bit sa�a kaymas�n� sa�lad�m.
	LSR R21
	LSR R22 //R22'deki de�eri son bir kere sa�a kayd�rd�m.
//Bu kayd�rma gary = num ^(num>>1) form�l�nden kaynaklan�yor.
	EOR R21, R22 // R21 ile R22'yi aralar�nda Xor i�lemine soktum.
//Burada gray koduna �evirme i�lemi tamamlan�yor.
	OUT PORTB, R21 // Buldu�umuz Gray kodu PortB'ye atad�m.