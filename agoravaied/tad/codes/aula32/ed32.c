// Tipo Abstrato de Dados ( TAD )

/*

    Um drone tem varias funcionalidades (ir para direita, esquerda, ligar a camera) e para esse drone funcionar ele é controlado por um
    controle remoto então quem pilota precisa do controle para de fato controlar o drone. E no controle remoto tem uma serie de botoes
    e em cada um deles tem certas funcionalidades, um de ligar outro de voar... Você sabe que esse botão tem essa funcionalidade de ligar
    ou seja você sabe o que esse botão faz, então esse controle remoto seria uma caixa preta, não sabe como ele foi feito, produzido, ou 
    como essas implementações de funcionalidades foram feitas, a unica coisa que sabemos é que cada um desses botoes tem uma funcionalidade
    e que cada botão faz, sabemos isso olhando o manual de intruções.

    Então a gente como usuário tem um produto fechado, não tendo acesso a implementação porém temos um conjunto de funcionalidades (manual)
    de modo que para você usuário a unica coisa que te interessa é saber as funcionalidades do produto (o que os botoes fazem), não importa
    pra gente saber como foi feito.

    A empresa desse tal drone deixa aberto as especificações das funcionalidades desse drone para outras empresas fazerem seus próprios 
    controles remotos, porém cabe a cada uma das empresas a partir dessas empresas que implementará o seu próprio controle remoto decidir
    como essas funcionalidades serão implementadas, qual será o algoritmo, o circuito, a caixa preta que seria o produto final... 

    Visão mais técnica de TAD:
    -> visa desvincular o tipo de dados(estrutura de dados e operações que as manipulam) de sua implementação.
    -> Quando definimos um tipo abstrato de dados estamos preocupados com o que ele faz(especificação) e não como ele faz(implementação)
    -> ideia parecida com Encapsulamento em POO -> escondemos os dados e detalhes do usuário, fornecendo apenas uma interface pública...
    -> ... (métodos/operações) para manipulá-los

    Tipos Abstratos de dados:
    Especificação -> Sintaze(assinatura, funções) e Semântica (documentação do código -> essa função faz taltal)
    Implementação -> Representação(estrutura de dados) e Algoritmos -> implementar as especificações das funcionalidades.

    TAD em Linguagem C:
    -> Separamos a especificação do tipo em um arquivo de cabeçalho (.h) e sua implementação em um arquivo fonte (.c)
        seu_tad.h -> especificação da TAD
        seu_tad.c -> implementação da TAD
    -> os programas ou outras TADs que utilizam seu TAD deve incluir sua especificação:
        #include "seu_tad.h" -> .h de header(cabeçalho) -> ou seja a gente importará um arquivo de especificações...
    -> ... que vai ter lá como as funções foram feitas e etc, ai a gente só implementará no arquivo .c

    Vantagens de usar TAD (separar implementação de especificação):
    -> Reutilização: (não precisa passar o código fonte, então não precisa ficar recompilando coisas)
    -> Facilidade de manutenção: (mudanças na implementação não afetam o código fonte dos programas que o utilizam (ocultamento de informação))
    -> Corretude: (códigos testados em diferentes contextos)

*/