#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100
#define MAX_NAME_LEN 16

typedef struct StudentData
{
	int num;
	char name[MAX_NAME_LEN];
	unsigned int kor, eng, math, total;
}S_DATA;

char* GetNextString(char* ap_src_str, char a_delimiter, char* ap_buffer)
{
	while (*ap_src_str && *ap_src_str != a_delimiter) *ap_buffer++ = *ap_src_str++;
	if (*(ap_buffer - 1) == '\n') *(ap_buffer - 1) = 0;
	else*ap_buffer = 0;

	if (*ap_src_str == a_delimiter)ap_src_str++;
	return ap_src_str;
}

int ReadData(const char* ap_file_name, S_DATA* ap_data, unsigned int* ap_data_count)
{
	S_DATA* p_start = ap_data;
	FILE* p_file = NULL;
	if (0 == fopen_s(&p_file, ap_file_name, "rt"))
	{
		char one_line_string[128], str[32], * p_pos;

		if (NULL != fgets(one_line_string, 128, p_file))
		{
			while (NULL != fgets(one_line_string, 128, p_file))
			{
				p_pos = GetNextString(one_line_string, ',', str);
				ap_data->num = atoi(str);
				p_pos = GetNextString(p_pos, ',', ap_data->name);
				p_pos = GetNextString(p_pos, ',', str);
				ap_data->kor = atoi(str);
				p_pos = GetNextString(p_pos, ',', str);
				ap_data->eng = atoi(str);
				p_pos = GetNextString(p_pos, ',', str);
				ap_data->math = atoi(str);

				ap_data->total = ap_data->kor + ap_data->eng, ap_data->math;
				ap_data++;
			}
			*ap_data_count = ap_data - p_start;
		}
		fclose(p_file);
		return 1;
	}
	return 0;
}

void ShowData(S_DATA* ap_data, unsigned int a_count)
{

	printf("--------------------------------------------------------------------------\n");
	printf("   Student ID         Name     Kor    Eng   Math    Total    Avg                \n");
	printf("--------------------------------------------------------------------------\n");

	for (unsigned int i = 0; i < a_count; i++, ap_data++)
	{
		printf("   %08u     %10s    %3d    %3d    %3d      %3d    %.2lf\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->total, ap_data->total / 3.0);
	}
}

void SaveData(const char* ap_file_name, S_DATA* ap_data, unsigned int a_count)
{
	FILE* p_file = NULL;
	if (0 == fopen_s(&p_file, ap_file_name, "wt"))
	{
		fprintf(p_file, "Student ID,Name,Kor,Eng,Math,total,Avg\n");
		for (unsigned int i = 0; i < a_count; i++, ap_data++)
		{
			fprintf(p_file, "%d,%s,%u,%u,%u,%u,%.2lf\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->total, ap_data->total / 3.0);
		}
		printf("%s !\n", ap_file_name);
		fclose(p_file);
	}
}

int main()
{
	S_DATA data[MAX_COUNT];
	unsigned int data_count = 0, select = 0;

	if (ReadData("score_data.csv", data, &data_count))
	{
		while (select != 3)
		{
			printf("\n\n==========[   Menu   ]==========\n");
			printf("1. See Score\n");
			printf("2. Save Data\n");
			printf("3. End program\n");

			printf("select : ");
			if (1 == scanf_s("%u", &select))
			{
				printf("\n\n");
				if (select == 1) ShowData(data, data_count);
				else if (select == 2) SaveData("score_data_new.csv", data, data_count);
			}
			else
			{
				printf("\nYou've entered a wrong value. enter again\n\n");
				rewind(stdin);
			}
		}
	}
	else
	{
		printf("Can't open file: score_data.csv.");
	}
	return 0;
}