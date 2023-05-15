
#include "fonctions.h"


int main(void)
{
  NINJA nin1;
  NINJA nin2;
  
  NINJA * ninja1 = createNINJA("Sakura", 2000, NULL, NULL);
  NINJA * ninja2 = createNINJA("Shikamaru", 1000, ninja1, NULL);
  ninja1->next = ninja2;
  NINJA * ninja3 = createNINJA("choji", 2000, ninja2, NULL);
  ninja2->next = ninja3;
  
}

