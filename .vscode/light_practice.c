#include <stdio.h>

int main(){

    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nEnter in radius in inches: ");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("\nThe circumference of your circle is %lf inches", circumference);
    printf("\nThe area of your circle is %lf inches.", area);
}
