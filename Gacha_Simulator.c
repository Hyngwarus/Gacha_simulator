#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int pulls=0, pity_activation=0, pity_increase=0, price=0, cost=0, pity=0, l_count=0, ur_count=0, sr_count=0, r_count=0, c_count=0, current_pity=0;
    int legendary, ultra_rare, super_rare, rare, common, current_pulls;
    getc(stdin);
    puts("Write the price (in game currency) for one pull");
    scanf("%i", &price);
    puts("Write the number of pulls required to activate the pity (leave 0 if there's no pity)");
    scanf("%i", &pity_activation);
    if(pity_activation)
    {
        puts("Write the pity (chances to get the best result after a number of pulls)");
        scanf("%i", &pity);
        puts("Write the pity increase (if the result isn't the desired, it'll increase the pity until the desired result is achieved)");
        scanf("%i", &pity_increase);
    }
    puts("Write the chance to get a legendary");
    scanf("%i", &legendary);
    puts("Write the chance to get an ultra rare");
    scanf("%i", &ultra_rare);
    puts("Write the chance to get a super rare");
    scanf("%i", &super_rare);
    puts("Write the chance to get a rare");
    scanf("%i", &rare);
    common=10000-legendary-ultra_rare-super_rare-rare;
    rare=common+rare;
    super_rare=rare+super_rare;
    ultra_rare=super_rare+ultra_rare;
    legendary=10000;
    int running=1, number, rng, no_luck=0;
    while(running)
    {
        system("cls");
        printf("pulls: %i \t\tcost: %i\n", pulls, cost);
        printf("Legendary pulls:\t %i\n", l_count);
        printf("Ultra rare pulls:\t %i\n", ur_count);
        printf("Super rare pulls:\t %i\n", sr_count);
        printf("Rare pulls:\t %i\n", r_count);
        printf("Common pulls:\t %i\n", c_count);
        puts("OPTIONS:");
        puts("1. Do a number of pulls");
        puts("0. Exit");
        scanf("%i", &running);
        switch(running)
        {
        case 1:
            puts("Write the number of pulls");
            scanf("%i", &current_pulls);
            pulls=pulls+current_pulls;
            cost=cost+price*current_pulls;
            for(number=0; number<current_pulls; number++)
            {
                if(pity_activation){
                rng=rand()%10001+pity+(pity_increase*no_luck);}
                else{
                    rng=rand()%10001;
                }
                if(rng>ultra_rare)
                {
                    l_count++;
                    if(pity_activation)
                    {
                        current_pity=0;
                        no_luck=0;
                    }
                    printf("L ");
                }
                else if((rng<=ultra_rare)&&(rng>super_rare))
                {
                    ur_count++;
                    if(pity_activation)
                    {
                        if(pity_activation==current_pity)
                        {
                            no_luck++;
                        }
                        else
                            current_pity++;

                    }
                    printf("UR ");
                }
                else if((rng<=super_rare)&&(rng>rare))
                {
                    sr_count++;
                    if(pity_activation)
                    {
                        if(pity_activation==current_pity)
                        {
                            no_luck++;
                        }
                        else
                            current_pity++;

                    }
                    printf("SR ");
                }
                else if((rng<=rare)&&(rng>common))
                {
                    r_count++;
                    if(pity_activation)
                    {
                        if(pity_activation==current_pity)
                        {
                            no_luck++;
                        }
                        else
                            current_pity++;

                    }
                    printf("R ");
                }
                else
                {
                    c_count++;
                    if(pity_activation)
                    {
                        if(pity_activation==current_pity)
                        {
                            no_luck++;
                        }
                        else
                            current_pity++;

                    }
                    printf("C ");
                }
            }
            getc(stdout);
            break;
        case 0:
            break;
        }
    }
}
