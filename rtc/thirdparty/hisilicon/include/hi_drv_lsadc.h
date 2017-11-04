#ifndef _LSADC_H_
#define _LSADC_H_

#define LSADC_DEVICE_NAME	"hi_lsadc"



enum KEY_STATUS{
	KEY_STAT_DOWN,
	KEY_STAT_UP,
};

struct key_attr {
	unsigned long long value;
	enum KEY_STATUS key_stat;
};

#endif
