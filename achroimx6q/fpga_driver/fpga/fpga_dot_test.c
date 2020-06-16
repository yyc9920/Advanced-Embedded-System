#include "../include/fpga_test.h"
#include "../include/fpga_dot_font.h"

unsigned char quit = 0;
void user_signal1(int sig) { quit = 1; }


void InsertLcdChar(char * buf, char insChar){
    unsigned char befBuf[TEXT_LCD_MAX_BUF];
    int i;
    memcpy (befBuf, buf, TEXT_LCD_MAX_BUF);
    for(i = TEXT_LCD_MAX_BUF - 1; i != 0; i--){
        befBuf[i] = befBuf[i - 1];
    }
    befBuf[0] = insChar;
    memset (buf, ' ', TEXT_LCD_MAX_BUF);
    memcpy (buf, befBuf, TEXT_LCD_MAX_BUF);
}

int main (int argc, char **argv)
{
    unsigned char buf[TEXT_LCD_MAX_BUF];
    unsigned char push_sw_buf[PUSH_SWITCH_MAX_BUTTON];
    
    int dev_dot;
    int dev_lcd;
    int dev_button;
    int num;
    
    ssize_t ret;
    
    int i;
    int button_pushed = 0;
    int button_ver = 0;
    int button_value = 0;
    
    (void)signal(SIGINT, user_signal1);
    
    dev_dot = open(DOT_DEVICE, O_WRONLY);
    
    dev_lcd = open(TEXT_LCD_DEVICE, O_WRONLY);
    
    dev_button = open(PUSH_SWITCH_DEVICE, O_RDONLY);
    
    while (!quit)
    {
        read (dev_button, &push_sw_buf, sizeof (push_sw_buf));
        for (i = 0; i < PUSH_SWITCH_MAX_BUTTON; i++){
            if(push_sw_buf[i] == 1 && button_pushed == 0){
                button_pushed = 1;
                button_value = i;
                ret = write (dev_dot, fpga_number[button_value], sizeof (fpga_number[button_value]));
                InsertLcdChar(buf, button_value + '0');
                write (dev_lcd, buf, TEXT_LCD_MAX_BUF);
            }
            button_ver += push_sw_buf[i];
        }
        if(button_ver == 0){
            button_pushed = 0;
        }
        button_ver = 0;
        printf ("\n");

        
    }
    
    close (dev_dot);
    close (dev_lcd);
    close (dev_button);
    return 0;
}
