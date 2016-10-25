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
#include <sys/types.h>

/*! \brief Main function
 *  \return
 */
int nod(int a, int b) { //  Euklidian algorithm -  input two numbers, out the greatest common divisor (NOD)
   int c;
   while (b) {
      c = a % b;
      a = b;
      b = c;
   }
   return fabs(a);
 }
 
void fruction_reduction (int *a, int *b){// function for fruction reduction - input  two pointers of numerator and denominator
	int Lnod =  nod(*a,*b);
	*a /= Lnod;
	*b /= Lnod;
}
 
int main(){
	int numerator_1, denominator_1;
	int numerator_2, denominator_2;
	int result_num, result_den;
	char operator[3];
	float float_value_1, float_value_2;

	// запрос и ввод данных
	while(1){
		printf("Enter first value:\n");
		if (scanf("%i/%i",&numerator_1, &denominator_1) ==2){
			break;
		}
		else{
			if (scanf("%f", &float_value_1)==1){
				break;
			}
			else {
				printf("uncorrect value\n");
			}
		}

	scanf("%2s",&operator);

	printf("Enter second value:\n");
	if (scanf("%i/%i",&numerator_2, &denominator_2) ==2){
			break;
		}
		else{
			if (scanf("%f", &float_value_2)==1){
				break;
			}
			else {
				printf("uncorrect value\n");
			}
		};

	// TODO проверка
	// парсинг строки
	// выполнение действий с рациональными дробями
    switch(operator){
		case '+':
			result_num = numerator_1*denominator_2 + numerator_2*denominator_1;
			result_den = denominator_1*denominator_2;
			// TODO сокращение дроби путем поиска НОК используя алгоритм Евклида
			fruction_reduction(&result_num, result_den);
			
		break;

		case '-':
			result_num = numerator_1*denominator_2 - numerator_2*denominator_1;
			result_den = denominator_1*denominator_2;
			fruction_reduction(&result_num, result_den);
		break;

		case '*':
			result_num = numerator_1*numerator_2;
			result_den = denominator_1*denominator_2;
			fruction_reduction(&result_num, result_den);
		break;

		case '/':
			result_num = numerator_1*denominator_2;
			result_den = denominator_1*numerator_2;
			fruction_reduction(&result_num, result_den);
		break;
		default:

		break;
    }
    // работа с десятичными дробями

    // TODO преобразовать рациональную дробь в десятичную
    switch (operator){
    	case '>':

    	break;

    	case '<':

    	break;
    	case '>=':

    	break;
    	case '<=':

    	break;
    	case '!=':

    	break;

    }

	return 0;
}
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
