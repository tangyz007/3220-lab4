#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void open_store(char* filename,double offset1);
void file_number(int value);
void write_to_file(char* filename1,char* filename2);
void do_scale(char* filename,double scale1);
//void Read_file(char* filename);
int main(int argc, char* argv[]){


int value;
int i = 1, count,q;
float offset, scale;
char *myname[100];
char *output_file;

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
	
            value = atof(argv[i+1]);
			
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
		offset = atof(argv[i+1]);
		//printf("%f",offset);
		
		 open_store(myname, offset);
			break;
			
		case 's':
		scale = atof(argv[i+1]);
		printf("%f",scale);
		do_scale(myname, scale);
		break;
		case 'r':	
		
		output_file = argv[i+1];
		write_to_file(myname,output_file);
		}
		i++;
	}
	
	}
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
	double * data_scale= malloc(l*sizeof(double));
	
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
	
//void Read_file(char* filename)
//{
	//int l,m;
	 //FILE*fp;
	
	 
//	fp= fopen(filename,"r");
	
	//fscanf(fp,"%d",&l);
	//int length;
	//length=l;
	//int * newarray= (int*)malloc(l*sizeof(int));
	//while(i<l)
	//{ 
	//	fscanf(fp,"%d",(newarray+i));
	//	i++;
		
//	}
//	fclose(fp);
//}
	
	
	void write_to_file(char* filename1,char* filename2){
		 FILE*fp1;
	     FILE*fp2;
		 int l,m;
		 int i=0;
	 
	fp1= fopen(filename1,"r");
	fscanf(fp1,"%d",&l);
	fscanf(fp1,"%d",&m);
	int length;
	length=l;
	int * newarray= (int*)malloc(l*sizeof(int));
	while(i<l)
	{ 
		fscanf(fp1,"%d",(newarray+i));
		i++;
		
	}
	
	 

        fp2 = fopen(filename2,"w");

 

        int j = 0;
        while(j < length){
			
                fprintf(fp2,"%d \n" , *(newarray+j));
                j++;
        }

	fclose(fp1);
	fclose(fp2);
}



