// Copyright 2025 NNTU-CS
#include <iostream>
#include <vector>
#include <cstdint>

uint32_t saveCache[1000001] = { 0 };

unsigned int collatzLen(uint64_t num) {
	if (num == 0) return 0;
	if (num == 1) return 1;
	if (num <= 1000000 && saveCache[num] != 0) {
		return saveCache[num];
	}
	uint16_t len;
	if (num % 2 == 0) {
		len = 1 + collatzLen(num / 2);
	}
	else {
		len = 1 + collatzLen(3 * num + 1);
	}
	if (num <= 1000000) {
		saveCache[num] = len;
	}
	return len;
}

uint64_t collatzMaxValue(uint64_t num) {
	uint64_t maxValue = num;
	while (num > 1) {
		if (num % 2 == 0) {
			num /= 2;
		} else {
			num = num * 3 + 1;
			if (num > maxValue) maxValue = num;
		}
	}
	return maxValue;
}

unsigned int seqCollatz(unsigned int* maxlen, 
	uint64_t lbound, 
	uint64_t rbound) {
	if (lbound > rbound) return 0;
	*maxlen = collatzLen(lbound);
	uint64_t num = lbound;
	while (lbound != rbound) {
		lbound++;
		if (*maxlen < collatzLen(lbound)) {
			*maxlen = collatzLen(lbound);
			num = lbound;
		}
	}
	return num;
}
	return num;
}
