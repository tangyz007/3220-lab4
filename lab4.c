#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void open_store(char* filename);
void file_number(int value);
void write_to_file(char* filename, double* array, int length);
void off_set(int * array,int l,double offset);
int main(int argc, char* argv[]){


int value;
int i = 1, count,q;
float offset;
char *myname[100];

q=argc%2;
	if (q==0)
	{
		if ((argv[1][0] == '-') && (argv[1][1] == 'h'))
		{printf(" options:\n -n: File number (value needed)\n -o: offset value (value needed)\n -s: scale factor (value needed)\n -r: Rename files (name needed)\n -h: Help (display how the program should be called, including the different input options)\n");
		}
	else 
	{
		printf(" Please input ./a.out -h for help!");
		
	}
	}
	else
	{
	while(i < argc){
	if((argv[i][0] == '-'))
		goto l1;
	else{
		if(i%2==0)
		{i++;}
	else 
		printf("wrong input");
	}
	
	l1:
	count=argv[i][1];
	switch(count)
	{
	case 'n':
	
            value = atoi(argv[i+1]);
			
			if (value<=0||value>11)
			{
            printf("Int value should be 0-11\n");
			}
			else{
				
				sprintf(myname,"Raw_data_%02d.txt",value);

				
				i++;
				break;
			}
		case 'o':
		
		open_store(myname);
		offset = atoi(argv[i+1]);
		 off_set(newarray, l, offset);
			
		}
		i++;
	}
	
	}
}

	
	

int read_fromfile(char *filename)
{
	
}
//void file_number(int value){
	 
	// char *myname[100];
	 
	
	
	
	//sprintf(myname,"Raw_data_%02d.txt",value);
//}
	//int o=0;
	//while (o<10)
	//{
	//printf("%d",myname[o]);
	//o++;
	//}
	void open_store(char* filename)
	{
		 int l,m;
	 FILE*fp;
	fp= fopen(filename,"r");
	
	fscanf(fp,"%d",&l);
	//printf("%d",l);
	int length;
	length =l;
	//printf("\n");
	fscanf(fp,"%d",&m);
	//printf("%d",m);
	//printf("\n");
	int * newarray= (int*)malloc(l*sizeof(int));
	
	int i=0;
	while(i<l)
	{ 
		fscanf(fp,"%d",(newarray+i));
		//printf("%d",*(newarray+i));
		i++;
		
	}
	
	
	fclose(fp);
	}
	
	void off_set(int * array, int length,double offset)
	{
		
		double *data_offset;
		
		int i=0;
		while(i<length)
	{ 

		*(data_offset+i)=*(array+i)+offset;
		printf("%f",*(data_offset+i));
		i++;
		
	}
	}
	
	void write_to_file(char* filename, double* array){
  	
	 if(filename == NULL){
                printf("WRITE FILE ERROR! FILENAME WAS NULL OR LENGTH WAS INVALID\n");
                exit(0);
         }

        FILE* fp = fopen(filename,"w");
        if(fp == NULL){
                printf("There was an error attempting to open file %s\n",filename);
                exit(0);
        } 

        int i = 0;
        while(i < length){
                fprintf(fp,"%lf", *(array+i));
                i++;
        }

	
}



