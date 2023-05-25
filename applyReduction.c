#include <stdio.h>

float ft_atoi(char *str){ 
    
    float   nbr;
    int     x;
    int     y;

    nbr = 0;
    x = 0;
    y = 10;

    if(str[x] >= 48 && str[x] <= 57)
    {
        while (str[x] && str[x] >= 48 && str[x] <= 57)
        {
            if(x == 0)
                nbr = str[0] - 48;
            else
                nbr = nbr * 10 + (str[x] - 48);
            x++;
        }

        if(str[x] == 46)
        {
            while (str[x++] && str[x] >= 48 && str[x] <= 57)
            {
                float i = str[x] - 48;
                i = i / y;
                nbr = nbr + i;
                y = y * 10;
            }
        }
    }
    return nbr;
}

float ft_applyReduction(float   nbr, float  reduction) {

    float x;
    float y;

    y = reduction - 100;
    x = nbr/100 * y;
    return x;
}

float ft_applyReductionStr(char *nbr, char  *reduction)
{
    float nbr_convert;
    float reduction_convert;

    nbr_convert = ft_atoi(nbr);
    reduction_convert = ft_atoi(reduction);
    return ft_applyReduction(nbr_convert, reduction_convert);
}

int main(int size, char * str[]) {
    if(size == 3){
        if (ft_atoi(str[1]) < 0 || ft_atoi(str[2]) < 0)
        {
            printf("Error Pls use : Prog1.exe <positive number>");
            return 1;
        }
        float i = ft_applyReductionStr(str[1], str[2]);
        printf("result : %f", i);
    }
    else {
        printf("Error Pls use : Prog1.exe <positiv number>");
    }
    return 1;
}