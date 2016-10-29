/*! \file lab1.c
 * 	\brief Laboratory work №1 variant 15, forc and exec process,
 *
 * 	\details Forking child process with its executing. (TODO)
 *           Child process is a program for operation with fraction.
 *           Unit-testing for functions to operate on fractions.(TODO)
 *           Created on: Oct 21, 2016
 *     		 Author: kate
 */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>

/*! \brief Nod function
 * \details Euklidian algorithm -  input two numbers
 *  \return return the greatest common divisor (NOD)
 */
int nod(int a, int b) { //
   int c;
   while (b) {
      c = a % b;
      a = b;
      b = c;
   }
   return fabs(a);
 }
/*! \brief Fraction_reduction function
 *  \details function for fraction reduction. It takes two pointers on numerator and denominator of fraction
 *  \return result of reduction
 */
void fraction_reduction (int *a, int *b){//  -
	int Lnod =  nod(*a,*b);
	*a /= Lnod;
	*b /= Lnod;
}

/*! \brief Stdin_free function
 *  \details This function cleans stdin after using scanf().
 *  \return Integer 0 upon exit success
 */
void stdin_free(){
	while(1) {
		/* value is a return value of getchar()*/
		int value = getchar();
		if (value == EOF || value=='\n') break;
	};
}

/*! \brief Main function
 *  \details It takes the value from the user and makes operations on fractions
 *  \return Integer 0 upon exit success
 */

int main(){
	/*числитель и знаменатель первой дроби*/
	int numerator_1, denominator_1;
	/*числитель знаменатель второй дроби*/
	int numerator_2, denominator_2;
	/*результаты действий над дробями*/
	int result_num, result_den;
	/*оператор*/
	char operator[3];
	float float_value_1, float_value_2;
	/*флаг для различения поступивших данных (рац.дробь или десятичная дробь)*/
	int option_1,option_2;
	/*запрос и ввод данных*/
	while(1){
		printf("Enter first value:");
		if (scanf("%i/%i",&numerator_1, &denominator_1) == 2){
			/*проверка знаменателя*/
			if (denominator_1 != 0){
				/*введена рациональная дробь*/
				option_1 = 0;
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
				/*введена десятичная дробь*/
				option_1 = 1;
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
			/*проверка знаменателя*/
			if (denominator_2 != 0){
				/*введена рациональная дробь*/
				option_2 = 0;
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
				/*введена десятичная дробь*/
				option_2 = 1;
				stdin_free();
				break;
			} else {
				printf("incorrect value\n");
				stdin_free();
				continue;
			}
		};
	};

	/*выполнение действий с рациональными дробями*/
	/*если обе дроби имеют вид n/m */
	/* сравнивается строка, полученная от пользователя с оператором и выполняется арифметическое действие*/
	if (option_1 == 0 && option_2 == 0){
		if (!strcmp (operator, "+")==0){
			result_num = numerator_1*denominator_2 + numerator_2*denominator_1;
			result_den = denominator_1*denominator_2;
			fraction_reduction(&result_num, &result_den);
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
	else {
		/* если одна или обе дроби в виде десятичной, то выполняются действия с десятичными дробями*/
		/* сравнивается строка, полученная от пользователя с оператором и выполняется арифметическое действие*/
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
