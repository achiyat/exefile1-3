#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)


int exercise_1()
{
	FILE* f;

	f = fopen("data1.bin", "w");

	if (f == NULL)
	{
		// error

	}
	else
	{
		int arr[10];
		for (int i = 0; i < 10; i++)
		{
			printf("%d) enter a number\n",i);
			scanf(" %d", &arr[i]);
			fwrite(&arr[i], sizeof(int), 1, f);
		}
		fclose(f);
	}
	return 0;
}

int exercise_2()
{
	FILE* f;

	f = fopen("data2.bin", "w");

	if (f == NULL)
	{
		// error

	}
	else
	{
		int arr1[8];
		int arr2[4];
		int sum1 = 0;
		int sum2 = 0;
		int num = 0;

		printf("numbers of arr1\n");
		for (int i = 0; i < 8; i++)
		{
			printf("enter a number\n");
			scanf(" %d", &arr1[i]);
			sum1 += arr1[i];
			//fwrite(&arr[i], sizeof(int), 1, f);
		}
		printf("%d\n", sum1);

		num = 0;
		printf("numbers of arr2\n");
		for (int i = 0; i < 4; i++)
		{
			printf("enter a number\n");
			scanf(" %d", &arr2[i]);
			sum2 += arr2[i];
			//fwrite(&arr[i], sizeof(int), 1, f);
		}
		printf("%d\n", sum2);

		if (sum1 > sum2)
		{
			for (int i = 0; i < 8; i++)
			{
				fwrite(&arr1[i], sizeof(int), 1, f);
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				fwrite(&arr2[i], sizeof(int), 1, f);
			}
		}

		fclose(f);
	}
	return 0;
}

int exercise_3()
{
	FILE* f;

	f = fopen("data3.bin", "w");

	if (f == NULL)
	{
		//error
	}
	else
	{
		int len;

		struct  aaa
		{
			char name[100];
			int val;
			short answer;
		};

		// מבנה 1
		struct aaa exe;
		strcpy(exe.name, "achiya");
		exe.val = 18;

		len = strlen(exe.name);
		if (len > 5 && exe.val > 10)
		{
			exe.answer = 1;
		}
		else
		{
			exe.answer = 0;
		}

		// מבנה 2
		struct aaa exe2;
		strcpy(exe2.name, "bar");
		exe2.val = 10;

		len = strlen(exe2.name);
		if (len > 5 && exe2.val > 10)
		{
			exe2.answer = 1;
		}
		else
		{
			exe2.answer = 0;
		}

		// מבנה 3
		struct aaa exe3;
		strcpy(exe3.name, "tzur");
		exe3.val = 5;

		len = strlen(exe3.name);
		if (len > 5 && exe3.val > 10)
		{
			exe3.answer = 1;
		}
		else
		{
			exe3.answer = 0;
		}

		// כתיבה בקובץ
		fwrite(&exe, sizeof(struct aaa), 1, f);
		fwrite(&exe2, sizeof(struct aaa), 1, f);
		fwrite(&exe3, sizeof(struct aaa), 1, f);
		fclose(f);
	}
	return 0;
}

int exercise_4()
{
	FILE* f;

	f = fopen("data4.bin", "w");

	if (f)
	{

		int arr[12];

		for (int i = 0; i < 12; i++)
		{
			arr[i] = (i + 1) * 10;
			fwrite(&arr[i], sizeof(int), 1, f);
		}

		fclose(f);
	}
	else
	{
		// error
	}

	return 0;
}

int exercise_5()
{
	FILE* f;

	f = fopen("Q4.bin", "r");

	if (f) // f != 0
	{
		int item;
		int sum = 0;
		int num = 0;
		while (fread(&item, sizeof(int), 1, f))  // fread(&item, sizeof(int), 1, f) != 0
		{
			printf("%d\n", item);
			sum += item;
			num += 1;
		}

		printf("\n%d", sum);
		printf("\n%d", num);
		fclose(f);
	}
	else
	{
		// error
	}

	return 0;
}

