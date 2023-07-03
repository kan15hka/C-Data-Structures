#include<stdio.h>
#include<stdlib.h>

//*******************************************
//** STACK
#define size 10

struct stack {
	
	int count;
	char* stack[size];
} s;

void display() {
	
	if(s.count == 0) {
		
		printf("Stack is empty!");
	}
	else {
		
		printf("Stack data:");
		for(int i = s.count - 1; i >= 0; i--) {
			
			printf("\n");
			printf("%s", s.stack[i]);
		}
	}
	
	printf("\n");
}

void stack_push(char* c) {
		
	if(s.count < size) {
		
		s.stack[s.count] = c;
		s.count = s.count + 1;
	}
}

char* stack_pop() {
	
	char* item;
	
	if(s.count > 0) {
		
		s.count = s.count - 1;
		item = s.stack[s.count];
	}

	return item;
}

int stack_isEmpty() {

	return s.count == 0;
}
//*******************************************
//** Aux operations
int isOperand(char c) {
	
	return c >= 'A' && c <= 'Z';
}

char* operators = "+-*/^\0";

int isOperator(char c) {
	
	int result = 0;
	
	for(int i = 0; operators[i] != '\0'; i++) {
		
		if(operators[i] == c) {
			
			result = 1;
			break;
		}
	}
	
	return result;
}

int getPrecedence(char c) {

	int result = 0;
	
	for(int i = 0; operators[i] != '\0'; i++) {
		
		result++;
		
		// +-*/^ - operators order
		if(operators[i] == c) {
		
			if(c == '-' || c == '/') 
				result--;
			
			break;		
		}
	}
	
	return result;	
}

int getLowestPrecMainOp(char* subExpression) {
	
	int lowest = 100;
	
	int parenthesesCount = 0;
	for(int i = 0; subExpression[i] != '\0'; i++) {
		
		char c = subExpression[i];
		
		if(parenthesesCount == 0 && isOperator(c)) {
			
			int opPrecedence = getPrecedence(c);
			
			if(opPrecedence < lowest) {
				
				lowest = opPrecedence;
			}
		}
		else if(c == '(') {
			
			parenthesesCount++;
		}
		else if(c == ')') {
			
			parenthesesCount--;
		}
	}
	
	return lowest;
}

char* concatCharP(char* start, char* middle, char* end) {
	
	char* result = malloc(sizeof(char));
	
	int idx = 0;
	for(int i = 0; start[i] != '\0'; i++)
		result[idx++] = start[i];
	
	for(int i = 0; middle[i] != '\0'; i++)
		result[idx++] = middle[i];
	
	for(int i = 0; end[i] != '\0'; i++)
		result[idx++] = end[i];
	
	result[idx] = '\0';
	
	return result;
}
//*******************************************
//** to Infix
void toInfix(char* expression) {

	char* result;
	
	for(int i = 0; expression[i] != '\0'; i++) {
		
		char* cp = malloc(sizeof(char));
		cp[0] = expression[i];
		
		if(isOperand(cp[0])) {
			
			stack_push(cp);
		}
		else { // is operator
			
			char* exp2 = stack_pop();
			char* exp1 = stack_pop();
			
			int opPrecedence = getPrecedence(cp[0]);
			int lowestPrecExp2 = getLowestPrecMainOp(exp2);
			int lowestPrecExp1 = getLowestPrecMainOp(exp1);
			
			if(lowestPrecExp2 < opPrecedence) {
				
				exp2 = concatCharP("(", exp2, ")");
			}
			if(lowestPrecExp1 < opPrecedence) {
				
				exp1 = concatCharP("(", exp1, ")");
			}	

			char* newExpression = concatCharP(exp1, cp, exp2);
			
			stack_push(newExpression);
		}
	}
	
	result = stack_pop();
	printf("Infix: %s\n", result);
}
//*******************************************
//** main
char* readLine() {
	
	char* result = malloc(sizeof(char));
	
	int idx = 0;
	char c;
	while((c = getchar()) != '\n' && c != EOF) {
		
		result[idx++] = c;
	}
	result[idx] = '\0';
	
	return result;
}

int main() {

	int test = 1;
	
	if(test == 0) {
		printf("Insert expression: ");
		char* expression = readLine();
	
		toInfix(expression);		
	}
	else {

		char* expressions[] = {
			"AB+C/", 						// (A+B)/C
			"ABC/+",						// A+B/C
			"ABCD*+*E+",				// A*(B+C*D)+E
			"ABCDE-/+*", 				// A*(B+C/(D-E))
			"AB+C*DEFG*+/+H-",	// (A+B)*C+D/(E+F*G)-H
			
			"AB/C+",						// A/B+C
			"ABC+/", 						// A/(B+C)
			"AB*CD*+E*",				// (A*B+C*D)*E
			"ABC^*D+",					// A*B^C+D
			"ABC*DEF^/G*-H*+",	// A*(B*C-D/E^F*G)*H
			"AB-CDEF/+G-*-H-"		// A-B-C*(D+E/F-G)-H
		};
		
		int sizeExp = sizeof(expressions) / sizeof(expressions[0]);
		for(int i = 0; i < sizeExp; i++) {

			char* expression = expressions[i];
					
			printf("%d)\n", i + 1);
			printf("Postfix: %s\n", expression);
			toInfix(expression);	
			
			printf("\n");
		}		
	}

	return 0;
}