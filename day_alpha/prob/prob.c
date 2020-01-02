
/*
 * Code written by dhkim@stealien
 * 2020-01-20
 */

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void arb_read(void);
void arb_write(void);
size_t dummy(void);

int main(void) {

	uint32_t choice = 0;

	while (choice != 3) {

		write(1, "> ", 2);
		read(0, &choice, sizeof(choice));

		switch (choice) {
			case 0: arb_write(); break;
			case 1: arb_read();  break;
			case 2: dummy();     break;
			default: break;
		}

		write(1, "OK\n", 3);
	}

	write(1, "BYE\n", 4);
	return 0;
}

void arb_write(void) {

	void *addr = NULL;
	uint64_t value = 0;
	int type;

	write(1, "> ", 2);
	read(0, &addr, sizeof(addr));

	write(1, "> ", 2);
	read(0, &value, sizeof(value));

	write(1, "> ", 2);
	read(0, &type, sizeof(type));

	switch (type) {
		case 1:
			*(uint8_t *)addr = (uint8_t)value;
			break;
		case 2:
			*(uint16_t *)addr = (uint16_t)value;
			break;
		case 4:
			*(uint32_t *)addr = (uint32_t)value;
			break;
		default:
			*(uint64_t *)addr = (uint64_t)value;
			break;
	}
}

void arb_read(void) {

	void *addr = NULL;
	uint64_t size = 0;

	write(1, "> ", 2);
	read(0, &addr, sizeof(addr));

	write(1, "> ", 2);
	read(0, &size, sizeof(size));

	write(1, addr, size);
}

size_t dummy(void) {

	int n;
	char buf[256];
	
	write(1, "> ", 2);
	n = read(0, buf, 255);
	buf[n] = '\0';

	return strlen(buf);
}