int exercise_6()
{
	FILE* f;

	f = fopen("data6.bin", "w");

	if (f == NULL)
	{
		//printf("error %d",GetlastError());
	}
	else
	{
		int len;
		int size;
		char str[100];

		struct  targil
		{
			char name[100];
			int val;
			short answer;
		};

		struct targil* list;
		struct targil* current_targil;
		printf("\n");
		scanf("%d", &size);
		current_targil = malloc(sizeof(struct targil) * size);
		list = current_targil;


		// מבנה דינמי
		for (int i = 1; i <= size; i++)
		{
			struct targil tar;
			printf("enter name: ");
			scanf("%s", tar.name);
			//getch();
			printf("enter value: ");
			scanf("%d", &tar.val);

			len = strlen(tar.name);
			if (len > 5 && tar.val > 10)
			{
				tar.answer = 1;
			}
			else
			{
				tar.answer = 0;
			}
			fwrite(&tar, sizeof(struct targil), 1, f);

			strcpy(current_targil->name, tar.name);
			current_targil->val = tar.val;
			current_targil->answer = tar.answer;
			current_targil++;
		}

		/// Save Memory
		f = fopen("list_targil_6.bin", "w");
		fwrite(list, sizeof(struct targil), size, f);
		fclose(f);

		// free
		free(list);
	}

	return 0;
}

int main()
{
	// exercise 1
	// קלטו ממשתמש מספרים ושימו במערך בן 10 תאים, המערך מסוג אינט יש לשמור את המערך בקובץ
	exercise_1();

	// exercise 2
	//קלטו מהמשתמש 2 מערכים, אחד בגודל 4 ואחד בגודל 8. המערך שסכומו הכי גבוהה אותו יש לשמור בקובץ
	exercise_2();

	// exercise 3
	/*
	הגדירו מבנה שמכיל את השדות הבאים:
	int val
	char [100] name
	short answer
	תרגיל
	יש להגדיר 3 מופעים (סטטים  ללא הגדרה דינמית) של המבנה הזה
	להכניס ערכים מהמשתמש :שם + ערך
	את השדה "אנסבר" יש לחשב לפי האלגוריתם הבא:
	אם אורך השם המוכנס גדול מ 5 וגם "בל" גדול מ 10 אז "אנסבר" יהיה 1
	אחרת הוא יהיה 0
	יש לכתוב את המבנים הללו בקובץ
	*/
	exercise_3();

	// exercise 4
	/*
	 יש להגדיר מערך מספרי בגודל של 10-20 "אינט" ויש להכניס מספרים ארדקוד
	 אתם תחליטו מה גודל המערך. יש לכתוב את המספרים שבמערך לקובץ ולהעלות ל קבוצת הווצאפ
	*/
	exercise_4();

	// exercise 5
	/*
	לאחר שהחברים העלו את הקובת, הורידו אותו וקראו אותו מבלי לדעת כמה תאים יש במערך.
	קיראו "אינט" אחר "אינט" והדפיסו את המערך , את סכומו וכמה איברים היו בקובץ
	*/
	exercise_5();

	// exercise 6
	/*
	יש להגדיר את המבנה כמו בתרגיל 3 ולבקש מהמשתמש שיכניס כמות המבנים הדינמיים שהוא רוצה לעדכן.
	נניח הוא מכניס 5 אז צריך לייצר מקום בזכרון (דינמי)  ל 5 מבנים
	יש להגדיר בזכרון "הלף" כמות מספקת לכל "איקס" המבנים,
	ולבקש מהמשתמש להכניס "איקס" סטים של ערכים (שם, "בל" וחישוב "אנסבר" יש לשים בזכרון כמו שיש בדוגמא הנ"ל:
	*/
	exercise_6();



	return 0;
}