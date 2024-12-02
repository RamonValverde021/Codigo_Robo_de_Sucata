void _DisplaySerial(char index, int coordenada) {
  switch (index) {
    case '0':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("FUNCAO:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print("ENTRADA DE DADOS");
      Serial.println("\nFUNCAO: ENTRADA DE DADOS");
      break;

    case '1':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("AUTOMACAO 01:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print("INICIANDO...");
      Serial.println("\nAUTOMACAO 01");
      break;

    case '2':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("AUTOMACAO 02:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(" ");
      Serial.println("\nAUTOMACAO 02");
      break;

    case '3':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("AUTOMACAO 03:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(" ");
      Serial.println("\nAUTOMACAO 03");
      break;

    case 'I':
      lcd.begin();
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();           // ACENDE OS CARACTERS
      lcd.setBacklight(HIGH);  // ACENDE A LUZ DE FUNDO
      lcd.setCursor(1, 0);     // Coluna 1 Linha 0
      lcd.print("INICIANDO ROBO");
      lcd.setCursor(2, 1);  // Coluna 3 Linha 1
      lcd.print("ARM MARK III");
      Serial.println("\n\n     INICIANDO ROBO     ");
      Serial.println("      ARM MARK III      ");
      delay(1000);  // 5000
      lcd.clear();
      break;

    case 'B':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("BASE:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(">> ");
      lcd.setCursor(3, 1);  // Coluna 0  Linha 0
      lcd.print(coordenada);
      Serial.print("\nBASE: ");
      Serial.println(coordenada);
      break;

    case 'O':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("OMBRO:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(">> ");
      lcd.setCursor(3, 1);  // Coluna 0  Linha 0
      lcd.print(coordenada);
      Serial.print("\nOMBRO: ");
      Serial.println(coordenada);
      break;

    case 'C':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("COTOVELO:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(">> ");
      lcd.setCursor(3, 1);  // Coluna 0  Linha 0
      lcd.print(coordenada);
      Serial.print("\nCOTOVELO: ");
      Serial.println(coordenada);
      break;

    case 'P':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("PULSO:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(">> ");
      lcd.setCursor(3, 1);  // Coluna 0  Linha 0
      lcd.print(coordenada);
      Serial.print("\nPULSO: ");
      Serial.println(coordenada);
      break;

    case 'R':
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();        // ACENDE OS CARACTERS
      lcd.setCursor(0, 0);  // Coluna 0  Linha 0
      lcd.print("ROTACAO PULSO:");
      lcd.setCursor(0, 1);  // Coluna 0  Linha 0
      lcd.print(">> ");
      lcd.setCursor(3, 1);  // Coluna 0  Linha 0
      lcd.print(coordenada);
      Serial.print("\nROTACAO: ");
      Serial.println(coordenada);
      break;

    case 'G':
      if (coordenada == 0) {  // Fecha a Garra
        lcd.noDisplay();
        lcd.clear();
        lcd.display();        // ACENDE OS CARACTERS
        lcd.setCursor(0, 0);  // Coluna 0  Linha 0
        lcd.print("GARRA:");
        lcd.setCursor(0, 1);  // Coluna 0  Linha 0
        lcd.print(">> ");
        lcd.setCursor(3, 1);  // Coluna 0  Linha 0
        lcd.print("ABRIR");
        Serial.print("\nGARRA: ");
        Serial.println(coordenada);
        break;
      } else if (coordenada == 1) {  // Abre a Garra
        lcd.noDisplay();
        lcd.clear();
        lcd.display();        // ACENDE OS CARACTERS
        lcd.setCursor(0, 0);  // Coluna 0  Linha 0
        lcd.print("GARRA:");
        lcd.setCursor(0, 1);  // Coluna 0  Linha 0
        lcd.print(">> ");
        lcd.setCursor(3, 1);  // Coluna 0  Linha 0
        lcd.print("FECHAR");
        Serial.print("\nGARRA: ");
        Serial.println(coordenada);
        break;
      }

    case 'L':
      if (coordenada == 1) {
        lcd.noDisplay();  // APAGA OS CARACTERES
        lcd.clear();
        lcd.display();        // ACENDE OS CARACTERS
        lcd.setCursor(0, 0);  // Coluna 0  Linha 0
        lcd.print("LUZ:");
        lcd.setCursor(0, 1);  // Coluna 0  Linha 0
        lcd.print(">> ");
        lcd.setCursor(3, 1);  // Coluna 0  Linha 0
        lcd.print("Ligar");
        Serial.print("\nLUZ: ");
        Serial.println("Ligar");
      } else if (coordenada == 0) {
        lcd.noDisplay();  // APAGA OS CARACTERES
        lcd.clear();
        lcd.display();        // ACENDE OS CARACTERS
        lcd.setCursor(0, 0);  // Coluna 0  Linha 0
        lcd.print("LUZ:");
        lcd.setCursor(0, 1);  // Coluna 0  Linha 0
        lcd.print(">> ");
        lcd.setCursor(3, 1);  // Coluna 0  Linha 0
        lcd.print("Desligar");
        Serial.print("\nLUZ: ");
        Serial.println("Desligar");
      }
      break;

    default:
      break;
  }
}
