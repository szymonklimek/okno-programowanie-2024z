#include <functions.h>
#include <stdio.h>

int main()
{
    char name[30];
    struct Point pointA, pointB, pointC;
    struct Triangle triangle;

    printf("Podaj swoje imię: ");
    fgets(name, sizeof(name), stdin);

    printf("Cześć %s", name);

    printf("Podaj współrzędną X punktu A.: ");
    scanf("%d", &pointA.x);

    printf("Podaj współrzędną Y punktu A.: ");
    scanf("%d", &pointA.y);

    printf("Podaj współrzędną X punktu B.: ");
    scanf("%d", &pointB.x);

    printf("Podaj współrzędną Y punktu B.: ");
    scanf("%d", &pointB.y);

    printf("Podaj współrzędną X punktu C.: ");
    scanf("%d", &pointC.x);

    printf("Podaj współrzędną Y punktu C.: ");
    scanf("%d", &pointC.y);

    printf("Punkt A: (%d, %d)\n", pointA.x, pointA.y);
    printf("Punkt B: (%d, %d)\n", pointB.x, pointB.y);
    printf("Punkt C: (%d, %d)\n", pointC.x, pointC.y);

    triangle = createTriangle(pointA, pointB, pointC);
    printf(
        "Trójkąt o wierzchołkach A(%d, %d), B(%d, %d), C(%d, %d) został utworzony.\n",
        triangle.cornerA.x, triangle.cornerA.y, triangle.cornerB.x, triangle.cornerB.y,
        triangle.cornerC.x, triangle.cornerC.y
    );
    return 0;
}
