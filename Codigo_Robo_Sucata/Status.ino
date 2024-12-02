unsigned long tempo_Anterior_Status = 0;
unsigned long intervalo_Status = 1000;  // 1000

void _Status(int envio) {
  int base = analogRead(scanner_Base);
  int ombro = analogRead(scanner_Ombro);
  int cotovelo = analogRead(scanner_Cotovelo);
  int pulso = analogRead(scanner_Pulso);
  int rotacao = analogRead(scanner_Rotacao);
  int garra = analogRead(scanner_Garra);

  base = map(base, 0, 1023, 0, 100);
  ombro = map(ombro, 0, 1023, 0, 100);
  cotovelo = map(cotovelo, 0, 1023, 0, 100);
  pulso = map(pulso, 0, 1023, 0, 100);
  rotacao = map(rotacao, 0, 1023, 0, 100);
  garra = map(garra, 0, 1023, 0, 100);

  garra <= 3 ? status_garra = "Fechada" : status_garra = "Aberta";

  unsigned long tempo_Atual_Status = millis();
  if (tempo_Atual_Status - tempo_Anterior_Status >= intervalo_Status) {
    tempo_Anterior_Status = tempo_Atual_Status;

    lcd.noDisplay();  // APAGA OS CARACTERES
    lcd.clear();
    lcd.display();  // ACENDE OS CARACTERS

    lcd.setCursor(0, 0);  // Coluna 0  Linha 0
    lcd.print("B");
    lcd.setCursor(1, 0);  // Coluna 1  Linha 0
    lcd.print(String(base));
    lcd.setCursor(3, 0);  // Coluna 4  Linha 0
    lcd.print("-");

    lcd.setCursor(4, 0);
    lcd.print("O");
    lcd.setCursor(5, 0);
    lcd.print(String(ombro));
    lcd.setCursor(7, 0);
    lcd.print("-");

    lcd.setCursor(8, 0);
    lcd.print("C");
    lcd.setCursor(9, 0);
    lcd.print(String(cotovelo));
    lcd.setCursor(11, 0);
    lcd.print("-");

    lcd.setCursor(12, 0);
    lcd.print("P");
    lcd.setCursor(13, 0);
    lcd.print(String(pulso));

    lcd.setCursor(0, 1);  // Coluna 0  Linha 1
    lcd.print("R");
    lcd.setCursor(1, 1);  // Coluna 1  Linha 1
    lcd.print(String(rotacao));
    lcd.setCursor(3, 1);  // Coluna 4  Linha 1
    lcd.print("-");

    lcd.setCursor(4, 1);
    lcd.print("G");
    lcd.setCursor(5, 1);
    lcd.print(String(garra));
    lcd.setCursor(7, 1);
    lcd.print("-");

    lcd.setCursor(8, 1);
    lcd.print("L");
    lcd.setCursor(9, 1);
    (digitalRead(luz) == 1) ? lcd.print("1") :  lcd.print("0");

    if (envio == 1) {
      String dados = "";
      dados += "B = ";
      dados += String(base);
      dados += " - O = ";
      dados += String(ombro);
      dados += " - C = ";
      dados += String(cotovelo);
      dados += " - P = ";
      dados += String(pulso);
      dados += " - R = ";
      dados += String(rotacao);
      dados += " - G = ";
      dados += status_garra;
      dados += " - L = ";
      digitalRead(luz) == HIGH ? dados += "Ligada" : dados += "Desligada";

      Serial.print("\nStatus: ");
      Serial.println(dados);
    } else if (envio == 2) {
      String dados = "";
      dados += "B-";
      dados += String(base);
      dados += "/O-";
      dados += String(ombro);
      dados += "/C-";
      dados += String(cotovelo);
      dados += "/P-";
      dados += String(pulso);
      dados += "/R-";
      dados += String(rotacao);
      dados += "/G-";
      dados += status_garra;
      dados += "/L-";
      digitalRead(luz) == HIGH ? dados += "LIGADA" : dados += "DESLIGADA";

      Bluetooth.print(dados);
    }
  }
}
