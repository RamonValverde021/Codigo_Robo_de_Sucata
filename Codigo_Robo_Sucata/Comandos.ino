void _Comandos() {
  char articulacao  = 'x';
  int posicao  = 0;
  // Ao chamar a função, é preciso passar os endereços das variáveis onde deseja armazenar os resultados, isso é feito usando o operador '&' antes das variáveis.
  _entradaDados(&articulacao, &posicao);
  if (posicao != -1) {
    if (articulacao == 'B') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Base(posicao);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'O') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Ombro(posicao);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'C') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Cotovelo(posicao);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'P') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Pulso(posicao);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'R') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Rotacao(posicao);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'G') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Garra(posicao);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'L') {
      if (posicaoAtual != posicao) {
        posicao == 1 ? digitalWrite(luz, HIGH) : digitalWrite(luz, LOW);
      }
      posicaoAtual = posicao;
    }
  }
}
