#include <stdio.h>

		float Know_your_grade();
	    int  Select_Your_Level();
		float First_Level();
		float Second_Level();
	    float Third_Level();
	  //  float Fourth_Level();

	int semester_Selection();
	int SELECT(int Number_Of_Select);
	float Score_Of_Grade(int TotalMark);

int main()
{
	int Select_Manuale_otomatic;
	printf("--------------------------------------------------------------------\n");
	printf("----------WELCOME THIS PROGRAM TO CALCULATE YOUR GREAD--------------\n");
	printf("--------------------------------------------------------------------\n");
	
	Start:
	printf("Are you know total marke of your subject\n");
	printf("1-Yes\n");
	printf("2-No\n");
	scanf("%d",&Select_Manuale_otomatic);
	if(Select_Manuale_otomatic==1)
	{
		Know_your_grade();
	}
	else if (Select_Manuale_otomatic==2)
	{
		Select_Level: 
       int level= Select_Your_Level();
	       if (level==1)
		   {
			   First_Level();
		   }
		   else if (level==2)
		   {
			   Second_Level();

		   }
		   else if (level==3)
		   {
			   Third_Level();
		   }
		    else if (level==4)
		   {
			   First_Level();
		   }
		   else 
		   {
			   printf("Sorry You entered error value ");
			   goto Select_Level;
		   }  
	}
	else
	{
	printf("\n\n\nSorry Your select error value\n");
	goto Start;
	}
}
	float Know_your_grade()
	{
		float TotalMark,YouMark,grade;
		printf("Welcome,This program To know your Score with your grade\n\n");
printf("Please enter Total marke of subject : ");
scanf("%f",&TotalMark);

printf("Please enter your grade : ");
scanf("%f",&YouMark);
grade=(YouMark/TotalMark)*100;
	if (grade<0 || grade >100)
		printf("Sorry , you entered error grade\n");
	else if (grade>=0 && grade<50)
		printf("Your failed\n");
	else if (grade>=50 && grade<65)
		printf("Your Score is Pass\n");
	else if (grade>=65 && grade<75)
		printf("Your Score is Good\n");
	else if (grade>=75 && grade<85)
		printf("Your Very Good\n");
	else if (grade>=85 && grade<100)
		printf("Your grade is Excellent\n");
	}
	
	 int  Select_Your_Level()
	{
		
				int Level;
				printf("please select the year of subject\n\n");
				printf("1-First Level\n");
				printf("2-Second Level\n");
				printf("3-Third Level\n");
				printf("4-Fourth Level\n");
				scanf("%d",&Level);
				return Level;
			}

	int semester_Selection()
	{
			int Select_Semester;
			semester:
			printf("Please select the Semester\n");
			printf("1-First semester\n");
			printf("2-Second semester\n");	
			scanf("%d",&Select_Semester);
		if (Select_Semester<=0&&Select_Semester>2)
		{
		goto semester;
		}
		else 
		return Select_Semester;

		}

	int SELECT(int Number_Of_Select)
	{
	int Selected;
		scanf("%d",&Selected);
		if (Selected>Number_Of_Select)
			return 0;
		else if (Selected>0&&Selected<=Number_Of_Select)
			return Selected;
	}
	
	float Score_Of_Grade(int TotalMark)
    {
	
	float YouMark;
printf("Please enter your grade : ");
scanf("%f",&YouMark);
int grade=(YouMark/TotalMark)*100;
	if (grade<0 )
		printf("Sorry,You entered error grade\n");
    else if (grade>100 )
		printf("Sorry,You entered error grade\n");
	else if (grade>=0 && grade<50)
		printf("Your failed\n");
	else if (grade>=50 && grade<65)
		printf("Your Score is Pass\n");
	else if (grade>=65 && grade<75)
		printf("Your Score is Good\n");
	else if (grade>=75 && grade<85)
		printf("Your Very Good\n");
	else if (grade>=85 && grade<100)
		printf("Your grade is Excellent\n");
	}
	 float First_Level()
	{
		int Semester=semester_Selection();
		if (Semester==1)
		{
			Semester:
			printf("Please select the subject\n\n");
			printf("1-Electronics _1_ \n");
			printf("2-Operating systems\n");
			printf("3-Electric Circuits_1_ \n");
			printf("4-Elective\n");
			printf("5-Technical English\n");
			printf("6-Mathematics_3_\n");
			printf("7-Modern Physics\n");
            int Select=SELECT(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(100);
			}
			else if (Select==3)
			{
				Score_Of_Grade(150);
			}
			else if (Select==4)
			{
				Score_Of_Grade(50);
			}
			else if (Select==5)
			{
				Score_Of_Grade(50);
			}
			else if (Select==6)
			{
				Score_Of_Grade(100);
			}
			else if (Select==7)
			{
				Score_Of_Grade(150);
			}
			
		}
		else if(Semester==2)
		{
			printf("Please select the subject\n\n");
			printf("1-Electronics_2_ \n");
			printf("2-Logic Circuits Design \n");
			printf("3-Electric Circuits (2) \n");
			printf("4-Electromagnetic Field\n");
			printf("5-Elective\n");
			printf("6-Mathematics (4) \n");
			printf("7-Numerical Analysis\n");
		 int Select=SELECT(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(125);
			}
			else if (Select==2)
			{
				Score_Of_Grade(150);
			}
			else if (Select==3)
			{
				Score_Of_Grade(125);
			}
			else if (Select==4)
			{
				Score_Of_Grade(100);
			}
			else if (Select==5)
			{
				Score_Of_Grade(50);
			}
			else if (Select==6)
			{
				Score_Of_Grade(100);
			}
			else if (Select==7)
			{
				Score_Of_Grade(100);
			}
		}
	}
	
	float Second_Level()
	{
		int Semester=semester_Selection();
		if (Semester==1)
		{
			Semester:
			printf("Please select the subject\n\n");
			printf("1-Electronic Measurements (1)  \n");
			printf("2-Electronic Circuits (1)\n");
			printf("3-Communication Systems (1) \n");
			printf("4-ElectricalMachine and transformers \n");
			printf("5-Computer Architectures\n");
			printf("6-Feasibility studies and operations research \n");
			printf("7-Civil Engineering\n");
            int Select=SELECT(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(150);
			}
			else if (Select==3)
			{
				Score_Of_Grade(125);
			}
			else if (Select==4)
			{
				Score_Of_Grade(100);
			}
			else if (Select==5)
			{
				Score_Of_Grade(100);
			}
			else if (Select==6)
			{
				Score_Of_Grade(50);
			}
			else if (Select==7)
			{
				Score_Of_Grade(75);
			}
		}
		else if(Semester==2)
		{
			printf("Please select the subject\n\n");
			printf("1-Electronics (3)  \n");
			printf("2-Electronic Measurements (2)  \n");
			printf("3-Communication Systems (2) \n");
			printf("4-Electronic Circuits (2)\n");
			printf("5-Field Training   (1)\n");
			printf("6-Engineering Economics and Projects Management  \n");
			printf("7-Mechanical Engineering\n");
		 int Select=SELECT(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(150);
			}
			else if (Select==3)
			{
				Score_Of_Grade(125);
			}
			else if (Select==4)
			{
				Score_Of_Grade(150);
			}
			else if (Select==5)
			{
				Score_Of_Grade(50);
			}
			else if (Select==6)
			{
				Score_Of_Grade(50);
			}
			else if (Select==7)
			{
				Score_Of_Grade(75);
			}
		}
	}
	
	float Third_Level()
	{
		int Semester=semester_Selection();
		if (Semester==1)
		{
			Semester:
			printf("Please select the subject\n\n");
			printf("1-Electronic Circuits (3)  \n");
			printf("2-Electromagnetic Waves\n");
			printf("3-Digital Signal Processing  \n");
			printf("4-Automatic Control \n");
			printf("5-Digital Communication Systems (1)\n");
			printf("6-Technical Report Writing  \n");
			printf("7-Eelective \n");
            int Select=SELECT(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(125);
			}
			else if (Select==3)
			{
				Score_Of_Grade(125);
			}
			else if (Select==4)
			{
				Score_Of_Grade(100);
			}
			else if (Select==5)
			{
				Score_Of_Grade(150);
			}
			else if (Select==6)
			{
				Score_Of_Grade(50);
			}
			else if (Select==7)
			{
				Score_Of_Grade(50);
			}
		}
		else if(Semester==2)
		{
			printf("Please select the subject\n\n");
			printf("1-Antennas  \n");
			printf("2-Electronic Circuits (4)   \n");
			printf("3-Microprocessor  and Interfacing  \n");
			printf("4-Field Training  (2)\n");
			printf("5-Human Rights \n");
			printf("6-Elective (1)   \n");
			printf("7-Elective (1) \n");
		 int Select=SELECT(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(150);
			}
			else if (Select==3)
			{
				Score_Of_Grade(150);
			}
			else if (Select==4)
			{
				Score_Of_Grade(50);
			}
			else if (Select==5)
			{
				Score_Of_Grade(50);
			}
			else if (Select==6)
			{
				Score_Of_Grade(100);
			}
			else if (Select==7)
			{
				Score_Of_Grade(100);
			}
		}
	}
	/*float Fourth_Level()
	{
		int Semester=semester_Selection();
		if (Semester==1)
		{
			Semester:
			printf("Please select the subject\n\n");
			printf("1-Electronic Measurements (1)  \n");
			printf("2-Electronic Circuits (1)\n");
			printf("3-Communication Systems (1) \n");
			printf("4-ElectricalMachine and transformers \n");
			printf("5-Computer Architectures\n");
			printf("6-Feasibility studies and operations research \n");
			printf("7-Civil Engineering\n");
            int Select=Select(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(150);
			}
			else if (Select==3)
			{
				Score_Of_Grade(125);
			}
			else if (Select==4)
			{
				Score_Of_Grade(100);
			}
			else if (Select==5)
			{
				Score_Of_Grade(100);
			}
			else if (Select==6)
			{
				Score_Of_Grade(50);
			}
			else if (Select==7)
			{
				Score_Of_Grade(75);
			}
		}
		else if(Semester==2)
		{
			printf("Please select the subject\n\n");
			printf("1-Electronics (3)  \n");
			printf("2-Electronic Measurements (2)  \n");
			printf("3-Communication Systems (2) \n");
			printf("4-Electronic Circuits (2)\n");
			printf("5-Field Training   (1)\n");
			printf("6-Engineering Economics and Projects Management  \n");
			printf("7-Mechanical Engineering\n");
		 int Select=Select(7);
			if (Select==0)
			{
				goto Semester;
			}
			else if (Select==1)
			{
				Score_Of_Grade(150);
			}
			else if (Select==2)
			{
				Score_Of_Grade(150);
			}
			else if (Select==3)
			{
				Score_Of_Grade(125);
			}
			else if (Select==4)
			{
				Score_Of_Grade(150);
			}
			else if (Select==5)
			{
				Score_Of_Grade(50);
			}
			else if (Select==6)
			{
				Score_Of_Grade(50);
			}
			else if (Select==7)
			{
				Score_Of_Grade(75);
			}
		}
	}
	*/