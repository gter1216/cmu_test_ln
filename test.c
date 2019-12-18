#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

int dayOfWeek(char * inputStr, char * outputStr, int k)
{
     int inDay = -1;
     int outDay = -1;

     if(0==strcmp(inputStr, "Mon"))
     {
          inDay = 1;
     }else if(0==strcmp(inputStr, "Tue"))
     {
          inDay = 2;
     }else if(0==strcmp(inputStr, "Wed"))
     {
          inDay = 3;
     }
     else if(0==strcmp(inputStr, "Thu"))
     {
          inDay = 4;
     }
     else if(0==strcmp(inputStr, "Fri"))
     {
          inDay = 5;
     }
     else if(0==strcmp(inputStr, "Sat"))
     {
          inDay = 6;
     }
     else if(0==strcmp(inputStr, "Sun"))
     {
          inDay = 7;
     }
     else
     {
           printf("input day format is wrong\n");
           return FAILURE;
     }

     outDay = (inDay + k)%7;

     switch(outDay)
     {
         case 1:
		snprintf(outputStr, 4, "%s", "Mon");
		break;
	  case 2:
		snprintf(outputStr, 4, "%s", "Tue");
		break;
         case 3:
		snprintf(outputStr, 4, "%s", "Wed");
		break;
         case 4:
		snprintf(outputStr, 4, "%s", "Thu");
		break;
         case 5:
		snprintf(outputStr, 4, "%s", "Fri");
		break;
         case 6:
		snprintf(outputStr, 4, "%s", "Sat");
		break;
         case 0:
		snprintf(outputStr, 4, "%s", "Sun");
		break;
     }
	 
     return SUCCESS;
}

void getMaxPos(int inNum, int * pos, int * outNum)
{
     char a[5+1] = {0};

     int i = -1, j = -1, len = 0;

     snprintf(a, sizeof(a), "%d", inNum);

      len = strlen(a);

      // insert 5 to head
      switch(len)
      {
          case 1:
		inNum += 50;
		break;
	   case 2:
		inNum += 500;
		break;
          case 3:
		inNum += 5000;
		break;
          case 4:
		inNum += 50000;
		break;
      }

      snprintf(a, sizeof(a), "%d", inNum);

	for(j = 0; j < len; j++)
	{
	    if(a[j+1]>='5')
	    {
	        a[j] = a[j+1];
	        a[j+1] = '5';
	    }
	    else
	    {
	        break;
	    }
	}

	*pos = j;
	
	*outNum =  atoi(a);

	 return;
}

void getMinPos(int inNum, int * pos, int * outNum)
{
     char a[5+1] = {0};

     int i = -1, j = -1, len = 0;

     snprintf(a, sizeof(a), "%d", inNum);

      len = strlen(a);

      // insert 5 to head
      switch(len)
      {
          case 1:
		inNum += 50;
		break;
	   case 2:
		inNum += 500;
		break;
          case 3:
		inNum += 5000;
		break;
          case 4:
		inNum += 50000;
		break;
      }

      snprintf(a, sizeof(a), "%d", inNum);
 
	for(j = 0; j < len; j++)
	{
	    if(a[j+1]<'5')
	    {
	        a[j] = a[j+1];
	        a[j+1] = '5';
	    }
	    else
	    {
	        break;
	    }
	}

	*pos = j;
	
	*outNum =  atoi(a);

	 return;
}

void task_one()
{
       /*Task One: DayOfWeek*/
       char inputStr[3+1] = {0};
	char outputStr[3+1] = {0};

	int k = 0;
	int ret = FAILURE;

       printf("Task One: DayOfWeek \n");

       printf("please input day, Mon, Thu, ...\n");
	scanf("%s", inputStr);
	//printf("input day is %s\n", inputStr);

	printf("please input passingdays\n");
	scanf("%d", &k);
	//printf("input passing days is %d\n", k);
	
	ret =  dayOfWeek(inputStr, outputStr, k);

	if(FAILURE==ret)
	{
	      printf("task one failure\n");
	}
       else
	{
	    printf("output day is %s\n", outputStr);
       }

	return;
     
}

void task_two()
{
    	/*Task Two: AddFive*/
	int inputNum = -1;
	int pos = -1;
	int outputNum = -1;

       printf("Task Two: AddFive \n");
	
	printf("please input number\n");
	scanf("%d", &inputNum);

	if(( inputNum < -8000) ||
		(inputNum > 8000))
	{
	     printf("Error: inputNum is out of Range\n");
	}

       if(inputNum >= 0)
       {
            
	     getMaxPos(inputNum, &pos, &outputNum);
       }
	else
	{
	     inputNum *= -1;
	     getMinPos(inputNum, &pos, &outputNum);
	     outputNum *= -1;
	}

	printf("max pos is %d, output Num is %d \n", pos, outputNum);
	
	return;
}

void task_three()
{
      /*Task Three: EraseOneLetter*/
      char inputWord[64+1] = {0};

      int ret = FAILURE;

       printf("Task Three: EraseOneLetter \n");

       printf("please input word, max len is 64\n");
       scanf("%s", inputWord);

       if(strlen(inputWord)>64)
       {
            printf("the lenth of input word is too long!\n");
	     return;
       }else if(strlen(inputWord)<=1)
       {
            printf("the lenth of input word is too short!\n");
	     return;
       }

       int len = strlen(inputWord);

       int i = 0;
  
       while(inputWord[i]>=inputWord[i+1])
            i++;
    
       while(i < len-1)
       {
          inputWord[i] = inputWord[i+1];
          i++;
       }
 
        inputWord[len-1] = '\0';
   
        printf("output word is %s \n", inputWord);
   
	return;
	   
}

void task_four()
{
     /*Task Four: BattleShip*/
     printf("Task Four: BattleShip \n");
   
     system("./battleship.bin");
   
     return;
}

void main()
{
      int taskNo = -1;
      printf("please input Task No. you want to perform!\n");
      scanf("%d", &taskNo);

      switch(taskNo)
      	{
      	    case 1:
		task_one();
		break;
	    case 2:
		task_two();
		break;
           case 3:
		task_three();
		break;
           case 4:
		task_four();
		break;
	    default:
		printf("input wrong task no. exit!\n");
      	}
	
}
