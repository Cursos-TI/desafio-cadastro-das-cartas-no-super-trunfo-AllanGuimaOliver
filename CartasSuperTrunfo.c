#include <stdio.h>

int main() {
    
    // Variáveis da primeira carta
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Variáveis da segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Cadastro da primeira carta
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a Area (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cadastro da segunda carta
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Calcular densidade demográfica
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int opcao;
    do {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        printf("\n=== RESULTADO ===\n");
        switch(opcao) {
            case 1: // População
                printf("Atributo: População\n");
                printf("%s: %d habitantes\n", nomeCidade1, populacao1);
                printf("%s: %d habitantes\n", nomeCidade2, populacao2);
                if(populacao1 > populacao2)
                    printf("Vencedor: %s\n", nomeCidade1);
                else if(populacao1 < populacao2)
                    printf("Vencedor: %s\n", nomeCidade2);
                else
                    printf("Empate!\n");
                break;

            case 2: // Área
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", nomeCidade1, area1);
                printf("%s: %.2f km²\n", nomeCidade2, area2);
                if(area1 > area2)
                    printf("Vencedor: %s\n", nomeCidade1);
                else if(area1 < area2)
                    printf("Vencedor: %s\n", nomeCidade2);
                else
                    printf("Empate!\n");
                break;

            case 3: // PIB
                printf("Atributo: PIB\n");
                printf("%s: %.2f bilhões\n", nomeCidade1, pib1);
                printf("%s: %.2f bilhões\n", nomeCidade2, pib2);
                if(pib1 > pib2)
                    printf("Vencedor: %s\n", nomeCidade1);
                else if(pib1 < pib2)
                    printf("Vencedor: %s\n", nomeCidade2);
                else
                    printf("Empate!\n");
                break;

            case 4: // Pontos turísticos
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
                printf("%s: %d\n", nomeCidade2, pontosTuristicos2);
                if(pontosTuristicos1 > pontosTuristicos2)
                    printf("Vencedor: %s\n", nomeCidade1);
                else if(pontosTuristicos1 < pontosTuristicos2)
                    printf("Vencedor: %s\n", nomeCidade2);
                else
                    printf("Empate!\n");
                break;

            case 5: // Densidade demográfica (menor vence)
                printf("Atributo: Densidade Demográfica\n");
                printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
                printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);
                if(densidade1 < densidade2)
                    printf("Vencedor: %s\n", nomeCidade1);
                else if(densidade1 > densidade2)
                    printf("Vencedor: %s\n", nomeCidade2);
                else
                    printf("Empate!\n");
                break;

            case 0:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opção inválida! Escolha entre 0 e 5.\n");
        }

    } while(opcao != 0);

    return 0;
}