#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct strStack{
	char string[100];
	struct strStack * top;
};

struct intStack{
	double val;
	struct intStack * top;
};

int checkString(const char *);
int isNum(const char *);
int stringToInt(const char *);
char* postfixToInfix(int, const char **);
struct strStack* strPush(struct strStack*, char*);
struct strStack* strPop(struct strStack*);
char* strPeek(struct strStack*);
struct intStack* intPush(struct intStack*, double);
struct intStack* intPop(struct intStack*);
double intPeek(struct intStack*);
double evaluate(int, const char **);
int strIsOnly(struct strStack*);
int intIsOnly(struct intStack*);
int strOperatorIsValid(struct strStack*);
int intOperatorIsValid(struct intStack*);

int main(int argc, const char * argv[]){
	printf("The expression yielded: %f\n", evaluate(argc, argv));

	printf("The infix equivalent: %s\n", postfixToInfix(argc, argv));

	return 0;
}

int checkString(const char * string){
	char current = string[0];
	int x = 0;

	do{
		// if there is anything not numbers or 'x' '/' '+' '-'
		if ((current < 48 || current > 57) && current != 43 && current != 45 && current != 47 && current != 120){
			return 0;
		}
		// if there are more than one 'x' '/' '+' '-'
		if ((current == 120 || current == 43 || current == 45 || current == 47) && x > 0){
			return 0;
		}
		x++;
		current = string[x];
	} while (current != '\0');

	return 1;
}

// assumes checkString has already been called
int isNum(const char * string){
	if (string[0] > 47 && string[0] < 58){
		return 1;
	} else {
		return 0;
	}
}

// assumes checkString has already been called
int stringToInt(const char * string){
	char current = string[0];
	int x = 1, val = 0;

	switch (current){
		case 49:
			val += 1;
			break;
		case 50:
			val += 2;
			break;
		case 51:
			val += 3;
			break;
		case 52:
			val += 4;
			break;
		case 53:
			val += 5;
			break;
		case 54:
			val += 6;
			break;
		case 55:
			val += 7;
			break;
		case 56:
			val += 8;
			break;
		case 57:
			val += 9;
			break;
	}

	current = string[1];

	while (current != '\0'){
		val *= 10;

		switch (current){
			case 49:
				val += 1;
				break;
			case 50:
				val += 2;
				break;
			case 51:
				val += 3;
				break;
			case 52:
				val += 4;
				break;
			case 53:
				val += 5;
				break;
			case 54:
				val += 6;
				break;
			case 55:
				val += 7;
				break;
			case 56:
				val += 8;
				break;
			case 57:
				val += 9;
				break;
		}
		x++;
		current = string[x];
	}

	return val;
}

char* postfixToInfix(int count, const char * strings[]){
	struct strStack* stack = NULL;
	int x;
	char exp1[100], exp2[100], rexp[100];
	for (x = 1; x < count; x++){
		if (!checkString(strings[x])){
			return ("ERROR: unacceptable characters in string!");
		}
		if (isNum(strings[x])){
			strcpy(exp1, strings[x]);
			stack = strPush(stack, exp1);
		} else if(strOperatorIsValid(stack)){
			strcpy(exp1, strPeek(stack));
			stack = strPop(stack);
			strcpy(exp2, strPeek(stack));
			stack = strPop(stack);
			strcpy(rexp, "(");
			strcat(rexp, exp2);
			strcat(rexp, strings[x]);
			strcat(rexp, exp1);
			strcat(rexp, ")");
			stack = strPush(stack, rexp);
		} else{
			return("ERROR: operator cannot operate on less than two operands!");
		}
	}
	if (strIsOnly(stack)){
		return(strPeek(stack));
	} else {
		return("ERROR: unrseloved operands!");
	}
}

struct strStack* strPush(struct strStack* stack, char* s){
	if (stack == NULL){
		stack = malloc(sizeof(struct strStack));
		strcpy(stack->string, s);
		stack->top = NULL;
		return stack;
	} else {
		struct strStack* bottom = malloc(sizeof(struct strStack));
		strcpy(bottom->string, s);
		bottom->top=stack;
		return bottom;
	}
}

struct strStack* strPop(struct strStack* stack){
	struct strStack* new = stack->top;
	free(stack);
	return new;
}

char* strPeek(struct strStack* stack){
	return stack->string;
}

struct intStack* intPush(struct intStack* stack, double d){
	if (stack == NULL){
		stack = malloc(sizeof(struct intStack));
		stack->val = d;
		stack->top = NULL;
		return stack;
	} else {
		struct intStack* bottom = malloc(sizeof(struct intStack));
		bottom->val = d;
		bottom->top=stack;
		return bottom;
	}
}

struct intStack* intPop(struct intStack* stack){
	struct intStack* new = stack->top;
	free(stack);
	return new;
}

double intPeek(struct intStack* stack){
	return stack->val;
}

double evaluate(int argc, const char * argv[]){
	struct intStack* stack = NULL;
	double num1, num2;
	int x;
	for (x = 1; x < argc; x++){
		if (!checkString(argv[x])){
			return 0;
		}
		if (isNum(argv[x])){
			stack = intPush(stack, (double)stringToInt(argv[x]));
		} else {
			if (!intOperatorIsValid(stack)){
				return 0;
			} else {
				num2 = intPeek(stack);
				stack = intPop(stack);
				num1 = intPeek(stack);
				stack = intPop(stack);
				switch (argv[x][0]){
					case '+':
						stack = intPush(stack, num1 + num2);
						break;
					case '-':
						stack = intPush(stack, num1 - num2);
						break;
					case 'x':
						stack = intPush(stack, num1 * num2);
						break;
					case '/':
						stack = intPush(stack, num1 / num2);
						break;
				}
			}
		}
	}

	if (intIsOnly(stack)){
		return intPeek(stack);;
	} else {
		return 0;
	}
}

int strIsOnly(struct strStack* stack){
	if (stack == NULL){
		return 0;
	} else if (stack->top != NULL){
		return 0;
	} else {
		return 1;
	}
}

int intIsOnly(struct intStack* stack){
	if (stack == NULL){
		return 0;
	} else if (stack->top != NULL){
		return 0;
	} else {
		return 1;
	}
}

int strOperatorIsValid(struct strStack* stack){
	if (stack == NULL){
		return 0;
	} else if (stack->top == NULL){
		return 0;
	} else {
		return 1;
	}
}

int intOperatorIsValid(struct intStack* stack){
	if (stack == NULL){
		return 0;
	} else if (stack->top == NULL){
		return 0;
	} else {
		return 1;
	}
}
