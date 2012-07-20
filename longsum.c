#include <stdio.h>
#include <stdlib.h>

struct digit{
	//struct digit * prev;
	struct digit * next;
	unsigned char digit;
	
};
struct dlist {
	char sign;
	struct digit * head;
};

struct digit * new_head(){
	struct digit * tmp;
	tmp = malloc(sizeof(struct digit));
	if(!tmp)
		return NULL;
	tmp->next = NULL;
	return tmp;
}

void add_digit(struct dlist * list, char num ){
	struct digit * tmp;
	tmp = list->head;
	if(tmp)
	   while(tmp->next)
		tmp++;
	
}

struct dlist * num2list(long long num){
	struct dlist * ret;
	char i,j;
        ret = malloc(sizeof(dlist));
	if (!ret)
		return NULL;
	if ( num < 0 ) {
		ret.sign = -1;
	}else{	
		ret.sign = 1;
	}
	if( ! (ret->head = new_head() ) )
		return NULL;
	

	while(num){
		i = num % 10;
		num /= 10;
		add_digit(ret, i);
	}
	
};
int main(int argc, char * argv[]){
	// free stuff
	printf("%ld\n", sizeof(long long));
	return 0;
}
