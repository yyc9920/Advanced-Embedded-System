#include "../include/fpga_test.h"

int main(int argc, char **argv)
{
	int i;
	int dev;
	int str_size;
	int chk_size;
	char *str = "ffffuck";
	unsigned char string[32];
	
	memset(string,0,sizeof(string));
	/*
	if(argc<2&&argc>3) {
		printf("Invalid Value Arguments!\n");
		return -1;
	}

	if(strlen(argv[1])>TEXT_LCD_LINE_BUF||strlen(argv[2])>TEXT_LCD_LINE_BUF)
	{
		printf("16 alphanumeric characters on a line!\n");
		return -1;
	}
	*/
	dev = open(TEXT_LCD_DEVICE, O_WRONLY);
	if (dev<0) {
		printf("Device open error : %s\n",TEXT_LCD_DEVICE);
		return -1;
	}
	str_size=strlen(str);
	if(str_size>0) {
		strncat(string,str,str_size);
		memset(string+str_size,' ',TEXT_LCD_LINE_BUF-str_size);
	}
	
	str_size=strlen("seo");
	if(str_size>0) {
		strncat(string,"seo",str_size);
		memset(string+TEXT_LCD_LINE_BUF+str_size,' ',TEXT_LCD_LINE_BUF-str_size);
	}
	
	write(dev,string,TEXT_LCD_MAX_BUF);
	close(dev);
	return(0);
}
