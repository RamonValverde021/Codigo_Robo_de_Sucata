// A função recebe dois ponteiros (articulacao e posicao), ela le a entrada de dados e armazena os resultados nas variáveis apontadas pelos ponteiros '*'.
void _entradaDados(char *articulacao, int *posicao) {
  String comando = "";
  if (Serial.available() || Bluetooth.available()) {  // Verifica se tem algo na Serial ou no Bluetooth
    if (Serial.available()) {                         // Se tem algo na Serial bloqueia o Bluetooth
      serial = true;
      bluetooth = false;
    } else if (Bluetooth.available()) {  // Se tem algo no Bluetooth bloqueia a Serial
      serial = false;
      bluetooth = true;
    }
    if (serial == true) {
      while (Serial.available()) {      // Enquanto houver bytes disponíveis para leitura, ...
        char caracter = Serial.read();  // recebe o byte como caractere
        comando += caracter;
        delay(10);
      }
    } else if (bluetooth == true) {
      while (Bluetooth.available()) {
        char caracter = Bluetooth.read();
        comando += caracter;
        delay(10);
      }
    }

    String letras;
    String numeros;
    // Iterar através da string de entrada
    for (char caractere : comando) {
      if (isalpha(caractere)) {
        // Se for uma letra, adicione à string de letras
        letras += caractere;
      } else if (isdigit(caractere)) {
        // Se for um dígito, adicione à string de números
        numeros += caractere;
      }
      // Se não for uma letra nem um dígito, ignore
    }

    // Verifica se ouve alguma entrada de coordenada
    if (numeros.length() != NULL) {
      // Converta a string de números para inteiro
      int numeroConvertido = numeros.toInt();
      // Converte o caractere em maiúsculo
      char caractereMaiusculo = toupper(comando[0]);

      // Definindo limites de articulação dos motores
      switch (caractereMaiusculo) {
        case 'B':
          numeroConvertido = constrain(numeroConvertido, min_Base, max_Base);  // 1, 99
          break;
        case 'O':
          numeroConvertido = constrain(numeroConvertido, min_Ombro, max_Ombro);  // 1, 44
          break;
        case 'C':
          numeroConvertido = constrain(numeroConvertido, min_Cotovelo, max_Cotovelo);  // 15, 99
          break;
        case 'P':
          numeroConvertido = constrain(numeroConvertido, min_Pulso, max_Pulso);  // 15, 90
          break;
        case 'R':
          numeroConvertido = constrain(numeroConvertido, min_Rotacao, max_Rotacao);  // 1, 99
          break;
        case 'G':
          numeroConvertido = constrain(numeroConvertido, min_Garra, max_Garra);  // Fecha ou Abre
          break;
        default:
          break;
      }

      *posicao = numeroConvertido;
      *articulacao = caractereMaiusculo;
    } else {
      *posicao = -1;
      *articulacao = 'v';  // v de voide de vazio
    }

    // Quando o aplicativo solicita um status de posição do robo
    if (comando.indexOf("Status") >= 0) _Status(2);
  }
}