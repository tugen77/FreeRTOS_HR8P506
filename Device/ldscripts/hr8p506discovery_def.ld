/* Memory Spaces Definitions */

ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 36K
  RAM  (xrw) : ORIGIN = 0x20000000, LENGTH = 8K
}

/* highest address of the user mode stack */
_estack = 0x20002000;



