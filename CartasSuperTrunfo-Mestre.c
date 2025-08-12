#include <stdio.h>

// Função mostrar Resultado
void mostrarResultado(char* atributo, float valor1, float valor2, int tipoMaiorVence);

int main() {
    // Carta 1
    char estado1;
    char codigo1[4];
    char nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos1;
    float densidade1, pibPerCapita1, superPoder1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos2;
    float densidade2, pibPerCapita2, superPoder2;

    // Comparações
    int vPopulacao, vArea, vPIB, vPontos, vDensidade, vPerCapita, vSuperPoder;

    // Entrada Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: A): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // Cálculos Carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superPoder1 = populacao1 + area1 + pib1 + pontos1 + (1 / densidade1) + pibPerCapita1;

    // Entrada Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: B): ");
    scanf(" %c", &estado2);
    printf("Código (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder2 = populacao2 + area2 + pib2 + pontos2 + (1 / densidade2) + pibPerCapita2;

    // Comparações
    vPopulacao   = populacao1 > populacao2;
    vArea        = area1 > area2;
    vPIB         = pib1 > pib2;
    vPontos      = pontos1 > pontos2;
    vDensidade   = densidade1 < densidade2; // menor vence
    vPerCapita   = pibPerCapita1 > pibPerCapita2;
    vSuperPoder  = superPoder1 > superPoder2;

    // Exibição dos resultados
    printf("\n=== Comparação das Cartas ===\n");
    mostrarResultado("População", populacao1, populacao2, 1);
    mostrarResultado("Área", area1, area2, 1);
    mostrarResultado("PIB", pib1, pib2, 1);
    mostrarResultado("Pontos turísticos", pontos1, pontos2, 1);
    mostrarResultado("Densidade Populacional", densidade1, densidade2, 0); // menor vence
    mostrarResultado("PIB per Capita", pibPerCapita1, pibPerCapita2, 1);
    mostrarResultado("Super Poder", superPoder1, superPoder2, 1);

    return 0;
}

void mostrarResultado(char* atributo, float valor1, float valor2, int tipoMaiorVence) {
    printf("%s: ", atributo);
    if (valor1 == valor2) {
        printf("Empate\n");
    } else if ((tipoMaiorVence && valor1 > valor2) || (!tipoMaiorVence && valor1 < valor2)) {
        printf("Carta 1 venceu\n");
    } else {
        printf("Carta 2 venceu\n");
    }
}
