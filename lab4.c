#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void open_store(char* filename,double offset1);
void file_number(int value);
void write_to_file(char* filename2,int* array, int length);
void do_scale(char* filename,double scale1);
int return_length(char* filename);
int return_max(char* filename);
int* Read_file(char* filename);
int find_max(int* array, int length);
double average(int* array, int length);
double* center(int* array,double mean1, int length);
double* normalize(int* array,double max1, int length);


int main(int argc, char* argv[]){


int value,size,maximum;
int i = 1, count,q;
float offset, scale;
char *myname[100];
char *output_file;
int* ayeray;
double* ayeray2;
double mean;

q=argc%2;
	//if (q==0)
	//{
		//if ((argv[1][0] == '-') && (argv[1][1] == 'h'))
		//{printf(" options:\n -n: File number (value needed)\n -o: offset value (value needed)\n -s: scale factor (value needed)\n -r: Rename files (name needed)\n -h: Help (display how the program should be called, including the different input options)\n");
		//}
	//else 
	//{
	//	printf(" Please input ./a.out -h for help!");
		
	//}
	//}
	//else
	//{
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
	
            value = atof(argv[i+1]);
			
			if (value<=0||value>11)
			{
            printf("Int value should be 0-11\n");
			}
			else{
				
				sprintf(myname,"Raw_data_%02d.txt",value);

				
			
				
			}
			break;
		case 'o':
		offset = atof(argv[i+1]);
		//printf("%f",offset);
		
		 open_store(myname, offset);
			break;
			
		case 's':
		scale = atof(argv[i+1]);
		//printf("%f",scale);
		do_scale(myname, scale);
		break;
		case 'r':	
		
		output_file = argv[i+1];
		//write_to_file(myname,output_file);
		break;
		
		case 'S':
		//Read_file(myname);
		size=return_length(myname);
		//printf("%d",size);
		ayeray = Read_file(myname);
		
		if(ayeray == NULL){
		printf("Read file returned a NULL address\nexiting...\n");
		return -1;
	}
		
		
		printf("The max is: %d\n",find_max(ayeray,size));
		
		printf("The average is: %f\n",average(ayeray, size));
		break;
		
		case 'C':
		size=return_length(myname);
		ayeray = Read_file(myname);
		mean=average(ayeray,size);
		//printf("%f",mean);
		ayeray2=center(ayeray,mean,size);
		int i=0;
		
	while(i<size)
	{ 
		
		
		printf("%f \n",*(ayeray2+i));
		
		i++;
		
	}
		break;
		
		case 'N':
		size=return_length(myname);
		ayeray = Read_file(myname);
		maximum=return_max(myname);
		ayeray2=normalize(ayeray,maximum, size);
		
		
	while(i<size)
	{ 
		
		
		printf("%f \n",*(ayeray2+i));
		
		i++;
		
	}
	break;
		}
		i++;
	}
	
	//}
}
	int return_max(char* filename)
	{
		int l,max;
		FILE*fp;
	
	 
	fp= fopen(filename,"r");
	fscanf(fp,"%d",&l);
	fscanf(fp,"%d",&max);
	
	fclose(fp);
	return max;
		
	}
	
	int return_length(char* filename)
	{
		int l,length;
		FILE*fp;
	
	 
	fp= fopen(filename,"r");
	fscanf(fp,"%d",&l);
	length=l;
	fclose(fp);
	return length;
	}


	void open_store(char* filename,double offset1)
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
	double * data_offset= malloc(l*sizeof(double));
	
	int i=0;
	while(i<l)
	{ 
		fscanf(fp,"%d",(newarray+i));
		*(data_offset+i)=*(newarray+i)+offset1;
		printf("\n %.4f",*(data_offset+i));
		//printf("%d",*(newarray+i));
		i++;
		
	}
	
	

		//*(data_offset+j)=*(newarray+j)+offset1;
		//printf("%f",*(data_offset+j));
		//j++;
		
	
	
	fclose(fp);
	}
	
	void do_scale(char* filename,double scale1)
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
	double * data_scale = malloc(l*sizeof(double));
	
	int i=0;
	while(i<l)
	{ 
		fscanf(fp,"%d",(newarray+i));
		*(data_scale+i)=*(newarray+i)*scale1;
		printf("\n %.4f",*(data_scale+i));
		//printf("%d",*(newarray+i));
		i++;
		
	}
	
		
	
	
	fclose(fp);
	}
	
int* Read_file(char* filename)
{
	int l,m;
	 FILE*fp;
	
	 
    fp= fopen(filename,"r");
	
	fscanf(fp,"%d",&l);
	fscanf(fp,"%d",&m);
	
	int * newarray=(int*) malloc(l*sizeof(int));
	int i=0;
	while(i<l)
	{ 
	fscanf(fp,"%d",(newarray+i));
		
		//printf("%d",*(newarray+i));
		i++;
	}
	fclose(fp);
	return newarray;
}
	
	
	
	void write_to_file(char* filename2,int* array, int length){
		 FILE*fp2;
		 int i=0;
	 
	 fp2 = fopen(filename2,"w");
	while(i<length)
	{ 
		fprintf(fp2,"%d \n" , *(array+i));
		i++;
		
	}
	
	fclose(fp2);
}

int find_max(int* array, int length){
	
	

	int i = 0;
	int max = *(array+i);
	i++;

	while(i < length){
		if( *(array+i) > max ){
			max = *(array+i);
		}	
		i++;
	}

	return max;
}

double average(int* array, int length)
{
	double sum=0; double ag;
	int i = 0;
	while(i < length){
		sum= sum+ (*(array+i));
			
			
		i++;
	}
	ag=sum/length;

	return ag;
}
double* center(int* array,double mean1, int length)
{
	double * data = malloc(length*sizeof(double));
	int i = 0;
	while(i < length){
		*(data+i)= *(array+i)-mean1;
		//printf("\n %.4f",*(data+i));	
			
		i++;
	}
	

	return data;
}

double* normalize(int* array,double max1, int length)
{
	double * data = malloc(length*sizeof(double));
	int i = 0;
	while(i < length){
		*(data+i)= *(array+i)/max1;
		//printf("\n %.4f",*(data+i));	
			
		i++;
	}
	

	return data;
	
}