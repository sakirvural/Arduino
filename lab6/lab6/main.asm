setup:
	LDI R16, 0X00 //0000 0000 daki Register'ý R16'ya yükledim.
	OUT DDRD, R16 //R16 içindeki deðeri (0) PortD'ye atadým.
	LDI R16, 0xFF //1111 1111 deki Register'ý R16'ya yükledim.
	OUT DDRB, R16 //R16 içindeki deðeri (1) PortB'ye atadým.
LOOP:
	LDI R16, 0x00 //Register'ýn ilk deðerini (0) yaptým. (kapalý)
	OUT PORTB, R16 //PortB'nin de ilk deðerini (0) yaptým.
	LDI R21, 0x00 //R21'i de 0000 0000 yaptým.
	IN R23, PIND // D pinini giriþ pini olarak ayarladým.
	MOV R24, R23 //R23 içinde tutulan deðeri R24'e atadým.
	ANDI R24, 0x80 //R21'den input deðeri okuyup, R23 ve R24'e atadým.
				//R24 ile 1000 0000 (pin 7) sayýsýný ve iþlemine soktum.
	BREQ LOOP //Elde edilen sonuç 0 ise baþa dönmesini saðladým.
	
	LDI R16, 0x08 //1 ise 1000 0000 deðerini R16'ya yükledim.
	AND R16, R23 // R16 ile R23'ü aralarýnda ve iþlemine soktum.
	OR R21, R16 // R21 ile R16'yý aralarýnda veya iþlemine soktum.
	
	LDI R17, 0x10 // 0001 0000 deðerini R17'ye yükledim.
	AND R17, R23 // R17 ile R23'ü aralarýnda ve iþlemine soktum.
	OR R21, R17 // R21 ile R17'yi aralarýnda veya iþlemine soktum.

	LDI R18,0x20 // 0010 0000 deðerini R18'e yükledim.
	AND R18, R23 // R18 ile R23'ü aralarýnda ve iþlemine soktum.
	OR R21, R18 // R21 ile R18'i aralarýnda veya iþlemine soktum.

	LDI R19, 0x40 // 0100 0000 deðerini R19'a yükledim.
	AND R19, R23 // R19 ile R23'ü aralarýnda ve iþlemine soktum.
	OR R21, R19 // R21 ile R19'u aralarýnda veya iþlemine soktum.
//Burada yaptýðým iþlem: 7 numaralý pin 1 ise þimdiki deðeri bir
//öncekine atama iþlemi.
	RCALL to_Gray //to_Gray adlý alt fonksiyonu çaðýrdým.
	RJMP LOOP //Sonsuz döngü
to_Gray: // to_Gray isimli alt fonksiyon.
	MOV R22, R21 //R21 içinde tutulan deðeri R22'ye atadým.

	LSR R21 //R21 içindeki deðeri 3 kere saða kaydýrarak
	LSR R21 //3 bit saða kaymasýný saðladým.
	LSR R21
	LSR R22 //R22'deki deðeri son bir kere saða kaydýrdým.
//Bu kaydýrma gary = num ^(num>>1) formülünden kaynaklanýyor.
	EOR R21, R22 // R21 ile R22'yi aralarýnda Xor iþlemine soktum.
//Burada gray koduna çevirme iþlemi tamamlanýyor.
	OUT PORTB, R21 // Bulduðumuz Gray kodu PortB'ye atadým.