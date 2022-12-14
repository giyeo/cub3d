Existem alguns tipos de caracteres válidos para um mapa.

Identificador de espaço:    0, 1, ' ', '\n'
Identificador de direção:   N, E, S, W

Obrigatoriedade de espaço: Sempre vamos ter ao menos o char '1'.
Obrigatoriedade de direção: Ao menos uma, e não mais dessas deve ser encontrada no mapa.

Para testar se a direção funciona, e nosso programa consegue
interpretar o corretamente a direção, precisamos de um mapa
simples com diferentes direções, esse, pode ser encontrado
no diretório "directions", onde mapas pensado para testar
essas caracteristicas reside.

Podemos caracterizar mapas válidos da seguinte forma:
-minimal -> o minimo para ser um mapa válido (pensado para usar menos char possivel para apresentar uma característica).
-simples -> mapas comuns, estética "quadrada", com ou sem edges.
-complex -> mapas válidos com propriedades incomuns.
-testground -> mapas onde juntamos todas as propriedades, para um teste geral.