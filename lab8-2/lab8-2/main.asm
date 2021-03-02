		cli; Program baþlangýcý
     	
	//TCCR1B|=(1<<WGM12); CTC mode
    	ldi	r30, 0x81	; r30 129 deðer atar
     	ldi	r31, 0x00	; r31 0 deðer atadým
     	ld	r24, Z
       ori	r24, 0x08	; r24 8 atadým
       st	Z, r24
	//TCCR1B|=(1<<CS12);Timer 1 için Fcpu/256
       ld	r24, Z
      	ori	r24, 0x04	; r24  4 atadým
       st	Z, r24
     //bu kýsýmda sayýlabilecek maksimum deðer taþma bayraðý
	//OCR1A=49911;
      	ldi	r24, 0x24	; r24 36 atsam
    	ldi	r25, 0xF4	; r25  244 deðer atadým
     	sts	0x0089, r25	; 
    	sts	0x0088, r24	; 
	
//TIMSK1 |= (1 << OCIE1A); taþma kontrol
      	ldi	r30, 0x6F	
       ldi	r31, 0x00	
       ld	r24, Z
       ori	r24, 0x02	
       st	Z, r24
       sei
       ldi	r24, 0x00	
      	ldi	r25, 0x00	
       ret

//ISR(TIMER1_COMPA_vect) interput oluþmasý durumunda çalýþacak blok (her 1 saniyede)
    	push	r1
      	push	r0
     	in	r0, 0x3f	;r0  63 deðer attým
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
 	sbiw	r24, 0x3c	; r24 6 deger attým
       cpc	r26, r17
	cpc	r27, r19
	brne 34     	
	
       //her 60 saniyede bir dakika arttýrdým
	lds	r24, 0x0102	; 
	lds	r25, 0x0103	; 
  	adiw	r24, 0x01	
 	sts	0x0103, r25	; 
 	sts	0x0102, r24	; 0x800102 <d>
	
      //saniye=0; her dakikada saniye sýfýrlama
 	sts	0x0104, r1	;
	sts	0x0105, r1	; 
	sts	0x0106, r1	; 
 	sts	0x0107, r1	;
	
	//if (d==60) dakika 60 olursa durumunda saat gösterimi
 	lds	r24, 0x0102	; 
 	lds	r25, 0x0103	; 
	sbiw	r24, 0x3c	;
	brne	26     	; 

	//her dakika bir saat 1 arttýrdm
	lds	r24, 0x0100	; 
 	lds	r25, 0x0101	; 
	adiw	r24, 0x01	; 
	sts	0x0101, r25	; 
	sts	0x0100, r24	; 

	//d=0;her yeni saatte dakika sýfýrla
    sts	0x0103, r1	; 
	sts	0x0102, r1	; 
	
//	if (s==24) saat 24 olduðu durumda gün gösterimi
	lds	r24, 0x0100	; 
	lds	r25, 0x0101	;
    	sbiw	r24, 0x18	; 
    	
	//g++; her 24 saatte bir gün 1 arttýrdým
	lds	r24, 0x0110	; 
	lds	r25, 0x0111	; 
	adiw	r24, 0x01	; 
	sts	0x0111, r25	; 
	sts	0x0110, r24	; 
	//s=0;her yeni günde saat 0lama
	sts	0x0101, r1	; 
 	sts	0x0100, r1	; 
	
	//printf("Zaman: ");// geçen zaman ekrana yazdýrma
  	ldi	r24, 0x08	; 8 deðer atadým
	ldi	r25, 0x01	; 1 deðer atadým
  	push	r25
    push	r24
	call	0x242	; 
	//printf(g);geçen zaman ekrana yazdýrma
	lds	r24, 0x0111	; 
  	push	r24
	lds	r24, 0x0110	; 
	push	r24
	call	0x242	; 
	//ekranda yazdýrmalar arasýnda boþluk
   	ldi	r24, 0x20	; 32 deðer ata
   	ldi	r25, 0x00	; 0 deðer ata
 	call	0x26e	; 
	//geçen saati ekran yazdýrma
	lds	r24, 0x0101	; 
 	push	r24
	lds	r24, 0x0100	; 
       push	r24
       call	0x242	; 
	//dakikadan sonra : iþareti
  	ldi	r24, 0x3A	; 58 deðer
  	ldi	r25, 0x00	; r25 3 0 deðer attým
 	call	0x26e	; 
	//geçen dakika  deðeri interput baðlý
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
	//geçen saniyee deðerini interput baðlý olarak arttýrdým
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
		//burdan sonraki kýsýmda registerlarý tamizledim
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
