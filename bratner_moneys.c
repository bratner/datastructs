// bratner_moneys.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

void paym_do(int sum, int cur_index, int cur_quant);

int vmtypes[]={100,50,20,10,5,1};
int vmqnty[]={2,7,3,5,2,9};
int amnt=sizeof(vmqnty)/sizeof(int);

void paym(int sum){
    paym_do(sum, 0, vmqnty[0]);
}
void paym_do(int sum, int cur_index, int cur_quant){
    if(sum==0) {
        if(vmqnty[cur_index]-cur_quant)
            printf("%d x %d\n", vmtypes[cur_index], vmqnty[cur_index]-cur_quant);
        return;
    }
   
    if(cur_index==(amnt-1) && cur_quant == 0 ){
        printf("Can't really do it!\n");
        return;
    }
    if(sum < vmtypes[cur_index] || cur_quant == 0){

        if(vmqnty[cur_index]-cur_quant)
            printf("%d x %d\n", vmtypes[cur_index], vmqnty[cur_index]-cur_quant );

        paym_do(sum, cur_index+1, vmqnty[cur_index+1]);
        return;
    }
    //printf("%d\n",vmtypes[cur_index]);
    paym_do(sum - vmtypes[cur_index], cur_index, cur_quant - 1);           
}
int main(int argc, char * argv[])
{
    paym(393);
//    scanf("%d", &argc);
    return 0;
}

