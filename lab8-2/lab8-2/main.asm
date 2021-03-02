		cli; Program ba�lang�c�
     	
	//TCCR1B|=(1<<WGM12); CTC mode
    	ldi	r30, 0x81	; r30 129 de�er atar
     	ldi	r31, 0x00	; r31 0 de�er atad�m
     	ld	r24, Z
       ori	r24, 0x08	; r24 8 atad�m
       st	Z, r24
	//TCCR1B|=(1<<CS12);Timer 1 i�in Fcpu/256
       ld	r24, Z
      	ori	r24, 0x04	; r24  4 atad�m
       st	Z, r24
     //bu k�s�mda say�labilecek maksimum de�er ta�ma bayra��
	//OCR1A=49911;
      	ldi	r24, 0x24	; r24 36 atsam
    	ldi	r25, 0xF4	; r25  244 de�er atad�m
     	sts	0x0089, r25	; 
    	sts	0x0088, r24	; 
	
//TIMSK1 |= (1 << OCIE1A); ta�ma kontrol
      	ldi	r30, 0x6F	
       ldi	r31, 0x00	
       ld	r24, Z
       ori	r24, 0x02	
       st	Z, r24
       sei
       ldi	r24, 0x00	
      	ldi	r25, 0x00	
       ret

//ISR(TIMER1_COMPA_vect) interput olu�mas� durumunda �al��acak blok (her 1 saniyede)
    	push	r1
      	push	r0
     	in	r0, 0x3f	;r0  63 de�er att�m
    	push	r0
      	eor	r1, r1
       push	r18
       push	r19
      	push	r20
       push	r21
       push	r22
       push	r23
      	push	r24
       push	r25
      	push	r26
      	push	r27
      	push	r30
       push	r31
	//if (saniye==60)
	lds	r24, 0x0104	; 
 	lds	r25, 0x0105	; 
	lds	r26, 0x0106	; 
 	lds	r27, 0x0107	; 
 	sbiw	r24, 0x3c	; r24 6 deger att�m
       cpc	r26, r17
	cpc	r27, r19
	brne 34     	
	
       //her 60 saniyede bir dakika artt�rd�m
	lds	r24, 0x0102	; 
	lds	r25, 0x0103	; 
  	adiw	r24, 0x01	
 	sts	0x0103, r25	; 
 	sts	0x0102, r24	; 0x800102 <d>
	
      //saniye=0; her dakikada saniye s�f�rlama
 	sts	0x0104, r1	;
	sts	0x0105, r1	; 
	sts	0x0106, r1	; 
 	sts	0x0107, r1	;
	
	//if (d==60) dakika 60 olursa durumunda saat g�sterimi
 	lds	r24, 0x0102	; 
 	lds	r25, 0x0103	; 
	sbiw	r24, 0x3c	;
	brne	26     	; 

	//her dakika bir saat 1 artt�rdm
	lds	r24, 0x0100	; 
 	lds	r25, 0x0101	; 
	adiw	r24, 0x01	; 
	sts	0x0101, r25	; 
	sts	0x0100, r24	; 

	//d=0;her yeni saatte dakika s�f�rla
    sts	0x0103, r1	; 
	sts	0x0102, r1	; 
	
//	if (s==24) saat 24 oldu�u durumda g�n g�sterimi
	lds	r24, 0x0100	; 
	lds	r25, 0x0101	;
    	sbiw	r24, 0x18	; 
    	
	//g++; her 24 saatte bir g�n 1 artt�rd�m
	lds	r24, 0x0110	; 
	lds	r25, 0x0111	; 
	adiw	r24, 0x01	; 
	sts	0x0111, r25	; 
	sts	0x0110, r24	; 
	//s=0;her yeni g�nde saat 0lama
	sts	0x0101, r1	; 
 	sts	0x0100, r1	; 
	
	//printf("Zaman: ");// ge�en zaman ekrana yazd�rma
  	ldi	r24, 0x08	; 8 de�er atad�m
	ldi	r25, 0x01	; 1 de�er atad�m
  	push	r25
    push	r24
	call	0x242	; 
	//printf(g);ge�en zaman ekrana yazd�rma
	lds	r24, 0x0111	; 
  	push	r24
	lds	r24, 0x0110	; 
	push	r24
	call	0x242	; 
	//ekranda yazd�rmalar aras�nda bo�luk
   	ldi	r24, 0x20	; 32 de�er ata
   	ldi	r25, 0x00	; 0 de�er ata
 	call	0x26e	; 
	//ge�en saati ekran yazd�rma
	lds	r24, 0x0101	; 
 	push	r24
	lds	r24, 0x0100	; 
       push	r24
       call	0x242	; 
	//dakikadan sonra : i�areti
  	ldi	r24, 0x3A	; 58 de�er
  	ldi	r25, 0x00	; r25 3 0 de�er att�m
 	call	0x26e	; 
	//ge�en dakika  de�eri interput ba�l�
	lds	r24, 0x0103	;
       push	r24
 	lds	r24, 0x0102	; 
  	push	r24
	call	0x242	;
	//printf(":"); dakikadan sonra
   	ldi	r24, 0x3A	; 58
   	ldi	r25, 0x00	; 0
	call	0x26e	; 
	//printf(saniye);
	lds	r24, 0x0104	; 
	lds	r25, 0x0105	; 
	lds	r26, 0x0106	; 
 	lds	r27, 0x0107	; 
  	push	r25
     push	r24
	call	0x242	; 
	//ge�en saniyee de�erini interput ba�l� olarak artt�rd�m
	lds	r24, 0x0104	; 
 	lds	r25, 0x0105	; 
 	lds	r26, 0x0106	; 
 	lds	r27, 0x0107	; 
    adiw	r24, 0x01	; 1
   	adc	r26, r1
    adc	r27, r1
	sts	0x0104, r24	; 
 	sts	0x0105, r25	; 
	sts	0x0106, r26	; 
	sts	0x0107, r27	; 
	in	r24, 0x3d	; 61
    in	r25, 0x3e	; 62
      	adiw	r24, 0x0a	; 10
      	in	r0, 0x3f	; 63
     	cli
     	out	0x3e, r25	; 62
       	out	0x3f, r0	; 63
		//burdan sonraki k�s�mda registerlar� tamizledim
     	pop	r31
      	pop	r30
       	pop	r27
     	pop	r26
      	pop	r25
       	pop	r24
     	pop	r23
       	pop	r22
   	pop	r21
     	pop	r20
      	pop	r19
    	pop	r18
   	pop	r0
    	out	0x3f, r0	; 63
       	pop	r0
  	pop	r1
    	reti
