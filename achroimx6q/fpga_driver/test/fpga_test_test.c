#include "../include/fpga_test.h"
unsigned char quit = 0;
void user_signal1(int sig) { quit = 1; }

int switch(void) {
	unsigned char push_sw_buf[PUSH_SWITCH_MAX_BUTTON];
	int dev, i;

	dev = open(PUSH_SWITCH_DEVICE, O_RDONLY);
	assert2(dev >= 0, "Device open error", PUSH_SWITCH_DEVICE);

	(void)signal(SIGINT, user_signal1);
	printf("Press <ctrl+c> to quit.\n");

	while (!quit) {
		usleep(400000);
		read(dev, &push_sw_buf, sizeof(push_sw_buf));
		for (i = 0; i < PUSH_SWITCH_MAX_BUTTON; i++)
		{
			if(push_sw_buf[i]){
				printf("%d", i);
				return i;
		}
		printf("\n");
	}
	close(dev);
	return 0;
}

int main(int argc, char**argv) {
	int dev;
	unsigned char data[4];
	ssize_t ret;
	int data_len;
	int i;
	char c;

	char usage[50];
	sprintf(usage, "Usage:\n\tfpga_fnd_test <%d digits>\n", FND_MAX_DIGIT);
	assert(argc == 2, usage);

	data_len = strlen(argv[1]);

	memset(data, 0, sizeof(data));
	for (i = 0; i < data_len; i++) {
		c = argv[1][i];
		assert('0' <= c && c <= '9', "Invalid digit value");
		data[i] = c - '0';
	}
	dev = open(FND_DEVICE, O_RDWR);
	assert2(dev >= 0, "Device open error", FND_DEVICE);

	ret = write(dev, data, FND_MAX_DIGIT);
	assert2(ret >= 0, "Device write error", FND_DEVICE);

	sleep(1);

	memset(data, 0, sizeof(data));
	ret = read(dev, data, FND_MAX_DIGIT);
	assert2(ret >= 0, "Device read error", FND_DEVICE);

	printf("Current FND value: ");
	for (i = 0; i < data_len; i++) {
		printf("%d", data[i]);
	}
	printf("\n");

	close(dev);
	return 0;

}
