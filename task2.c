#include<math.h>
#include<stdio.h>


double evaluation(double R);

int main(){
    double R, result;
    scanf("%lf",&R);
    result = evaluation(R);
    printf("%.0lf", result);
    return 0;
}

double evaluation(double R){
    double V;
    double P = 21500;
    V = (4.0 / 3.0) * M_PI * pow(R,3);
    double m = V * P;
    return m;
}