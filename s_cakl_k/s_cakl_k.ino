float sicaklik;               
int deger;            
float volt;      

void setup () {
  Serial.begin(9600);  
}


void loop () {
 deger = analogRead(A1);      
 volt = (5000/1023)*deger; 
 sicaklik =volt /10.0;               

 Serial.print("Sıcaklik degeri: ");
 Serial.print (sicaklik);
 Serial.println (" derece");
 delay (1000);                          
}
