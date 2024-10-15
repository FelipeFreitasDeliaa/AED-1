/*Felipe Freitas D' Elia
            RA: 176284*/

#include <stdio.h>´
#include <math.h>
 
int main() {
 
    double raio;
    double area;
    
    scanf ("%lf", &raio);
    
    area = 3.14159 * (pow (raio, 2));
    
    printf ("A=%.4lf\n",area);
    
    return 0;
}
