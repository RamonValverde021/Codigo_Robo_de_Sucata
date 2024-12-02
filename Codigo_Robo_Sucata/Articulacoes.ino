void _Base(int coordenada) {
  constrain(coordenada, min_Base, max_Base);
  int leitura = 0, c = 0, aux1 = coordenada - 5, aux2 = coordenada + 5;
  int tamanho_media = 10;
  int contador = 0;
  // Verifica a posição da articulação 3 vezes
  while (c < 3) {
    while (coordenada != leitura) {
      // Incrementa o contador com 10 leituras de posições
      for (int c = 0; c < tamanho_media; c++) {
        leitura = analogRead(scanner_Base);
        leitura = map(leitura, 0, 1023, 0, 100);
        contador += leitura;  // Incrementando o contador
      }
      leitura = (contador / tamanho_media);  // Calcula a media das 10 posições lidas e passa para a variavel da leitura das sensores
      contador = 0;                          // Zera o contador
      if (coordenada > leitura) {
        digitalWrite(baseE, HIGH);
        digitalWrite(baseD, LOW);
      } else if (coordenada < leitura) {
        digitalWrite(baseE, LOW);
        digitalWrite(baseD, HIGH);
      } else if (coordenada == leitura) {
        digitalWrite(baseE, LOW);
        digitalWrite(baseD, LOW);
      }
      ((leitura < aux2) && (leitura > aux1)) ? analogWrite(pwm_Base, 255) : analogWrite(pwm_Base, 255);
      if (coordenada == leitura) analogWrite(pwm_Base, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();  // APAGA A LUZ DE FUNDO
  delay(200);
  lcd.backlight();  // ACENDE A LUZ DE FUNDO
}

void _Ombro(int coordenada) {
  constrain(coordenada, min_Ombro, max_Ombro);
  int leitura = 0, c = 0, aux1 = coordenada - 10, aux2 = coordenada + 10;
  int tamanho_media = 10;
  int contador = 0;
  // Verifica a posição da articulação 3 vezes
  while (c < 3) {
    while (coordenada != leitura) {
      // Incrementa o contador com 10 leituras de posições
      for (int c = 0; c < tamanho_media; c++) {
        leitura = analogRead(scanner_Ombro);
        leitura = map(leitura, 0, 1023, 0, 100);
        contador += leitura;  // Incrementando o contador
      }
      leitura = (contador / tamanho_media);  // Calcula a media das 10 posições lidas e passa para a variavel da leitura das sensores
      contador = 0;                          // Zera o contador
      if (coordenada > leitura) {
        digitalWrite(ombroE, HIGH);
        digitalWrite(ombroD, LOW);
      } else if (coordenada < leitura) {
        digitalWrite(ombroE, LOW);
        digitalWrite(ombroD, HIGH);
      } else if (coordenada == leitura) {
        digitalWrite(ombroE, LOW);
        digitalWrite(ombroD, LOW);
      }
      ((leitura < aux2) && (leitura > aux1)) ? analogWrite(pwm_Ombro, 220) : analogWrite(pwm_Ombro, 255);
      if (leitura <= 25) analogWrite(pwm_Ombro, 255);
      if (coordenada == leitura) analogWrite(pwm_Ombro, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _Cotovelo(int coordenada) {
  constrain(coordenada, min_Cotovelo, max_Cotovelo);
  int leitura = 0, c = 0, aux1 = coordenada - 5, aux2 = coordenada + 5;
  int tamanho_media = 10;
  int contador = 0;
  // Verifica a posição da articulação 3 vezes
  while (c < 3) {
    while (coordenada != leitura) {
      // Incrementa o contador com 10 leituras de posições
      for (int c = 0; c < tamanho_media; c++) {
        leitura = analogRead(scanner_Cotovelo);
        leitura = map(leitura, 0, 1023, 0, 100);
        contador += leitura;  // Incrementando o contador
      }
      leitura = (contador / tamanho_media);  // Calcula a media das 10 posições lidas e passa para a variavel da leitura das sensores
      contador = 0;                          // Zera o contador
      if (coordenada > leitura) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, LOW);
      } else if (coordenada < leitura) {
        digitalWrite(cotoveloE, LOW);
        digitalWrite(cotoveloD, HIGH);
      } else if (coordenada == leitura) {
        digitalWrite(cotoveloE, LOW);
        digitalWrite(cotoveloD, LOW);
      }
      ((leitura < aux2) && (leitura > aux1)) ? analogWrite(pwm_Cotovelo, 215) : analogWrite(pwm_Cotovelo, 255);
      if (coordenada == leitura) analogWrite(pwm_Cotovelo, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _Pulso(int coordenada) {
  constrain(coordenada, min_Pulso, max_Pulso);  // 15, 90
  int leitura = 0, c = 0, aux1 = coordenada - 5, aux2 = coordenada + 5;
  int tamanho_media = 10;
  int contador = 0;
  // Verifica a posição da articulação 3 vezes
  while (c < 3) {
    while (coordenada != leitura) {
      // Incrementa o contador com 10 leituras de posições
      for (int c = 0; c < tamanho_media; c++) {
        leitura = analogRead(scanner_Pulso);
        leitura = map(leitura, 0, 1023, 0, 100);
        contador += leitura;  // Incrementando o contador
      }
      leitura = (contador / tamanho_media);  // Calcula a media das 10 posições lidas e passa para a variavel da leitura das sensores

      contador = 0;  // Zera o contador
      if (coordenada > leitura) {
        digitalWrite(pulsoE, HIGH);
        digitalWrite(pulsoD, LOW);
      } else if (coordenada < leitura) {
        digitalWrite(pulsoE, LOW);
        digitalWrite(pulsoD, HIGH);
      } else if (coordenada == leitura) {
        digitalWrite(pulsoE, LOW);
        digitalWrite(pulsoD, LOW);
      }
      ((leitura < aux2) && (leitura > aux1)) ? analogWrite(pwm_Pulso, 200) : analogWrite(pwm_Pulso, 255);
      if (coordenada == leitura) analogWrite(pwm_Pulso, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _Rotacao(int coordenada) {
  constrain(coordenada, min_Rotacao, max_Rotacao);  // 1, 99
  int leitura = 0, c = 0, aux1 = coordenada - 5, aux2 = coordenada + 5;
  int tamanho_media = 10;
  int contador = 0;
  // Verifica a posição da articulação 3 vezes
  while (c < 3) {
    while (coordenada != leitura) {
      // Incrementa o contador com 10 leituras de posições
      for (int c = 0; c < tamanho_media; c++) {
        leitura = analogRead(scanner_Rotacao);
        leitura = map(leitura, 0, 1023, 0, 100);
        contador += leitura;  // Incrementando o contador
      }
      leitura = (contador / tamanho_media);  // Calcula a media das 10 posições lidas e passa para a variavel da leitura das sensores
      contador = 0;                          // Zera o contador
      Serial.println(leitura);
      if (coordenada > leitura) {
        digitalWrite(rotacaoE, HIGH);
        digitalWrite(rotacaoD, LOW);
      } else if (coordenada < leitura) {
        digitalWrite(rotacaoE, LOW);
        digitalWrite(rotacaoD, HIGH);
      } else if (coordenada == leitura) {
        digitalWrite(rotacaoE, LOW);
        digitalWrite(rotacaoD, LOW);
      }
      ((leitura < aux2) && (leitura > aux1)) ? analogWrite(pwm_Rotacao, 200) : analogWrite(pwm_Rotacao, 255);  //190 240
      if (coordenada == leitura) analogWrite(pwm_Rotacao, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _Garra(int posicao) {
  constrain(posicao, min_Garra, max_Garra);
  // 1 garra aberta   0 garra fechada
  int espera = 400;  // 300
  analogWrite(pwm_Garra, 200);
  if (posicao == 0) {
    // Abre a Garra
    digitalWrite(garraE, HIGH);
    digitalWrite(garraD, LOW);
    delay(espera);
    status_garra = "Aberta";
  } else {
    // Fecha a Garra
    digitalWrite(garraE, LOW);
    digitalWrite(garraD, HIGH);
    delay(espera);
    status_garra = "Fechada";
  }
  // Para o motor
  digitalWrite(garraE, HIGH);
  digitalWrite(garraD, HIGH);
  delay(500);
  digitalWrite(garraE, LOW);
  digitalWrite(garraD, LOW);
}



/////////////////// MOVENDO DOIS SERVOS AO MESMO TEMPO ///////////////////

void _OmbroCotovelo(int ombro, int cotovelo) {
  // Delimita os limites das articulações
  constrain(ombro, min_Ombro, max_Ombro);
  constrain(cotovelo, min_Cotovelo, max_Cotovelo);

  // Variaveis de controle do Ombro
  int leitura1 = 0, aux11 = ombro - 10, aux12 = ombro + 10;

  // Variaveis de controle do Cotovelo
  int leitura2 = 0, aux21 = cotovelo - 5, aux22 = cotovelo + 5;

  // Variaveis da media de valores lidos
  int tamanho_media = 10;
  int contador1 = 0, contador2 = 0, c = 0;

  while (c < 3) {
    while ((ombro != leitura1) || (cotovelo != leitura2)) {  // Enquanto as articulações não chegam aos sua posição
      for (int c = 0; c < tamanho_media; c++) {
        // Analisa a posição do ombro e soma os dados na media
        leitura1 = analogRead(scanner_Ombro);
        leitura1 = map(leitura1, 0, 1023, 0, 100);
        contador1 += leitura1;

        // Analisa a posição do cotovelo e soma os dados na media
        leitura2 = analogRead(scanner_Cotovelo);
        leitura2 = map(leitura2, 0, 1023, 0, 100);
        contador2 += leitura2;
      }
      // Calcula a media das posições
      leitura1 = (contador1 / tamanho_media);
      leitura2 = (contador2 / tamanho_media);

      // Zera os somadores
      contador1 = 0;
      contador2 = 0;

      //Movimenta o Ombro
      if (ombro > leitura1) {
        digitalWrite(ombroE, HIGH);
        digitalWrite(ombroD, LOW);
      } else if (ombro < leitura1) {
        digitalWrite(ombroE, LOW);
        digitalWrite(ombroD, HIGH);
      } else if (ombro == leitura1) {
        digitalWrite(ombroE, HIGH);
        digitalWrite(ombroD, HIGH);
      }
      ((leitura1 < aux12) && (leitura1 > aux11)) ? analogWrite(pwm_Ombro, 220) : analogWrite(pwm_Ombro, 255);
      if (leitura1 <= 25) analogWrite(pwm_Ombro, 255);
      if (ombro == leitura1) analogWrite(pwm_Ombro, 0);

      //Movimenta o Cotovelo
      if (cotovelo > leitura2) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, LOW);
      } else if (cotovelo < leitura2) {
        digitalWrite(cotoveloE, LOW);
        digitalWrite(cotoveloD, HIGH);
      } else if (cotovelo == leitura2) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, HIGH);
      }
      ((leitura2 < aux22) && (leitura2 > aux21)) ? analogWrite(pwm_Cotovelo, 215) : analogWrite(pwm_Cotovelo, 255);
      if (cotovelo == leitura2) analogWrite(pwm_Cotovelo, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _CotoveloPulso(int cotovelo, int pulso) {
  // Delimita os limites das articulações
  constrain(cotovelo, min_Cotovelo, max_Cotovelo);
  constrain(pulso, min_Pulso, max_Pulso);

  // Variaveis de controle do Cotovelo
  int leitura1 = 0, aux11 = cotovelo - 5, aux12 = cotovelo + 5;

  // Variaveis de controle do Pulso
  int leitura2 = 0, aux21 = pulso - 5, aux22 = pulso + 5;

  // Variaveis da media de valores lidos
  int tamanho_media = 10;
  int contador1 = 0, contador2 = 0, c = 0;

  while (c < 3) {
    while ((cotovelo != leitura1) || (pulso != leitura2)) {  // Enquanto as articulações não chegam aos sua posição
      for (int c = 0; c < tamanho_media; c++) {
        // Analisa a posição do cotovelo e soma os dados na media
        leitura1 = analogRead(scanner_Cotovelo);
        leitura1 = map(leitura1, 0, 1023, 0, 100);
        contador1 += leitura1;

        // Analisa a posição do pulso e soma os dados na media
        leitura2 = analogRead(scanner_Pulso);
        leitura2 = map(leitura2, 0, 1023, 0, 100);
        contador2 += leitura2;
      }
      // Calcula a media das posições
      leitura1 = (contador1 / tamanho_media);
      leitura2 = (contador2 / tamanho_media);

      // Zera os somadores
      contador1 = 0;
      contador2 = 0;

      //Movimenta o Cotovelo
      if (cotovelo > leitura1) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, LOW);
      } else if (cotovelo < leitura1) {
        digitalWrite(cotoveloE, LOW);
        digitalWrite(cotoveloD, HIGH);
      } else if (cotovelo == leitura1) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, HIGH);
      }
      ((leitura1 < aux12) && (leitura1 > aux11)) ? analogWrite(pwm_Cotovelo, 215) : analogWrite(pwm_Cotovelo, 255);
      if (cotovelo == leitura1) analogWrite(pwm_Cotovelo, 0);

      //Movimenta o Pulso
      if (pulso > leitura2) {
        digitalWrite(pulsoE, HIGH);
        digitalWrite(pulsoD, LOW);
      } else if (pulso < leitura2) {
        digitalWrite(pulsoE, LOW);
        digitalWrite(pulsoD, HIGH);
      } else if (pulso == leitura2) {
        digitalWrite(pulsoE, HIGH);
        digitalWrite(pulsoD, HIGH);
      }
      ((leitura2 < aux22) && (leitura2 > aux21)) ? analogWrite(pwm_Pulso, 200) : analogWrite(pwm_Pulso, 255);
      if (pulso == leitura2) analogWrite(pwm_Pulso, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _BaseRotacao(int base, int rotacao) {
  // Delimita os limites das articulações
  constrain(base, min_Base, max_Base);
  constrain(rotacao, min_Rotacao, max_Rotacao);

  // Variaveis de controle da Base
  int leitura1 = 0, aux11 = base - 5, aux12 = base + 5;

  // Variaveis de controle da Rotacao
  int leitura2 = 0, aux21 = rotacao - 5, aux22 = rotacao + 5;

  // Variaveis da media de valores lidos
  int tamanho_media = 10;
  int contador1 = 0, contador2 = 0, c = 0;

  while (c < 3) {
    while ((base != leitura1) || (rotacao != leitura2)) {  // Enquanto as articulações não chegam aos sua posição
      for (int c = 0; c < tamanho_media; c++) {
        // Analisa a posição do ombro e soma os dados na media
        leitura1 = analogRead(scanner_Base);
        leitura1 = map(leitura1, 0, 1023, 0, 100);
        contador1 += leitura1;

        // Analisa a posição do cotovelo e soma os dados na media
        leitura2 = analogRead(scanner_Rotacao);
        leitura2 = map(leitura2, 0, 1023, 0, 100);
        contador2 += leitura2;
      }
      // Calcula a media das posições
      leitura1 = (contador1 / tamanho_media);
      leitura2 = (contador2 / tamanho_media);

      // Zera os somadores
      contador1 = 0;
      contador2 = 0;

      //Movimenta a Base
      if (base > leitura1) {
        digitalWrite(baseE, HIGH);
        digitalWrite(baseD, LOW);
      } else if (base < leitura1) {
        digitalWrite(baseE, LOW);
        digitalWrite(baseD, HIGH);
      } else if (base == leitura1) {
        digitalWrite(baseE, LOW);
        digitalWrite(baseD, LOW);
      }
      ((leitura1 < aux12) && (leitura1 > aux11)) ? analogWrite(pwm_Base, 255) : analogWrite(pwm_Base, 255);
      if (base == leitura1) analogWrite(pwm_Base, 0);

      //Movimenta a Rotacao
      if (rotacao > leitura2) {
        digitalWrite(rotacaoE, HIGH);
        digitalWrite(rotacaoD, LOW);
      } else if (rotacao < leitura2) {
        digitalWrite(rotacaoE, LOW);
        digitalWrite(rotacaoD, HIGH);
      } else if (rotacao == leitura2) {
        digitalWrite(rotacaoE, LOW);
        digitalWrite(rotacaoD, LOW);
      }
      ((leitura2 < aux22) && (leitura2 > aux21)) ? analogWrite(pwm_Rotacao, 215) : analogWrite(pwm_Rotacao, 255);  //190 240
      if (rotacao == leitura2) analogWrite(pwm_Rotacao, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}

void _OmbroCotoveloPulso(int ombro, int cotovelo, int pulso) {
  // Delimita os limites das articulações
  constrain(ombro, min_Ombro, max_Ombro);
  constrain(cotovelo, min_Cotovelo, max_Cotovelo);
  constrain(pulso, min_Pulso, max_Pulso);

  // Variaveis de controle do Ombro
  int leitura1 = 0, aux11 = ombro - 10, aux12 = ombro + 10;

  // Variaveis de controle do Cotovelo
  int leitura2 = 0, aux21 = cotovelo - 5, aux22 = cotovelo + 5;

  // Variaveis de controle do Pulso
  int leitura3 = 0, aux31 = pulso - 5, aux32 = pulso + 5;

  // Variaveis da media de valores lidos
  int tamanho_media = 10;
  int contador1 = 0, contador2 = 0, contador3 = 0, c = 0;

  while (c < 3) {
    while ((ombro != leitura1) || (cotovelo != leitura2) || (pulso != leitura3)) {  // Enquanto as articulações não chegam aos sua posição
      for (int c = 0; c < tamanho_media; c++) {
        // Analisa a posição do ombro e soma os dados na media
        leitura1 = analogRead(scanner_Ombro);
        leitura1 = map(leitura1, 0, 1023, 0, 100);
        contador1 += leitura1;

        // Analisa a posição do cotovelo e soma os dados na media
        leitura2 = analogRead(scanner_Cotovelo);
        leitura2 = map(leitura2, 0, 1023, 0, 100);
        contador2 += leitura2;

        // Analisa a posição do pulso e soma os dados na media
        leitura3 = analogRead(scanner_Pulso);
        leitura3 = map(leitura3, 0, 1023, 0, 100);
        contador3 += leitura3;
      }
      // Calcula a media das posições
      leitura1 = (contador1 / tamanho_media);
      leitura2 = (contador2 / tamanho_media);
      leitura3 = (contador3 / tamanho_media);

      // Zera os somadores
      contador1 = 0;
      contador2 = 0;
      contador3 = 0;

      //Movimenta o Ombro
      if (ombro > leitura1) {
        digitalWrite(ombroE, HIGH);
        digitalWrite(ombroD, LOW);
      } else if (ombro < leitura1) {
        digitalWrite(ombroE, LOW);
        digitalWrite(ombroD, HIGH);
      } else if (ombro == leitura1) {
        digitalWrite(ombroE, HIGH);
        digitalWrite(ombroD, HIGH);
      }
      ((leitura1 < aux12) && (leitura1 > aux11)) ? analogWrite(pwm_Ombro, 220) : analogWrite(pwm_Ombro, 255);
      if (leitura1 <= 25) analogWrite(pwm_Ombro, 255);
      if (ombro == leitura1) analogWrite(pwm_Ombro, 0);

      //Movimenta o Cotovelo
      if (cotovelo > leitura2) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, LOW);
      } else if (cotovelo < leitura2) {
        digitalWrite(cotoveloE, LOW);
        digitalWrite(cotoveloD, HIGH);
      } else if (cotovelo == leitura2) {
        digitalWrite(cotoveloE, HIGH);
        digitalWrite(cotoveloD, HIGH);
      }
      ((leitura2 < aux22) && (leitura2 > aux21)) ? analogWrite(pwm_Cotovelo, 215) : analogWrite(pwm_Cotovelo, 255);
      if (cotovelo == leitura2) analogWrite(pwm_Cotovelo, 0);

      //Movimenta o Pulso
      if (pulso > leitura3) {
        digitalWrite(pulsoE, HIGH);
        digitalWrite(pulsoD, LOW);
      } else if (pulso < leitura3) {
        digitalWrite(pulsoE, LOW);
        digitalWrite(pulsoD, HIGH);
      } else if (pulso == leitura3) {
        digitalWrite(pulsoE, HIGH);
        digitalWrite(pulsoD, HIGH);
      }
      ((leitura3 < aux32) && (leitura3 > aux31)) ? analogWrite(pwm_Pulso, 200) : analogWrite(pwm_Pulso, 255);
      if (pulso == leitura3) analogWrite(pwm_Pulso, 0);
    }
    c++;
    delay(100);
    Serial.print(">");
  }
  Serial.println(" OK \n-----------------------------");
  lcd.noBacklight();
  delay(200);
  lcd.backlight();
}
