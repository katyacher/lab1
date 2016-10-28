/*
 * lab1.c
 *Вариант 15. Программа принимает от пользователя три строки, (первая и
третья строки – это правильные рациональные или десятичные дроби вида
«1/3» или «0,5», вторая строка – это знак арифметической операции вида «+»,
«-», «*», «/» либо операции сравнения «<», «>», «=», «!=», «>=», «<=»),
выполняет требуемую операцию над полученными операндами, и выводит
результат на экран. Обеспечить также сокращение дроби при необходимости.
Если оба операнда арифметической операции являются рациональными
дробями, результатом тоже должна быть рациональная дробь. Для операций
сравнения достаточно результата «Истина» или «Ложь».
 *  Created on: Oct 21, 2016
 *      Author: kate
 */


#include <stdio.h>
#include <unistd.h>
#include <string.h> // strcmp()
#include <math.h> // fabs()
#include <sys/types.h>

int nod(int a, int b) { //  Euklidian algorithm -  input two numbers, out the greatest common divisor (NOD)
   int c;
   while (b) {
      c = a % b;
      a = b;
      b = c;
   }
   return fabs(a);
 }
 
void fraction_reduction (int *a, int *b){// function for fraction reduction - input  two pointers of numerator and denominator
	int Lnod =  nod(*a,*b);
	*a /= Lnod;
	*b /= Lnod;
}

void stdin_free(){			// функция для очистки stdin
	while(1) {
		int value = getchar();
		if (value == EOF || value=='\n') break;
	};
}

int main(){
	int numerator_1, denominator_1;				//числитель и знаменатель первой дроби
	int numerator_2, denominator_2;				//числитель знаменатель второй дроби
	int result_num, result_den;					//результаты действий над дробями
	char operator[3];							//оператор
	float float_value_1, float_value_2;
	int option_1,option_2;						// различать поступившие данные (рац.дробь или десятична дробь)
	// запрос и ввод данных
	while(1){
		printf("Enter first value:");
		if (scanf("%i/%i",&numerator_1, &denominator_1) == 2){
			if (denominator_1 != 0){ 							// проверка знаменателя
				option_1 = 0;									// введена рациональная дробь
				float_value_1 = numerator_1/denominator_1;
				stdin_free();
				break;
			} else {
				printf("incorrect value\n");
				stdin_free();
				continue;
			}
		} else {
			if (scanf("%f", &float_value_1)==1){
				option_1 = 1;// введена десятичная дробь
				stdin_free();
				break;
			} else {
				printf("incorrect value\n");
				stdin_free();
				continue;
			};
		};
	};

	printf("Enter operator: + - * / > < >= <= != =:\n");
	scanf("%[+-*/><=!]2s", operator);
	stdin_free();

	while (1){
		printf("Enter second value:\n");
		if (scanf("%i/%i",&numerator_2, &denominator_2) ==2){
			if (denominator_2 != 0){ 						// проверка знаменателя
				option_2 = 0;								// введена рациональная дробь
				float_value_2 = numerator_2/denominator_2;
				stdin_free();
				break;
			} else {
				printf("incorrect value\n");
				stdin_free();
				continue;
			}
		} else {
			if (scanf("%f", &float_value_2)==1){
				option_2 = 1;								// введена десятичная дробь
				stdin_free();
				break;
			} else {
				printf("incorrect value\n");
				stdin_free();
				continue;
			}
		};
	};

	if (option_1 == 0 && option_2 == 0){		// выполнение действий с рациональными дробями
		if (!strcmp (operator, "+")==0){
			result_num = numerator_1*denominator_2 + numerator_2*denominator_1;
			result_den = denominator_1*denominator_2;
			fraction_reduction(&result_num, &result_den);			//  сокращение дроби
			printf("the answer is %i/%i", result_num, result_den );
		}else if (!strcmp (operator, "-")==0){
			result_num = numerator_1*denominator_2 - numerator_2*denominator_1;
			result_den = denominator_1*denominator_2;
			fraction_reduction(&result_num, &result_den);
			printf("the answer is %i/%i", result_num, result_den );
		}else if (!strcmp (operator, "*")==0){
			result_num = numerator_1*numerator_2;
			result_den = denominator_1*denominator_2;
			fraction_reduction(&result_num, &result_den);
			printf("the answer is %i/%i", result_num, result_den );
		}else if (!strcmp (operator, "/")==0){
			result_num = numerator_1*denominator_2;
			result_den = denominator_1*numerator_2;
			fraction_reduction(&result_num, &result_den);
			printf("the answer is %i/%i", result_num, result_den );
		}else if (!strcmp (operator, ">")==0){
			if (float_value_1 > float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "<")==0){
			if (float_value_1 < float_value_2){
				printf("True");
			} else {
			printf("False");
			};
		}else if (!strcmp (operator, ">=")==0){
			if (float_value_1 >= float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "<=")==0){
			if (float_value_1 <= float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "!=")==0){
			if (float_value_1 != float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "=")==0){
			if (float_value_1 == float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else {
			printf ("unknown operator\n");
		};
	}
	else {															// действия с десятичными дробями
		if (!strcmp (operator, "+")==0){
			printf("%.3f\n",float_value_1 + float_value_2);
		 }else if (!strcmp (operator, "-")==0){
			printf("%.3f\n",float_value_1 - float_value_2);
		 }else if (!strcmp (operator, "*")==0){
			printf("%.3f\n",float_value_1 * float_value_2);
		 }else if (!strcmp (operator, "/")==0){
			printf("%.3f\n",float_value_1 / float_value_2);
		 }else if (!strcmp (operator, ">")==0){
			if (float_value_1 > float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "<")==0){
			if (float_value_1 < float_value_2){
				printf("True");
			} else {
			printf("False");
			};
		}else if (!strcmp (operator, ">=")==0){
			if (float_value_1 >= float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "<=")==0){
			if (float_value_1 <= float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "!=")==0){
			if (float_value_1 != float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else if (!strcmp (operator, "=")==0){
			if (float_value_1 == float_value_2){
				printf("True");
			} else {
				printf("False");
			};
		}else {
			printf ("unknown operator\n");
		};
	};
	return 0;
	getchar();
};


/*
пример создания дочернего процесса

int main()
{
  pid_t childPid;

  printf("The main program PID is %d\n", getpid());
  childPid = fork();
  if(0 != childPid)
  {
    printf("This is parent process, its PID is %d\n", getppid());
    printf("The child's PID is %d\n", childPid);
  }
  else
  {
    printf("This is child process, its PID is %d\n", getppid());
  }

  return 0;
}
*/
