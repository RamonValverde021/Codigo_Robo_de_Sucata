// Posicao Inicial/Final do Robo
void _posicaoInicial() {
  digitalWrite(luz, HIGH);
  delay(2000);  //2000
  digitalWrite(luz, LOW);

  _Ombro(43);
  _Cotovelo(15);
  _Pulso(42);
  _Garra(1);     // Fechada.
  _Rotacao(97);  // Centralizado
  _Base(45);     // Centralizado
}

// Rotina 01
void _Rotina_01() {
  // Pega a garrafinha
  _posicaoInicial();
  _Base(49);
  _Garra(0);
  _OmbroCotoveloPulso(20, 26, 53);
  _Garra(1);

  // Leva e solta a Garrafinha no potinho
  _Pulso(70);
  _OmbroCotoveloPulso(23, 23, 55);
  _Base(35);
  _Garra(0);

  // Reposiciona o Robo
  _Ombro(43);
  _Cotovelo(15);
  _Pulso(42);
  _Garra(1);

  // Pega a caixinha
  _BaseRotacao(55, 60);
  _CotoveloPulso(30, 15);
  _Garra(0);
  _Ombro(28);
  _Garra(1);

  // Levanta a caixinha
  _Ombro(43);

  // Leva e solta a caixinha no copinho
  _BaseRotacao(20, 97);
  _Pulso(40);
  _OmbroCotovelo(40, 15);
  _Garra(0);
  _posicaoInicial();
}