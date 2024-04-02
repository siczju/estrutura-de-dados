/*
        Pilha estática
    A pilha S[0..99] possui parte ocupada S[0..top]
    O indice top define o topo da pilha
    A pilha está vazia se top == -1 (indice invalido)
    A pilha está cheia se top == size - 1

    Empilhar (push) um elemento y>
     -> S[++top] = y // idem a(top++; S[top] = y);
    Consultar (peek) um elemento da pilha sem desempilha-lo (retorna o ultimo valor):
     -> x = S[top]
    Desempilhar(pop) um elemento da pilha (retorna o valor excluido):
     x S[top--] // ideam a(x = s[top]; top--);
*/