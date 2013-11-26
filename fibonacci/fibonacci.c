/*************************************************************************/
/*************************************************************************/
/**                                                                     **/
/** Copyright (C) 1989-2013 Synopsys, Inc.                              **/
/** All Rights Reserved.                                                **/
/***************************************************************/
//	LOCAL DEFINES
/***************************************************************/
#define SEQ_LEN (32)

/***************************************************************/
//	GLOBAL VARIABLES
/***************************************************************/
unsigned int sequence[SEQ_LEN] = {0,1};


//***************************************************************/
//	MAIN
//***************************************************************/
int main (int argc, char *argv[])
{
  int i;

  for (i = 2; i < SEQ_LEN; i++)
    sequence[i] = sequence[i - 1] + sequence[i - 2];

  if (sequence[SEQ_LEN - 1] != 1346269) return -1;

  return 0;
}
