#include <stdio.h>
#include <string.h>

// Estrutura para representar a carta de um país
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    float densidadeDemografica; // População / Área
} Carta;

// Função para exibir os atributos de forma organizada
void mostrarCarta(Carta c) {
    printf("\n===== %s =====\n", c.nome);
    printf("1 - População: %d\n", c.populacao);
    printf("2 - Área: %.2f km²\n", c.area);
    printf("3 - PIB: %.2f bilhões\n", c.pib);
    printf("4 - Densidade Demográfica: %.2f hab/km²\n", c.densidadeDemografica);
}

// Função que retorna o valor de um atributo específico
float obterAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidadeDemografica;
        default: return -1;
    }
}

// Função que retorna o nome do atributo
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213000000, 8516000, 2200, 213000000.0 / 8516000};
    Carta carta2 = {"Argentina", 46000000, 2780000, 500, 46000000.0 / 2780000};

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO: Comparação Avançada ===\n");
    
    printf("\nCarta 1: ");
    mostrarCarta(carta1);
    
    printf("\nCarta 2: ");
    mostrarCarta(carta2);

    // Escolha do primeiro atributo (com validação via switch)
    do {
        printf("\nEscolha o primeiro atributo (1 a 4): ");
        scanf("%d", &atributo1);

        switch(atributo1) {
            case 1: case 2: case 3: case 4:
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                atributo1 = 0; // força repetição
        }
    } while (atributo1 == 0);

    // Escolha do segundo atributo (menu dinâmico)
    do {
        printf("\nEscolha o segundo atributo (diferente de %s):\n", nomeAtributo(atributo1));
        for (int i = 1; i <= 4; i++) {
            if (i != atributo1) {
                printf("%d - %s\n", i, nomeAtributo(i));
            }
        }
        printf("Sua escolha: ");
        scanf("%d", &atributo2);

        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 4) {
            printf("Opção inválida! Escolha outro atributo.\n");
            atributo2 = 0;
        }
    } while (atributo2 == 0);

    // Obter valores dos atributos escolhidos
    float valor1_c1 = obterAtributo(carta1, atributo1);
    float valor1_c2 = obterAtributo(carta2, atributo1);
    float valor2_c1 = obterAtributo(carta1, atributo2);
    float valor2_c2 = obterAtributo(carta2, atributo2);

    int pontos_c1 = 0, pontos_c2 = 0;

    // Comparação do primeiro atributo
    printf("\n--- Comparando %s ---\n", nomeAtributo(atributo1));
    if (atributo1 == 4) {
        if (valor1_c1 < valor1_c2) { pontos_c1++; printf("%s venceu!\n", carta1.nome); }
        else if (valor1_c2 < valor1_c1) { pontos_c2++; printf("%s venceu!\n", carta2.nome); }
        else printf("Empate neste atributo!\n");
    } else {
        if (valor1_c1 > valor1_c2) { pontos_c1++; printf("%s venceu!\n", carta1.nome); }
        else if (valor1_c2 > valor1_c1) { pontos_c2++; printf("%s venceu!\n", carta2.nome); }
        else printf("Empate neste atributo!\n");
    }

    // Comparação do segundo atributo
    printf("\n--- Comparando %s ---\n", nomeAtributo(atributo2));
    if (atributo2 == 4) {
        if (valor2_c1 < valor2_c2) { pontos_c1++; printf("%s venceu!\n", carta1.nome); }
        else if (valor2_c2 < valor2_c1) { pontos_c2++; printf("%s venceu!\n", carta2.nome); }
        else printf("Empate neste atributo!\n");
    } else {
        if (valor2_c1 > valor2_c2) { pontos_c1++; printf("%s venceu!\n", carta1.nome); }
        else if (valor2_c2 > valor2_c1) { pontos_c2++; printf("%s venceu!\n", carta2.nome); }
        else printf("Empate neste atributo!\n");
    }

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s -> %s: %.2f | %s: %.2f | Soma = %.2f\n", 
           carta1.nome, nomeAtributo(atributo1), valor1_c1, nomeAtributo(atributo2), valor2_c1, soma_c1);
    printf("%s -> %s: %.2f | %s: %.2f | Soma = %.2f\n", 
           carta2.nome, nomeAtributo(atributo1), valor1_c2, nomeAtributo(atributo2), valor2_c2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\n>>> Vencedor da rodada: %s <<<\n", carta1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("\n>>> Vencedor da rodada: %s <<<\n", carta2.nome);
    } else {
        printf("\n>>> Empate! <<<\n");
    }

    return 0;
}
