
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}
void curto() {
  digitalWrite(8, HIGH);  
  delay(1000);                      
  digitalWrite(8, LOW);   
  delay(1000);
}

void longo() {
  digitalWrite(9, HIGH);  
  delay(3000);                      
  digitalWrite(9, LOW);   
  delay(1000);
}
void siletras() {               
  digitalWrite(10, HIGH);  
  delay(3000);
  digitalWrite(10,LOW);
}
void sipalavras() {
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
  digitalWrite(10, HIGH);  
  delay(250);
  digitalWrite(10, LOW);
  delay(250);
}
void repetir() {
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(7000);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);  
}

void loop() {
  repetir();
  char frase[] = "buon anno";
  int t = strlen(frase);
  for (int i = 0; i < t; i++) {
    if (frase[i] == 'a') {
      curto();
      longo();
      siletras();
    }
    else if (frase[i] == 'b') {
      longo();
      curto();
      curto();
      curto();
      siletras();
    }
    else if (frase[i] == 'c') {
      longo();
      curto();
      longo();
      curto();
      siletras();
    }
    else if(frase[i] == 'd'){
      longo();
      curto();
      curto();
      siletras();
    }
    else if(frase[i] == 'e'){
      curto();
      siletras();
}
    else if(frase[i] == 'f'){
      curto();
      curto();
      longo();
      curto();
      siletras();
  }
    else if(frase[i] == 'g'){
      longo();
      longo();
      curto();  
      siletras();
  }
  else if(frase[i] == 'h'){
      curto();
      curto();
      curto();  
      curto();
      siletras();
 }
   else if(frase[i] == 'i'){
      curto();
      curto();  
      siletras();
  }
   else if(frase[i] == 'j'){
      curto();  
      longo();
      longo();
      longo();
      siletras();
  }
   else if(frase[i] == 'k'){
      longo();
      curto();
      longo();  
      siletras();
  }
   else if(frase[i] == 'l'){
      curto();
      longo();
      curto();
      curto();  
      siletras();
  }
   else if(frase[i] == 'm'){
      longo();
      longo();  
      siletras();
  }
   else if(frase[i] == 'n'){
      longo();
      curto();  
      siletras();
  }
   else if(frase[i] == 'o'){
      longo();
      longo();
      longo();  
      siletras();
  }
   else if(frase[i] == 'p'){
      curto();
      longo();
      longo();
      curto();  
      siletras();
  }c:\Users\mario\Documents\Arduino\morse\morse.ino
   else if(frase[i] == 'q'){
      longo();
      longo();
      curto();
      longo();  
      siletras();
  }
   else if(frase[i] == 'r'){
      curto();
      longo();
      curto();  
      siletras();
  }
   else if(frase[i] == 's'){
      curto();
      curto();
      curto();  
      siletras();
  }
   else if(frase[i] == 't'){
      longo();
      siletras();
  }
   else if(frase[i] == 'u'){
      curto();
      curto();  
      longo();
      siletras();
  }
   else if(frase[i] == 'v'){
      curto();
      curto();  
      curto();
      longo();
      siletras();
  }
   else if(frase[i] == 'w'){
      curto();
      longo();
      longo();
      siletras();
  }
   else if(frase[i] == 'x'){
      longo();
      curto();
      curto();
      longo();  
      siletras();
  }
   else if(frase[i] == 'y'){
      longo();
      curto();
      longo();
      longo();  
      siletras();
  }
   else if(frase[i] == 'z'){
      longo();
      longo();
      curto();
      curto();  
      siletras();
  }
   else if(frase[i] == '0'){
      longo();
      longo();
      longo();
      longo();
      longo();  
      siletras();
  }
   else if(frase[i] == '1'){
      curto();
      longo();
      longo();
      longo();
      longo();
      siletras();
  }
   else if(frase[i] == '2'){
      curto();
      curto();
      longo();
      longo();
      longo();
      siletras();
  }
   else if(frase[i] == '3'){
      curto();
      curto();
      curto();
      longo();
      longo();
      siletras();
  }
   else if(frase[i] == '4'){
      curto();
      curto();
      curto();
      curto();
      longo();
      siletras();
  }
   else if(frase[i] == '5'){
      curto();
      curto();
      curto();
      curto();
      curto();
      siletras();
  }
   else if(frase[i] == '6'){
      longo();
      curto();
      curto();
      curto();
      curto();
      siletras();
  }
   else if(frase[i] == '7'){
      longo();
      longo();
      curto();
      curto();
      curto();
      siletras();
   }
   else if(frase[i] == '8'){
      longo();
      longo();
      longo();
      curto();
      curto();
      siletras();
   }
   else if(frase[i] == '9'){
      longo();
      longo();
      longo();
      longo();
      curto();
      siletras();
   }    
   else if(frase[i] ==' '){
    sipalavras();
   }
}
}