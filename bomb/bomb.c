/***************************************************************************
 * Dr. Evil's Insidious Bomb, Version 1.1
 * Copyright 2011, Dr. Evil Incorporated. All rights reserved.
 *
 * LICENSE:
 *
 * Dr. Evil Incorporated (the PERPETRATOR) hereby grants you (the
 * VICTIM) explicit permission to use this bomb (the BOMB).  This is a
 * time limited license, which expires on the death of the VICTIM.
 * The PERPETRATOR takes no responsibility for damage, frustration,
 * insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or other
 * harm to the VICTIM.  Unless the PERPETRATOR wants to take credit,
 * that is.  The VICTIM may not distribute this bomb source code to
 * any enemies of the PERPETRATOR.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and defuse the BOMB.  BOMB
 * proof clothing may not be worn when handling this program.  The
 * PERPETRATOR will not apologize for the PERPETRATOR's poor sense of
 * humor.  This license is null and void where the BOMB is prohibited
 * by law.
 ***************************************************************************/

#include "phases.h"
#include "support.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Note to self: Remember to erase this file so my victims will have no
 * idea what is going on, and so they will all blow up in a
 * spectaculary fiendish explosion. -- Dr. Evil
 */

FILE *infile;

int main(int argc, char *argv[]) {
  char *input;

  /* Note to self: remember to port this bomb to Windows and put a
   * fantastic GUI on it. */

  /* When run with no arguments, the bomb reads its input lines
   * from standard input. */
  if (argc == 1) {
    infile = stdin;
  }

  /* When run with one argument <file>, the bomb reads from <file>
   * until EOF, and then switches to standard input. Thus, as you
   * defuse each phase, you can add its defusing string to <file> and
   * avoid having to retype it. */
  else if (argc == 2) {
    if (!(infile = fopen(argv[1], "r"))) {
      printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
      exit(8);
    }
  }

  /* You can't call the bomb with more than 1 command line argument. */
  else {
    printf("Usage: %s [<input_file>]\n", argv[0]);
    exit(8);
  }

  /* Do all sorts of secret stuff that makes the bomb harder to defuse. */
  initialize_bomb();

  printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
  printf("which to blow yourself up. Have a nice day!\n");

  /* Hmm...  Six phases must be more secure than one phase! */
  input = read_line(); /* Get input                   */
  phase_1(input);      /* Run the phase               */
  phase_defused();     /* Drat!  They figured it out!
                        * Let me know how they did it. */
  printf("Phase 1 defused. How about the next one?\n");

  /* The second phase is harder.  No one will ever figure out
   * how to defuse this... */
  input = read_line();
  phase_2(input);
  phase_defused();
  printf("That's number 2.  Keep going!\n");

  /* I guess this is too easy so far.  Some more complex code will
   * confuse people. */
  input = read_line();
  phase_3(input);
  phase_defused();
  printf("Halfway there!\n");

  /* Oh yeah?  Well, how good is your math?  Try on this saucy problem! */
  input = read_line();
  phase_4(input);
  phase_defused();
  printf("So you got that one.  Try this one.\n");

  /* Round and 'round in memory we go, where we stop, the bomb blows! */
  input = read_line();
  phase_5(input);
  phase_defused();
  printf("Good work!  On to the next...\n");

  /* This phase will never be used, since no one will get past the
   * earlier ones.  But just in case, make this one extra hard. */
  input = read_line();
  phase_6(input);
  phase_defused();

  /* Wow, they got it!  But isn't something... missing?  Perhaps
   * something they overlooked?  Mua ha ha ha ha! */

  return 0;
}

/*
                0x6d    0x61    0x64    0x75    0x69    0x65    0x72    0x73
0x4024b8:       0x6e    0x66    0x6f    0x74    0x76    0x62    0x79    0x6c
0x4024c0:       0x53    0x6f    0x20    0x79    0x6f    0x75    0x20    0x74
0x4024c8:       0x68    0x69    0x6e    0x6b    0x20    0x79    0x6f    0x75
0x4024d0:       0x20    0x63    0x61    0x6e    0x20    0x73    0x74    0x6f
0x4024d8:       0x70    0x20    0x74    0x68    0x65    0x20    0x62    0x6f
0x4024e0:       0x6d    0x62    0x20    0x77    0x69    0x74    0x68    0x20
0x4024e8:       0x63    0x74    0x72    0x6c    0x2d    0x63    0x2c    0x20
0x4024f0:       0x64    0x6f    0x20    0x79    0x6f    0x75    0x3f    0x00
0x4024f8:       0x43    0x75    0x72    0x73    0x65    0x73    0x2c    0x20
0x402500:       0x79    0x6f    0x75    0x27    0x76    0x65    0x20    0x66
0x402508:       0x6f    0x75    0x6e    0x64    0x20    0x74    0x68    0x65
0x402510:       0x20    0x73    0x65    0x63    0x72    0x65    0x74    0x20
0x402518:       0x70    0x68    0x61    0x73    0x65    0x21    0x00    0x00
0x402520:       0x42    0x75    0x74    0x20    0x66    0x69    0x6e    0x64
0x402528:       0x69    0x6e    0x67    0x20    0x69    0x74    0x20    0x61
0x402530:       0x6e    0x64    0x20    0x73    0x6f    0x6c    0x76    0x69
0x402538:       0x6e    0x67    0x20    0x69    0x74    0x20    0x61    0x72
0x402540:       0x65    0x20    0x71    0x75    0x69    0x74    0x65    0x20
0x402548:       0x64    0x69    0x66    0x66    0x65    0x72    0x65    0x6e
0x402550:       0x74    0x2e    0x2e    0x2e    0x00    0x00    0x00    0x00
0x402558:       0x43    0x6f    0x6e    0x67    0x72    0x61    0x74    0x75
0x402560:       0x6c    0x61    0x74    0x69    0x6f    0x6e    0x73    0x21
0x402568:       0x20    0x59    0x6f    0x75    0x27    0x76    0x65    0x20
0x402570:       0x64    0x65    0x66    0x75    0x73    0x65    0x64    0x20
0x402578:       0x74    0x68    0x65    0x20    0x62    0x6f    0x6d    0x62
0x402580:       0x21    0x00    0x57    0x65    0x6c    0x6c    0x2e    0x2e
0x402588:       0x2e    0x00    0x4f    0x4b    0x2e    0x20    0x3a    0x2d
0x402590:       0x29    0x00    0x49    0x6e    0x76    0x61    0x6c    0x69
0x402598:       0x64    0x20    0x70    0x68    0x61    0x73    0x65    0x25
0x4025a0:       0x73    0x0a    0x00    0x0a    0x42    0x4f    0x4f    0x4d
0x4025a8:       0x21    0x21    0x21    0x00    0x54    0x68    0x65    0x20
*/