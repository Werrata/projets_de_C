#include <stdio.h>


void echange(float a, float b)
{
	float c = a;
	a = b;
	b = c;
}


int main(void)
{
  float a = 2.32;
  float b = 5.14;
  echange(a,b);
}
