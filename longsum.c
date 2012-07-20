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

int add_digit(struct dlist * list, unsigned char num ){
	struct digit * tmp;
	tmp = list->head;
	if(tmp){
		while(tmp->next)
			tmp = tmp->next;
		
		if((tmp->next = malloc(sizeof(struct digit))) == NULL)
			return 0;
		tmp = tmp->next;
		
	}else{
		if((list->head = malloc(sizeof(struct digit))) == NULL)
			return 0;
		tmp = list->head;
		
	}
	tmp->next = NULL;
	tmp->digit = num;
	return 1;
}

struct dlist * num2list(long long num){
	struct dlist * ret;
	unsigned char i;
        ret = malloc(sizeof(struct dlist));
	ret->head = NULL;
	if (!ret)
		return NULL;
	if ( num < 0 ) {
		ret->sign = -1;
		num *= -1;
	}else{	
		ret->sign = 1;
	}
	//if(!(ret->head = new_head()))
	//	return NULL;
	

	while(num){
		i = num % 10;
		num /= 10;
		if(!add_digit(ret, i))
			return NULL;
	}
	return ret;
	
};

void print_digits(struct digit * digit){
	
	if (!digit ){
		return;		
	}else{
		print_digits(digit->next);		
	}
	printf("%d",digit->digit);
}
void print_list(struct dlist * list){
	if(!list){
		return;
	}else if(list->sign == -1){
		printf("-");	      
	}
	print_digits(list->head);
}

int main(int argc, char * argv[]){
	// free stuff
	struct dlist * test;
	printf("%ld\n", sizeof(long long));
	test = num2list(1234567890);
	if(test)
	    print_list(test);
	return 0;
}
